/* Polymorphism.cpp - Change the "WhyPolymorphism" program to use polymorphism
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Problem statement:  Change the function to be "virtual", so that polymorphism
 *    can work (dynamic binding).
 *
 * Algorithm:
 *  1. Start with the "WhyPolymorphism" demonstration
 *  2. Make the function "virtual"
 *  3. Observe that now the function now uses the object type, rather than
 *     the variable type, to determine which version of a function to use
 *  4. Make another version of the function which passes the variable
 *     by reference
 *     4a. Verify that polymorphism still works
 *
 * Discuss 2 ways to call a function, by value and by reference
 *   - Each case works because the function itself is virtual.
 */

#include <iostream>
using namespace std ;

// Defining the base class function as virtual enables dynamic binding for
// that function
class Car {                     // grand parent class
    public:
        virtual string className() {
            return "a Car" ;
        }
} ;

class Porsche: public Car {     // parent class
    public:
        virtual string className() {
            return "a Porsche" ;
    }
} ;

class Spyder: public Porsche {  // child class
    public:
        string className() {
            return "a Spyder" ;
    }
} ;

// First option:
//    The variable referencing the object must contain the address
//    of the object when the function is invoked for each class.
void whichObjectPointer(Car *model) {
    cout << model->className() << endl ;
}

// Second option:
//     The variable referencing the object is passed by reference
void whichObjectReference(Car &model) {
    cout << model.className() << endl ;
}

// Change the three calls to "whichObject" to call a virtual function, first
// passing values by pointer, then passing by reference.
int main() {

    // Have to assign pointer to each call, otherwise using an rvalue with &
    Spyder spyder = Spyder() ;
    Porsche porsche = Porsche() ;
    Car car = Car() ;

    // First demonstrate pass by pointer
    cout << "Pass by pointer:"<< endl ;
    whichObjectPointer(&spyder) ;
    whichObjectPointer(&porsche) ;
    whichObjectPointer(&car) ;

    // Now demonstrate passing by reference
    cout << endl << "Pass by reference:" << endl ;
    whichObjectReference(spyder) ;
    whichObjectReference(porsche) ;
    whichObjectReference(car) ;

    return 0 ;
}


