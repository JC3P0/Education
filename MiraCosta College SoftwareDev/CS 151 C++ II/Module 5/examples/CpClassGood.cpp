/* CpClassGood.cpp - LAdding a copy constructor removes the problem
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Problem Statement:  The copy constructor makes a new object in the
 *    heap, rather than just copying the pointer.
 *
 * Algorithm:
 *   1. Demonstrate the sample (new-and-improved) program in the lecture
 *   2. Copy constructor is added which creates a new object in the heap
 *      rather than just copying the value of the pointer from one
 *      CpClass object to another
 */

#include <iostream>
using namespace std ;

class CpClass {
    private:
        int *p ;
    public:

        // The new-and-improved copy constructor
        CpClass(const CpClass &obj)
          { p = new int ; *p = *obj.p ; }

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
         << "The pointer to c2's int is " << c2.getP() << endl ;

    // What happens with c1 and c2 go out-of-scope?
}

int main() {

    makeTwo() ;                // Just call the function and (try to) exit
    return 0 ;
}
