/* SharedPointers.cpp - Demonstrate counting used by shared pointers
 * Author:     Chris Merrill
 * Module:     4
 * Project:    Demonstration
 * Problem statement: Create two shared pointers to the same Widget
 *    object.  Demonstrate counts internal to the pointer.  What happens
 *    when pointers are created and when pointers are deleted.
 *
 * Algorithm:
 *   1. Create a "Widget" object in the heap, reference by a raw pointer
 *   2. From this raw pointer, create (initialize) a shared pointer
 *   3. From this shared pointer (NOT the raw pointer), create ANOTHER shared 
 *      pointer (this should be ok)
 *   4. Reset the second shared pointer, which will clear the pointer, but
 *      leave the first shared pointer intact
 *   5. Reset the first shared pointer, which will clear the pointer
 *      delete the object from the heap
 *
 * Discussion:
 *   1. Create a Widget class with a constructor and destructor
 *   2. Creating the first pointer calls the Widget constructor
 *   3. Creating a second pointer just ups the counter in the shared
 *      pointer object
 *   4. The Widget destructor is called when the first pointer is
 *      reset (when the count of pointers to the Widget goes to 0)
 */

#include <iostream>
#include <memory>                 // required for shared pointers
using namespace std ;

// Widget class has only a constructor, destructor, and int value
class Widget {
    public:
        Widget()
           { cout << "In Widget constructor" << endl ; }
        ~Widget()
           { cout << "In Widget destructor" << endl ; }

        int value ;
} ;

int main() {

    // Create a shared pointer to a Widget created from the heap
    // (This is currently the only pointer to the Widget)
    shared_ptr<Widget> ptr_one(new Widget) ;
    cout << "Created shared pointer to a Widget" << endl
         << "Shared pointer 1 ->  count : " << ptr_one.use_count()
         << "  address: " << ptr_one << endl << endl ;

    // Use this pointer to access and change values of the Widget just
    // like a raw pointer
    ptr_one->value = 52 ;

    // Create a second (shared) pointer to the Widget the correct way
    shared_ptr<Widget> ptr_two = ptr_one ;
    cout << "Creating another pointer to the Widget" << endl
         << "Shared pointer 1 ->  count: " << ptr_one.use_count()
         << "  address: " << ptr_one << endl
         << "Shared pointer 2 ->  count: " << ptr_two.use_count()
         << "  address: " << ptr_two << endl << endl ;

    // Delete the second pointer
    ptr_two.reset() ;
    cout << "Resetting shared pointer 2..." << endl
         << "Shared Pointer 1 -> count: " << ptr_one.use_count()
         << "  address of 1: " << ptr_one << endl
         << "Shared Pointer 2 -> count: " << ptr_two.use_count()
         << "  address of 2: " << ptr_two << endl << endl ;

    // Delete the first pointer
    ptr_one.reset() ;
    cout << "Resetting shared pointer 1..." << endl
         << "Shared Pointer 1 -> count: " << ptr_one.use_count()
         << "  address of 1: " << ptr_one << endl
         << "Shared Pointer 2 -> count: " << ptr_two.use_count()
         << "  address of 2: " << ptr_two << endl ;

    return 0 ;
}
