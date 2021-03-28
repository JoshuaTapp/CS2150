
#include "hashTable.h"
using namespace std;

hashTable::hashTable() {
    table_size = getNextPrime(1024);
}

hashTable::~hashTable() {}

bool hashTable::count(const string &word) {
    return true;
}

void hashTable::insert(const string &word) {
    // 1. Hash Function
    // 2. go to address, if empty insert, if taken, check if the word already exist, else go to next spot and repeat
    // 3. update load factor
    // 4. resize table if load factor goes above 0.7  (subject to change)
    // 5.  ? 
}

unsigned int hashTable::hashFunction(const string &word) {
    // using DJB33A hash function. Suppose to be good for strings.
    return 1;
}

bool hashTable::checkprime(unsigned int p) {
    // use the provided code.
    return false;
}

unsigned int hashTable::getNextPrime(unsigned int n) {
    // use the provided code. Using this for resizing.
    return 1024;
}

void hashTable::resize() {
    // use previous table 
}

