#include <string>
#include <vector> 

#ifndef HASHTABLE_H
#define HASHTABLE_H

using namespace std;

class hashTable {
public:
    hashTable();
    ~hashTable();
    bool count(const string &word);
    void insert(const string &word);
    void print();

private:
    unsigned int hashFunction(const string &word);
    bool checkprime(unsigned int p);
    unsigned int getNextPrime (unsigned int n);
    void resize();
    float load_factor;
    int collisions;
    int elements;
    int table_size;
    vector<string> table;
};

#endif