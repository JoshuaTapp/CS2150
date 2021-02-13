/**
Author: Joshua Tapp
CompID: jct7bm
Date: 2/14/2021 13:00
File Name: LifeCycle.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 1 InLab
**/

#ifndef LIFECYCLE_H
#define LIFECYCLE_H
#include <iostream>
#include <string>

using namespace std;

// Declare the MyObject class
class MyObject {
public:
    static int numObjs;

    MyObject();                    // default constructor
    MyObject(string n);            // constructor with name parameter
    MyObject(const MyObject& rhs); // copy constructor
    ~MyObject();                   // destructor

    string getName() const;
    void setName(const string& newName);

    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

// Prototypes for non-member functions we define later on
// These are *non-member* functions because we didn't declare them as part of the MyObject class
MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
int cmpMyObj(const MyObject o1, const MyObject o2);
void swapMyObj(MyObject& o1, MyObject& o2);

#endif