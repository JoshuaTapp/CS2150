/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/21/2021 12:30
File Name: BSTPathTest.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 5 Inlab
Objective: Implement Binary Search Tree that can search for a string.
**/
#include "BinarySearchTree.h"

#include <iostream>
using namespace std;

int main() {
    BinarySearchTree bst;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            bst.insert(word);
        } else if (instr == "R") {
            bst.remove(word);
        } else if (instr == "L") {
            cout << "BST path: " << bst.pathTo(word) << endl;
        }
    }
    cout << "BST numNodes: " << bst.numNodes() << endl;
}