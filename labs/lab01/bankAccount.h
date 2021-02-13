/**
Author: Joshua Tapp
CompID: jct7bm
Date: 2/14/2021 14:00
File Name: bankAccount.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 1 Postlab
**/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

// Declare bankAccount object class
class bankAccount {
    public:
        bankAccount();              // default constructor
        bankAccount(double amount); // constructor that intializes the account balance
        ~bankAccount();             // destructor

        double withdraw(double amount);
        double deposit(double amount);
        double getBalance();

    private:
        double balance;
};

#endif