#Author: Joshua Tapp
#CompID: jct7bm
#Date: 3/21/2021 12:30
#File Name: Makefile

#Course: UVA's CS2150 Programming and Data Representation

#Title: LAB 5 Inlab
#Objective: Implement Binary Search Tree that can search for a string.

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2  # Enable all warnings and *optimize assembly code*
DEBUG=-g
OFILES=BSTPathTest.o BinaryNode.o BinarySearchTree.o

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o a.out

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

.PHONY: clean
clean:
	-rm -f *.o a.out