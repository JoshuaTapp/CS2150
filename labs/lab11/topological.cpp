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
#include <algorithm>

using namespace std;


int main(int argc, char **argv) {
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
        cout << a << " --- " << b << endl;
    }
        
    ifs.close();


}

