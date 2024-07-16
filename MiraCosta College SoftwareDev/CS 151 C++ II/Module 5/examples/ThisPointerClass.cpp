/* ThisPointerClass.cpp - Use the hidden "this" pointer to reference calling objects.
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Description:  Its function is to use the hidden "this" pointer which the compiler
 *    automatically assigns to the calling object that is a member of the class.  
 *    This allows the programmer to refer to the object as a whole in the 
 *    definition of a member function even when the object is not passed in to 
 *    the function as a parameter.
 *
 *    See updateXYZ() function below.
 */

#include <iostream>
#include "ThisPointerClass.h"
using namespace std ;

// Use same variable names for parameters and instance members
ThisPointerClass::ThisPointerClass(int x, int y, int z) {
    this->x = x ;
    this->y = y ;
    this->z = z ;
}

// OK (or even preferred) to use different names for parameters
void ThisPointerClass::set(int a, int b, int c) {
    x = a ;
    y = b ;
    z = c ;
}

// Demonstrate using "*this" to return the a copy of the calling object.
ThisPointerClass ThisPointerClass::updateXYZ() {
    x = 2 * x ;
    y = y + 2 ;
    z = z * z ;
    return *this ;        // returns a copy of this object (x,y,z)
                          // (will discuss later with copy constructors)
}

void ThisPointerClass::print() const {
    cout << "x = " << x
         << ", y = " << y
         << ", z = " << z << endl ;
}


