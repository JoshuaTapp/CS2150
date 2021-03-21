/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/20/2021 19:05
File Name: TreeCalc.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 5 Prelab
Objective: Implement postfix calculator with tree structure.
**/

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
    stack<TreeNode*> expressionStack = stack<TreeNode*>();
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    if(!this->expressionStack.empty()) this->cleanTree(this->expressionStack.top()); // clean out the TreeNodes. Parameter is the top of the stack.
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if(tree->left != NULL && tree->right != NULL) {
        this->cleanTree(tree->left);
        this->cleanTree(tree->right);
        delete tree->left;
        delete tree->right;
    }

}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree

    // Operator insert. Pop the two top 2 trees and make the operator its root.
    if(val == "+" || val == "-" || val == "*" || val == "/") {
        TreeNode* oprtr = new TreeNode(val);

        // This is the most recent object. So for (a b +), this is "b".
        oprtr->right = this->expressionStack.top();
        this->expressionStack.pop();

        // This is the next most recent object. Assigned to Left branch
        oprtr->left = this->expressionStack.top();
        this->expressionStack.pop();

        // Push the new root node back to the stack.
        this->expressionStack.push(oprtr);
    }
    else {
        // Operand insert.
        this->expressionStack.push(new TreeNode(val));
    }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
    
    // same as prefix, but print leafs before root. (operand before operator)
    if(tree->left != NULL && tree->right != NULL) {
        cout << tree->value << " "; // operator
        this->printPrefix(tree->left); // run the left side of tree recursively (typically next operator)
        cout << " "; 
        this->printPrefix(tree->right); // run right side recursively.
    }
    else cout << tree->value; // for leaf node

}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
    // if we have parent node, run recursive printing
    if(tree->left != NULL && tree->right != NULL) {
        cout << "(" ;
        this->printInfix(tree->left); // eventually terms to a number
        cout << " " << tree->value << " " ;
        this->printInfix(tree->right); // eventually terms to a number
        cout <<  ")" ;
    }
    
    else cout << tree->value;  // for leaf node (will be a number)

}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
    
    // If parent node, run recursive printing
    if(tree->left != NULL && tree->right != NULL) {
        this->printPostfix(tree->left);
        this->printPostfix(tree->right);
        cout << tree->value << " " ;
    }
    else cout << tree->value << " " ;  // leaf will always be a number.
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result

    // These are the possible operations. Use recursion to go down the tree
    // and find the leaves with operands.
    if(tree->value == "+" || tree->value == "-" || tree->value == "*" || tree->value == "/") {
        char ch = tree->value[0];        
        switch (ch) {   
            case('+') : 
                return (this->calculate(tree->left)) + (this->calculate(tree->right));
            case('-') :
                return this->calculate(tree->left) - this->calculate(tree->right);
            case('*') :
                return this->calculate(tree->left) * this->calculate(tree->right);
            case('/') :
                return this->calculate(tree->left) / this->calculate(tree->right);
        }
    }

    // if at leaf, have operand, convert to integer and return to calling operation.
    else if(tree->left == NULL && tree->right == NULL){
        return stoi(tree->value);
    }
    return 0; // if invalid, return 0.
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    if (this->expressionStack.empty()) return 0;
    return this->calculate(this->expressionStack.top());
}
