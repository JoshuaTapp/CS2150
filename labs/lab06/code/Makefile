#Author: Joshua Tapp
#CompID: jct7bm
#Date: 3/27/2021 13:00
#File Name: Makefile

#Course: UVA's CS2150 Programming and Data Representation

#Title: LAB 6 
#Objective: Implement hashTable that can quickly find a list of words in a NxM grid word puzzle.

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2 -Wall
DEBUG=
OFILES = wordPuzzle.o hashTable.o timer.o 

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)

wordPuzzle.o: wordPuzzle.cpp
hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm *.o a.out