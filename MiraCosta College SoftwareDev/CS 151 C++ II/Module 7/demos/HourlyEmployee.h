/* HourlyEmployee.h - Header for hourly employees
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Description: The derived class for an hourly employee from the Employee class
 *
 *       Adds wage_rate and hours data members, constructor, getters and setters,
 *       and a "printCheck" function
 */

#ifndef HOURLY_EMPLOYEE_H
#define HOURLY_EMPLOYEE_H

#include "Employee.h"
using namespace std ;

class HourlyEmployee : public Employee {

    private:
        double wage_rate ;
        double hours ;

    public:
        HourlyEmployee() ;
        HourlyEmployee(string, string, double, double) ;   // name, SSN, name, hours, rate
        void setRate(double) ;
        double getRate() const ;
        void setHours(double) ;
        double getHours() const ;
        void printCheck() ;

} ;

#endif
