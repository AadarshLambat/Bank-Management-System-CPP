#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <exception>

class account {
protected:
    int accno, age;
    std::string name, t, address;
    bool type; // 1: Saving, 0: Current
    double bal, minbal = 5000, intrest = 7.2, penalty = 3.6;
    long int phno;

public:
    account(int accno, std::string name, int age, std::string address, double bal, long int phno, bool type)
        : accno(accno), name(name), age(age), address(address), bal(bal), phno(phno), type(type) {
        t = type ? "Saving Account" : "Current Account";
    }

    virtual ~account() {} // Virtual destructor

    void display() const {
        std::cout << "************\n";
        std::cout << "Acc no: " << accno << "\n";
        std::cout << "Acc Holder Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Address: " << address << "\n";
        std::cout << "Phone No: " << phno << "\n";
        std::cout << "Balance: $" << bal << "\n";
        std::cout << "Acc Type: " << t << "\n";
        std::cout << "************\n";
    }

    int getAccNo() const {
        return accno;
    }

    virtual void compound_intrest() = 0;
    virtual void deposit() = 0;
    virtual void withdrawal() = 0;
};

class sav_acc : public account {
private:
    double comintrest;

public:
    sav_acc(int accno, std::string name, int age, std::string address, double bal, long int phno, bool type)
        : account(accno, name, age, address, bal, phno, true) {}

    void compound_intrest() override {
        if (bal > 0) {
            comintrest = (bal * intrest / 100);
            bal += comintrest;
            std::cout << "Your Saving Account got credited with $" << comintrest
                      << ". Now Balance is $" << bal << ".\n";
        }
    }

    void withdrawal() override {
        double tempamt;
        std::cout << "Enter Withdrawal amount: ";
        std::cin >> tempamt;
        if (tempamt > 0) {
            if (tempamt <= bal) {
                bal -= tempamt;
                std::cout << "Withdrawal of $" << tempamt << " successful. Remaining balance: $" << bal << "\n";
            } else {
                std::cout << "Insufficient balance.\n";
            }
        } else {
            std::cout << "Enter a valid amount.\n";
        }
    }

    void deposit() override {
        double tempamt;
        std::cout << "Enter Deposit amount: ";
        std::cin >> tempamt;
        if (tempamt < 0) {
            std::cout << "Enter a valid amount.\n";
        } else {
            bal += tempamt;
            std::cout << "Deposit successful. Your balance is $" << bal << ".\n";
        }
    }
};

class cur_acc : public account {
public:
    cur_acc(int accno, std::string name, int age, std::string address, double bal, long int phno, bool type)
        : account(accno, name, age, address, bal, phno, false) {}

    void compound_intrest() override {
        std::cout << "Feature is not available!\n";
    }

    void withdrawal() override {
        double tempamt;
        std::cout << "Enter Withdrawal amount: ";
        std::cin >> tempamt;
        if (tempamt > 0) {
            if (tempamt <= bal) {
                bal -= tempamt;
                std::cout << "Withdrawal of $" << tempamt << " successful. Remaining balance: $" << bal << "\n";
            } else {
                std::cout << "Insufficient balance.\n";
            }
        } else {
            std::cout << "Enter a valid amount.\n";
        }
    }

    void deposit() override {
        double tempamt;
        std::cout << "Enter Deposit amount: ";
        std::cin >> tempamt;
        if (tempamt < 0) {
            std::cout << "Enter a valid amount.\n";
        } else {
            bal += tempamt;
            std::cout << "Deposit successful. Your balance is $" << bal << ".\n";
        }
    }
};

class AccountNumberGenerator {
private:
    bool used[10000] = { false };
    std::mt19937 gen;

public:
    AccountNumberGenerator() {
        std::random_device rd;
        gen.seed(rd());
    }

    int generate() {
        std::uniform_int_distribution<> dist(1000, 9999);
        int num;
        do {
            num = dist(gen);
        } while (used[num]);
        used[num] = true;
        return num;
    }
};

