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
private:
    vector<string> table;
    unsigned int table_size;

    unsigned int hashFunction(const string &word);
    bool checkprime(unsigned int p);
    unsigned int getNextPrime (unsigned int n);
    void resize();
    double load_factor;
};

#endif