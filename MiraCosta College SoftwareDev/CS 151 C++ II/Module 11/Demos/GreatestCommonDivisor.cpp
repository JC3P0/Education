/* GreatestCommonDivisor.cpp - Greatest common divisor (gcd) of two numbers
 * Author:     Chris Merrill
 * Module:     11
 * Project:    Demonstration
 * Problem Statement: Create a recursive function to find the
 *     greatest common divisor (gcd) of two positive numbers
 *
 * Algorithm:
 *   1. Use Euclidean (Euclid's) algorithm which states that, given two positive
 *      numbers a and b:
 *                          gcd(a, b) = gcd(b, a % b)
 *   2. Recursive function:
 *         base case:  If second parameter is 0, the gcd is the first parameter
 *         recursive case: Call again replacing second parameter with first parameter,
 *               and first parameter % second parameter with second parameter
 *   3. Test cases:
 *          a:  13 and 11
 *          b.  17 and 51
 *          c.  9 and 27
 *          d.  100 and 2550
 *          e:  111 and 259
 */

#include <iostream>
using namespace std ;

// prototypes
int gcd(int, int) ;

// Test cases
const int TEST_CASES[][2] {{13, 11}, {17, 51}, {9, 27}, {100, 2550}, {111, 259}} ;

int main() {

    for (int i = 0 ; i < 5 ; i++) {

        int first = TEST_CASES[i][0] ;
        int second = TEST_CASES[i][1] ;
        cout << "The gcd of " << first << " and " << second << " is "
             << gcd(first, second) << endl << endl ;
    }
}

/***************************************************************************
 * recursion:
 *    base case:       x % y is 0,   (return y)
 *    recursive case:  return (y, x % y)
 ***************************************************************************/
int gcd(int x, int y) {

    return (x % y == 0 ? y : gcd(y, x % y)) ;
}

