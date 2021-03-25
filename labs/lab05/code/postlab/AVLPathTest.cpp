/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/25/2021 11:20
File Name: AVLPathTest.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 5 Postlab
Objective: Implement AVLTree that can search for a string and self balance.
**/
#include "AVLTree.h"

#include <iostream>
using namespace std;

int main() {
    AVLTree avl;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            avl.insert(word);

        } else if (instr == "R") {
            avl.remove(word);
        } else if (instr == "L") {
            cout << "AVL path: " << avl.pathTo(word) << endl;
        }
    }
    //cout << "Final Form:" << endl;
   // avl.printTree();
    cout << "AVL numNodes: " << avl.numNodes() << endl;
}