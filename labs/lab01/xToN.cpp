/**
Author: Joshua Tapp
CompID: jct7bm
Date: 2/7/2021 18:13
File Name: xToN.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 1 Prelab
Objective: To create a function written in C++ that can calculate the 
exponential function without use of the standard math function POW().

**/

#include <iostream>
using namespace std;

// Uses recursive call to calculate exponential function of a^b/
// b = 0 is base case. where n^0 = 1 in all cases
int multiply(int a, int b) {
    if(b == 0) {
        return 1;
    }
    else {
        return a * multiply(a, b-1);
    }
}
int main() {
    int x, y, z;
    cin >> x;
    cin >> y;
    z = multiply(x, y);
    cout << z << endl;
    return 0;
}