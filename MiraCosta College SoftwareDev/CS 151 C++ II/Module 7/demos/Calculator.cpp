/* Calculator.cpp - Provides addition, subtraction, multiplication, and division
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Problem statement: Create a BasicCalculator class with addition, subtraction, and
 *    multiplication functions.  Derive an EnhancedCalculator with division function.
 *
 * Algorithm:
 *    1. Create a BasicCalculator class that provides function for addition, subtraction,
 *       and multiplication of two double values
 *       1a. Constructor will take and save two doubles
 *       1b. "addition" function returns their sum
 *       1c. "subtraction" function reuturns their difference
 *       1d. "multiplication" function returns their product 
 *    2. Derive an EnhancedCalculator class From BasicCalculator
 *       2a. "divide" function returns the quotient of the two data members
 *    3. In main, create a BasicCalculator object and show that addition, subtraction,
 *       and multiplication are available, but that divide isn't available
 *    4. Create an EnhancedCalculator object and show that all four functions
 *       are available.
 *
 * Discussion:
 *    1. Uncomment the line and try division using BasicCalculator
 *    2. Needed to use getters in child class division function
 *       -- left_operand an right_operand are private in BasicCalculator
 *    3. All getters, setters, and addition, subtraction, and multiplication are
 *       inherited from BasicCalculator by EnhancedCalculator
 *    4. Notice that without the default constructor in BasicCalculator, the
 *       program doesn't compile (to be explained later).
 */

#include <iostream>
#include "BasicCalculator.h"
#include "EnhancedCalculator.h"
using namespace std ;

int main() {

    // Create a BasicClass object, then add, subtract, and multiply two numbers
    BasicCalculator basic(11.0, 5.8) ;
    cout << "Using BasicCalculator with operands "
         << basic.get_left() << " and " << basic.get_right() << endl << endl
         << "   addition:       " << basic.addition() << endl
         << "   subtraction:    " << basic.subtraction() << endl
         << "   multiplication: " << basic.multiplication() << endl
//         << "   division:       " << basic.division() << endl
         << endl << endl ;

    // Create a EnhancedCalculators object, then add, subtract, multiply,
    // and division two numbers
    EnhancedCalculator enhanced(11.0, 5.8) ;
    cout << "Using EnhancedCalculator with operands "
         << enhanced.get_left() << " and " << enhanced.get_right() << endl << endl
         << "   addition:       " << enhanced.addition() << endl
         << "   subtraction:    " << enhanced.subtraction() << endl
         << "   multiplication: " << enhanced.multiplication() << endl
         << "   division:       " << enhanced.division()
         << endl << endl ;

    return 0 ;
}

