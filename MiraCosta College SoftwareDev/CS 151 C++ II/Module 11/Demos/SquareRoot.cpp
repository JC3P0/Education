/* SquareRoot.cpp - Find the square root of a number using recursion
 * Author:     Chris Merrill
 * Module:     11
 * Project:    Demonstration
 * Problem Statement: Show a function for zeroing in on a square root of any
 *     number using a recursive binary search algorithm
 *
 * Algorithm:
 *   1. Establish a target number greater than 0.0 whose square root we will find
 *   2. Write a function which recursively determines the square root of that number
 *      2a. Set high to the number and low to 1
 *      2b. If the target is less than one, then set the low to 0 and high to 1
 *      2c. Find the midpoint of high and low
 *      2d. If the midpoint squared is greater than the target number, then
 *          set high to the midpoint and repeat
 *      2e. If the midpoint squared is less than the target number, then set
 *          low to the midpoint and repeat
 *      2f. Stop recursing when the new value squared is within a certain tolerance
 *          of the actual target
 *
 * Discussion:
 *   Uncomment the print statements in the squareRoot function to show how the function
 *      zeroes in on the correct number.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

// prototypes
double squareRoot(double, double) ;

double target_squared = 0.0,               // square of root we are searching for
       tolerance = 0.0 ;                   // acceptable tolerance (error)
int levels = 0 ;                           // number of levels of recursion

int main() {

    cout << "Enter a positive number to find square root: " ;
    cin >> target_squared ;

    double low = 1.0,                      // bottom of search range
           high = target_squared ;         // top of search range
    tolerance = target_squared * 1e-15 ;   // acceptable tolerance

    if (target_squared < 1) {
        low = 0 ;
        high = 1.0 ;
    }

    cout << fixed << setprecision(16)
         << "Looking for the square root of " <<  target_squared << endl ;

    double new_root = squareRoot(low, high) ;
    cout << new_root << " squared is " << (new_root * new_root) << endl ;

    double math_root = sqrt(target_squared) ;
    cout << math_root << " is from the Math library, squared is "
         << (math_root * math_root) << endl << endl
         << levels << " levels of recursion were required." << endl ;

    return 0 ;
} // end of main

// Start recursion
double squareRoot(double low, double high) {

    double midpoint = (low + high) / 2.0 ;
    double midpoint_squared = midpoint * midpoint ;

    // Base case
    if (abs(midpoint_squared - target_squared) < tolerance) {
        return midpoint ;
    }

    // Recursive case
    levels++ ;

    // Comment these lines out to just get the final numbers
    cout << "low: " << low << "  midpoint: " << midpoint << "   high: " << high
         << "  midpoint ^ 2: " << midpoint_squared << endl ;

    // Next recursive call
    if (midpoint_squared > target_squared) {
        return squareRoot(low, midpoint) ;
    }
    return squareRoot(midpoint, high) ;
}

