/* CpClassBad.cpp - Lack of a copy constructor causes program to terminate
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Problem Statement:  What happens when a copy constructor is not provided
 *    for class objects that have pointers to the same object in the heap?
 *
 * Algorithm:
 *   1. Demonstrate the sample program in the lecture
 *   2. The CpClass has a pointer p which is allocated to a "new" int in the
 *      heap upon creation of the object
 *     2a. Unfortunately there is no copy constructor, so when an assignment
 *         statement is used, the pointer's contents is copied
 *   3. Create a function "makeTwo" which creates a single CpClass object using
 *      the normal process
 *   4. Create a second object using the assignment operator
 *   5. When the function stops, both objects are deleted, so their destructors
 *      are called.
 *      5a. Both destructors try to return the same object in the heap.
 */

#include <iostream>
using namespace std ;

class CpClass {
    private:
        int *p ;
    public:
        CpClass(int v = 0)
           { p = new int ; *p = v ; }
        ~CpClass()
           { delete p ; }

        int * getP()               // Added to we can see the pointer's value
           { return p ; }
} ;

void makeTwo() {

    CpClass c1(5) ;
    CpClass c2 = c1 ;

    // The two pointers are now pointing to the same object in the heap!
    cout << "The pointer to c1's int is " << c1.getP() << endl
         << "The pointer to c2's int is " << c2.getP() << endl << endl ;

    // What happens with c1 and c2 go out-of-scope?
}

int main() {

    makeTwo() ;                // Just call the function and (try to) exit
    return 0 ;
}
