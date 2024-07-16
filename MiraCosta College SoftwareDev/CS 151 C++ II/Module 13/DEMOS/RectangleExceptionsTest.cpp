/* RectangleExceptionsTest.cpp - Use a loop to handle individual exceptions
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Exercise 1
 * Problem statement:  Create a Rectangle object where the length
 *    and width are entered by the user.  If either is negative,
 *    throw an exception of a class also created in the Rectangle
 *    class
 *
 *    Setters for length and for width will throw exceptions
 *    "NegativeWidthException" and "NegativeLengthException", which
 *    are inner classes to Rectangle, and hold the delinquent data.
 *
 * Algorithm:
 *    1. User enters width and length for a new Rectangle
 *    2. Rectangle constructor is called
 *      - setwidth checks for negative width
 *      - setLength checks for negative length
 *    3. Create one exception class for negative lengths and another for
 *       widths enter by the user
 *    4. Add a data member to the exception class, then use it when catching
 *       the exception
 *    5. Use a loop in main to ensure that neither the length nor the width
 *        goes negative
 *
 * Discussion:
 *  - Saving message in the exception class
 *  - Accessing the message using e.getValue (e is the object just thrown)
 *  - Because of the way exceptions are implemented, the exception classes had
 *    to be made public.  A better solution might allow the exception classes
 *    to be private, so they couldn't be used outside of the Rectangle class.
 */

#include <iostream>
#include "Rectangle.h"
using namespace std ;

int main() {

    int width ;                       // Rectangle's new width
    int length ;                      // Rectangle's new length
    bool try_again = true ;           // Flag to re-read input

    // Create a Rectangle object.
    Rectangle my_rectangle ;

    // Store the width in the myRectangle object.  Throw an exception
    // if the user enters a negative number.
    do {

         // Get the rectangle's width.
        cout << "Enter the rectangle's width: " ;
        cin >> width ;
        try {
            my_rectangle.setWidth(width) ;      // Can throw an exception
            try_again = false ;                 // exit loop (no exception)
        }
        catch (Rectangle::NegativeWidth e) {
            cout << "  ** Negative width not allowed like " << e.getValue() << endl ;
        }
    } while (try_again) ;

    // Store the length in the myRectangle object.
    try_again = true ;
    do {

        // Get the rectangle's length.
        cout << "Enter the rectangle's length: " ;
        cin >> length ;
        try {
            my_rectangle.setLength(length) ;    // Can throw an exception
            try_again = false ;                 // exit loop (no exception thrown)
        }
        catch (Rectangle::NegativeLength e) {
            cout << "  ** Negative value not allowed like " << e.getValue() << endl ;
        }
    } while (try_again) ;

    // Both length and width are non-negative, so display area of the rectangle.
    cout << "The rectangle's area is "
         << my_rectangle.calcArea() << endl ;

    return 0 ;
}
