/* FibonacciRecursive.cpp - Find the first 50 Finonacci numbers using recursion
 * Author:     Chris Merrill
 * Module:     11
 * Project:    Demonstration
 * Problem Statement: Using the formula fib(n) = fib(n-1) + fib(n-2), find the
 *    first 50 Fibonacci numbers using (multiple) recursion
 *
 * Algorithm:
 *
 *    Create a recursive function that calculates the Fibonacci numbers
 *
 *              fib(0) = 0
 *              fib(1) = 1
 *              fib(n) = fib(n-1) + fib(n-2)        for n > 1
 *
 *    Print Fibonacci numbers from 0 to 50
 *
 * Discussion:
 *   - Uses multiple recursion rather than using the results from the last 2 iterations
 *   - What happens!
 *      -- Is this because of too many levels of recursion?  (No)
 *      -- Is this because of multiple recursion (Yes - recalculating each Fibonacci
 *         number several times!)
 */

#include <iostream>
using namespace std ;

long long fibonacci(int) ;

int main() {

    for (int i = 0 ; i <= 50 ; i++) {
        cout << "fib(" << i << ") is " << fibonacci(i) << endl ;
    }

    return 0 ;
}

long long fibonacci(int number) {

    // base cases
    if (number == 0) {
        return 0 ;
    }
    if (number == 1) {
        return 1 ;
    }

    // multiple recursion
    return fibonacci(number - 1) + fibonacci(number - 2) ;
}

