/* Predicates.cpp - Demonstrate predicates IsOdd and Contains
 * Author:     Chris Merrill
 * Module:     8
 * Project:    Demonstration
 * Problem statement: Create two predicates, one to test if a number is odd,
 *     another to determine if one string appears inside another string
 *
 * Algorithm:
 *   * Create a unary predicate in the IsOdd class which returns true
 *     if an int argument is true, false otherwise
 *   * Create an overloaded binary predicate which returns true if
 *     a string (the second parameter) is included in another string (the
 *     first parameter)
 *     - One version should take a string as the second parameter, the second
 *       version should take a C-string as the second parameter
 *   * In main demonstrate the unary predicate using an odd number with
 *     an object of the IsOdd class
 *   * Demonstrate the unary predicate using an anonymous version
 *   * Demonstrate both versions of the binary predicate
 *     - What happens when the second version of the binary predicate is
 *       eliminated?
 *
 * Discussion:
 *   * Comment out the second version.  C++ will promote the string constant
 *     to a string and use the first version.
 */

#include <iostream>
using namespace std ;

// Unary predicates take a single parameter
class IsOdd {
    public:
        bool operator() (int x) {
            return x % 2 != 0 ;
        }
} ; // end class IsOdd

// Binary predicates (overloaded) which take two parameters
class Contains {
    public:

        // Version #1 which takes a string and a C-string (calls Version #2)
        bool operator() (const string source, const char *cfind_me) {
            return Contains() (source, string(cfind_me)) ;
        }

       // Version  #2 which takes two string objects (calls C++ string function)
        bool operator() (const string source, const string find_me) {
            return source.find(find_me) != -1 ;
        }
} ; // end of the class Contains

int main() {

    // Create a predicate that determines if a number is odd
    IsOdd odd_test ;
    cout << "Is 3 an odd number? " << (odd_test(3) ? "yes" : "no") << endl ;

    // Use an anonymous version
    cout << "Is 98 an odd number? " << (IsOdd()(98) ? "yes" : "no") << endl << endl ;

    // Does one string contain another?  Use an anonymous object
    // with the first version of overloaded predicate (string, C-string).
    string source = "abcdefg" ;
    cout << "Using Version #1" << endl ;
    cout << "Is \"def\" in \"" << source << "\"? "
         << (Contains() (source, "def") ? "yes" : "no") << endl ;

    // What about the second version (string, string)
    string find_me = "xyz" ;
    cout << "Using Version #2" << endl ;
    cout << "Is \"xyz\" in \"" << source << "\"? "
         << (Contains() (source, find_me) ? "yes" : "no") << endl ;

    return 0 ;
}
