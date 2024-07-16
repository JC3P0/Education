/* MoveMe.cpp - Demonstrate move constructor
 * Author:     Chris Merrill
 * Module:     6
 * Project:    Demonstration
 * Problem statement:  Create a class with a several overloaded constructors, include
 *    a "move" constructor.  Add statements at the front of each which display which
 *    constructor is being entered.  Then show that when returning an object by
 *    value which is also a temporary value (rvalue), how a move constructor can save
 *    time.
 *
 * Algorithm:
 *    1. Create a "MoveMe" object using the no-argument constructor
 *    2. Create a "MoveMe" object using the full constructor (sets all three data
 *       members)
 *    3. Using the object from Step 2, create another object using the copy
 *       constructor
 *    4. Create another "MoveMe" object to be used to demonstrate the move constructor
 *    5. Using the object from Step 4, pass it to a function named "some_function"
 *       by value (uses the copy constructor), then return it to the calling program
 *       (uses the move constructor).
 *
 *    6. In the MoveMe class, create:
 *           -- a no-argument constructor
 *           -- a full constructor
 *           -- a copy constructor
 *           -- a destructor
 *           -- an overloaded assignment operator
 *           -- a move constructor
 *       In each constructor, identify which constructor is being run on the console
 */

#include <iostream>
using namespace std ;

// A class with default, copy, and move constructors, a destructor, and an
// overloaded assignment operator function

// Class definition
class MoveMe {
    private :
        double *array_ptr = nullptr ;             // pointer to an array of doubles
        int size = 0 ;                            // size of array
        string name = "" ;                        // name of the object

    public:
        MoveMe() ;                                // default constructor
        MoveMe(int, double, string) ;             // full constructor
        MoveMe(MoveMe &) ;                        // copy constructor
        ~MoveMe() ;                               // destructor
        MoveMe &operator=(const MoveMe &) ;       // overloaded assignment operator
        MoveMe(MoveMe &&) ;                       // move constructor

        string getName() { return name ; }
} ;

// Default constructor
MoveMe::MoveMe() {
    cout << "Entering default constructor (no parameters specified)" << endl ;
    array_ptr = new double[10] ;
    for (int i = 0 ; i < 10 ; i++)
        *(array_ptr + i) = 0.0 ;
    name = "(default)" ;
}

// Constructor (size and initial values specified)
MoveMe::MoveMe(int new_size, double value, string name) {
    cout << "Entering constructor for " << name
         <<", size " << new_size << ", value: " << value << endl ;
    array_ptr = new double[new_size] ;
    size = new_size ;
    for (int i = 0 ; i < new_size ; i++)
        *(array_ptr + i) = value ;
    this->name = name ;
}

// Copy constructor
MoveMe::MoveMe(MoveMe &source_object) {
    cout << "Entering copy constructor of " << source_object.name << endl ;
    size = source_object.size ;
    array_ptr = new double[size] ;
    for (int i = 0 ; i < size ; i++)
        *(array_ptr + i) = *(source_object.array_ptr + i) ;
    name = "copy of " + source_object.name ;
}

// Overloaded assignment operator
MoveMe &MoveMe::operator=(const MoveMe &right) {
    cout << "In the assignment statement copying: " << right.name << endl ;
    if (this != &right) {
        if (size > 0)
            delete[] array_ptr ;          // delete old array, if present
        size = right.size ;
        array_ptr = new double[size] ;
        for (int i = 0 ; i < size ; i++)
            array_ptr[i] = right.array_ptr[i] ;
    }
    return *this ;
}

// The "move" constructor moves the values of a temporary object (rvalue)
// into a new object and clears the values in the temporary object.
MoveMe::MoveMe(MoveMe && temp) {
    cout << "In the move constructor copying: " << temp.name << endl ;
    this->size = temp.size ;
    this->array_ptr = temp.array_ptr ;
    this->name = "temporary object (copy of " + temp.name + ")" ;

    temp.size = 0 ;             // remove vital information from parameter object
    temp.array_ptr = nullptr ;
}

// Destructor
MoveMe::~MoveMe() {
    cout << "In the destructor for: " << name << endl ;
    if (size > 0)
        delete[] array_ptr ;
}

// Just some function that both takes and returns an object by value.
// The call should invoke the copy constructor, and the return should
// invoke the move constructor
MoveMe some_function(MoveMe moveMe_object) {

    cout << "Inside the function" << endl
         << "Working on the object: " << moveMe_object.getName() << endl ;

    // This should invoke the move constructor (NOT the copy constructor)
    // since the moveMe_object is a temporary object (rvalue)
    cout << endl << "Preparing to return from function" << endl ;
    return moveMe_object ;
} ;

int main() {

    // Demonstrate the default constructor
    cout << "*** Running The default constructor ***" << endl ;
    MoveMe first ;                           // Demonstrate default constructor

    // Demonstrate the full constructor
    cout << endl << "*** Running the full constructor ***" << endl ;
    MoveMe second(100, 1.0, "second") ;

    // Demonstrate the copy constructor
    cout << endl << "*** The copy constructor ***" << endl ;
    MoveMe third(second) ;                  // Demonstrate copy constructor

    // Create a fourth object to be used for demonstrating calls to a function
    cout << endl << "*** Creating a test object to call a function ***" << endl ;
    MoveMe original(100, 5, "original") ;

    // Demonstrate everything that happens when calling a function and the
    // assignment operator. The function both takes an object and returns an object.
    // Passing by value into the function should call the copy constructor
    // Returning by value from the function should call the move constructor, since
    // the object being returns is a (temporary) copy of the original.
    cout << endl << "*** Calling the function ***" << endl ;
    first = some_function(original) ;
    cout << "Returned from function" << endl ;

    cout << endl << "Ending program" << endl ;

    return 0 ;
}
