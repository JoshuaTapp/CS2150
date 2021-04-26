/**
Author: Joshua Tapp
CompID: jct7bm
Date: 04/25/2021 13:00
File Name: huffmanNode.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 10 prelab - Huffman Encoding
Objective:  Creates binary heap to implement queue for Huffman tree.
**/

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>

using namespace std;

class huffmanNode {
public:
    huffmanNode();          // Constructor
    huffmanNode(char c);    // Constructor with new value
    ~huffmanNode();         // Destructor
    char getValue();        // getter for value
    void increment();       // need because private member and use with table.
    void print();
    int getFrequency();
private:
    int frequency;              // how many times this value has appeared. [Probability]
    huffmanNode* left_child;    // left child of Huffman Tree
    huffmanNode* right_child;   // right child of Huffman Tree
    char value;                 // the ASCII value that we are encoding

    // make friend of the minHeap.
    friend class heap;

};

#endif
