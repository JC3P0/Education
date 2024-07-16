/* Clownfish.h - Declaration of Clownfish class
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Description:
 *     This class uses a header and an implementation file.  The Dog and Cat
 *     classes consolidate into a single (.h) file
 */

#ifndef CLOWNFISH_H
#define CLOWNFISH_H

#include "Animal.h"
using namespace std ;

// Looks just like Dog.h and Cat.h
class Clownfish : public Animal {
    public:
        virtual void quote() const override ;
} ;

#endif
