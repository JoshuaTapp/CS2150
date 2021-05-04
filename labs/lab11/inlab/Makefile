#Author: Joshua Tapp
#CompID: jct7bm
#Date: 5/4/2021 10:00
#File Name: Makefile

#Course: UVA's CS2150 Programming and Data Representation

#Title: LAB 11 Inlab 
#Objective: create brute force TSP solution

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O3 -Wall
DEBUG=-g
OFILES = traveling.o middleearth.o

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
	doxygen
	
traveling.o: traveling.cpp

middleearth.o: middleearth.cpp middleearth.h


.PHONY: clean
clean:
	-rm *.o a.out