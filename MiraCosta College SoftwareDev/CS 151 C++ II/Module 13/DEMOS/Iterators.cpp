/* Iterators.cpp - Start at the end and finish at the front
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Demonstration
 * Problem statement:  Create a vector of several numbers, then demonstrate
 *    * Using a forward iterator (++)
 *    * Using a reverse iterator (++)
 *    * Using a bidirectional iterator (++ and --)
 *    * An index iterator [ ]
 *    * Offset from the beginning (begin() + x)
 *    * Assign values using an iterator
 *
 * Discussion:
 *   * Use of "reverse_iterator" type instead of "iterator"
 *     - uses rbegin() and rend() with ++
 *   * Bi-directional iterator uses ++ and --
 *   * Using an index on an iterator [ ] and an offset from begin()
 *   * Assigning values using iterators (add one to existing values)
 */

#include <iostream>
#include <vector>
using namespace std ;

int main() {

    // Create a vector of 10 ints 10, 20, 30...
    vector<int> int_vector ;
    for (int i = 10 ; i <= 100 ; i += 10)
        int_vector.push_back(i) ;

    // Use a "forward" iterator and print the results
    cout << "Using a forward iterator (++)" << endl ;
    vector<int>::iterator forward = int_vector.begin() ;
    while (forward != int_vector.end())
        cout << *forward++ << " " ;

    // Use a "reverse" iterator and print
    cout << "\n\nUsing a reverse iterator (++)" << endl ;
    vector<int>::reverse_iterator reverse = int_vector.rbegin() ;
    while (reverse != int_vector.rend())
        cout << *reverse++ << " " ;             // Use ++ to go backwards

    // Using a bi-directional iterator
    cout << "\n\nUsing a bi-directional iterator (++ and --)" << endl ;
    vector<int>::iterator both_ways = int_vector.begin() ;
    cout << "Forward:   " ;
    while (both_ways != int_vector.end())
        cout << *both_ways++ << " " ;

    cout << "\nBackward:  " ;
    do {
        cout << *--both_ways << " " ;
    } while (both_ways != int_vector.begin()) ;

    cout << "\n\nIndexed [ ] " ;
    for (int i = 0 ; i < int_vector.size() ; i += 2)
        cout << both_ways[i] << " " ;

    cout << "\nOffset  (begin() + x):  " ;
    for (int i = 0 ; i < int_vector.size() ; i += 2)
        cout << *(int_vector.begin() + i) << " " ;

    cout << "\n\nAssigning values using iterators (add 1): " ;
    both_ways = int_vector.begin() ;
    while (both_ways != int_vector.end()) {
        *both_ways += 1 ;
        cout << *both_ways++ << " " ;
    }

    cout << endl  ;

    return 0 ;
}
