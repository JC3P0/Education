/* Animal.h - Declaration of an abstract base class
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Description:
 *
 *     Animal class is the (abstract) parent to Dog, Cat, and Clownfish
 *
 *         pure virtual function " void quote() const "
 *
 *     No definition file needed for Animal, since all functions are abstract
 */

using namespace std ;

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
    public:

        // Definition of this function must be in all concrete classes
        virtual void quote() const = 0 ;
} ;

#endif
