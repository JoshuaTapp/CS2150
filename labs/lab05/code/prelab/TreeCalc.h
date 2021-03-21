/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/20/2021 19:05
File Name: TreeCalc.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 5 Prelab
Objective: Implement postfix calculator with tree structure.
**/


#ifndef TREECALC_H
#define TREECALC_H

#include <stack>

#include "TreeNode.h"
using namespace std;

class TreeCalc {
public:
    TreeCalc();                     // Constructor
    ~TreeCalc();                    // Destructor

    void cleanTree(TreeNode* tree);  // Deletes tree/frees memory
    void readInput();               // Gets data from user
    void insert(const string& val); // Puts value in tree

    // print methods
    void printPrefix(TreeNode* tree) const;  // Prints data in prefix form
    void printInfix(TreeNode* tree) const;   // Prints data in infix form
    void printPostfix(TreeNode* tree) const; // Prints data in postfix form
    void printOutput() const;                // Prints in post, in, pre form
    int calculate();                         // Calls private calculate method

private:
    stack<TreeNode*> expressionStack;   // Stack to hold the expression

    int calculate(TreeNode* tree) const; // Evaluates tree, returns value

};

#endif
