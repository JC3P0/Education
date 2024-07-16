/* Overriding.cpp - A subtle difference between two function headings
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Problem statement:  Find the difference between two functions that look
 *    the same, but actually one is overloading the other, not overriding.
 *    Demonstrate the "override" keyword to prevent this.
 *
 * Algorithm:
 *   1. Create a parent class named "Base" with the following virtual function
 *
 *                   virtual void where (int arg) const
 *
 *   2. Create a child class named "Derived" with the following virtual function
 *
 *                    virtual void where (long arg) const
 *                  
 *   3. In main,
 *      3a. Create a shared_pointer of type Base.
 *      3b. Assign a (shared) pointer to an object of type Derived
 *      3c. Using the pointer, call the function with parameter of 6
 *          -- It calls the Base class version, not the Child class!
 *          -- This is because the Child class version does not override the Base
 *             class version
 *          -- It's actually overloading, not overriding.
 *   4. Add the keyword "override" to the child version.
 *      4a. A compiler error results.
 *      4b. Change the parameter type in Child class to int, and run again
 *      4c. Now the Child class version is seen.
 *   5. With the second function still using an int parameter, place the
 *      word "final" after the heading in the Base class
 *      5a. A compiler error results when the two headings are the same
 */

#include <iostream>
#include <memory>                     // Need for the shared pointer
using namespace std ;

class Base {
    public:
        virtual void where (int arg) const
            { cout << "This is Base version of where: arg = " << arg << endl ; }
 } ;

// The "where"function in the Derived class should override the "where" function
// in the Base class, but it doesn't...
class Derived : public Base {
    public:
        virtual void where (long arg) const
            { cout << "This is Derived version of where: arg = " << arg << endl ; }
 } ;

 int main()  {
    //Base pointer b points to a Derived class object .
    shared_ptr<Base> b = make_shared<Derived>() ;

    // Call virtual "where" function through Base pointer.
    // Yikes!  It still calls the Base class version
    b->where(6) ;

    return 0 ;
}

