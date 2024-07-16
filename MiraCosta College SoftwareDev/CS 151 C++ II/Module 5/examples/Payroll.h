/* Payroll.h - File definition for Payroll class
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Description: Is a "friend" of the Employee class, so it can use
 *    all functions in that class
 *
 *    Instance variables:
 *        EmployeeData employee
 */

#ifndef PAYROLL_H
#define PAYROLL_H

#include <string>
#include "EmployeeData.h"
using namespace std ;

class Payroll {

    public:
        Payroll( EmployeeData theEmployeeData ) ;  // one-arg constructor
        void writeCheck() ;

    private:
        EmployeeData employee ;

        // NOTE: We get access to the EmployeeData salary and SSN information
        //       because the Payroll class is a friend of the EmployeeData class
} ;

// one-arg constructor
Payroll::Payroll( EmployeeData theEmployee ) {
    employee = theEmployee ;
}

void Payroll::writeCheck() {
    cout << "Name: " << employee.getName() << "  "
         << "Badge: " << employee.getBadge() << "  "
         << "Monthly Wages: " << (employee.getSalary() / 12.0) << "  "
         << "SSN: " << employee.getSSN() << endl << endl ;
}

#endif
