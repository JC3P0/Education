/* BinarySearchRecursive.cpp - Demonstrate two examples of a binary search of numbers
 * Author:     Chris Merrill
 * Module:     11
 * Project:    Demonstration
 * Problem Statement: Create an array of 1000 numbers in sorted order.  Search
 *     specifically for element 477, then search for an element not in the array.
 *
 * Algorithm:
 *   1. Create an array of 1,000 numbers
 *   2. Print element #378, then search for it
 *      2a. Determine how many levels it took by using a static variable
 *   3. Search for a number that is greater than the 1000th entry
 *   4. Use the Binary search function from the textbook
 *
 * Discussion Points:
 *   *  What if we look for element #499 (the midpoint)?
 *   *  How about #249 (the quarter-point)?
 *   *  How about #0 (the lowest number in the array)
 *   *  What if we change the search to look at 1,000,000 numbers? 100,000,000?
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

/************************************************************************
* "search" algorithm taken from textbook.  Parameters include:
*       1) An array of doubles to be searched
*       2) the key (value) to search for
*       3) the lowest index to search
*       4) the highest index to search
*
* Returns the index (if the key is found) or -1 if the key is not found
************************************************************************/
int search(double *search_array, double key, int low, int high) {

    // Have we exhausted the search?  If so, we're done
    if (low > high)
        return -1 ;

    // Increment the number of times we've called this function
    levels++ ;

    // Find the midpoint of low and high.  See if that's it
    int mid = (low + high) / 2 ;
    if (search_array[mid] == key) {
       return mid ;
    }

    // Didn't find it, so see which half the the array to search next
    if (key < search_array[mid]) {
        return search(search_array, key, low, mid - 1) ;
    }
    return search(search_array, key, mid + 1, high) ;
}

