/**
Author: Joshua Tapp
CompID: jct7bm
Date: 04/25/2021 13:00
File Name: huffmanenc.cpp

Course: UVA's CS2150 Programming and Data Representation

Title: LAB 10 prelab - Huffman Encoding
Objective:  This file will read in a text file, construct a Huffman encoding, 
            encode said text file, and output the codebook, encoded file, and performance of encoding.

Sources:    Code modified by Joshua Tapp
            Original code written by Aaron Bloomfield, 2014
            https://uva-cs.github.io/pdr/labs/lab10/fileio.cpp.html
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include "heap.h"


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

    unordered_map<char, huffmanNode*> input;
    unordered_map<char, huffmanNode*>::iterator itr;
    unordered_map<char, string>::iterator itr2;
    heap queue;
    int count = 0;

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    while (file.get(g)) {
        //  to do
        //      create Huffman Tree for each element with height=1
        //      build complete huffman tree
        //      generate huffman code from tree
        //cout << g;
        if(g < 32 || g > 126){          // check if the char is valid, if not skip.
            continue;
        }
        count++;
        /*
            This part is using the power of the map to quickly sort through duplicate values
            and handle the frequency.
        */
        if(input.count(g) != 0) {
            itr = input.find(g);
            itr->second->increment();
        }
        else {
            (input.insert(make_pair(g, new huffmanNode(g))));
        }
    }


    for (auto& x: input) { 
        queue.insert(x.second);
    }

    while(queue.size() > 1) {
        queue.huffmanTree();
    }
    
    unordered_map<char, string>* codebook = new unordered_map<char, string>();
    queue.findCode(queue.findMin(), codebook, "");
    for (auto& x: *codebook) { 
        if(x.first == ' ') {
            cout << "space " << x.second << endl;
        }
        else { cout << x.first << " " << x.second << endl; }
    }
    

    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    
    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // Read the file again, and print to the screen
    while (file.get(g)) {
        // todo
        //      encode the message
            if(codebook->count(g) == 1) {
                cout << codebook->at(g) << " ";
            }
        
    }
    
    cout << endl;
    // close the file
    file.close();
    cout << "----------------------------------------" << endl;
    int cfBits = 0;
    double cr = 0.0;
    double cost =0.0;
    for (auto& x: *codebook) { 
        int num = input.at(x.first)->getFrequency();
        cfBits+= num*x.second.length();
    }
    cr = count*8;
    cr /= cfBits;
    cost = cfBits;
    cost /= count;

    cout << "There are a total of " << count << " symbols that are encoded." << endl;
    cout << "There are " << codebook->size() << " distinct symbols used." << endl;
    cout << "There were " << count*8 << " bits in the original file." << endl;
    cout << "There were " << cfBits << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << cr << endl;
    cout << "The cost of the Huffman tree is " << cost <<" bits per character." << endl;

}
