/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/21/2021 12:30
File Name: BinaryNode.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 5 Inlab
Objective: Implement Binary Search Tree that can search for a string.
**/

#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
    BinaryNode();
    ~BinaryNode();

    string value;
    BinaryNode* left;
    BinaryNode* right;

    friend class BinarySearchTree;
};

#endif