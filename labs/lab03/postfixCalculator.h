/**
 *  Author: Joshua Tapp
 *  CompID: jct7bm
 *  Date: 2/27/2021 14:37
 *  File Name: postfixCalculator.h

 *  Course: UVA's CS2150 Programming and Data Representation
 *
 * Title: LAB 3
 */

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <stack>
#include <string>
#include <iostream>

using namespace std;

class postfixCalculator {

public: 
    postfixCalculator();
    ~postfixCalculator();
    void calculate();

private:
    stack<string>* stack1; // this is for numbers
    stack<string>* stack2; // this is for operators

};

bool checkInteger(const string str);
#endif
