/**
 *  Author: Joshua Tapp
 *  CompID: jct7bm
 *  Date: 2/27/2021 17:20
 *  File Name: 

 *  Course: UVA's CS2150 Programming and Data Representation
 *
 * Title: LAB 3
 */

#ifndef STACK_H
#define STACK_H

#include <list>
#include <iostream>
using namespace std;

class stack{

public:
    stack();
    ~stack();
    void push (int e);
    void pop();
    int top();
    bool empty();

private:
    list<int>* List;
};

#endif
