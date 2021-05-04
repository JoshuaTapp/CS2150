
#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp
/**
    @brief A graph of middle earth populated with a random selection of cities.
    
    @details This class constructs a graph of middle earth based on user parameters. 
    This graph will then select the requested nodes of the graph to be randomly
    populated with cities from all_city_names. The distances of each will also be 
    selected randomly.

    @author Aaron Bloomfield
    @author Winston Liu
    @date 2014-2021
    @copyright (CC BY-SA 4.0)


*/
class MiddleEarth {
public:
    MiddleEarth(int xsize, int ysize, int num_cities, int seed); 
    void print();
    void printTable();
    float getDistance(const string& city1, const string& city2);
    vector<string> getItinerary(unsigned int length);

private:
    int num_city_names, xsize, ysize;
    /** The x-axis locatation of each city in the middle earth graph. */
    unordered_map<string, float> xpos;
    /** The y-axis locatation of each city in the middle earth graph. */
    unordered_map<string, float> ypos;
    /** The list of selected cities in middle earth. The list is populated during construction of object. */
    vector<string> cities;
    /** The hash table that contains the cities and their respective distances to the other cities in middle earth. */
    unordered_map<string, unordered_map<string, float>> distances;
/** Mersenne-Twister random number engine from the random library.
*/
    mt19937 gen;
    
};

#endif
