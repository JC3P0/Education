/* SwapMe.cpp - Demonstrate the swap template from the lecture
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Demonstration
 * Problem statement:  Using the swap template from the lecture, demonstrate
 *    swapping the values of ints, doubles, chars, strings, and vectors
 *
 * Algorithm:
 *   1. Use template function from lecture to swap two items
 *      1a. The "swap" template is already provided by the STL, so we have
 *          to rename ours to swapMe
 *   2. Create a function named "show" which takes a vector of ints and
 *      displays its contents
 *   3. In main:
 *      3a. Assign two int variables, display their values, call the swap
 *          function, then display their values again
 *      3b. Repeat for two double variables
 *      3c. Repeat for two char variables
 *      3d. Repeat for two string variables
 *      3e. Repeat for two vectors of ints (use the "show" function to
 *          display the values of the two vectors
 *      3f. Show what happens when values of different types are used
 *
 * Discussion:
 *    * Must use pass by reference (pass by value makes copies) in swapMe.
 *    * Can't mix types (see bottom of program).
 *    * C++ "instantiates" the swapMe function for each required template
 *      (once for ints, once for doubles, once for chars...)
 */

#include <iostream>
#include <vector>
using namespace std ;

// The swapMe template (use "typename" instead of "class")
template<typename T>
   void swapMe(T &x, T &y) {
      T temp = x ;
      x = y ;
      y = temp ;
   }

// Function to return the list of a ints in a vector in a string.
string show(vector<int> &vec) {
      string return_string = "{" ;
       for (int i = 0 ; i < vec.size() ; i++)
           return_string += " " + to_string(vec[i]) ;
       return return_string + " }" ;
}

int main() {

    // Start by swapping the values of two ints
    int a = 5, b = 7 ;
    cout << "Using ints" << endl
         << "Before swap:  a = " << a << "   b = " << b << endl ;
    swapMe(a, b) ;
    cout << "After swap:   a = " << a << "   b = " << b << endl << endl ;

    // Using doubles
    double x = 15.8 , y = -23.7 ;
    cout << "Using doubles:" << endl
         << "Before swap:  x = " << x << "   y = " << y << endl ;
    swapMe(x, y) ;
    cout << "After swap:   x = " << x << "   y = " << y << endl << endl ;

    // Using chars
    char c = 'c', d = 'd' ;
    cout << "Using chars" << endl
         << "Before swap:  c = '" << c << "'   d = '" << d << "'" << endl ;
    swapMe(c, d) ;
    cout << "After swap:   c = '" << c << "'   d = '" << d << "'" << endl << endl ;

    // Using strings
    string alpha = "alpha", beta = "beta" ;
    cout << "Using strings" << endl
         << "Before swap:  alpha = \"" << alpha << "\"  beta = \""
         << beta << '"' << endl ;
    swapMe(alpha, beta) ;
    cout << "After swap:   alpha = \"" << alpha << "\"  beta = \""
         << beta << '"' << endl << endl ;

    // Using vectors
    vector<int> first {1, 2, 3}, second {4, 5, 6} ;
    cout << "Using vectors" << endl
         << "Before swap:  first = " << show(first)
         << "   second = " << show(second) << endl ;
    swapMe(first, second) ;
    cout << "After swap:   first = " << show(first)
         << "   second = " << show(second) << endl << endl ;

    // Mixing types won't work (no automatic promotions or demotions)
    int anInt = 5 ;
    double aDouble = 2.5 ;
    string aString = "Hello" ;
    // swapMe(anInt, aDouble) ;
    // swapMe(anInt, aString) ;

    return 0 ;
}

