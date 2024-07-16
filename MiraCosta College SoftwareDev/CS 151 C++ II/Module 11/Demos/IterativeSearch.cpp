/* IterativeSearch.cpp - Convert BinarySearch.cpp to an iterative solution
 * Author:     Chris Merrill
 * Module:     11
 * Project:    Demonstration
 * Problem Statement: Change the search function in BinarySearch to use
 *    a while-loop instead of using recursion
 *
 * Algorithm:
 *    1. Start with the recursive version
 *    2. Since the recursive solution uses tail recursion, it's easy to
 *       convert to a loop
 *       2a. Create a loop which stops with high < low (the stopping case
 *           in the recursive version)
 *           -- If the loop ends, then return -1 (key not found)
 *       2b. Otherwise reset either high or low, then continue the loop
 *       2c. If the key is found at the top of each loop, then just return
 *           the index of the array
 *    3. No changes required to main.
 */

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std ;

// prototype
int search(double[], double, int, int) ;

const int SIZE_OF_ARRAY = 1000,      // size of array of doubles to search
          ELEMENT_TO_FIND = 378 ;    // element in array to use as search item
int levels = 0 ;                     // number of recursive calls counted

int main() {

    // Create an array of random numbers in sorted order
    srand(time(NULL)) ;                           // new seed for rand()
    double *array = new double[SIZE_OF_ARRAY] ;
    double dmax = RAND_MAX ;
    for (int i = 1 ; i < SIZE_OF_ARRAY ; i++) {
        array[i] = array[i - 1] + (rand() / dmax) ;
    }

    cout << fixed << "Low element: " << array[0]
         << "  High: " << array[SIZE_OF_ARRAY - 1]
         << "  Size: " << SIZE_OF_ARRAY << endl
         << "Ready to start searching <press ENTER>... " ;
    cin.get() ;

    // Using the binary search function, find a specific element in the array
    levels = 0 ;                                 // number of recursive levels
    double searchKey = array[ELEMENT_TO_FIND] ;  // value to search for
    int found ;                                  // return value from searching function

    cout << endl << "Looking for " << searchKey << endl ;
    if ((found = search(array, searchKey, 0, SIZE_OF_ARRAY - 1)) == -1) {
        cout << "Didn't find" ;
    } else {
        cout << "Found at index " << found ;
        }
    cout << " in " << levels << " recursive calls" << endl << endl ;

    // Now try to find a value that isn't in the array
    levels = 0 ;
    searchKey = array[SIZE_OF_ARRAY - 1] + 1.0 ;
    cout << "Looking for " << searchKey << endl ; ;
    if ((found = search(array, searchKey, 0, SIZE_OF_ARRAY - 1)) == -1) {
        cout << "Didn't find" ;
    } else {
        cout << "Found at index " << found ;
        }
    cout << " in " << levels << " recursive calls" ;
}

// Function converted to an iterative solution rather than recursive
int search(double *search_array, double key, int low, int high) {

    // Changed to "while" loop
    while (low <= high) {

        levels++ ;

        int mid = (low + high) / 2 ;
        if (search_array[mid] == key) {
           return mid ;
        }

        // Just reset either high or low, rather than calling function again
        if (key < search_array[mid]) {
            high = mid - 1 ;
        } else {
            low = mid + 1 ;
        }
    }

    // Didn't find the search key (moved this code to the bottom of the loop)
    return -1 ;

}



