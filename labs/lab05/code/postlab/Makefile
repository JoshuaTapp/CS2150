#Author: Joshua Tapp
#CompID: jct7bm
#Date: 3/25/2021 11:20
#File Name: Makefile

#Course: UVA's CS2150 Programming and Data Representation

#Title: LAB 5 Postlab
#Objective: Implement AVL balanced tree. 

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2  # Enable all warnings and *optimize assembly code*
DEBUG=-g
OFILES= AVLTree.o AVLNode.o AVLPathTest.o

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o a.out

AVLPathTest.o: AVLPathTest.cpp AVLNode.h AVLTree.h
AVLNode.o: AVLNode.cpp AVLNode.h
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h

.PHONY: clean
clean:
	-rm -f *.o a.out