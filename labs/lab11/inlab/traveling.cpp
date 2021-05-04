/**
    @brief A naive, brute-force implementation of a solution to the TSP,
    set in the world of Middle Earth.
    
    @details This program takes in 4 parameters that will allow a repeatable solution based on
    the seed parameter.

    @author Joshua Tapp
    @date May 4th, 2021
    
    @param width Determines width of middle earth. 
    @param height Determines height of middle earth. 
    @param num_cities Determines how many nodes are on the graph. Minimum is one.
    @param rand_seed Used to generate random numbers. Used for replication of results with same seed.
    @param cities_to_visit Determine how many cities to visit. Suggested maximum is 10.


*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth *me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    sort(++dests.begin(), dests.end());

    float smallestDistance = numeric_limits<float>::max();
    vector<string> smallestPath;
    do {
        float thisDistance = computeDistance(&me, dests.at(0), dests );
        if( thisDistance < smallestDistance) {
            smallestDistance = thisDistance;
            smallestPath = dests;
        }
    } while(next_permutation(++dests.begin(), dests.end()));
    
    cout << smallestDistance << " ";
    printRoute(smallestPath.at(0), smallestPath);
    

    return 0;
}

/** @brief Computes distance between all the nodes in provided vector.

    @param me Pointer to the middle earth object.
    @param start The value of the starting node.
    @param dests The vector of cities to visit.
    @return The total distance between all the nodes in the vector dests.
    @sa middleearth::getDistance() Used to calculate distance between two nodes.
*/
float computeDistance(MiddleEarth* me, const string& start, vector<string> dests) {
    float distance = 0;
    for(int i = 0; i < dests.size() - 1; i++) {
        distance+= me->getDistance(dests.at(i), dests.at(i+1) );
    }
    distance+= me->getDistance(dests.at(dests.size() - 1), start );
    return distance;
}


/** @brief Prints the route you travel from provided vector.

    @param start The value of the starting node.
    @param dests The vector of cities to visit.
*/
void printRoute(const string& start, const vector<string>& dests) {
    cout << start << " -> ";
    for(string str : dests) {
        if(str != start) cout << str << " -> ";
    }
    cout << start;
}
