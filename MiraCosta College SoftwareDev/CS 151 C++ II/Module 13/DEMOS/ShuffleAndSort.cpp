/* ShuffleAndSort.cpp - Demonstrate the two algorithms from STL
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Demonstration
 * Problem statement:  Using a vector of squares in a vector, perform a
 *    random shuffle, print, then sort and print
 *
 * Algorithm:
 *    1. Create a generic function which takes a beginning iterator, and ending
 *       iterator, and a string for a heading.  Print the heading followed by the
 *       contents of the structure identified by the beginning and ending iterators
 *       -- Use a RandomAccessIterator type for the two iterators.
 *       -- This will accept any bi-directional iterator
 *    2. In main, create a vector of ints
 *    3. Populate the array with the first 15 squares (1, 4, 9, 25, 36...)
 *    4. Print the contents of the vector using the function created in step 1
 *    5. Use the "shuffle" function (in algorithms) to shuffle the contents of
 *       the vector.
 *    6. Print the contents of the vector again (hopefully it's all scrambled)
 *    7. Use the "sort" function (in algorithms) to put the array back in
 *       sorted order
 *    8. Print the contents of the vector one last time (it should be sorted)
 *
 * Discussion:
 *   - Both the shuffle and sort algorithms take a beginning and an ending iterator
 *     in a data structure.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

// function to print the contents of a vector (iterator must be bi-directional)
template <class RandomAccessIterator>
    void print(RandomAccessIterator start, RandomAccessIterator stop, string heading) {

        cout << heading << ": " ;

        int size = (stop - start) ;                     // number of elements to traverse
        while (start != stop) {
            cout << *(start++) << "  " ;
        }
        cout << "(size: " << size << ")" << endl ;
    }

int main() {

    // Create a vector with the squares of the first 15 numbers and print
    vector<int> vec ;
    for (int k = 1 ; k <= 15 ; k++) {
        vec.push_back(k * k) ;
    }
    print(vec.begin(), vec.end(), "Initial vector: ") ;

    // Shuffle the vector and print
    random_shuffle(vec.begin(), vec.end()) ;
    print(vec.begin(), vec.end(), "\nShuffled:       ") ;

    // Sort and print
    sort(vec.begin(), vec.end()) ;
    print(vec.begin(), vec.end(), "\nSorted:         ") ;

    cout << endl ;

    return 0 ;
}



