/* AbstractAnimals.cpp - Demonstrate use of pure virtual function
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Problem statement:  Demonstrate a pure virtual (abstract) function
 *   in a parent class,
 *
 * Algorithm:
 *   1. Create a class named "Animal" with a pure virtual function:
 *
 *                        virtual void quote() const = 0
 *
 *      1a. Animal.h will have the virtual function defined.  No implementation
 *          (.cpp) file needed, since there aren't any functions to implement.
 *
 *   2. Create child classes Dog, Cat, and Clownfish.
 *      2a. Each child class will print something on the console that a typical
 *          animal of that class would say
 *      2b. Both the heading in the .h file and the actual implementation of the
 *          function in the .cpp file should have "const" in the heading
 *      2c. Only the .h file should indicate "override" at the end of its heading
 *          and "virtual" at the beginning of its heading
 *   3. In main, create an object of each child class and execute its "quote"
 *      function
 *
 * Discussion:
 *   -> Broke out classes into separte .h and .cpp file, since we
 *      haven't done that in a while.
 *   -> Use of the "override" modifier in all headings in subclasses
 *      -- It does NOT appear in the definition files, only the declarations
 *   -> The "virtual" in subclasses is unnecessary, but good practice
 */

#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Clownfish.h"
using namespace std ;

int main() {

    // Create one of each type of animal and make a noise
    Dog zeke ;
    zeke.quote() ;

    Cat garfield ;
    garfield.quote() ;

    Clownfish nemo ;
    nemo.quote() ;

    cout << endl ;

    return 0 ;
}
