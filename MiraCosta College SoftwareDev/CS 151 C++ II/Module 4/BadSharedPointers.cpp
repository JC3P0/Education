/* BadSharedPointers.cpp - What happens when shared counters are created poorly
 * Author:     Chris Merrill
 * Module:     4
 * Project:    Demonstration
 * Problem statement: Create two shared pointers to the same object inadvertantly
 *   by using an incorrect way to create the second pointer
 *
 * Algorithm:
 *   1. Create a "Widget" object in the heap, reference by a raw pointer
 *   2. From this raw pointer, create (initialize) a shared pointer
 *   3. From this raw pointer, create ANOTHER shared pointer (Yikes!)
 *   4. Reset the second shared pointer, which will clear the pointer
 *      and the object in the heap
 *   5. Reset the first shared pointer, which will clear the pointer
 *      and -- the object again???
 *
 * Discussion:
 *   * Instead of using the first shared pointer in the assignment statement for the
 *     second pointer, the raw pointer is used (similar to the way the first
 *     shared pointer is created).
 *   * This results in two shared pointer objects to the same Widget in the heap
 *   * The program aborts when the destructor to the Widget is called twice, causing
 *     a bad return code.
 */

#include <iostream>
#include <memory>                 // required for shared pointers
using namespace std ;

// Widget class has only a constructor and destructor
class Widget {
    public:
        Widget()
           { cout << "In Widget constructor" << endl ; }
        ~Widget()
           { cout << "In Widget destructor" << endl ; }
} ;

int main() {

    // Create a raw pointer to a Widget (calls the constructor)
    cout << "Creating a Widget and assigning to a raw pointer" << endl << endl ;
    Widget *raw_ptr = new Widget ;

    // Create a shared pointer to a Widget by using the raw pointer
    // (This is correct for the first shared pointer)
    shared_ptr<Widget> ptr_one(raw_ptr) ;
    cout << "Created shared pointer to a Widget" << endl
         << "Shared pointer 1 ->  count : " << ptr_one.use_count()
         << "  address: " << ptr_one << endl
         << "Raw pointer: " << raw_ptr << endl << endl ;

    // Create a second (shared) pointer to the Widget by using
    // the raw pointer (INCORRECT!)
    cout << "Creating another pointer to the Widget" << endl ;
    shared_ptr<Widget> ptr_two(raw_ptr) ;
    cout << "Shared pointer 1 ->  count: " << ptr_one.use_count()
         << "  address: " << ptr_one << endl
         << "Shared pointer 2 ->  count: " << ptr_two.use_count()
         << "  address: " << ptr_two << endl
         << "Raw pointer: " << raw_ptr << endl << endl ;

     // Reset the second pointer, which causes the Widget's destructor
     // to be called because the Widget is deleted
     cout << "Resetting shared pointer 2..." << endl ;
    ptr_two.reset() ;
    cout << "Shared Pointer 1 -> count: " << ptr_one.use_count()
         << "  address of 1: " << ptr_one << endl
         << "Shared Pointer 2 -> count: " << ptr_two.use_count()
         << "  address of 2: " << ptr_two << endl
         << "Raw pointer: " << raw_ptr << endl << endl ;

    // Reset the first pointer, which causes the program to abort
    // because the Widget's destructor is called again.
    cout << "Resetting shared pointer 1..." << endl ;
    ptr_one.reset() ;
    cout << "Shared Pointer 1 -> count: " << ptr_one.use_count()
         << "  address of 1: " << ptr_one << endl
         << "Shared Pointer 2 -> count: " << ptr_two.use_count()
         << "  address of 2: " << ptr_two << endl
         << "Raw pointer: " << raw_ptr << endl << endl ;

    return 0 ;
}
