/* SetBinaryTreeTest.cpp - Test the Set template class with several examples of set operations
 * Author:     Chris Merrill
 * Module:     16
 * Project:    Demonstration
 * Problem Statement: Demonstrate how the Set.cpp program works
 *
 * Algorithm:
 *    1. Create a generic Set class with insert, contains, setUnion, and setIntersect
 *       functions
 *    2. Create two Set objects of Strings representing scientists and artists
 *       2a. Make sure there are at least two common names.
 *    3. Print each of the lists
 *    4. Print the members of the union of the scientists and the artists
 *    5. Print the members of the union of the artists and the scientists
 *    6. Do the same for the intersection of the two sets
 *    7. Create two Set objects containing various doubles
 *       7a.  Ensure there at least two numbers that are the same
 *    8. Print both lists, the union of both sets, and the intersection of both sets
 */

#include <iostream>
#include <vector>
#include "SetBinaryTree.h"
using namespace std ;

int main() {

    cout << "********************** Using Strings **********************" << endl << endl ;
    // Create a set with three scientists, then print the members
    Set<string> scientists ;
    scientists.insert("Hubert") ;
    scientists.insert("Julia") ;
    scientists.insert("Leonard") ;
    scientists.insert("Alicia") ;
    scientists.insert("Tim") ;
    scientists.insert("Charlene") ;
    cout << "The Scientists are: " ;
    scientists.display() ;

    // Create a set with three Artists (including two from the Scientists,
    // and print the members
    Set<string> artists ;
    artists.insert("Tony") ;
    artists.insert("Alicia") ;
    artists.insert("Jason") ;
    artists.insert("Leonard") ;
    artists.insert("Elena") ;
    cout << "The Artists are:    " ;
    artists.display() ;

    // Show the union of Artists with Scientists, and Scientists with Artists
    cout << endl ;
    cout << "Artists union Scientists: " ;
    (artists.setUnion(scientists)).display() ;
    cout << "Scientists union Artists: " ;
    scientists.setUnion(artists).display() ;

    // Show the intersections of the same two sets
    cout << endl ;
    cout << "Artists intersect Scientists: " ;
    artists.setIntersect(scientists).display() ;
    cout << "Scientists intersect Artists: " ;
    scientists.setIntersect(artists).display() ;
    cout << endl << endl ;

    // Manipulate two sets of doubles
    double values1[] = {65.0, 79.6, 54.2, 43.9, 14.8, -2.3} ;
    double values2[] = {53.2, 43.9, -2.3, 88.2} ;
    Set<double> double_set1 ;
    Set<double> double_set2 ;

    for (double d : values1)
        double_set1.insert(d) ;
    for (double d : values2)
        double_set2.insert(d) ;

    cout << "********************* Using doubles ******************" << endl << endl ;

    cout << "Set 1: " ;
    double_set1.display() ;
    cout << "Set 2: " ;
    double_set2.display() ;
    cout << endl ;

    cout << "Set 1 intersect Set 2: " ;
    (double_set1.setIntersect(double_set2)).display() ;
    cout << "Set 1 union Set 2:     " ;
    (double_set1.setUnion(double_set2)).display() ;

    cout << "Set1 intersect Set 2 converted to a vector: " ;
    vector<double> *values = double_set1.setIntersect(double_set2).toVector() ;
    for (double d : *values) {
        cout << d << "  " ;
    }
    cout << endl << endl ;

    delete values ;

    return 0 ;
}
