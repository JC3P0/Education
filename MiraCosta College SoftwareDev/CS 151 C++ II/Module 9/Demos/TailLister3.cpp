/* TailLister3.cpp - Read and display the last 10 lines in a text file
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Exercise #2, Solution 3
 * Problem Statement:  Display the last 10 lines in a text file.  If the
 *     file has less than 10 lines, the whole file is displayed with a
 *     message saying that the entire file was displayed.  The program
 *     should seek to the end of the file, then move back 10 lines (or less).
 *
 * Algorithm:
 *    1.  Prompt for the name of a file to open.  If it doesn't exist,
 *        give an error message and re-prompt.
 *    2.  Seek to the end of the file.
 *    3.  Scan backwards until 10 '\n' characters are counted or else the
 *        beginning of the file is hit.
 *    4.  Read in each line from current position and print on the screen.
 *    5.  If less than 10 were counted before the beginning of the file is
 *        reached, then print a message that there are less than 10 lines
 *        in the file.
 *    6.  Close all files.
 *
 * Discussion:
 *    * Opening the file as a binary file
 *    * Counting \n characters
 *    * Using seekg to go backwards and forward one character from current position
 */

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std ;

int main()  {

    char file_name[80] ;                  // C-string for name of file entered by user
    ifstream input_stream ;               // input text file stream

    // Get file name from user and open.  If user enters "Q", then quit the program.
    while (true) {
        cout << "Enter name of text file to scan ('q' to quit): " ;
        cin >> file_name ;
        if ((strcmp(file_name, "Q") == 0) || (strcmp(file_name, "q") == 0)) {
            return 0 ;
        }
        input_stream.open(file_name, ios::binary) ;
        if (input_stream ) {
            break ;                  // valid file entered
        }
        cout << "Can't find that file" << endl << endl ;
        input_stream.clear() ;      // clear open error
    } // end while

    // Seek to the end of the file, then back up 10 lines (or less if
    // the beginning of the file is reached.
    //
    // Determine the position of the beginning of the file using the
    // long long variable pos_beg.  Determine last position of the
    // last character in the file and put into pos_end.
    input_stream.seekg(0L, ios::beg) ;                 // first character in the file
    long long pos_beg = input_stream.tellg() ;
    input_stream.seekg(-1L, ios::end) ;                // last character in the file
    long long pos_end = input_stream.tellg() ;

    // If the last character is '\n' (which it should be), then
    // backup over that character.
    char ch = input_stream.peek() ;
    if (ch == '\n') {
        input_stream.seekg(-1L, ios::cur) ;
    }

    // Loop until we're back at the beginning of the file, or we've hit
    // the 10th '\n' character
    int line_count = 0 ;
    while (input_stream.tellg() > pos_beg && line_count < 10) {
        ch = input_stream.peek() ;
        if (ch == '\n') {
            line_count++ ;                             // end of a line
        }
        if (line_count < 10) {
            input_stream.seekg(-1L, ios::cur) ;        // back up one char
        }
    }

    // If NOT at beginning of the file, then move back over the last
    // '\n' character that was scanned.
    if (input_stream.tellg() > pos_beg) {
        input_stream.seekg(1L, ios::cur) ;
    }

    // Print out everything to end of file.  Since we're processing
    // a binary file, build strings character-by-character.
     cout << endl << "Last 10 lines of " << file_name << endl ;

    input_stream.clear() ;                    // clear any issues with input stream
    string line_of_text = "" ;                // next line from file
    line_count = 0 ;                          // lines printed
    while (input_stream.tellg() <= pos_end) {
        ch = input_stream.get() ;
        if (ch == '\n') {
            cout << ++line_count << " " << line_of_text << endl ;
            line_of_text = "" ;
        } else {
            line_of_text += ch ;
        }
    }

    // If the last line in the file didn't end with an '\n', then
    // print the last line of the file
    if (line_of_text != "") {
        cout << ++line_count << " " << line_of_text << endl ;
    }

    // If 10 lines weren't printed, then print a message that the
    // entire file was printed.
    if (line_count < 10) {
        cout << "(There are less than 10 lines in the entire file.)" << endl ;
    }

    // Always, always, always
    input_stream.close() ;
    return 0 ;
}

