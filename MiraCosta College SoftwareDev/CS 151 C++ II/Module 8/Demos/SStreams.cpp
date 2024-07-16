/* SStreams.cpp - Use sstreams to convert numbers to hex / binary
 * Author:     Chris Merrill
 * Module:     8
 * Project:    Exercise #1
 * Problem statement:  Use an istringstream to convert numbers from
 *   strings to internal formats.  Use a stringstream to convert
 *   a number to hex and back to decimal
 *
 * Discussion:
 *    * Must include sstream
 *    * Objects of class stringstream can do both input and output
 *    * IO manipulators dec, hex, and oct, but sadly no binary
 */

#include <iostream>
#include <sstream>
using namespace std ;

int main() {

    // Load a string with two numbers into an istringstream string, then
    // extract the two numbers and assign to variables
    istringstream in("400 99.99") ;              // constructor
    int first_number ;
    double second_number ;
    in >> first_number >> second_number ;
    cout << "The first number is: " << first_number << endl
         << "The second number is: " << second_number << endl << endl ;

    // Use the hex manipulator to convert a number to a hex string, then
    // back to the original number
    stringstream iostream ;                // both input << and output >>
    int original = 123456, back_again ;
    iostream << hex << original ;
    cout << "The hex form of " << original << " is "
         << iostream.str() << endl ;
    iostream >> hex >> back_again ;
    cout << "Back to its internal form: " << back_again << endl ;

    return 0 ;
}
