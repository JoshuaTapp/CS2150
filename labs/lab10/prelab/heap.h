/**
Author: Joshua Tapp
CompID: jct7bm
Date: 04/25/2021 13:00
File Name: heap.h

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 10 prelab - Huffman Encoding
Objective:  Creates binary heap to implement queue for Huffman tree.

Sources:    Code modified by Joshua Tapp

            Original code written by Aaron Bloomfield, 2014
            Released under a CC BY-SA license
            This code is part of the https://github.com/aaronbloomfield/pdr repository
**/

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <unordered_map>

#include "huffmanNode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<char> vec);
    ~heap();

    void insert(huffmanNode* n);
    huffmanNode* findMin();
    huffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    void huffmanTree();
    void findCode(huffmanNode* n, unordered_map<char, string>* codebook, string s);
private:
    vector<huffmanNode*> heapDS;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif