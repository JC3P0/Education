/*______________________________________
* FILE: HW_12_SEQUENCE_SUM_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 12
* PROJECT: 2
* LAST MODIFIED: November 13, 22
* PROBLEM STATEMENT: Uses AbstractSeq class with fun(int) pure virtual member function to be used in derived classes to output and process a sequence of numbers.
* ALGORITHM:
*    INITIALIZE AbstractSeq class with pure virtual function fun(int) that prints a sequence of numbers and processes them by derived classes. Also uses sumSeq to add the sum of two locations in the sequence.
 *    INITIALIZE Odds and Factorial derived classes to return odd and factorials of the sequence of numbers called.
 *    INITIALIZE class objects to process a sequence of numbers
 *    CALCULATE with AbstractSeq class sumSeq function the sum from two locations in the sequence to be added together
 *    CALCULATE fun(int) per object class definition
 *    OUTPUT original (n) and calculated fun(n) sequence of numbers
 *    OUTPUT the sum of sumSeq
*______________________________________*/

#include <iostream>
#include <iomanip>
#include "Odds.h"
#include "Factorial.h"
using namespace std;

int main() {

    //create class objects
    AbstractSeq *objOne = new Odds;
    AbstractSeq *objTwo = new Factorial;

    cout << "Odd numbers fun(3) to fun(12) are:\n";
    //use setw to align columns
    cout << setw(9) << "n" << right << setw(12) << "fun(n)" << endl;
    cout << setw(11) << "-----" << right << setw(12) << "----------" << endl;
    //call printSeq uses Odds class fun(int) function
    objOne->printSeq(3, 12);
    cout << "The sum of Odds fun(7) to fun(10) is: " << objOne->sumSeq(7, 10) << endl;

    cout << "\nFactorial numbers from fun(0) to fun(10) are:\n";
    //use setw to align columns
    cout << setw(9) << "n" << right << setw(12) << "fun(n)" << endl;
    cout << setw(11) << "-----" << right << setw(12) << "----------" << endl;
    //call printSeq uses Factorial class fun(int) function
    objTwo->printSeq(0, 10);
    //output the sum of 4 through 6
    cout << "The sum of Factorial fun(4) to fun(6) is: " << objTwo->sumSeq(4, 6) << endl;

    return 0;
}
