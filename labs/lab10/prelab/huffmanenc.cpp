/**
Author: Joshua Tapp
CompID: jct7bm
Date: 2/20/2021 14:19
File Name: huffmanenc.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 10 prelab - Huffman Encoding
Objective:  This file will read in a text file, construct a Huffman encoding, 
            encode said text file, and output the codebook, encoded file, and performance of encoding.

Sources:
            + fileio.cpp - https://uva-cs.github.io/pdr/labs/lab10/fileio.cpp.html
            +
**/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    while (file.get(g)) {
        cout << g;
    }

    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // Read the file again, and print to the screen
    while (file.get(g)) {
        cout << g;
    }

    // close the file
    file.close();
}
