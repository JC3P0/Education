/* DivisibleTest.cpp - Create unary predicates to test divisibility
 * Author:     Chris Merrill
 * Module:     8
 * Project:    Exercise #2
 * Problem statement: Create three unary predicates which return true
 *    if a number (stored as a property in those predicates) evenly divides
 *    into a parameter to the overloaded () operator
 *
 * Algorithm:
 *   * Create a class named DivisibleTest which has two functions:
 *     1. A constructor which saves an int parameter in a private
 *        data member named "divisor"
 *     2. An overloaded () operator which takes a single parameter
 *        and returns "true" if the parameter is evenly divisible
 *        by "divisor", otherwise it returns false
 *
 *   * In main:
 *     1. Create three predicates which determine if a parameter
 *        is evenly divisible by 3, by 5, and by 7
 *     2. Create an array of numbers (ints) to test for divisilibity
 *     3. Using a "for-each" loop, test each of the numbers in the array
 *        for divisibility by 3, 5, and 7.  Print the results
 *
 * Discussion:
 *   * Notice that the constructor call looks very similar to the
 *     overloaded operator call (both take a single int parameter)
 */

#include <iostream>
using namespace std ;

class DivisibleTest {

    private:
        int divisor ;               // number to divide by (3, 5, or 7)

    public:
        DivisibleTest (int divisor) :               // constructor sets divisor
            divisor(divisor) { } ;
        bool operator() (int test_number)           // overloaded () operator
            { return test_number % divisor == 0 ; }

} ; // end class

int main() {

    // Create three predicate (functors) to test for
    // divisibility by 3, by 5, and by 7
    DivisibleTest divisibleBy3(3) ;     // calls constructor saving divisor property
    DivisibleTest divisibleBy5(5) ;
    DivisibleTest divisibleBy7(7) ;

    // Array of numbers to test for divisibility
    int test_numbers[] = {3, 5, 7, 11, 15, 28, 105} ;

    // For each number in the array, test divisibility using the predicates
    for (int test : test_numbers) {
        cout << "Testing divisibility of " << test << endl
             << "    by 3? " << (divisibleBy3(test) ? "yes" : "no") << endl
             << "    by 5? " << (divisibleBy5(test) ? "yes" : "no") << endl
             << "    by 7? " << (divisibleBy7(test) ? "yes" : "no") << endl << endl ;
    }

    return 0 ;
}

