/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/20/2021 19:05
File Name: TreeNode.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 5 Prelab
Objective: Implement postfix calculator with tree structure.
**/

#include "TreeNode.h"

// Default Constructor - left and right are NULL, value '?'
TreeNode::TreeNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

// Constructor - sets value to val
TreeNode::TreeNode(const string& val) {
    value = val;
    left = NULL;
    right = NULL;
}
