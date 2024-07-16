/* TextRead.cpp - Read the data file containing grades created from TextWrite.cpp
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Demonstration
 * Problem statement:  Read the data just created by TextWrite using an ifstream
 *   class object
 *
 * Algorithm:
 *   1. Open the Grades.txt file to an fstream variable (not binary)
 *   2. Create several variable representing the data in the file
 *      2a. first_name - a 80-character array
 *      2b. middle_initial - a 1-char variable
 *      2c. last_name - a 80-character array
 *      2d. score - an int
 *   3. Using stream extraction, read each of the four variables for each
 *      of the three people
 *      3a. Recall that the stream extraction operator stops when it hits
 *          white space (or the end of the stream)
 *      3b. close the file
 *
 * Discussion:
 *    Remember than cin uses whitespace as a delimiter
 *    What happens if the file is missing?
 *    We needed to know how many people were in the file to create this program
 *    What happens if a person has a double first name, such as Joe Bob or
 *        Juan Maria?
 */

#include <iostream>
#include <fstream>
using namespace std ;

int main() {

    // Create an instance of class ifstream and open to Grades.txt
    ifstream input ;                        // only usable to read from files
    input.open("Grades.txt") ;              // could be consolidated with line above

    // Create variables to store data read in
    char first_name[80] ;
    char middle_initial ;
    char last_name[80] ;
    int score ;

    // Display data of the three students
    input >> first_name >> middle_initial >> last_name >> score ;
    cout << first_name << " " << middle_initial << " " << last_name << " "
         << score << endl ;

    input >> first_name >> middle_initial >> last_name >> score ;
    cout << first_name << " " << middle_initial << " " << last_name << " "
         << score << endl ;

    input >> first_name >> middle_initial >> last_name >> score ;
    cout << first_name << " " << middle_initial << " " << last_name << " "
         << score << endl << endl ;

    input.close() ;
    cout << "Done reading" << endl ;

    return 0 ;
}
