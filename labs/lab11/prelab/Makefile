#Author: Joshua Tapp
#CompID: jct7bm
#Date: 5/3/2021 13:00
#File Name: Makefile

#Course: UVA's CS2150 Programming and Data Representation

#Title: LAB 11 
#Objective: topo sort

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2 -Wall
DEBUG=-g
OFILES = topological.o middleearth.o

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
	doxygen
	
topological.o: topological.cpp

middleearth.o: middleearth.cpp middleearth.h


.PHONY: clean
clean:
	-rm *.o a.out