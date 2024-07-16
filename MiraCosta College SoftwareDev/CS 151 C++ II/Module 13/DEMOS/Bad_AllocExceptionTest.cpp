/* Bad_AllocExceptionTest.cpp - Create an array too large for the heap
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Demonstration
 * Problem statement:  Demonstrate the bad_alloc exception which
 *   is thrown when the new operator fails to allocate memory.
 *
 * Algorithm:
 *   1. Create an array of 100 double pointers
 *   2. Using a for-loop, allocate arrays of 1 billion doubles from the heap until
 *      no more arrays can be created
 *      1a. When that happens, a "bad_alloc" exception will be thrown
 *    
 * Discussion:
 *   * Must include "new" (contains "bad-alloc" data type definition)
 *   * Can also occur when heap becomes severely segmented
 */

#include <iostream>
#include <new>                // Needed for bad_alloc
using namespace std ;

int main() {

    double *ptr[100] ;       // Should declare outside of try block

    try {
        for (int i = 1 ; i <= 100 ; i++) {
            ptr[i] = new double [1000000000] ;      // one billion doubles
            cout << "Allocated block " << i << endl ;
        }
    }
    catch (bad_alloc) {
        cout << "Insufficient memory.\n" ;
    }

    return 0 ;
}

