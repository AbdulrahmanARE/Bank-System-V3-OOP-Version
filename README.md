# Bank System V3 (C++ - OOP Version)

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
- clsBankClient → Handles client data and operations
- clsUser → Handles system users and permissions
- clsPerson → Base class for shared person data
- clsDate → Date handling utilities

---

### 2. Screens (UI Layer)

Each feature is now separated into its own screen class:

#### Client Management Screens
- clsAddNewClientScreen
- clsDeleteClientScreen
- clsUpdateClientScreen
- clsFindClientScreen
- clsClientListScreen

#### Transactions Screens
- clsDepositScreen
- clsWithdrawScreen
- clsTotalBalancesScreen
- clsTransactionsScreen

#### User Management Screens
- clsAddNewUserScreen
- clsDeleteUserScreen
- clsUpdateUserScreen
- clsFindUserScreen
- clsListUsersScreen
- clsManageUsersScreen

#### System Screens
- clsLoginScreen
- clsMainScreen

---

### 3. Utilities
- clsUtil → Helper functions
- clsString → String processing utilities
- clsInputValidateDate → Input validation

---

### 4. Base Screen System
- clsScreen → Base class for all screens (common UI logic, permissions, headers, etc.)

---

### 5. Global Configuration
- Global.h → Shared global variables and system-wide settings

---

## Features

### Client Management
- Add / Update / Delete clients
- Find client by account number
- Display client list

### Transactions
- Deposit money
- Withdraw money (with validation)
- View total balances

### User Management & Permissions
- Add / Update / Delete users
- Find and list users
- Role-based access control (permissions system)

### Security
- Login system as entry point
- Permission-based screen access control
- Admin-protected operations

---

## Data Storage

All data is stored using file-based persistence:

### Clients.txt
FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#AccountBalance

**Example:**
ABDO#//#Ramadan#//#ARE@gmail.com#//#01111101010#//#A101#//#1234#//#7000.000000

### Users.txt
FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#Password#//#Permissions

**Example:**
Adli#//#Haddad#//#Adli@Gmail.com#//#8983883#//#User1#//#1234#//#7

---

## Program Flow

- Program starts from `main.cpp`
- System redirects to `clsLoginScreen`
- After successful login → `clsMainScreen`
- User navigates through screens based on permissions

---

## Main Entry Point

```cpp
#include <iostream>
#include "clsLoginScreen.h"

int main() {

    while (true)
    {
        clsLoginScreen::ShowLoginScreen();
    }

    return 0;
}

```
## Design Improvements (Compared to V2)

- Full transition from procedural → Object-Oriented Design  
- Separation of concerns (UI / Logic / Data)  
- Modular screen-based architecture  
- Reusable base screen class (clsScreen)  
- Better maintainability and scalability  
- Easier to extend with new features  

---

## Purpose of the Project

This project was built to practice:

- Object-Oriented Programming (OOP)  
- Class hierarchy design  
- Encapsulation & abstraction  
- File handling in C++  
- Scalable console application architecture  
- Role-based access control system design  

---

## Author

**Abdulrahman Ramadan**  
C++ Developer – OOP Banking System (Refactored Version from Procedural to Modular Architecture)
