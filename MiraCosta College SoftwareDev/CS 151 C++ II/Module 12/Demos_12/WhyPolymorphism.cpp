/* WhyPolymorphism.cpp - Demonstrate how polymorphism works (or doesn't work).
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Problem statement:  Show when polymorphism works and when it doesn't
 *
 * Algorithm:
 *   1. Create a Base class called "Car"
 *      1a. Provide a function named "className" which returns a string "a Car"
 *   2. Create a child class of Car named "Porsche"
 *      2a. Provide a function named "className" which returns a string "a Porsche"
 *   3. Create a child class of Porsche named "Spyder"
 *      3a. Provide a function named "className" which returns a string "a Spyder"
 *   4. Create a function named "whichObject":
 *      4a. It should take a pointer to an object of type Car
 *      4b. It should use the object to print the string returned by whichObject
 *   5. In main:
 *      5a. Create a Car, a Porsche, and a Spyder object
 *      5b. Call whichObject for each object
 *
 * Discussion:
 *   - Notice that each object passed in this case is anonymous (that means
 *     that it wasn't assigned to a variable
 *   - The argument of the function itself can be an object of the Car class or
 *     one of Car's derived classes.
 *      -- The function does not "see" any of the functions in derived classes
 *         of Car, but only those functions of the Car class itself
 *      -- Since the className fuction isn't virtual, C++ uses the version of
 *         the function in the Car class for the three function calls.
 *   - Finally, notice that the object is passed by reference
 *      -- Why wouldn't this work if we just passed a Car, Porsche, or Spyder
 *         object into the function instead of a pointer (hint: copies!)
 */

#include <iostream>
using namespace std ;

class Car {                     // grand parent class
    public:
        string className() {
            return "a Car" ;
        }
} ;

class Porsche : public Car {    // parent class
    public:
        string className() {
            return "a Porsche" ;
    }
} ;

class Spyder : public Porsche {  // child class
    public:
        string className() {
            return "a Spyder" ;
    }
} ;

void whichObject(Car *model) {
    cout << model->className() << endl ;
}

// Call the "whichObject" function by passing anonymous objects.  The compiler
// accepts the Porsche and Spyder objects as arguments to the function because
// of their "is-a" relationship with Car.
int main() {

    // Which model is which by just displaying the class name directly?
    cout << "Which model is the Spyder?  " << (Spyder()).className() << endl ;
    cout << "Which model is the Porsche? " << (Porsche()).className() << endl ;
    cout << "Which model is the Car?     " << (Car()).className() << endl << endl ;

    // Call a function which takes a Car parameter to do the same thing
    cout << "Which model is the Spyder?  " ;
    whichObject(new Spyder()) ;
    cout << "Which model is the Porsche? " ;
    whichObject(new Porsche()) ;
    cout << "Which model is the Car?     " ;
    whichObject(new Car()) ;

    return 0 ;
}

