/* Primes.cpp - Use a predicate and a lambda expression to build a list of primes
 * Author:     Chris Merrill
 * Module:     9
 * Project:    Review Exercise
 * Problem statement: Create a list of the first 1,000 numbers, then whittle down
 *    to a list of prime numbers
 *
 * Algorithm:
 *    1. Create a function named "primeCheck" which takes a positive int and
 *       returns true if the number is prime, false otherwise
 *      1a. Handle numbers 1 and 2 separately (both are considered prime numbers)
 *      1b. Find the lowest whole number whose square is less than the number to
 *          be tested.
 *      1c. loop from 2 to the number found in 2b, and determine if that number
 *          is an even factor of the number to be tested
 *   2. Create a class "NotPrime" which overloads the function operator to return
 *      true if passed a number that is NOT prime, otherwise returns false
 *   3. In main, create an array of the first 1,000 numbers (beginning with 1)
 *   4. Use the NotPrime class to demonstrate the overloaded function operator to
 *      remove numbers in the array (created in step 3) which aren't prime.
 *   5. Use using the "remove_if" template, remove all of the numbers from the
 *      array which aren't prime
 *   6. Print the list of remaining numbers on the console.
 *   7. Repeat steps 3-6, except use a lambda expression (instead of an
 *      overloaded function operator to remove those numbers in the array
 *      which aren't prime.
 *
 * Discussion:
 *    1. The first version (the remove-if template uses the bool function to
 *       remove those numbers in the array which aren't prime numbers
 *    2. Comment the first "remove-if" and uncomment the second version which
 *       uses a lambda expression to do the same thing.
 */

#include <iostream>
#include <cmath>                        // for floor and sqrt functions
#include <algorithm>                    // for remove-if templates
using namespace std ;

// Unary predicate returns "true" if a positive number (the parameter) is prime
bool primeCheck(int number) {

    // Numbers 1 and 2 are considered prime
    if (number <= 2) {
        return true ;
    }

    // Test the factors from 2 to the square-root of the the number to
    // determine of they evenly divide the parameter.
    int limit = ceil(sqrt(number)) ;
    for (int factor = 2 ; factor <= limit ; factor++) {
        if (number % factor == 0) {     // "number" is divisible by "factor"
            return false ;
        }
    }
    return true ;                       // No factors except 1 and itself
}

class NotPrime {
    public:
        // Overloaded function operator returns true if a number is NOT prime
        bool operator() (int number) {
            return !(primeCheck(number)) ;
        }
} ;

int main() {

    // Create an array filled with numbers from 1 to 1,000
    const int SIZE = 1000 ;
    int test_cases[SIZE] ;
    for (int i = 0 ; i < SIZE ; i++) {
        test_cases[i] = i + 1 ;
    }

    // Remove all numbers that aren't prime, where the "new" end of the items in
    // the array is the returned value.  Uses the overloaded () operator from the
    // NotPrime class and an to determine if a number isn't prime.
    int *pEnd = remove_if(test_cases, test_cases + SIZE, NotPrime()) ;

    // Use a lambda expression to do the same thing.  (Note:  The "primeCheck"
    // function was made global (and thus static) for this to work.
/*  int *pEnd = remove_if(test_cases, test_cases + SIZE,
                             [](int i) { return ! primeCheck(i) ; }) ;
*/
    // Finally you can use a lambda expression which uses the functor
/*  int *pEnd = remove_if(test_cases, test_cases + SIZE,
                             [](int i) { return NotPrime()(i) ; }) ;
*/
    // Print the numbers still remaining in the array (should be only primes)
    for (int *ptr = test_cases ; ptr != pEnd ; ptr++) {
         cout << *ptr << " " ;
    }

    return 0 ;
}
