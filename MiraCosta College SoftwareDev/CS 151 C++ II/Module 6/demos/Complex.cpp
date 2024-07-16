/* Complex.cpp - A class with two numbers representing a complex number
 * Author:     Chris Merrill
 * Module:     6
 * Project:    Exercise #1
 * Problem statement: Create a class which has two double instance variables.
 *    Provide default and full constructors, prefix and postfix increment
 *    operators, stream insertion operator, and addition operator.
 *
 * Algorithm:
 *   1.  Create a class named "Complex" with left and right (int) instance
 *       variables
 *   2.  Provide default and full constructors with definitions inside the class
 *   3.  Provide prototypes for the pre-increment and post-increment operators
 *   4.  Provide (friend) prototype for addition operator
 *   5.  Provide (friend) prototype for stream insertion operator
 *   6.  In main, create two Complex objects (5.3, 12.7) and (18.1, -3.4).
 *   7.  Print the two objects using the insertion operator
 *   8.  Demonstrate the addition operator by adding the two objects and
 *       printing the results.
 *   9.  Demonstrate the post-increment and pre-increment operators by showing
 *       the affected object both before and after the increment
 */

#include <iostream>
#include <iomanip>
using namespace std ;

class Complex {

    private:
        double left, right ;

    public:

        // Default constructor
        Complex()
            { left = right = 0 ; }

        // Full Constructor
        Complex(double left, double right) {
            this->left = left ;
            this->right = right ;
        }

        // Prototypes and Friends
        Complex operator++() ;                         // prefix increment operator
        Complex operator++(int) ;                      // postfix increment operator
        friend Complex operator+(Complex, Complex) ;   // addition operator
        friend ostream & operator<<(ostream &, const Complex &) ;   // stream insertion
} ;

// Add the definitions of the overloaded functions

int main() {

    // Create and print two Complex objects
    Complex obj1(5.3, 12.7) ;
    Complex obj2(18.1, -3.4) ;

    cout << fixed << setprecision(1) ;
    // cout << "One:   " << obj1 << endl ;
    // cout << "Two:   " << obj2 << endl << endl ;

    // Show results of prefix increment operator
    // cout << "++One: " << ++obj1 << endl ;
    // cout << "One:   " << obj1 << endl << endl ;

    // Show results of postfix increment operator
    // cout << "Two++: " << obj2++ << endl ;
    // cout << "Two:   " << obj2 << endl << endl ;

    // Show results of addition operator
    // cout << "Sum:   " << (obj1 + obj2) << endl ;

     return 0 ;
}
