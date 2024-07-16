/* Employee.cpp - Parent to SalariedEmployee and HourlyEmplyee
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Description:
 *
 *    Function implementations for:
 *       default, partial, and full constructor
 *       G\getters and setters
 *       printCheck (shouldn't be used)
 */

#include <iostream>
#include "Employee.h"
using namespace std ;

// Constructors use member initialization
Employee::Employee() :       // default constructor
    name("no name yet"),
    ssn("no number yet"),
    netPay(0) { } ;

Employee::Employee(string name, string SSN) :    // partial
    name(name),
    ssn(SSN),
    netPay(0) { } ;

Employee::Employee(string name, string SSN, double net_pay) :   // full
    name(name),
    ssn(SSN),
    netPay(net_pay) { } ;

// Getters
string Employee::getName() const {
    return name ;
}

string Employee::getSSN() const {
    return ssn ;
}

double Employee::getNetPay() const {
    return netPay ;
}

// Setters
void Employee::setName(string newName) {
    name = newName ;
}

void Employee::setSSN(string newSSN) {
    ssn = newSSN ;
}

void Employee::setNetPay(double newNetPay) {
    netPay = newNetPay ;
}

// Shouldn't use this -- use only printCheck for hourly or salaried employee
void Employee::printCheck() {
     cout << "\nERROR: printCheck function called for an "
          << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n" ;
     exit(1) ;
}
