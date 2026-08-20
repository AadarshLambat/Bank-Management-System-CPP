# 🏦 Banking Management System

A console-based **Banking Management System** developed in **C++** using Object-Oriented Programming (OOP) concepts.

The project allows users to create and manage **Saving Accounts** and **Current Accounts**, perform deposits and withdrawals, view account details, and calculate compound interest for saving accounts.

---

## 📌 Features

* Create a new Saving Account
* Create a new Current Account
* Automatically generate unique account numbers
* Store customer information
* View account details
* Deposit money
* Withdraw money
* Compound interest calculation for Saving Accounts
* Separate functionality for Saving and Current Accounts
* Account searching using account number
* Maximum account limit handling
* Input validation and exception handling
* Automatic memory cleanup using a virtual destructor
* Menu-driven console interface

---

## 🏦 Account Types

### Saving Account

Saving Accounts support:

* Deposits
* Withdrawals
* Compound interest
* Account information display

The current implementation uses an interest rate of **7.2%**.

### Current Account

Current Accounts support:

* Deposits
* Withdrawals
* Account information display

Compound interest is not available for Current Accounts.

---

## 🧠 OOP Concepts Used

This project demonstrates several important Object-Oriented Programming concepts in C++.

### 1. Encapsulation

Account-related data such as:

* Account number
* Name
* Age
* Address
* Phone number
* Balance
* Account type

is maintained inside the `account` class.

### 2. Inheritance

The following classes inherit from the base `account` class:

```text
             account
              /    \
             /      \
       sav_acc      cur_acc
```

* `sav_acc` → Saving Account
* `cur_acc` → Current Account

### 3. Polymorphism

The base class contains virtual functions:

```cpp
virtual void compound_intrest() = 0;
virtual void deposit() = 0;
virtual void withdrawal() = 0;
```

The derived classes override these functions to provide their own implementations.

This allows the program to work with different account types through an `account*` pointer.

### 4. Abstraction

The `account` class is an abstract class because it contains pure virtual functions.

The actual implementation of operations such as deposit, withdrawal, and interest calculation is provided by the derived classes.

### 5. Virtual Destructor

The base class contains:

```cpp
virtual ~account() {}
```

This ensures proper destruction of derived objects when they are deleted through a base-class pointer.

---

## 🧩 Main Classes

### `account`

The abstract base class that stores common account information and defines the interface for banking operations.

### `sav_acc`

Derived class representing a Saving Account.

Provides:

* Deposit
* Withdrawal
* Compound interest

### `cur_acc`

Derived class representing a Current Account.

Provides:

* Deposit
* Withdrawal

Compound interest is unavailable for this account type.

### `AccountNumberGenerator`

Generates random account numbers between `1000` and `9999`.

It uses the C++ `<random>` library to generate account numbers and prevents duplicate numbers within the generator's current lifetime.

### `Bank`

Manages the collection of accounts and provides the main banking menu.

---

## 📋 Program Menu

The main menu provides the following options:

```text
*** Menu ***

1. Create an Account
2. Get Account Details
3. Access Account
4. Exit
```

After accessing an account, the user can choose:

```text
* Account Menu *

1. Deposit
2. Withdrawal
3. Compound Interest
4. Exit
```

---

## 🔄 Program Flow

```text
Start
  |
  v
Banking System
  |
  +---- Create Account
  |       |
  |       +---- Saving Account
  |       |
  |       +---- Current Account
  |
  +---- Get Account Details
  |
  +---- Access Account
  |       |
  |       +---- Deposit
  |       +---- Withdrawal
  |       +---- Compound Interest
  |
  +---- Exit
  |
  v
End
```

---

## 🛠️ Technologies Used

* **Language:** C++
* **Programming Paradigm:** Object-Oriented Programming
* **Compiler:** GCC / MinGW
* **Libraries:**

  * `<iostream>`
  * `<string>`
  * `<limits>`
  * `<random>`
  * `<exception>`

---

## 💻 Requirements

To run this project, you need:

* A C++ compiler supporting **C++11 or later**
* GCC / MinGW / Clang / Visual Studio
* Terminal or command prompt

---

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone https://github.com/YOUR-USERNAME/Banking-System-CPP.git
```

### 2. Navigate to the project directory

```bash
cd Banking-System-CPP
```

### 3. Compile the program

Using GCC:

```bash
g++ BankingSystem.cpp -o BankingSystem
```

### 4. Run the program

On Windows:

```bash
BankingSystem.exe
```

On Linux/macOS:

```bash
./BankingSystem
```

---

## 📸 Example

```text
*** Menu ***

1. Create an Account
2. Get Account Details
3. Access Account
4. Exit

Enter your choice: 1

1. Saving Account
2. Current Account
3. Exit

Enter what type of account you'd like to open: 1

Enter Your Full Name: John Doe
Enter Your Address: Pune
Enter Your Age: 21
Enter Your Phone Number: 9876543210
Enter Initial Deposit: 10000

Account created. Your account number is 5834
```

---

## ⚙️ Current Limitations

This project is designed as an educational OOP project and currently stores account data only during program execution.

Some possible future improvements include:

* Persistent database/file storage
* Login authentication
* Transaction history
* Fund transfers between accounts
* Account deletion
* Account modification
* Better input validation
* Transaction receipts
* Different interest rates based on account conditions
* GUI interface
* Database integration using MySQL
* Password/PIN-based account security

---

## 🚀 Future Enhancements

The project can be extended into a more complete banking application by adding:

1. **File Handling**

   Store accounts permanently using files.

2. **Database Integration**

   Connect the application with MySQL or another database.

3. **Authentication**

   Add customer login using account number and PIN/password.

4. **Transaction History**

   Maintain records of deposits and withdrawals.

5. **Money Transfer**

   Allow users to transfer money between accounts.

6. **Improved Security**

   Add authentication and validation mechanisms.

7. **GUI**

   Convert the console application into a graphical banking application.

---

## 🎯 Learning Objectives

This project was developed to practice:

* Classes and Objects
* Constructors and Destructors
* Inheritance
* Abstraction
* Encapsulation
* Runtime Polymorphism
* Pure Virtual Functions
* Dynamic Memory Allocation
* Exception Handling
* Random Number Generation
* Arrays and Pointers
* Menu-driven programming

---

## 👨‍💻 Author

**Aadarsh Lambat**

C++ | Object-Oriented Programming | Data Structures & Algorithms

---

## 📄 License

This project is available for educational and learning purposes.
