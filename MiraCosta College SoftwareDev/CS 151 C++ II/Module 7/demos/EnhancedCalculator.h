/* EnhancedCalculator.h - Header file for a enhanced calculator doing division
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Description:
 *
 *   Functions for:
 *        full constructor (uses setters to set values in BasicCalculator)
 *        division
 */

#ifndef ENHANCED_CALCULATOR_H
#define ENHANCED_CALCULATOR_H

#include "BasicCalculator.h"
using namespace std ;

class EnhancedCalculator : public BasicCalculator {

    public:
        EnhancedCalculator(double left, double right) {        // full constructor
            set_left(left) ;
            set_right(right) ;
        }

        // The missing arithmetic function
        double division()
            { return get_left() / get_right() ; }
} ;

#endif
