/* BinaryIO.cpp - Demonstrate writing and reading an array of double values.
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Demonstration
 * Problem Statement:  Create an array of doubles.  Write then onto a file named "array.dat",
 *     close the file, then read the numbers into another array of the same size and print
 *
 * Algorithm:
 *   1. Create an array of 5 or 6 doubles in unsorted order
 *      1a.  Set the size of the array to an int named "elements"
 *   2. Open an fstream object named "binaroio" for output and for binary
 *      (using the ios::out and ios::binary tags) to a file named "array.dat"
 *   3. Write the contents of the array onto a file using a loop
 *      3a. Use the "reinperpret_cast" statement to cast to an array of chars
 *   4. Close the file
 *   5. Create a new array of the same size as the array above in step 1
 *   6. Open the fstream object again for input and for binary
 *      (using the ios::in and ios::binary tags) to the same file.
 *   6. Use the read function to read in the entire array
 *      6a. Aain recast the new array as an array of chars with the actual
 *          byte count for its size
 *   7. Close the file
 *   8. Display the contents of the new array using a loop
 *      8a. This array should be identical to the array created in step 1 above
 *
 * Discussion:
 *   * fstream binaryio is opened once for input and once for output
 *   * reinterpret_cast conversion used twice in this program
 *     - first param for both read and write is the ** address ** of variable to read or write
 *     - second param for both is the number of bytes to read or write
 *     - the reinterpret_cast essentially tells C++ to interpret the data as a
 *       series of bytes (the size of the array in bytes)
 *     - the size of the array (in bytes) should be 8 times the size of number
 *       of doubles in the array
 */

#include <iostream>
#include <fstream>
using namespace std ;

int main() {

    const string file_name = "array.dat" ;                  // data file name
    double array[] = {3.4, 12.9, -4.1, 5.6, 11.3 -0, 28} ;  // original array of doubles
    int elements = sizeof(array) / sizeof(double) ;
    cout << "Original array contents: " ;
    for (int i = 0 ; i < elements ; i++) {
        cout << array[i] << "  " ;
    }
    cout << endl ;

    // Create a file stream object
    fstream binaryio ;            // for both input and output, but not at the same time

    // Write the array to the file
    binaryio.open(file_name, ios::out | ios::binary) ;
    if (!binaryio) {
        cout << "Cannot open " << file_name << " for output -- aborting..." << endl ;
        exit(1) ;
    }
    binaryio.write(reinterpret_cast <char *>(&array), sizeof(array)) ;
    binaryio.close() ;

    // Read array from the file into a new array of the same size as original
    double result[elements] ;
    binaryio.open(file_name, ios::in | ios::binary) ;
    if (!binaryio) {
        cout << "Cannot open " << file_name << " for input -- aborting..." << endl ;
        exit(1) ;
    }
    binaryio.read(reinterpret_cast <char *>(&result), sizeof(result)) ;
    binaryio.close() ;

    // Display the contents of the new array
    cout << "New array contents:      " ;
    for (int i = 0 ; i < elements ; i++) {
        cout << result[i] << "  " ;
    }
    cout << endl ;

    return 0 ;
}

