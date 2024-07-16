/* MultipleInheritance.cpp - How to implement, order of constructors
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Problem statement:  Create an example of multiple inheritance, show
 *    how to implement, and the order in which multiple constructors
 *    are called:
 *
 * Credits: Geeks for Geeks
 *
 * Algorithm:
 *   1. Create two parent classes A and B which each:
 *      1a. Have a constructor that identifies which constructor is being run
 *      1b. Define an int variable named "x"
 *      1c. Assign x to different values in class A and B
 *  2.  Define a class C with both B and A as parents:
 *
 *            class C : public class B, class A
 *
 *      Also create a function named showX which displays the value of the
 *      variable "x" (inherited from both parents)
 *
 *   3. In main, create an object of type C
 *      3a. Observe how parent classes are called.
 *      3b. Call the showX function
 *
 * Discussion:
 *    - Won't compile as is
 *      -- Comment out one of the definitions of the 'x' variable
 *    - Parent constructors are called first (in order B, then A)
 *      Then the child's constructor is called
 *    - What happens if we reverse the order of the parents in the class C
 *      definition?
 *
 *    Multiple inheritance is often discouraged for this very reason.
 *
 *              It can be very confusing!
 *
 *    It also can be very powerful, as demonstrated in the iostream class
 *    which inherits both istream and ostream!
 */

#include <iostream>
using namespace std ;

class A {
    public:
        A()
            { cout << "A's constructor called" << endl ; }
        int x = 12 ;
} ;

class B {
    public:
        B()
            { cout << "B's constructor called" << endl ; }
        int x = 5 ;
} ;

class C : public B, public A { // Note the order
    public:
        C()
            { cout << "C's constructor called" << endl ; }
        void showX ()
            { cout << "Value of x is " << x << endl ; }
} ;

int main() {

    C c ;
    c.showX() ;

    return 0 ;
}
