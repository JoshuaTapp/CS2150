/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/7/2021 13:00
File Name: prelab4.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 4 PreLab
Objective: Excercise on number representation in C++ on 64bit computer.

**/
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

void sizeOfTest() {
   cout << "Size of int: " << sizeof(int) << endl;
   cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
   cout << "Size of float:" << sizeof(float) << endl;
   cout << "Size of double: " << sizeof(double) << endl;
   cout << "Size of char:" << sizeof(char) << endl;
   cout << "Size of bool: " << sizeof(bool) << endl;
   cout << "Size of int*: " << sizeof(int*) << endl;
   cout << "Size of char*: " << sizeof(char*) << endl;
   cout << "Size of double*: " << sizeof(double*) << endl;
}


void overflow() {
    unsigned int i = UINT_MAX;
    i++;
    cout << UINT_MAX << " + 1 = " << i << endl;
}

void outputBinary(unsigned int x) {
    unsigned int temp = x;
    int power = 31;
    int div   = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 4; j++) {
            div = pow(2, power);
            if(temp >= div) {
                cout << "1";
                temp = temp - div;
            }
            else {
                cout << "0";
            }
            power = power - 1;
        }
        cout << " ";
    }
    cout << endl;
}

int main() {
  sizeOfTest();
  overflow();
  unsigned int l;
  cin >> l;
  outputBinary(l);

  return 0;
}