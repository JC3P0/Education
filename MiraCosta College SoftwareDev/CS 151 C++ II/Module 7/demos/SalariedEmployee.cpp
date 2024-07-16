/* SalariedEmployee.cpp - Functional definitions for a salaried employee
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Description: Definitions for functions added by Employee class
 *
 *     default and full constructors
 *     getters and setters
 *     printCheck()
 */

#include <iostream>
#include <iomanip>
#include "SalariedEmployee.h"
using namespace std ;

// Constructors call setters of parent class, use assignment statement for this class
SalariedEmployee::SalariedEmployee() {
    setName("no name yet") ;
    setSSN("no number yet") ;
    salary = 0.0 ;
}

SalariedEmployee::SalariedEmployee(string name, string SSN,
                                   double weekly_salary ) {
    setName(name) ;
    setSSN(SSN) ;
    salary = weekly_salary ;
}

// Getters and setters for instance member of this class only
void SalariedEmployee::setSalary(double new_salary) {
    salary = new_salary ;
}

double SalariedEmployee::getSalary() const {
    return salary ;
}

// Print a check for employee's of this class
void SalariedEmployee::printCheck() {

    setNetPay(salary) ;

    cout << fixed << setprecision(2)
         << "\n----------------------------------------------\n"
         << "Pay to the order of " << getName() << endl
         << "The sum of " << getNetPay() << " Dollars\n"
         << "----------------------------------------------\n"
         << "Check Stub:  NOT NEGOTIABLE\n"
         << "Employee Number: " << getSSN() << endl
         << "Salaried Employee.    Regular Pay: $" << salary << endl
         << "==============================================\n" ;
}
