/**
Author: Joshua Tapp
CompID: jct7bm
Date: 04/27/2021 23:00
File Name: huffmanenc.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 10 inlab - Huffman Encoding
Objective:  This file will read in a text file and decode a Huffman encoding.
            Implemenation is a huffman tree through the use of a vector data structure.
            Some shortcuts were made due to promised limited size of the codebook.

Sources:    Code modified by Joshua Tapp
            Original code written by Aaron Bloomfield, 2014
            https://uva-cs.github.io/pdr/labs/lab10/inlab-skeleton.cpp
**/


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

// main(): we want to use parameters
int main (int argc, char** argv) {
    vector<char>* tree = new vector<char>();
    tree->assign(4096, '\0');
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
        int node = 1;
        for(int i = 0; i < prefix.length(); i++) {
            if(i+1 == prefix.length()) {
                if(prefix[i] == '0') tree->at(node*2) = character[0] ;
                else tree->at(node*2 + 1) = character[0] ;
                break;
            }

            if(prefix[i] == '0') {
                node *= 2;
            }
            else if(prefix[i] == '1') {
                node *= 2;
                node++;
            }
        }
    }
      // Huffman tree is printing out correctly.
        /*int k = 0;
        for (auto& x: *tree) { 
            if(x != '\0') cout << x << " - " << k << ", ";
            k++;
        }*/

    int index = 1;
    while (true) {
        string bit="";
        // read in the first token on the line
        file >> bit;
        // did we hit the separator?
        if (bit[0] == '-' && bit.length() > 1) {
            break;
        }
        for(int i = 0; i < bit.length(); i++) {
            
            if(bit[i] == '0') index*=2;
        
            if(bit[i] == '1') index = index*2 + 1;

            if(!(tree->at(index) == tree->at(0))){
             cout << tree->at(index);
             index = 1;
            }
        }
    }
    cout << endl;
    return 0;
}