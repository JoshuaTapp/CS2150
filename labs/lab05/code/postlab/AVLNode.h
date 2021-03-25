/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/25/2021 11:20
File Name: AVLNode.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 5 Postlab
Objective: Implement AVLTree that can search for a string and self balance.
**/
#ifndef AVLNODE_H
#define AVLNODE_H
#include <string>
using namespace std;

class AVLNode {
    AVLNode();
    ~AVLNode();

    string value;
    AVLNode* left;
    AVLNode* right;
    int height;

    friend class AVLTree;
};

#endif