/* TextReadWithErrors.cpp - Add error checking to the TextRead.cpp program
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Demonstration
 * Problem statement:  Demonstrate testing to see if a file exists by using
 *    the fail() function. It also invokes the eof() function on the input
 *    object to determine the end of the file while reading.
 *
 * Algorithm:
 *   1. Start with the TextRead program
 *   2. Add error checking to make sure that the "Grades.txt" file was
 *      opened successfully
 *   3. Using stream extraction, read each of the four variables until
 *      the end-of-file is reached
 *      3a. Recall that the stream extraction operator stops when it hits
 *          white space (or the end of the stream)
 *   4. When done with the file, close it
 *
 * Discussion:
 *    - inputfile.open() is false if the file doesn't exist for input
 *          -- can also test if inputfile is null
 *          -- change file name to something else and run
 *    - inputfile.open() is false if C++ can't open the file for output
 *    - loop tests for eof while trying to read data
 *    - must be aware of how data is stored:
 *         - change data type of the "score" variable below and see what happens
 */

#include <iostream>
#include <fstream>
using namespace std ;

int main() {

    // Create an ifstream object
    ifstream input("Grades.txt") ;

    // If the file doesn't exist, then print an error message and stop
    // Note:  Can also test if input == null or !input
    // if (!input) {
    if (input.fail()) {
        cout << "File does not exist -- aborting program" << endl ;
        exit(1) ;
    }

    // Use a loop to read data from file. The loop will terminate
    // when the input reaches the end of the file. The eof() returns
    // true when there is no more data in the file.
    // To read data from a file correctly, you must know exactly how
    // the data is stored. See what happens if an int is indicated as
    // a char below.

    char first_name[80] ;
    char middle_initial ;
    char last_name[80] ;
    int score ;
    // char score ;  // uncomment char and comment int score - see what happens!

    while (true) {                    // Continue if not end of file
        input >> first_name >> middle_initial >> last_name >> score ;
        if (input.eof()) {
            break ;
        }
        cout << first_name << " " << middle_initial << " " << last_name
             << " " << score << endl ;
    }

    input.close() ;
    cout << "\nDone" << endl ;

    return 0 ;
}

