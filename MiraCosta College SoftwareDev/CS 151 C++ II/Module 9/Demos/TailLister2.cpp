/* TailLister2.cpp - Same as TestLister1.cpp, except use a vector of pointer into the data file
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Exercise #2, Solution 2
 * Problem Statement: List the last 10 lines in a text file using a sequence of reads.  Keep the
 *    last 10 lines in a vector of strings.
 *
 * Algorithm:
 *    1. Prompt for the name of a text file.  (Loop until a valid file is found)
 *    2. Open the file for sequential text input
 *    3. Create a vector of 10 long longs (points into the data file)
 *    4. Start reading the file
 *       4.1.  Get the address of the line about to be read.
 *       4.2   Read the next line
 *       4.3   Add the pointer to the vector of longs longs
 *       4.2   If the size of the vector is greater than 10, then delete the first element
 *    5. When all done, print the lines in order in the vector
 *       5.1   Use the seekg() function to position the pointer before reading each line
 *
 * Discussion items:
 *   *  Use of the seekg function
 *   *  Much more efficient than passing hundreds or thousands or strings through a vector,
 *      only to delete most of them
 *   *  Don't forget to clear flags before reading second through.
 *   *  A even more efficient way of performing this might be to read every byte in the
 *      file and only recording the occurrent of eacn '\n' char.
 *
 * Note:
 *    - Had to make this a "binary" file because of flaky implementation of seekg in
 *      non-binary file!
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
        input_stream.open(file_name, ios::in | ios::binary) ;
        if (input_stream) {
            break ;                     // valid file entered
        }
        cout << "Can't find that file" << endl << endl ;
        input_stream.clear() ;          // clear open error
    } // end while

    // Create an array of longs (positions in the file).  Only keep the last 10 in the file being read.
    vector<long long> positions ;

    //Read in lines.  Delete anything over line 10
    string line_of_text ;
    while (true) {
        long long position = input_stream.tellg() ;
        if (!getline(input_stream, line_of_text)) {
            break ;
        }
        positions.push_back(position) ;
        if (positions.size() > 10) {
            positions.erase(positions.begin()) ;
        }
    }

    // Display (up to) 10 lines of the file
    input_stream.clear() ;                      // Clear any eof flags
    cout << "The last 10 lines of " << file_name << endl ;
    for (int i = 0 ; i < positions.size() ; i++) {
        input_stream.seekg(positions[i], ios::beg) ;
        getline(input_stream, line_of_text) ;
        cout << (i + 1) << "  " << line_of_text << endl ;
    }

    // Are there less than 10 lines in the file?
    if (positions.size() < 10) {
        cout << "(There are less than 10 lines in the file)" << endl ;
    }

    // Always close
    input_stream.close() ;
    return 0 ;
}
