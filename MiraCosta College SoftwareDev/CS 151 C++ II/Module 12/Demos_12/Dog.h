/* Dog.h - Declaration of Dog class
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Description: Just use a header file (no .cpp file) for Dogs
 */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"
using namespace std ;

// Looks just like Cat.h
class Dog : public Animal {
    public:
        virtual void quote() const override
            { cout << "My dog says: Play with me 6 hours a day"
                   << " or I'll chew on the couch." << endl << endl ; }
} ;

#endif
