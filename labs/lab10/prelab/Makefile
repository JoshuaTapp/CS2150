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
OFILES = heap.o huffmanenc.o

a.out: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES)

heap.o: heap.cpp heap.h
huffmanenc.o: huffmanenc.cpp

.PHONY: clean
clean:
	-rm *.o a.out