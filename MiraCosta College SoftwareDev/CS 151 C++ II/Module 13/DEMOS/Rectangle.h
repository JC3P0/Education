/* Rectangle.h - Rectangle with width, length, and inner Exception classes
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Exercise 1
 * Description:
 *
 *    Create 2 inner exception types:  NegativeWidth and NegativeLength
 *    Both classes contain a element which contains the value of the
 *    width / length entered by the user
 *
 * Both exception classes should have a constructor which stores the bad value
 * in the exception object as it is thrown
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std ;

class Rectangle {

    private:
        double width ;     // The rectangle's width
        double length ;    // The rectangle's length

    public:
        // Exception class for a negative width
        class NegativeWidth {
            private:
                int value ;
            public:
                NegativeWidth(double val)
                    { value = val ; }
                int getValue() const
                    { return value ; }
        } ;

        // Exception class for a negative length
        class NegativeLength {
            private:
                int value ;
            public:
                NegativeLength(int val)
                    { value = val ; }
                int getValue() const
                    { return value ; }
        } ;

    public:
        // Default constructor
        Rectangle()
            { width = 0.0 ; length = 0.0 ; }

        // Mutator functions, defined outside of class
        void setWidth(double) ;
        void setLength(double) ;

        // Accessor functions
        double getWidth() const
            { return width ; }

        double getLength() const
            { return length ; }

        double calcArea() const
            { return width * length ; }
} ;

//**************************************************
// Sets the value of the member variable width.    *
//    Throws a new exception NegativeWidth(w)  *
//**************************************************
void Rectangle::setWidth(double new_width) {
    if (new_width >= 0)
        width = new_width ;
    else
        throw NegativeWidth(new_width) ;
}

//**************************************************
// Sets the value of the member variable length.   *
//    Throws a new exception NegativeLength(l) *
//**************************************************
void Rectangle::setLength(double new_length) {
    if (new_length >= 0)
        length = new_length ;
    else
        throw NegativeLength(new_length) ;
}
#endif
