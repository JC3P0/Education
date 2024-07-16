/* STLList.cpp - Demonstrate several functions on lists
 * Author:     Chris Merrill
 * Module:     14
 * Project:    Demonstration
 * Problem statement:  Using several of the functions available on STL list,
 *     demonstrate how an STL list works similarly (but identical to) a vector
 *
 * Algorithm:
 *    1. Create a generic function named "show" which lists the contents of a
 *       list
 *       -- takes a string (the heading) and a generic list.  The list should be
 *          passed by reference so a copy isn't made
 *    2. In main,
 *       2a. Create a list of ints
 *           -- add elements 10, 30 70, 10, 30, 50, 70, and 90 using push_back
 *           -- List one should now contain 10, 10, 30, 30, 50, 70, 70, and
 *           -- use the "show" function to print the contents of the list
 *       2b. Create another list of ints
 *           -- add elements 20, 40, 60, 80, and 100 using push_front
 *           -- list two should now contain 100, 80, 60, 40, and 20
 *           -- use the "show" function to print the contents of the list
 *       2c. Use the "sort" function (from the algorithm library) to sort both
 *           lists, then display their contents again
 *           -- the second list should be sorted 20, 40, 60, 80, and 100
 *       2d. Use the "unique" function to remove duplicates from list one
 *           -- should remove duplicate 10, 30, and 70
 *       2e. Use the "merge" function to move the second list into the first
 *           -- list one should be 10, 20, 30, 40, 50, 60, 70, 80, 90, and 100
 *           -- list two should be empty
 *       2f. Use the "reverse" function to reverse the order of list one
 *       2g. Use the "find" function to determine find the locations of 30 and
 *           70 in list one
 *       2h. Remove the elements from 30 (exclusive) to 70 (inclusive) in the list
 *           and show its contents
 */

// Includes
#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>          // needed for "find" function for lists
using namespace std ;

// Generic version of "show" function which lists contents of a list
// Parameter 1 is heading of list, parameter 2 is a generic list
template <typename T>
void show(string heading, list<T> &the_list) {
    cout << left << setw(8) << heading ;        // print heading
    auto iter = the_list.begin() ;
    while (iter != the_list.end()) {
       cout << *(iter++) << " " ;
    }
    cout << endl ;                             // end with a new-line
}

int main() {

    list<int> list1, list2 ;

    // Build list1 with elements 10, 30, and 70, then 10, 30, 50, 70, and 90
    list1 = {10, 30, 70} ;
    for (int i = 10 ; i <= 100 ; i += 20) {
        list1.push_back(i) ;
    }
    cout << "Initial list1 contents" << endl ;
    show ("list1:", list1) ;

    // Build list2 as 100, 80, 60, 40, and 20  (using push_front)
    for (int i = 20 ; i <= 100 ; i += 20) {
        list2.push_front(i) ;
    }
    show("list2:", list2) ;

    // Sort both list in ascending order, then show their contents
    list1.sort() ;
    list2.sort() ;
    cout << "\nAfter sorting" << endl ;
    show("list1:", list1) ;
    show("list2:", list2) ;

    // Pull out the duplicates from list1 (10, 30, and 70)
    cout << "\nRemove duplicates from list1" << endl ;
    list1.unique() ;
    show("list1:", list1) ;

    // Merge all elements into list1, leaving list2 empty
    // Note:  contents of both lists should be sorted.
    cout << "\nAfter merging list1 and list2" << endl ;
    list1.merge(list2) ;
    show("list1:", list1) ;
    show("list2:", list2) ;

    // Put list1 in reverse order
    cout << "\nReverse contents of list1" << endl ;
    list1.reverse() ;
    show("list1:", list1) ;

    // Use the find function (in stl) to delete elements from 70 (inclusive)
    // down to 30 (exclusive)
    cout << "\nDelete from 70 (inclusive) to 30 (exclusive)" << endl ;
    list<int>::iterator found70 = find(list1.begin(), list1.end(), 70) ;
    list<int>::iterator found30 = find(found70, list1.end(), 30) ;
    if (found30 != list1.end()) {
        list1.erase(found70, found30) ;
    }
    show("list1:", list1) ;

    cout << endl ;
    return 0 ;
}


