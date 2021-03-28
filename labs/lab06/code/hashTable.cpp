
#include "hashTable.h"
#include <iostream>
using namespace std;

hashTable::hashTable() {
    table_size = getNextPrime(50000);
    //cout << table_size;
    table.reserve(table_size);
    //cout << " capacity: " << table.capacity() << endl;
    load_factor = 0;
    //cout << load_factor << endl;
}

hashTable::~hashTable() {}

void hashTable::print() {
    for(int i = 0; i < table.capacity(); i++) {
        if(table[i] != ""){
            if(table[i] == "abacus") cout << "found abacus" << endl;
        }
    }
}
bool hashTable::count(const string &word) {
    unsigned int hash = hashFunction(word);
    while(true) {
        if ( table[hash] == word ) return true;
        else if(table[hash] == "") return false;
        ++hash;
    }
}

void hashTable::insert(const string &word) {
    // 1. Hash Function
    // 2. go to address, if empty insert, if taken, check if the word already exist, else go to next spot and repeat
    // 3. update load factor
    // 4. resize table if load factor goes above 0.7  (subject to change)
    // 5.  ? 
    unsigned int hash = hashFunction(word);
    //cout << hash << "\t value: " << table[hash] << endl;
    
    while(true) {
        if(table[hash] == "") {
            table[hash] = word; // found empty space, insert here.
            //cout << table[hash] << endl;
            elements++;
            //if(word == "abacus") cout << "Success " << word << endl; 
            //load_factor = (elements / table_size);
            //double k = 3/2;
            //cout << k << endl;
            break;    
        } 
        else if(table[hash] == word) {
            break; /* Do nothing, we have a duplicate*/
            }

        else {
            //collisions++;
            if(hash == (table_size -1)) hash = 0;
            else hash++;
        } 
        
    }
    //cout << "collisions: " << collisions;
    //collisions = 0;
    //cout << "\tload_factor: " << load_factor << "\tsize: " << elements << "\ttablesize: " << table_size << endl;
    if((elements/table_size) > .7) {
        //cout << "RESIZE" << endl;
        resize();
    }
}

// Citation: https://groups.google.com/g/comp.lang.c/c/lSKWXiuNOAk?pli=1
// the hash was created by Daniel J. Bernstein - cir. 1991
unsigned int hashTable::hashFunction(const string &word) {
    unsigned int hash = 5381; 
    for(int i = 0; i < word.length(); i++) {
        hash = ((hash << 5) + hash) +  word[i];
    }
    //cout << hash << "\tnew hash: "  << (hash % table_size) << endl; 
    return hash % table_size;
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

unsigned int hashTable::getNextPrime(unsigned int n) {
    while ( !checkprime(++n) );
        return n; // all your primes are belong to us
}

void hashTable::resize() {
    vector<string> temp;
    temp.reserve(elements);
    for(int i = 0; i < table.capacity(); i++) {
        temp.push_back(table[i]);    
    } 
    table.reserve(getNextPrime(2*table.capacity()));
    table.clear();
    table_size = table.capacity();
    for(const auto &str : temp ) {
        if(str != "") insert(str);
    }

    /*
    temp_table.assign(table.begin(), table.end());
    table.reserve(getNextPrime(2*table_size)); // double size of table
    table.clear(); // empty our table of previous strings
    //cout << table_size << " ";
    table_size = table.capacity(); 
    //cout << table_size << endl;

    cout << endl;
    for (unsigned int i = 0 ; i < temp_table.capacity(); i++) {
            if(temp_table[i] != ""){
                insert(temp_table[i]); // if not "", then rehash this item.
            }
    }
    */
}

