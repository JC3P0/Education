/* TailLister1.cpp - Print the last 10 lines of a text file using sequential reads and a vector
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Exercise #1, Solution #1
 * Problem Statement: List the last 10 lines in a text file using a sequence of reads.  Keep the
 *    last 10 lines in a vector of strings.
 *
 * Algorithm:
 *    1. Prompt for the name of a text file.  (Loop until a valid file is found)
 *    2. Open the file for sequential text input
 *    3. Create a vector of 10 strings
 *    4. Start reading the file
 *       4.1.  Put the next line read at the end of the vector
 *       4.2   If the size of the vector is greater than 10, then delete the first element
 *    5. When all done, print the lines in order in the vector
 *
 * Discussion items:
 *   *  Looping until a valid file name is entered
 *      - Exiting loop of 'Q' or 'q' is entered
 *      - Clearing the error bit if file doesn't exist
 *   *  Using a vector of strings
 *   *
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std ;

int main() {
    char file_name[80] ;                 // C-string for name of file entered by user
    ifstream input_stream ;              // input text file stream

    // Get file name from user and open.  If user enters "Q", then quit the program.
    while (true) {
        cout << "Enter name of text file to scan ('q' to quit): " ;
        cin >> file_name ;
        if ((strcmp(file_name, "Q") == 0) || (strcmp(file_name, "q") == 0)) {
            return 0 ;
        }
        input_stream.open(file_name, ios::in) ;
        if (input_stream) {
            break ;                     // valid file entered
        }
        cout << "Can't find that file" << endl << endl ;
        input_stream.clear() ;          // clear open error
    } // end while

    // Create an array of strings (only keep the last 10 in the file being read)
    vector<string> lines ;

    //Read in lines.  Delete anything over line 10
    string line_of_text ;
    while (getline(input_stream, line_of_text)) {
        lines.push_back(line_of_text) ;
        if (lines.size() > 10) {
            lines.erase(lines.begin()) ;
        }
    }

    // Display (up to) 10 lines of the file
    cout << "The last 10 lines of " << file_name << endl ;
    for (int i = 0 ; i < lines.size() ; i++) {
        cout << (i + 1) << "  " << lines[i] << endl ;
    }

    // Are there less than 10 lines in the file?
    if (lines.size() < 10) {
        cout << "(There are less than 10 lines in the file)" << endl ;
    }

    // Always close
    input_stream.close() ;
    return 0 ;
}
