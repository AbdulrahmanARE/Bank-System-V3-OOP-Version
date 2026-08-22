# Bank System V4 (C++ - OOP Version)

Console-based Bank Management System in C++ (Object-Oriented Design)
This is an upgraded version of the previous procedural bank system, fully refactored using OOP principles and a screen-based architecture.

---

## Project Overview

The system has been redesigned from a single-file procedural structure into a modular Object-Oriented Architecture.

Instead of calling functions directly from `main`, the system is now built around Screens (UI layers) and Classes (business logic layer).

The application starts from the Login Screen, which acts as the entry point to the system.

---

## Architecture

### 1. Core Business Logic (Models)

* clsBankClient → Handles client data and operations
* clsUser → Handles system users and permissions
* clsPerson → Base class for shared person data
* clsCurrency → Handles currency data and exchange rates
* clsDate → Date handling utilities

---

### 2. Screens (UI Layer)

Each feature is now separated into its own screen class:

#### Client Management Screens

* clsAddNewClientScreen
* clsDeleteClientScreen
* clsUpdateClientScreen
* clsFindClientScreen
* clsClientListScreen

#### Transactions Screens

* clsDepositScreen
* clsWithdrawScreen
* clsTotalBalancesScreen
* clsTransactionsScreen
* clsTransferScreen

#### User Management Screens

* clsAddNewUserScreen
* clsDeleteUserScreen
* clsUpdateUserScreen
* clsFindUserScreen
* clsListUsersScreen
* clsManageUsersScreen

#### System Screens

* clsLoginScreen
* clsMainScreen
* clsLoginRegisterListScreen
* clsTransferLogScreen

#### Currency Exchange Screens

* **clsCurrenciesListScreen** (New)
* **clsFindCurrencyScreen** (New)
* **clsUpdateCurrencyRateScreen** (New)
* **clsCurrencyCalculatorScreen** (New)
* **clsCurrencyExchangeMainScreen** (New)

---

### 3. Utilities

* clsUtil → Helper functions
* clsString → String processing utilities
* clsInputValidateDate → Input validation

---

### 4. Base Screen System

* clsScreen → Base class for all screens (common UI logic, permissions, headers, etc.)

---

### 5. Global Configuration

* Global.h → Shared global variables and system-wide settings

---

## Features

### Client Management

* Add / Update / Delete clients
* Find client by account number
* Display client list

### Transactions

* Deposit money
* Withdraw money (with validation)
* View total balances
* **Transfer Money**: Secure transfer between accounts with balance validation.
* **Transfer Log**: Keeps a record of all transfer operations.

### User Management & Permissions

* Add / Update / Delete users
* Find and list users
* Role-based access control (permissions system)
* **Login Register**: Tracks all user login activities.
* **Log Register Permission**: Restrict access to login logs based on user permissions.

### Currency Exchange

* List available currencies
* Find currency by currency code
* Update currency exchange rates
* Currency calculator for converting between currencies

### Security & Enhancements

* Login system as entry point
* Permission-based screen access control
* Admin-protected operations
* **Password Encryption**: Passwords are now encrypted before being stored in the file.
* **Login Lockout**: The system automatically locks after 3 failed login attempts.
* **Session Info**: All screens now display the current date and the logged-in user.

---

## Data Storage

All data is stored using file-based persistence:

### Clients.txt

FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#AccountBalance

### Users.txt

FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#Password#//#Permissions
*(Passwords are stored in encrypted format)*

### LoginRegister.txt

Date#//#UserName#//#Password#//#Permissions
*(Passwords are stored in encrypted format)*

### TransferLog.txt

Date#//#SourceAccount#//#DestinationAccount#//#Amount#//#BalanceAfter#//#BalanceAfter#//#User

---

## Program Flow

* Program starts from `main.cpp`
* System redirects to `clsLoginScreen`
* After successful login → `clsMainScreen`
* User navigates through screens based on permissions
* Currency Exchange can be accessed through its dedicated `clsCurrencyExchangeMainScreen`
* User can return to the Main Menu from the Currency Exchange Menu

---

## Main Entry Point

```cpp
#include <iostream>
#include "clsLoginScreen.h"

int main() {

    while (true)
    {
        if(!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }

    return 0;
}
```

---

## Design Improvements (Compared to V2)

* Full transition from procedural → Object-Oriented Design
* Separation of concerns (UI / Logic / Data)
* Modular screen-based architecture
* Reusable base screen class (clsScreen)
* Better maintainability and scalability
* Easier to extend with new features

---

## Design Improvements (Compared to V3)

* **Currency Exchange Module** for managing currencies and exchange rates
* **Currency Management** with dedicated screens for listing, searching, and updating currencies
* **Currency Calculator** for converting between currencies

---

## Purpose of the Project

This project was built to practice:

* Object-Oriented Programming (OOP)
* Class hierarchy design
* Encapsulation & abstraction
* File handling in C++
* Scalable console application architecture
* Role-based access control system design
* Currency exchange and rate management

---

## Author

**Abdulrahman Ramadan**
C++ Student Developer – OOP Banking System Project
