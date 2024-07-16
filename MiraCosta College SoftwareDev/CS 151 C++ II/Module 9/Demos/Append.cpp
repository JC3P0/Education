/* Append.cpp - Open file, write cities, close, then re-open to append
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Demonstration
 * Problem statement:  Demonstrate opening a file, writing data to it,
 *    closing the file, reopening the file and appending more data to
 *    it.  Different file modes are used for opening a file:
 *
 *                     in, out, and app.
 * Algorithm:
 *   1. Create an fstream for output using a file named "City.txt" which will
 *      hold a list of city names (separated by a space)
 *   2. Open the file
 *   3. Write the names of three cities on the file
 *   4. Close the file
 *   5. Reopen the file in "append" mode
 *   6. Write the names of several more cities on the file, separated by
 *      spaces and new-lines
 *   7. Close the file
 *   8. Open the file one more time for input
 *   9. Read each file name and print on the screen
 *  10. Close the file
 *
 * Discussion:
 *    Opens in "out" mode, writes, closes, then opens again in "append" mode
 *    Uses fstream variable so can both read and write
 *    Reading data only reads words using input stream extraction operator, 
 *        not entire lines (use getline)
 *    Open "City.txt" file and note spaces and newlines
 *
 *    Credit:  Mrs. Porto?  (raised on Lanii)
 */

#include <iostream>
#include <fstream>
using namespace std ;

int main() {

    // Create an fstream object that allows reading and writing to a file
    fstream in_out ;

    // Open file for writing using the out file modifier
    in_out.open("City.txt", ios::out) ;

    // Write cities, then close the file
    in_out << "Hilo" << " " << "Kahului" << " " << "Honolulu" << " " ;
    in_out.close() ;

    // Reopen file and append data to it
    in_out.open("City.txt", ios::out | ios::app) ;

    // Write more cities
    in_out << "Lihue" << " " << "Kapaa" << " " << "Lahaina\n" ;       // all white space
    in_out << "Hana" << " " << "Hanalei" << " " << "Molokini\n" ;
    in_out << "Kona" << " " << "Waimea" << " " << "Wailua" ;
    in_out.close() ;

    char city[20]  ;

    // Open the file again for reading using the "in" file modifier
    in_out.open("City.txt", ios::in) ;
    while (!in_out.eof()) {          // Continue if not end of file
        in_out >> city ;             // Only up to next white-space character
        cout << city << " " ;
    }
    cout << endl << endl ;           // Only affects output, not in the file

    // Close all files when done
    in_out.close() ;

    return 0 ;
}

