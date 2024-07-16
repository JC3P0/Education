/* Greater.cpp - C++ program to demonstrate lambda expression in C++
 * Author:     Chris Merrill
 * Module:     8
 * Project:    Demonstration
 * Problem Statement:  Use a lambda expression to sort an array of
 *    doubles in descending order.
 *
 * Algorithm:
 *   1.  Create a lambda expression to compare two doubles, returning
 *       true if the first is greater than the second
 *   2.  Create an array of doubles in unsorted order
 *   3.  Sort the array using the sort algorithm and the lambda expression
 *   4.  Display the sorted array
 *   5.  Create a Mountain class consisting of a mountains name, continent,
 *       and elevation (in feet)height at its peak
 *   6.  Create an array of unsorted Mountains (the largest mountains on
 *       each continent)
 *   7.  Sort the array using a lambda expressions that returns true if the
 *       name of a Mountain object for the first item comes after the name
 *       of the Mountain object is a second item
 *   8.  Use the new sort algorithm to sort and print the Mountains sorted by name
 *   9.  Repeat steps 7 and 8 using a lambda expression that sorts Mountain
 *       objects by continent name
 *  10.  Repeat steps 7 and 8 using the elevation of each mountain is descending
 *       order.
 *
 * Discussion:
 *   - The Mountain class
 *   - Using the sort algorithm provided by C++ STD library
 *   - Using the sort algorithm to sort doubles
 *     -- Notice that it simply takes the starting and ending memory
 *        location of the items to be sorted in the array
 *   - Using the lambda expression (assigned to a name) to sort the
 *     array of doubles in descending order
 *   - Use unnamed lambda expressions to sort the Mountains in the
 *     array by name, then by continent, then by descending elevation
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Mountain.h"
using namespace std ;

// prototypes
void printMountains(string, Mountain[]) ;

int main() {

    // Lambda expression to return true if first param > second param
    auto compare = [](double a, double b) { return a > b ; } ;

    // Sort an array of doubles in descending order
    double d_values[]{ 12.7, 45.9 , 6.9, 1.2, 28.3 } ;
    sort(begin(d_values), end(d_values), compare) ;

    // Print the array
    cout << "An array of doubles sorted in descending order" << endl ;
    for (double x : d_values) {
        cout << x << " " ;
    }
    cout << endl << endl ;

    // Create an Array of Mountain objects in random order
    Mountain *peaks = new Mountain[6] ;
    peaks[0] = Mountain("Denali", "North America", 20310) ;
    peaks[1] = Mountain("Aconcagua", "South America", 22831) ;
    peaks[2] = Mountain("Kilimanjaro", "Africa", 19340) ;
    peaks[3] = Mountain("Mt. Elbrus", "Europe", 18510) ;
    peaks[4] = Mountain("Mt. Everest", "Asia", 29035) ;
    peaks[5] = Mountain("Kosciuszko", "Australia", 7310) ;

    /********************* Anonymous Lambda Expressions *******************/

    // Sort by name
    // (Interpretation:  If the name of Mountain a comes before the
    // name of Mountain b, then Mountain a precedes Mountain b)
    sort(peaks, (peaks + 6), [](Mountain a, Mountain b)
        { return a.getName() < b.getName() ; } ) ;
    printMountains("         *** Sorted by Name ***", peaks) ;

    // Sort by continent
    sort(peaks, (peaks + 6), [](Mountain a, Mountain b)
        { return a.getContinent() < b.getContinent() ; } ) ;
    printMountains("       *** Sorted by Continent ***", peaks) ;

    // Sort by descending elevation
    sort(peaks, (peaks + 6), [](Mountain a, Mountain b)
        { return a.getElevation() > b.getElevation() ; } ) ;
    printMountains(" *** Sorted by Descending Elevation ***", peaks) ;

    delete [] peaks ;
}

// Print the mountains in order they are stored in the array
void printMountains(string heading, Mountain peaks[]) {
    cout << heading << endl ;
    for (int i = 0 ; i < 6 ; i++) {
        cout << left << setw(15) << peaks[i].getName()
             << setw(15) << peaks[i].getContinent()
             << setw(10) << right << peaks[i].getElevation() << endl ;
    }
    cout << endl ;
}

