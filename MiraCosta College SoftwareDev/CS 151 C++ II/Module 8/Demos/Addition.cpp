/* Addition.cpp - Create functors that allow addition of numbers and strings
 * Author:     Chris Merrill
 * Module:     8
 * Project:    Demonstration
 * Problem statement:  Create a class named "Addition" which has two
 *    functions which overload the () operator.  One takes two ints
 *    and returns another int, another takes two doubles and returns
 *    another double, and the third takes two strings and returns
 *    another string.
 *
 * Algorithm:
 *   * Create an Addition class
 *   * Inside the class, create three functions which overload ():
 *
 *             int operator()(int a, int b)
 *             double operator()(double a, double b)
 *             string operator()(string a, dstring b)
 *
 *     The two numeric versions return the sum of two numbers.  The
 *     string version returns the concatenation of two strings.
 *
 * Discussion:
 *   * Function overloading (multiple signatures)
 *   * Some calls are anonymous (the object disappears as soon as it
 *     is no longer needed). Other calls use a named object.
 *   * Ambiguity (doesn't compile) when the fourth call is uncommented.
 */

#include <iostream>
using namespace std ;

class Addition {

    public:

        // integer version
        int operator() (const int a, const int b) {
            cout << "Running int version with " << a << " and " << b << endl ;
            return a + b ;
        }

        // double version
        double operator() (const double a, const double b) {
            cout << "Running double version with " << a << " and " << b << endl ;
            return a + b ;
        }

        // string version
        string operator() (const string a, const string b) {
            cout << "Running string version with \"" << a << "\" and \"" << b << "\"" << endl ;
            return a + b ;
        }
} ;

int main() {

    // Run the overloaded () version that takes two ints
    cout << Addition() (8, 3) << endl << endl ;  // anonymous object

    // Run the version that takes two doubles (does this increase readability?)
    // Since it's assigned to a variable, this version is not anonymous
    Addition adder ;                             // create object of the Addition class
    cout << adder(4.4, 5.5) << endl << endl ;    // overloaded ( ) operator

    // Run the version that takes two strings
    cout << adder("Hello", " World!") << endl << endl ;

    // What happens here with one int and one double?
    // cout << Addition() (4, 5.0) << endl << endl ;      // ambiguous?

    return 0 ;
}
