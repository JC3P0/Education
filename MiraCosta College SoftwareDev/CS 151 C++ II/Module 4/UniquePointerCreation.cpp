/* UniquePointerCreation.cpp - What happens when creating and deleting a unique pointer to a structure
 * Author:     Chris Merrill
 * Module:     4
 * Project:    Demonstration
 * Problem statement:  Demonstrate creating (with constructor) and deletion (with destructor) of
 *    a structure
 * Algorithm:
 *   1.  Create a structure named "Simple" with one int value, a constructor that sets that
 *       value and displays a message, and a destructor that displays a message
 *   2.  In main, create a unique pointer to a Simple structure, setting its value to 5.
 *       2a. Verify that the message in the constructor is displayed
 *   3.  Create another unique pointer to a Simple structure with a value of 17.
 *       3a. Verify that the message in the constructor is displayed.
 *   3.  Reset the unique pointer with a value of 5 (clearing that objects)
 *       3a. Verify that the message in the destructor is displayed
 *   4.  Pause
 *   5.  When the program terminates, ensure that the destructor of the Simple structure
 *       with a value of 17 is displayed.
 */

#include <iostream>
#include <memory>                       // needed for unique pointers
using namespace std ;

// Create a simple structure with a constructor and destructor
struct Simple {

    int value ;
    Simple(int new_value) {
        value = new_value ;
        cout << "In the constructor of Simple with value " << value << endl ;
    }
    ~Simple() {
        cout << "In the destructor of Simple with value " << value << endl ;
    }
} ;

int main() {

    // Create a new unique pointer and assign to a new structure
    unique_ptr<Simple> ptr_to_5(new Simple(5)) ;
    unique_ptr<Simple> ptr_to_17(new Simple(17)) ;

    //Access the element through unique_ptr
    cout << "The Simple structure 5 has a value:  " << ptr_to_5->value << endl ;
    cout << "The Simple structure 17 has a value: " << ptr_to_17->value << endl ;

    // Delete the structure
    ptr_to_5.reset() ;

    return 0 ;
}
