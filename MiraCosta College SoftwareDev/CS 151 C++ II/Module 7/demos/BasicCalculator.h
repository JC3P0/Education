/* BasicCalculator.h - Header file for a basic calculator doing +, -, and *
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Description:
 *
 *   Instance data members for
 *        left_operand (double) - operand on left side of +, -, or *
 *        right_operand (double) - operand on right side of +, -, or *
 *
 *   Functions for
 *        full constructor
 *        getters for both operands
 *        addition
 *        subtraction
 *        multiplication
 */

#ifndef BASIC_CALCULATOR_H
#define BASIC_CALCULATOR_H

using namespace std ;

class BasicCalculator {

    // properties are left and right operands
    private:
        double left_operand = 0.0,
               right_operand = 0.0 ;

    public:

        // Constuctors
        BasicCalculator()                                   // default constuctor
            { left_operand = right_operand = 0.0 ; }
        BasicCalculator(double left, double right) {        // full constructor
            left_operand = left ;
            right_operand = right ;
        }

        // Getters and setters
        double get_left() const
            { return left_operand ; }
        double get_right() const
            { return right_operand ; }
        void set_left(const double new_left)
            { left_operand = new_left ; }
        void set_right(const double new_right)
            { right_operand = new_right ; }

        // Arithmetic operators (excluding division)
        double addition()
            { return left_operand + right_operand ; }
        double subtraction()
            { return left_operand - right_operand ; }
        double multiplication()
            { return left_operand * right_operand ; }
} ;

#endif
