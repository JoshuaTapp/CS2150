/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/16/2021 11:00
File Name: inlab4.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 4 PostLab
Objective: Excercise on number representation in C++ on 64bit computer.

**/

#include <string>
#include <iostream>
#include <stdio.h>
#include <cmath>



using namespace std;

int convertBit(int x);
int convertBaseTen(string str, int start);
string convertBaseTenToBaseXYZ(int input, int end);


int main(int argc, char **argv) {

    if(argc == 2) {
        string countInput   = argv[1];
        // just run bit counter....
        cout << countInput << " has " << convertBit(stoi(countInput)) << " bit(s)\n" ;
    }

    else if(argc == 5) {
        string countInput   = argv[1];
        string num          = argv[2];
        string startBase    = argv[3];
        string endBase      = argv[4];

        // bit counter
        cout << countInput << " has " << convertBit(stoi(countInput)) << " bit(s)" << endl ;

        // base converter
        if((stoi(endBase) > 36 || (stoi(endBase) < 1)) ||  (stoi(startBase) > 36 || (stoi(startBase) < 1))  ) {
            cout << "error: Invalid base parameters\nStarting Base: " << startBase << "\nEnding Base: " << endBase << endl;
            return 0;
        }
        int baseTen = convertBaseTen(num, stoi(startBase));
        string converted = convertBaseTenToBaseXYZ(baseTen, stoi(endBase));
        cout << num << " (base " << startBase << ") = " << converted << " (base " << endBase << ")\n" ;
    }

    else {
        cout << "error: Not enough input parameters" << endl;
        return 0;
    }

    return 0;
}

int convertBit(int x) {
    int i = 0;
    if(x == 0) {
        return i;
    }
    else if(x % 2 == 0) {
        i = convertBit(x/2);
    }
    else if(x % 2 == 1) {
        i = 1 + convertBit(x/2);
    }
    return i;
}

int convertBaseTen(string str, int start) {
    int answ = 0;
    for(int i = 0; i < str.length(); i++) {
        int temp = 0;
        char ch = str[i];

        if(ch > '9') {
            temp = ((ch - '7') * pow(start, (str.length() - 1 - i) ));
        }
        else {
            temp = ((ch - '0') * pow(start, (str.length() - 1 - i) ));
        }
        answ += temp;
        
    }
    return answ;
}

string convertBaseTenToBaseXYZ(int input, int end) {
    int div = input;
    string answ = "";
    if(div == 0){
        return "0";
    }
    while(div != 0) {
        string::iterator itr = answ.begin();
        int remain = div % end;
        div = div / end;
        char ch;
        if(end == 1) {
            answ.insert(itr, '1');
            div--;
        }
        else if(remain > 9) {
            ch = remain + '7';
            answ.insert(itr, ch);
        }
        else {
            ch = remain + '0';
            answ.insert(itr, ch);
        }
    }
    
    return answ;
}
