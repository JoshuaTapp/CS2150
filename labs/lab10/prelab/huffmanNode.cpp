/**
Author: Joshua Tapp
CompID: jct7bm
Date: 04/25/2021 13:00
File Name: huffmanNode.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 10 prelab - Huffman Encoding
Objective:  Creates binary heap to implement queue for Huffman tree.
**/

#include "huffmanNode.h"

huffmanNode::huffmanNode() {
    frequency = 0;
    left_child = NULL;
    right_child = NULL;
    value = '\0';
}
huffmanNode::huffmanNode(char c) {
    frequency = 1;
    left_child = NULL;
    right_child = NULL;
    value = c;
}

char huffmanNode::getValue() {
    return this->value;
}

void huffmanNode::increment() {
    this->frequency++;
}

int huffmanNode::getFrequency() {
    return this->frequency;
}


void huffmanNode::print() {
    cout << this-> value;
    cout << " | " << this->frequency;
    cout << endl;
}