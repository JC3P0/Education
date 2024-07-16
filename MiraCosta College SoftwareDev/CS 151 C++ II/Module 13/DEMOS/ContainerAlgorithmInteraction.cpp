/* ContainerAlgorithmInteraction.cpp - Show interaction between contains and algorithms.
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Demonstration
 * Problem statement:  Show the interaction between a vector (container) of ints and
 *    a few algorithms which can use iterators on that container.
 *
 * Algorithm:
 *   1. Create an vector of several random ints
 *   2. Use the "find" algorithm on the vector to find a specific item in the vector
 *   3. Use the "distance" algorithm to determine the index of that specific item
 *      in the vector.allocator_type
 *
 * Discussion
 *   * It is commonly said that iterators form the bridge to connect the
 *     algorithms and the containers in the STL
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;

int main() {

    // Create a dynamic vector of integers
    vector <int> int_vector = {50, 294, -12, 70, 581, 34, -420, 942, 115, 89, -105} ;

    // Display the contents of the vector
    cout << "The contents of the vector are: " << endl ;
    vector <int>::iterator iter = int_vector.begin() ;
    while (iter != int_vector.end())   {
        cout << *iter++ << "  " ;
    }

    // Find an element in the vector using the 'find' algorithm
    int target = int_vector[8] + 1 ;                   // should be 115
    vector <int>::iterator target_ptr =
              find(int_vector.begin(), int_vector.end(), target) ;

    // Check if value was found, determine offset from position found using "distance"
    if (target_ptr != int_vector.end()) {
        int index = distance(int_vector.begin(), target_ptr) ;
        cout << "\n\nValue " << *target_ptr << " found at index: " << index << endl ;
    }
    cout << endl ;

    return 0 ;
}


