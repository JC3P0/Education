/* DequeDemo.cpp - Demonstrate some of the functions in the Deque class.
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Demonstration
 * Problem statement:  Demonstrate how to use some of the functions in
 *    the deque class from the STL.
 *
 * Algorithm:
 *   1. Create a deque of ints with elements 1, 2, 3, 4, 5, 6, and 7 (and print)
 *   2. Re-assign to a deque of 4 values of 99 (and print)
 *   3. Use the 'at' function to change a value (and print...)
 *   4. Use an iterator to insert values in the deque
 *   5. Use an iterator to remove values between two indices
 *   6. Clear the deque
 *   7. Use the push_front and push_back functions to add values to the deque
 *   8. Use the pop_front and pop_back functions to remove values from the deque
 *
 * Discussion:
 *   - A deque's capabilities are a combination of a queue and a stack
 *   - It is typically implemented as list of small vectors, hopefully
 *     resulting in the best of both worlds during updates.
 */

#include <iostream>
#include <deque>
using namespace std ;

int main() {

    // Create an array of integer values from 1 - 7 in sorted order
    int values[] = {1, 2, 3, 4, 5, 6, 7} ;
    deque<int> int_deque(values, values + 7) ;

    cout << "Initial contents of \"int_deque\":                    " ;
    for (int i = 0 ; i < int_deque.size() ; i++)
        cout << int_deque[i] << " " ;

    // Assign the deque to four values of 99 (clear the existing deque values)
    int_deque.assign(4, 99) ;
    cout << "\nAfter re-assigning to 4 elements of value 99:       " ;
    for (int i = 0 ; i < int_deque.size() ; i++)
        cout << int_deque[i] << " " ;

    // Change the first value (index = 0) to 22
    int_deque.at(0) = 22 ;
    cout << "\nAfter using \"at\" function to set element 0 to 22:   " ;
    for (int i = 0 ; i < int_deque.size() ; i++)
        cout << int_deque[i] << " " ;

    // Use an iterator to insert 33 at position 1, then 44 at position 1
    deque<int>::iterator itr = int_deque.begin() ;
    int_deque.insert(itr + 1, 33) ;
    int_deque.insert(itr + 1, 44) ;
    cout << "\nAfter the insert function at position 1 twice:      " ;
    for (int i = 0 ; i < int_deque.size() ; i++)
        cout << int_deque[i] << " " ;

    // Use an iterator again to delete the values at position 2 and 3
    itr = int_deque.begin() ;
    int_deque.erase(itr + 2, itr + 4) ;
    cout << "\nAfter the erasing at positions + 2 & 3:             " ;
    for (int i = 0 ; i < int_deque.size() ; i++)
        cout << int_deque[i] << " " ;

    // Clear the deque
    int_deque.clear() ;
    cout << "\nAfter the clear function, int_deque:                " ;
    cout << "Size is " << int_deque.size() << endl ;
    cout << "Is empty? "
         << (int_deque.empty() ? "true" : "false") ;

    // Push 20 at the front, 30 at the end, and 10 at the front
    int_deque.push_front(20) ;
    int_deque.push_back(30) ;
    int_deque.push_front(10) ;
    cout << "\nAfter insertions at front, back, and front:         " ;
    for (int i = 0 ; i < int_deque.size() ; i++)
        cout << int_deque[i] << " " ;

    // Pop off the front element, then the last element
    int_deque.pop_front() ;
    int_deque.pop_back() ;
    cout << "\nAfter popping at front and back:                    " ;
    for (int i = 0 ; i < int_deque.size() ; i++)
        cout << int_deque[i] << " " ;

    cout << endl << endl ;

    return 0 ;
}
