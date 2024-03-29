/**
Author: Joshua Tapp
CompID: jct7bm
Date: 2/20/2021 14:19
File Name: ListNode.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 2
**/

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class ListNode {
public:
    ListNode();         // Constructor

private:
    int value;          // The value of the node!
    ListNode* next;     // The next ListNode in the List
    ListNode* previous; // The previous ListNode in the list

    // List needs access to value, next, and previous
    friend class List;

    // ListItr needs access to value
    friend class ListItr;

    // Not writing a destructor is fine in this case since there is no
    // dynamically allocated memory in this class.
};

#endif
