#include <iostream>
#include <fstream>
#include <queue>
#include "timer.h"
#include "hashTable.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len, int numRows, int numCols);
vector<string> print_output;
timer stop_watch;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "error: not enough args" << endl;
        return 1;
    }
    ios_base::sync_with_stdio(false); // speeds up c++ iostream - https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    cin.tie(NULL);

    string dictionary_file_name = argv[1];
    string grid_file_name = argv[2];
    int rows, cols;
    hashTable* dictionary = new hashTable();
    int max_word_size_found = 0;

    if(readInGrid(grid_file_name, rows , cols)){
        fstream dictionary_file(dictionary_file_name, fstream::in);
        string input;
        while(dictionary_file.good()) {
            getline(dictionary_file, input);
            if(input.length() > 2) {
                if(input.length() > max_word_size_found) max_word_size_found = input.length();
                dictionary->insert(input);
            }
        }
    }

    /**     
    **  Ran test of insert valid words from words.txt into two DS that will be the bones of my hashtable    **
    * Speed of vector vs static array
    *   static array with 25k string size indexes. Time: 0.0054762s
    *   vector<string> with no reserve. Time: 0.0064891s
    *   vector<string> with 32k reserve Time: 0.00654765s
    *       Conclusion: will be using vector<string> with reserve(table_size)
    *       as DS for hashTable. compiler/ is doing such a good job of optimizing
    *       the resizing, I see no need to go through the trouble of static array
    *       implementation. I guess this is why we test vs. assuming theoretical results.
    **/
    // cout << dictionary->size() << endl; // Got 24984 valid words in words.txt and 1525 valid words in words2.txt

    int words_found = 0;
    string direction;
    queue<string> output; // using queue DS to speed up output of text, because cout is slow.


    stop_watch.start();

    for(int current_row = 0; current_row < rows; current_row++) {
        for(int current_col = 0; current_col < cols; current_col++) {
            for(int current_dir = 0; current_dir < 8; current_dir++) {
                for(int word_length = 3; word_length < 23; word_length++) {
                    string current_word = getWordInGrid(current_row, current_col, current_dir, word_length, rows, cols);
                    if(current_word.length() != word_length || current_word.length() > max_word_size_found ) break; // saves time for the dictionaries that do not have 22 length words.
                    
                    if(dictionary->count(current_word) > 0) {
                        words_found++;
                        string found_word = getWordInGrid(current_row, current_col, current_dir, word_length, rows, cols);
                            // This switch statement was used from Aaron Bloomfield's getWordInGrid                        
                            // This will return the proper direction for the console output
                            switch (current_dir) { 
                                        case 0:
                                            direction = "N ";
                                            break; // north
                                        case 1:
                                            direction = "NE";
                                            break; // north-east
                                        case 2:
                                            direction = "E ";
                                            break; // east
                                        case 3:
                                            direction = "SE";
                                            break; // south-east
                                        case 4:
                                            direction = "S ";
                                            break; // south
                                        case 5:
                                            direction = "SW";
                                            break; // south-west
                                        case 6:
                                            direction = "W ";
                                            break; // west
                                        case 7:
                                            direction = "NW";
                                            break; // north-west
                            }
                            output.push(direction);
                            output.push("(");
                            output.push(to_string(current_row)); 
                            output.push(", "); 
                            output.push(to_string(current_col)); 
                            output.push("): \t");
                            output.push(found_word); 
                            output.push("\n");
                        }
                    }
                }
            }
        }
    
    stop_watch.stop();
    
    // print out all the strings from queue.
    while(!output.empty()) {
        cout << output.front();
        output.pop();
    }
    
    cout << words_found << " words found" << endl;
    cout <<  (int)(stop_watch.getTime()*1000) << endl;
    return 0;
}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}