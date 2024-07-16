/* Clownfish.cpp - Implementation details for Clownfish file
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Description: Implementation of "quote" function for what a clownfish says
 */

#include <iostream>
#include "Clownfish.h"
using namespace std ;

// Can't specify "override" here, since it's a virtual specifier
// Must specify "const" here and in declaration
void Clownfish :: quote() const {
    cout << "Nemo says: I shall call him Squishy and he shall be mine" << endl
         << "           and he shall be my Squishy. Come on, Squishy." << endl
         << "           Come on, little Squishy." << endl ;
}
