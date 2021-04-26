/**
Author: Joshua Tapp
CompID: jct7bm
Date: 04/25/2021 13:00
File Name: heap.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 10 prelab - Huffman Encoding
Objective:  Creates binary heap to implement queue for Huffman tree.

Sources:    Code modified by Joshua Tapp
            Original code written by Aaron Bloomfield, 2014
            Released under a CC BY-SA license
            This code is part of the https://github.com/aaronbloomfield/pdr repository
**/

#include <iostream>
#include "heap.h"

using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    heapDS.push_back(new huffmanNode());
}

// builds a heap from an unsorted vector
heap::heap(vector<char> vec) : heap_size(vec.size()) {
    /*
    heap = vec;
    heap.push_back(heap[0]);
    heap[0] = NULL;
    for (int i = heap_size/2; i > 0; i--) {
       // percolateDown(i); // FIX THIS
    }
    */
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* n) {
// a vector push_back will resize as necessary
    heapDS.push_back(n);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    int x = heapDS[hole]->frequency;
    huffmanNode* temp = heapDS[hole];

    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x < heapDS[hole/2]->frequency); hole /= 2) {
        heapDS[hole] = heapDS[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heapDS[hole] = temp;
}

huffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        cout << "deleteMin() called on empty heap" << endl;
    }

    // save the value to be returned
    huffmanNode* ret = heapDS[1];
    // move the last inserted position into the root
    heapDS[1] = heapDS[heap_size--];
    // make sure the vector knows that there is one less element
    heapDS.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
   // get the value to percolate down
    int x = heapDS[hole]->frequency;
    huffmanNode* temp = heapDS[hole];

    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heapDS[child+1]->frequency < heapDS[child]->frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (x > heapDS[child]->frequency) {
            heapDS[hole] = heapDS[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heapDS[hole] = temp;
}

huffmanNode* heap::findMin() {
    if (heap_size == 0) {
        cout << "findMin() called on empty heap" << endl;
    }
    return heapDS[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heapDS.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << heapDS[0] << ") " << "\n\t";
    for (int i = 1; i <= heap_size; i++) {
        cout << heapDS[i]->value << "-" << heapDS[i]->frequency << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
    
}

void heap::huffmanTree() {
    huffmanNode* A = deleteMin();
    huffmanNode* B = deleteMin();
    huffmanNode* newNode = new huffmanNode();
    newNode->left_child = A;
    newNode->right_child = B;
    newNode->frequency = A->frequency + B->frequency;
    this->insert(newNode);
}

void heap::findCode(huffmanNode* n, unordered_map<char, string>* codebook, string s) {
    if(n->right_child == NULL && n->left_child == NULL) {
        codebook->insert(make_pair(n->value, s));
    }
    else {
        string strL = s+"0";
        string strR = s+"1";
        findCode(n->left_child, codebook, strL);
        findCode(n->right_child, codebook, strR);
    }

    
    
}
