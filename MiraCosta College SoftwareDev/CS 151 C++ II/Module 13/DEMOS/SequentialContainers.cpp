/* SequentialContainers.cpp - Demonstrate the types of containers classified as "sequential"
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Demonstration
 * Problem statement:  Sequential contains in the STL are vector, list, and deque.
 *
 * Algorithm:
 *   1. Create a generic function which takes a container of type vector, list
 *      of deque
 *      1a. Use an iterator to cycle through the contents of the container,
 *          printing the results on the console
 *   2. In main,
 *      2a. Create two vector of ints
 *      2b. Push 1, then 2 onto the first vector
 *      2c. Push 30 onto the back of the second vector
 *      2d. Call the function created in step 1 above to print the contents of the
 *          two vectors
 *      2e. Swap the two vectors using the "swap" function
 *      2f. Print the contents of the two vectors again
 *
 *      2g. Create two lists of ints
 *      2h. Do the same thing as 2b through 2f above
 *
 *      2i. Create a deque of ints
 *      2j. Using a sequence of push_back and push_front calls, create the deque
 *          contents so the sequence is 1, 2, 3, 4, and 5
 *      2k. Print the contents of the deque
 *
 * Discussion:
 *    * Notice the user of a template to print the contents of all three containers
 *      - The data type should support the begin(), end(), and size() functions,
 *        and the ++ operator
 */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std ;

// Template to print the contents of a container (vector, list, or deque)
// Note:  lists do not support [ ] notation, so must use an iterator
template <typename T>
    void print(T container, string heading) {
        cout << heading << ": " ;
        auto iter = container.begin() ;
        while (iter != container.end()) {
           cout << *iter++ << "  " ;
        }
        cout << "(size: " << container.size() << ")" << endl ;
    }

int main() {

    // Create various sequential containers
    vector<int> vector1, vector2 ;
    list<int> list1, list2 ;
    deque<int> deque ;

    cout << "Using vectors: " << endl ;
    vector1.push_back(1) ;   // append element to the vector
    vector1.push_back(2) ;
    vector2.push_back(30) ;
    // Size of vector - how many elements
    print (vector1, "vector1") ;
    print (vector2, "vector2") ;
    cout << "after swap..." << endl ;
    swap(vector1, vector2) ;
    print (vector1, "vector1") ;
    print (vector2, "vector2") ;

    // Do the exact same thing except with a list
    cout << "\nUsing lists: " << endl ;
    list1.push_back(1) ;   // append element to the vector
    list1.push_back(2) ;
    list2.push_back(30) ;
    // Size of vector - how many elements
    print (list1, "list1") ;
    print (list2, "list2") ;
    cout << "after swap..." << endl ;
    swap(list1, list2) ;
    print (list1, "vector1") ;
    print (list2, "vector2") ;

    cout << "\nUsing a deque: " << endl ;
    deque.push_back(3) ;      // can add to either back or front
    deque.push_front(2) ;
    deque.push_front(1) ;
    deque.push_back(4) ;
    deque.push_back(5) ;
    cout << "maximum size of deque: " << deque.max_size() << endl ;
    print(deque, "contents of deque") ;

    cout << endl << endl ;

    return 0 ;
}

