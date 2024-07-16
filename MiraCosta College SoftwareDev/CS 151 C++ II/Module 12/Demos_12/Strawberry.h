/* Strawberry.h - Child of Fruit, no data members, a "prepare" function
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Exercise 2
 * Description: Definition of "Strawberry" class
 *
 *   Constructor simply calls constructor for Fruit to set "is_ripe"  Also has
 *      an (overridden) prepare function.
 */

#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include "Fruit.h"
using namespace std ;

class Strawberry : public Fruit {

    public :
        Strawberry(bool is_ripe) : Fruit(is_ripe) { }   // lone constructor

        void prepare() {
            cout << "Dipping the "
                 << (getIsRipe() ? "ripe " : "")
                 << "strawberry in chocolate" << endl ;
        }

} ;

#endif

