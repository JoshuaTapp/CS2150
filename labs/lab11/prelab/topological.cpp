/**
    @brief
    @details

    @author Joshua Tapp
    @date  05/03/2021
    @todo  Accept fil~e 
    @todo  Contruct graph from file
    @todo  sort graph
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool searchVector(vector<vector<string>> *graph, string str);
void addNode(vector<vector<string>> *graph, string a, string b);
void topoSort(vector<vector<string>> *graph);
vector<int> getDegrees(vector<vector<string>> *graph);


int main(int argc, char **argv) {
    vector<vector<string>> *graph = new vector<vector<string>>();
    if(argc != 2) {
        cout << "Please include a valid file name as the sole parameter" << endl;
        exit(1); 
    }
    ifstream ifs(argv[1]);
    if(!ifs.is_open()) {
        cout << "Bad file name. It is possible the file does not exist." << endl;
        exit(1); 
    }


    while(ifs.good()) {
        string a, b;
        ifs >> a;
        ifs >> b;
        // Check if we are at end of file. (which is 0 0).
        if(a == "0" && b == "0") {
            break;
        }
        // This works. I have the file input working well with the fstream.
        if( !searchVector(graph, a) ) {
            vector<string> temp = {a};
            graph->push_back(temp);
        }
        if( !searchVector(graph, b) ) {
            vector<string> temp = {b};
            graph->push_back(temp);
        }

        //cout << it << endl;
    }
        
    sort(graph->begin(), graph->end());
    int graphSize = graph->size();
    

    ifs.clear(); // Clears the _state_ of the file, not its contents!
    ifs.seekg(0);

    while(ifs.good()) {
        string a, b;
        ifs >> a;
        ifs >> b;
        // Check if we are at end of file. (which is 0 0).
        if(a == "0" && b == "0") {
            break;
        }
        // This works. I have the file input working well with the fstream.
        addNode(graph, a, b);


        //cout << it << endl;
    }


    ifs.close();
    topoSort(graph);


}

bool searchVector(vector<vector<string>> *graph, string str) {
    for(int i = 0; i < graph->size(); i++) {
        if(graph->at(i).at(0) == str) return true;
    }
    return false;
}

void addNode(vector<vector<string>> *graph, string a, string b) {
    vector<string>* temp = nullptr;
    bool nodeFound = false;
    for(auto& x:*graph) {
        if(x[0] == a) {
            temp = &x;
            break;
        }
    }
    for(auto& edge : *temp){
        if(edge == b){
            nodeFound = true;
            break;      // its already added, no need to do it again.
        }
    }
    if(!nodeFound) {
        temp->push_back(b); // add the node to node a's forward edge list.
    }
}

void topoSort(vector<vector<string>> *graph) {
    vector<int> degree = getDegrees(graph);
    queue<string> sorted;
    while(true) {
    cout << endl;
        for(int i = 0; i < degree.size(); i++) {
            if(degree[i] == 0) {
                sorted.push(graph->at(i).at(0));
                degree.at(i) = -1;
                for( int n = 1; n < graph->at(i).size(); n++ ) {
                    for (int s = 0; s < graph->size(); s++ ) {
                        if( graph->at(s).at(0) == graph->at(i).at(n) ) {
                            degree.at(s)--;
                        }
                    }
                }
            }
        }
        int count = 0;
        for(auto x : degree) {
            if(x == -1) count++;
        }

        if(count == degree.size()) break;
    }
    

    while( !sorted.empty() ) {
        cout << sorted.front() << " ";
        sorted.pop();
    }
    cout << endl;
}




vector<int> getDegrees(vector<vector<string>> *graph) {
    vector<int> degree(graph->size(), 0); 
    
    for(int i = 0; i < graph->size(); i++) {
        vector<string> node = graph->at(i);
        for(int j = 1; j < node.size(); j++) {
            
            for( int k = 1; k < graph->size(); k++) {
                if( graph->at(k).at(0) == node[j] ) {
                    degree[k]++;
                }
            }
        }
    }
    return degree;
}

/*
for(auto& x:*graph) {
        if(x[0] == a) {
            for(auto y : x) {
                cout << y << " ";
                if(y == b) {
                    cout << "\ny == b\n";
                    break; // If we already have it, skip this.
                } 
            }
            find()
            cout << endl;
        }
    }
    */
    