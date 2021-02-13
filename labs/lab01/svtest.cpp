/**
Date: 2/14/2021 13:00
File Name: svtest.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 1 InLab
Objective: 
**/

// This was part of the In-Lab, If you comment out '#include <iostream>', it will still compile.
// I assume this is because it is included in 'svutil.h' and is imported when 'svtest.cpp' includes the header file
#include <iostream>
#include <string>

// svutil is a library to support string-vectors, i.e. vector<string>
#include "svutil.h"

// If we comment out the namespace, it will still compile. This must mean that it is 
// included by using #include 'svutil.h'
using namespace std;

// Exercise the svutil library by defining some vector<string> objects and
// calling operations on them.

int main() {
    vector<string> cs216Section1, cs216Section2;

    cs216Section1.push_back("Alex");
    cs216Section1.push_back("Jodi");
    cs216Section1.push_back("Kit");

    cout << "Section contains: " << endl;
    svOutput(cs216Section1);

    string name;
    cout << "Enter student name: ";
    cin >> name;

    int posn = svFind(cs216Section1, name);

    if ( posn == -1 )
        cout << "Student not found in section." << endl;
    else {
        cout << "Found student at index " << posn << endl;
        if ( svDeleteAt(cs216Section1, posn) )
            cout << "Deleted student from section!" << endl;
    }

    cout << "Final section contents are:" << endl;
    svOutput(cs216Section1);

    return 0;

}