account* createacc() {
    static const int MAX_ACCOUNTS = 100;
    static int count = 0;
    static AccountNumberGenerator gen;

    if (count >= MAX_ACCOUNTS) {
        std::cout << "Maximum account limit reached!\n";
        return nullptr;
    }

    while (true) {
        std::string name, address;
        int age, accno, resp;
        double bal;
        long int phno;
        account* ptr = nullptr;

        try {
            std::cout << "\n1. Saving Account\n2. Current Account\n3. Exit\n";
            std::cout << "Enter what type of account you'd like to open: ";
            std::cin >> resp;

            if (std::cin.fail()) {
                throw std::invalid_argument("Bad input");
            }

            if (resp == 1 || resp == 2) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter Your Full Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Your Address: ";
                std::getline(std::cin, address);
                std::cout << "Enter Your Age: ";
                std::cin >> age;
                if (age < 18) {
                    std::cout << "You must be over 18 to open an account.\n";
                    return nullptr;
                }
                std::cout << "Enter Your Phone Number: ";
                std::cin >> phno;
                std::cout << "Enter Initial Deposit: ";
                std::cin >> bal;
                accno = gen.generate();

                if (resp == 1) {
                    ptr = new sav_acc(accno, name, age, address, bal, phno, true);
                } else {
                    ptr = new cur_acc(accno, name, age, address, bal, phno, false);
                }

                std::cout << "Account created. Your account number is " << accno << "\n******\n";
                count++;
                return ptr;
            } else if (resp == 3) {
                return nullptr;
            } else {
                std::cout << "Invalid option. Try again.\n";
            }

        } catch (const std::exception& e) {
            std::cerr << "Error occurred: " << e.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

class Bank {
private:
    static const int MAX_ACCOUNTS = 100;
    account* accounts[MAX_ACCOUNTS];
    int count = 0;
    int choice;

public:
    ~Bank() {
        for (int i = 0; i < count; ++i) {
            delete accounts[i];
        }
    }

    void run() {
        while (true) {
            std::cout << "\n*** Menu ***\n";
            std::cout << "1. Create an Account\n";
            std::cout << "2. Get Account Details\n";
            std::cout << "3. Access Account\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                if (count < MAX_ACCOUNTS) {
                    account* acc = createacc();
                    if (acc != nullptr) {
                        accounts[count++] = acc;
                    }
                }
                break;

            case 2: {
                int searchAcc;
                std::cout << "Enter Account Number: ";
                std::cin >> searchAcc;
                bool found = false;
                for (int i = 0; i < count; ++i) {
                    if (accounts[i]->getAccNo() == searchAcc) {
                        accounts[i]->display();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Account not found!\n";
                }
                break;
            }

            case 3: {
                int searchAcc;
                std::cout << "Enter Account Number: ";
                std::cin >> searchAcc;
                bool found = false;

                for (int i = 0; i < count; ++i) {
                    if (accounts[i]->getAccNo() == searchAcc) {
                        found = true;
                        std::cout << "\n* Account Menu *\n";
                        while (true) {
                            int opt;
                            std::cout << "\n1. Deposit\n2. Withdrawal\n3. Compound Interest\n4. Exit\n";
                            std::cout << "Enter a choice: ";
                            std::cin >> opt;

                            if (opt == 1) {
                                accounts[i]->deposit();
                            } else if (opt == 2) {
                                accounts[i]->withdrawal();
                            } else if (opt == 3) {
                                accounts[i]->compound_intrest();
                            } else if (opt == 4) {
                                break;
                            } else {
                                std::cout << "Invalid input\n";
                            }
                        }
                        break;
                    }
                }

                if (!found) {
                    std::cout << "Account not found!\n";
                }

                break;
            }

            case 4:
                std::cout << "Thank you for using the banking system!\n";
                return;

            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
            }
        }
    }
};

int main() {
    Bank B;
    B.run();
    return 0;
}
