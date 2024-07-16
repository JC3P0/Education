/* UniquePointerMovement.cpp - Moving an object from one unique pointer to another
 * Author:     Chris Merrill
 * Module:     4
 * Project:    Demonstration
 * Problem statement:  Demonstrate moving a Simple structure object from one unique pointer
 *        to another.
 * Algorithm:
 *    1.  Create a Simple (structure) object and assign to a unique pointer
 *    2.  Try to assign to another raw pointer
 *    3.  Try to assign to another unique pointer
 *    4.  Try moving to another unique pointer
 *        4a. Show old and new values of each pointer
 *    5.  Assign the object to a raw pointer (dangerous)
 *        5a.  Now use the RAW pointer to delete from the heap -- YIKES
 *        5b.  Try to run the program with the delete message commented / uncommented
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
    cout << "Creating one unique pointer, value 5" << endl ;
    unique_ptr<Simple> my_ptr(new Simple(5)) ;

    // Can we reset the pointer?
    // my_ptr = new Simple(11) ;

    // Can we re-assign it to another pointer?
    // my_ptr = new Simple(25) ;

    // Let's create another pointer, then move first to second
    cout << "\nCreating second unique pointer, value 17" << endl ;
    unique_ptr<Simple> your_ptr(new Simple(17)) ;

    // Now move the first into the second
    cout << "\nMoving first pointer to second" << endl ;
    your_ptr = move(my_ptr) ;

    // Is the first pointer empty?
    cout << endl ;
    cout << "The first pointer is " << (my_ptr ? "not " : "") << "empty" << endl ;
    cout << "The second pointer is " << (your_ptr ? "not " : "") << "empty" << endl ;
    if (your_ptr)
        cout << "The second pointer references Simple Task with value " << your_ptr->value  ;
    cout << endl << endl ;

    // Can we get the address of the object and put into a raw pointer?
    Simple *raw_ptr = your_ptr.get() ;
    cout << endl ;
    cout << "The raw pointer references Simple Task with value " << raw_ptr->value << endl ;;
    cout << "The address of the raw pointer is: " << raw_ptr << endl ;

    // delete raw_ptr ;     // YIKES  DON'T DO THIS!!!!!
                            // C++ will also try to de-allocate by releasing your_ptr.
                            // Blows up on repl.it, not on Dev-C++
    
    cout << "Just use the raw pointer to delete memory still allocated to your_ptr..." << endl ;
    cout << "The your_ptr references Simple Task value " << your_ptr->value << endl << endl ;

    return 0 ;
}


