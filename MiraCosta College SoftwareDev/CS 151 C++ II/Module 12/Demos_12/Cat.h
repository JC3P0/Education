/* Cat.h - Declaration of Cat class
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Description: Just use a header file (no .cpp file) for Cats
 */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"
using namespace std ;

// Looks just like Dog.h
class Cat : public Animal {
    public:
        virtual void quote() const override
            { cout << "Garfield says: I randomly refuse to follow orders" << endl
                   << "               just to prove that I can." << endl << endl ; }
} ;

#endif
