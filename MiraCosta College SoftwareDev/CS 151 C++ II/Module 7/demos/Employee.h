/* Employee.h - Base class for hourly and salaried employees
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Description:
 *
 *   Data members:
 *       name (string)
 *       ssn (Social Security Number) int
 *       netPay (double)
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std ;

class Employee {

   private:
       string name ;
       string ssn ;
       double netPay ;

   public:
       Employee() ;
       Employee(string, string) ;
       Employee(string, string, double) ;
       string getName() const ;
       string getSSN() const ;
       double getNetPay() const ;
       void setName(string) ;
       void setSSN(string) ;
       void setNetPay(double) ;
       void printCheck() ;

} ;

#endif
