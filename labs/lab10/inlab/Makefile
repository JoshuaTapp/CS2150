#Author: Joshua Tapp
#CompID: jct7bm
#Date: 4/25/2021 13:00
#File Name: Makefile

#Course: UVA's CS2150 Programming and Data Representation

#Title: LAB 10 
#Objective: Implement Priority Queue to handle Huffman coding/decoding

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2 -Wall
DEBUG=-g
OFILES = huffmanenc.o 

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)

huffmanenc.o: huffmanenc.cpp

.PHONY: clean
clean:
	-rm *.o a.out