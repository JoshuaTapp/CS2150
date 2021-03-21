/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/20/2021 19:05
File Name: TreeNode.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 5 Prelab
Objective: Implement postfix calculator with tree structure.
**/


#ifndef TREENODE_H
#define TREENODE_H

#include <string>
using namespace std;

class TreeNode {
public:
    TreeNode();                  // Default Constructor
    TreeNode(const string& val); // Constructor

private:
    string value;
    TreeNode* left;
    TreeNode* right;
    friend class TreeCalc;       // gives TreeCalc access to private data
};

#endif
