/* SalariedEmployee.h - Header for salaried employees
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Description: The derived class for a salaried employee from the Employee class
 *
 *     Adds a "salary" data member field
 *
 *     Adds constructors, getter and setter for salary, and printCheck headers
 */

#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H

#include "Employee.h"
using namespace std ;

class SalariedEmployee : public Employee {

    private:
        double salary ;   //weekly pay rate

    public:
        SalariedEmployee() ;
        SalariedEmployee(string, string, double) ;      // name, ssn, pay rate
        void setSalary(double) ;
        double getSalary() const ;
        void printCheck() ;
} ;

#endif
