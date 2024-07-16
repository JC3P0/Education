/* HourlyEmployee.cpp - Functional definitions for an hourly employee
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Description:
 *
 *   Functional definitions for
 *     default and full constructors
 *     getters and setters for hours and pay rate
 *     printCheck()
 */

#include <iostream>
#include <iomanip>
#include <locale>
#include "HourlyEmployee.h"
using namespace std ;

// Constructors use setters in parent, assignment statement in this class
HourlyEmployee::HourlyEmployee() {
    setName("no name yet") ;
    setSSN("no number yet") ;
    wage_rate = 0.0 ;
    hours = 0.0 ;
}

HourlyEmployee::HourlyEmployee(string name, string SSN,
                               double wage_rate, double hours ) {

    setName(name) ;
    setSSN(SSN) ;
    this->wage_rate = wage_rate ;
    this->hours = hours ;
}

// Setters and getters
void HourlyEmployee::setRate(double new_wage_rate) {
    wage_rate = new_wage_rate ;
}

double HourlyEmployee::getRate() const {
    return wage_rate ;
}

void HourlyEmployee::setHours(double hours_worked) {
    hours = hours_worked ;
}

double HourlyEmployee::getHours() const {
    return hours ;
}

// Print a check for an hourly employee.  (First set pay amount in Employee)
void HourlyEmployee::printCheck() {

    setNetPay( hours * wage_rate ) ;

    cout << setprecision(2) << fixed
         << "\n----------------------------------------------\n"
         << "Pay to the order of " << getName() << endl
         << "The sum of " << getNetPay() << " Dollars\n"
         << "----------------------------------------------\n"
         << "Check Stub:  NOT NEGOTIABLE\n"
         << "Employee Number: " << getSSN() << endl
         << "Hourly Employee.  \nHours worked: " << setprecision(1) << hours
         << "  Rate: $" << setprecision(2) << wage_rate
         << "  Pay: $" << getNetPay() << endl
         << "==============================================\n" ;
}
