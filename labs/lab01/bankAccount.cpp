/**
Author: Joshua Tapp
CompID: jct7bm
Date: 2/14/2021 14:00
File Name: bankAccount.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 1 Postlab
**/

#include "bankAccount.h"

bankAccount::bankAccount() {
    balance = 0.0;              // defaults to $0.00 balance
}

bankAccount::bankAccount(double amount) {
    balance = amount;
}

bankAccount::~bankAccount() {}

double bankAccount::withdraw(double amount) {
    if(this->balance >= amount) {
        balance -= amount;
    }
    return balance;
}

double bankAccount::deposit(double amount) {
    balance += amount;
    return balance;
}

double bankAccount::getBalance() {
    return balance;
}


