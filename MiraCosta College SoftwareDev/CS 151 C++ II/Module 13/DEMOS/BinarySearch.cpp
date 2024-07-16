/* BinarySearch.cpp - Demonstrate searching a vector of ints using binary search
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Demonstration
 * Problem statement:  Create an array of 100,000 ints in sorted order.  Perform
 *    different binary searches for elements in (and not in) the array.
 *
 * Note:  A binary search algorithm assumes that the container to be searched is
 *        already in sorted order.  Otherwise only a linear search will find
 *        (or not find) an element in the array.
 *
 * Algorithm:
 *    1. Use the binary_search function in the STL which takes two iterators and
 *       a value (known as the "key") to look for between those two iterators: The
 *       statement:
 *
 *                binary_search(iterator1, iterator2, value)
 *
 *       will look between the "low" element at iterator1 (inclusive) and
 *       the "high" element at iterator2 (exclusive)
 *
 *       This function returns true if the "value" was found in that range,
 *       otherwise returns false.
 *
 *       The function uses the == operator to determine equality between the data
 *       element in the binary tree node and the value to be searched
 *
 *    2. In main,
 *       2a. Create a sorted vector of ints of size 100,000
 *           -- The value of the array at index "index" is just index * 2
 *       2b. Create pointers to the beginning, end, and middle of the
 *           array using iter.begin(), iter.end, and a calculation for
 *           the middle of the vector
 *       2c. Print the first 10 values of the array using square bracket
 *           notation.
 *       2d. Print the first 10 values again using an iterator and ++
 *       2e. Check if 30,000 is in the array (it should be) using a binary
 *           search from beginning to end
 *       2f. Check if 30,001 is in the array (it should not be in the array, since
 *           the array contains only even numbers) using a binary search from
 *           to end.
 *       2g. Next, find out if the number 160,000 is in the first half or the
 *           last half of the array.  (Should be in last half.)
 *
 * Discussion
 *    * the "distance" function determines number of elements between two vectors
 *    * binary searches can be performed using non-sequential access containers such
 *      as a list, but the performance will be horendous.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main() {

    const int SIZE = 100000 ;             // size of the array to be searched

    // Create an integer array of 100,000 elements with values from 2 to 200,000.
    // Note that the array will be sorted.
    int array[SIZE] ;
    for (int i = 0 ; i < SIZE ; i++) {
        array[i] = 2 * (i + 1) ;
    }

    // Put the array into a vector
    vector<int> int_vector(array, array + SIZE) ;

    // Three iterators point to beginning, middle, and end of vector
    vector<int>::iterator iter_begin, iter_middle, iter_end ;

    // Set the first iterator to point to the beginning of the vector, and
    // the second iterator to one passed the last element of the vector.
    iter_begin = int_vector.begin() ;
    iter_end = int_vector.end() ;

    // Set the middle iterator close the middle of the vector.
    int vector_size = distance(iter_begin, iter_end) ;
    iter_middle = int_vector.begin() + (vector_size / 2) - 1 ;

    cout << "There are " << vector_size << " elements in the vector." << endl << endl
         << "The begin iterator points to:   " << *iter_begin << endl
         << "The middle iterator points to:  " << *iter_middle << endl
         << "The end iterator points to:     " << *iter_end << endl
         << "  (one less points to:)         " << *(iter_end - 1) << endl << endl ;

    cout << "Here are the first 10 values in the vector using at():\n" ;
    for (int i = 0 ; i < 10 ; i++)
        cout << int_vector.at(i) << " " ;
    cout << endl << endl ;

    cout << "And here they are using an iterator:\n" ;
    for(int i = 0 ; i < 10 ; iter_begin++, i++)
        cout << *iter_begin << " " ;
    cout << endl << endl ;

    // Reset the first iterator to the beginning of the vector.
    iter_begin = int_vector.begin() ;

    // Is 30000 in the vector?
    int search_value = 30000 ;
    cout << "The value " << search_value << " is "
         << (binary_search(iter_begin, iter_end, search_value) ? "" : "not ")
         << "in the vector." << endl ;

    // Is 30001 in the vector?
    search_value = 30001 ;
    cout << "The value " << search_value << " is "
         << (binary_search(iter_begin, iter_end, search_value) ? "" : "not ")
         << "in the vector." << endl << endl ;

    // Search for a value in the first half and then in the last half of the vector
    search_value = 160000 ;
    cout << "The value " << search_value << " is "
         << (binary_search(iter_begin, iter_middle, search_value) ? "" : "not ")
         << "in the first half." << endl ;

    cout << "The value " << search_value << " is "
         << (binary_search(iter_middle, iter_end, search_value) ? "" : "not ")
         << "in the last half." << endl ;

    cout << endl ;

    return 0 ;
}

