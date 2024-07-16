/* ThisPointer.cpp - Demonstrate how the "this" pointer works
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Problem statement:  Demonstrate how "this" works both when using an instance
 *    variable with the same name as a parameter to a function, and when
 *    returning an object
 *
 * Algorithm:
 *   1. Create a class named "ThisPointerClass".
 *      1a. Data members ints x, y, and z
 *      1b. Constructor with default values of zero for x, y, and z
 *      1c. Method named "set" which sets the values of three data members
 *      1d. Method named "updateXYZ" which multiplies x by 2, adds 2 to y, and
 *          multiplies z by itself.  It returns a copy of the calling object.
 *      1e. Method named "print" which prints the values of the three data
 *          members
 *   2. In main, create two ThisPointerClass objects, one with default values
 *      and one where x = 3, y = 5, and z = 7
 *   3. Print the values of each object
 *   4. Using an assignment statement, assign the second object variable
 *      to the first object (makes a copy of the object on the right)
 *   5. Call updateXYZ on the second object
 *   6. Print values of both objects again 
 *
 * Discussion:
 *    * The "this" pointer is used in the constructor to differentiate data member
 *      variables with the same name as parameters
 *    * The "this" pointer is used to return (a copy of) the calling object from
 *      the updateXYZ function
 *    * What happens when we remove "this" in updateXYZ function?
 *       -- sets returned value to garbage
 *       -- not a compiler error...
 */

#include <iostream>
#include "ThisPointerClass.h"
using namespace std ;

int main() {

    ThisPointerClass object1(3, 5, 7) ;     // Values for x, y, and z
    ThisPointerClass object2 ;              // uses default values in constructor

    cout << "Initial values after creation" << endl << "Object 1:  " ;
    object1.print() ;
    cout << "Object 2:  " ;
    object2.print() ;
    cout << endl ;

    // Calls updateXYZ, which updates the values of x, y, and z, then
    // returns a copy of object1 and assigns to object2
    object2 = object1.updateXYZ() ;

    cout << "After updating object1 and assigning to object2: " << endl ;
    cout << "Object 1:  " ;
    object1.print() ;
    cout << "Object 2:  " ;
    object2.print() ;

    // Use updateXYZ as a void function on object2 (ignores returned value)
    object2.updateXYZ() ;
    cout << endl << "After call to updateXYZ on object2" << endl ;
    cout << "Object 1:  " ;
    object1.print() ;
    cout << "Object 2:  " ;
    object2.print() ;
    cout << endl ;

    return 0 ;
}
