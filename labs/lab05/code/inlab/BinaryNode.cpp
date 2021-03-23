/**
Author: Joshua Tapp
CompID: jct7bm
Date: 3/21/2021 12:30
File Name: BinaryNode.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 5 Inlab
Objective: Implement Binary Search Tree that can search for a string.
**/
#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}