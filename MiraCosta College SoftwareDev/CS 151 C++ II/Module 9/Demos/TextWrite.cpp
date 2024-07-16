/* TextWrite.cpp - Write the names and grades of three students on "Grades.txt"
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Demonstration
 * Problem statement:   Write the names (first, middle init, last) and grade of
 *    three students onto a text file.
 *
 * Algorithm:
 *   1. Open a text file named "Grades.txt" for output
 *   2. Write the first name, middle initial, last name, and score (an int) onto
 *      the file, followed by a new-line
 *   3. Close the file
 *
 * Discussion:
 *    * Three students (no complex names) written onto data file
 *    * No error checking -- yet.
 *    * ofstreams are for output only and go to a data file
 *    * Take a look at data file when done
 */

#include <iostream>
#include <fstream>
using namespace std ;

int main() {

    // Create instance of ostream and open a text file named "Grades.txt"
    ofstream output ;               // for output only, deletes any existing file
    output.open("Grades.txt") ;     // simplest form of "open" function
                                    // (could be consolidated into a single statement)

    // Write one line for each of three students onto the file
    // Data represents first name, middle initial, last name, and score (an int)
    output << "Juan" << " " << "T" << " " << "Quiros" << " " << 90 << endl ;
    output << "Eric" << " " << "K" << " " << "Smith" << " " << 75 << endl ;
    output << "Alicia" << " " << "P" << " " << "Williams" << " " << 88 << endl ;

    // Always close files when done -- especially output files
    output.close() ;
    cout << "Done" << endl ;

    return 0 ;
}

