/* Orange.h - Child of Fruit, one data member (variety), prepare function
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Exercise 2
 * Description:
 *
 *    Instance variables:
 *       (string) variety - the variety of the orange
 *
 *    Functions:
 *       Constructor
 *       prepare - prints a message to prepare the <ripe> <variety> orange
 */

#ifndef ORANGE_H
#define ORANGE_H

#include <iostream>
#include "Fruit.h"
using namespace std ;

class Orange : public Fruit {

    private:
        string variety ;

    public:
        Orange(bool is_ripe, string variety) :
            Fruit(is_ripe), variety(variety) { }

        void prepare() {
            cout << "Peeling and preparing the "
                 << (getIsRipe() ? "ripe " : "")
                 << variety
                 << " orange" << endl ;
        }
} ;

#endif
