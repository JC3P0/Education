/* Sets.cpp - Demonstrate the functions in sets and multisets
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Demonstration
 * Problem statement:  This program many of the functions in the sets and multisets
 *     template (STL) classes
 *
 * Algorithm:
 *   1. Create a generic function which takes any container (list, set, vector,
 *      multi-set, etc.) and prints on the console
 *   2. In main
 *      2a. Create a set of ints
 *      2b. Insert 10, 20, 30, 40, 50, ..., and 100
 *      2c. Print the contents of the set
 *      2d. Remove 20, 40, 60, 80, and 100
 *      2e. Print the contents of the set again (should be 10, 30, 50, 70, and 90)
 *      2f. Insert 10, 20, 30, 40..., and 100
 *      2g. Print the contents again (should be 10, 20, 30, 40, ..., 100)
 *   3. Do the same thing except use a multi-set
 *      3a. Multi-sets allow duplicates
 *
 * Discussion:
 *   * Functions are "insert" to add and "erase" to remove
 *   * In the set, items 10, 30, 50, 70, and 90 in last operation are not added
 *     because duplicates aren't allowed
 *      - In multiset, those items are added (and duplicated)
 *   * In both sets and multisets, items are always in sorted order
 */

#include <iostream>
#include <set>
using namespace std ;

// Template to print the contents of a container (set or multiset)
// Note:  sets do not support [ ] notation, so must use an iterator
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

    // Create various containers
    set<int> my_set ;
    multiset<int> my_multiset ;

    // Add 10, 20, 30, 40, ..., 100 and print
    cout << "Using Set: " << endl ;
    for (int i = 10 ; i <= 100 ; i += 10) {
        my_set.insert(i) ;
    }
    print(my_set, "Inserting 10, 20, 30...") ;

    // Remove 20, 40, 60, 80, and 100, then print
    for (int i = 20 ; i <= 100 ; i += 20) {
        my_set.erase(i) ;
    }
    print(my_set, "Removing  20, 40, 60...") ;

    // Add 10, 20, 30, 40, ..., 100 again and print (no duplicates)
    for (int i = 10 ; i <= 100 ; i += 10) {
        my_set.insert(i) ;
    }
    print(my_set, "Inserting 10, 20, 30...") ;

    // Useing a multiset, do the same set of operations (multisets allow duplicates)
    cout << "\nUsing Multiset: " << endl ;
    for (int i = 10 ; i <= 100 ; i += 10) {
        my_multiset.insert(i) ;
    }
    print(my_multiset, "Inserting 10, 20, 30...") ;

    for (int i = 20 ; i <= 100 ; i += 20) {
        my_multiset.erase(i) ;
    }
    print(my_multiset, "Removing  20, 40, 60...") ;

    for (int i = 10 ; i <= 100 ; i += 10) {
        my_multiset.insert(i) ;
    }
    print(my_multiset, "Inserting 10, 20, 30...") ;

    cout << endl ;

    return 0 ;
}
