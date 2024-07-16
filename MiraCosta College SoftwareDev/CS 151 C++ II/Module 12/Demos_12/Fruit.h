/* Fruit.h - Parent class to Orange and Strawberry
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Exercise 2
 * Description:
 *
 *    Instance variables:
 *       (bool) isRipe - true if this object is ripe
 *
 *    Functions:
 *       Constructor
 *       getter and setter for instance variable
 *       prepare - prints a message to prepare the <ripe> Fruit
 */

#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>
using namespace std ;

class Fruit {

    private:
        bool is_ripe = false ;           // Lone data member

    public:
        // Constructor has one parameter to record whether it is ripe.
        Fruit(bool is_ripe) : is_ripe(is_ripe) { }
        bool getIsRipe() const
            { return is_ripe ; }
        void prepare() {
            cout << "Prepare the "
                 << (is_ripe ? "ripe " : "")
                 << "fruit" << endl ;
        }
} ;

#endif
