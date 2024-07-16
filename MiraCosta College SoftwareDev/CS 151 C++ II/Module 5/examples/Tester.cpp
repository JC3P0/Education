/* Tester.cpp - Demo the use of the friend functionality in C++.
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Problem statement: The EmployeeData objects are accessible to several departments
 *    in the company. However we only want to expose salary information to
 *    the Accounting department that uses this data to create paychecks. If the
 *    EmployeeData had public set and get functions for these then EVERYONE could
 *    access the data (which is not what we want).
 *
 * Algorithm:
 *   1. Create an EmployeeData class (put everything in .h file)
 *      1a. Make name and age (through associated functions) available to all
 *          departments in the company
 *      1b Make the SSN and the salary data private, but available to the Payroll department
 *          by making Payroll a friend of this class.
 *   2. Create a Payroll class
 *      2a. Have as its sole data member an EmployeeData object
 *      2b. Create a constructor which takes an EmployeeData object as its
 *          sole parameter
 *      2c. Also create a function that prints a simple paycheck for the employee
 *   3. In main (in this class), create several EmployeeData objects and print their
 *      paychecks
 *
 * Discussion:
 *   - What happens when we don't make Payroll a friend of the EmployeeData class?
 *   - Note that the function to print a paycheck has to be in the Payroll class,
 *     since sensitive employee data is not directly available to this class.
 *   - Uncomment the code at the bottom of Tester.cpp.  It doesn't compile because
 *     it is not a "friend" of EmployeeData.
 *   - Unfortunately we cannot make only the writeCheck function a friend of the
 *     Employee class in a separate file without more work...
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "EmployeeData.h"
#include "Payroll.h"
using namespace std ;

// function prototypes
void display( EmployeeData employeeData[], int numEmployees ) ;

int main() {

    int numEmployees = 5 ;

    // create and fill an array of EmployeeData objects
    EmployeeData employeeArray[5] = { EmployeeData("Bob", 25, 30000, 112233),
                                      EmployeeData("Carol", 30, 42000, 443322),
                                      EmployeeData("Ted", 28, 34000, 336644),
                                      EmployeeData("Alice", 32, 35000,998877),
                                      EmployeeData("Joe", 24, 40000,264214) } ;

    // display the contents of the employee data array
    // Note: the Payroll.writeCheck() function can access the salary info
    //       because it is a friend of the EmployeeData class even though the
    //       the salary is declared a private class members.
    cout << "\nPrinting the data for the Employee array:" << endl << endl ;
    for(int i = 0 ; i < numEmployees ; i++) {
        cout << "Employee[" << i << "] " << endl ;
        Payroll payroll(employeeArray[i]) ;
        payroll.writeCheck() ;
    }
    cout << endl ;

    // Try running below by uncommenting -- should be a problem because
    // getSalary and getSSN are is private except to the Payroll class.

    /*
    cout << "Current Employees: " << endl ;
    for(int i = 0 ; i < numEmployees ; i++) {
       cout << "Employee[" << i << "] " << endl
            << "Name:  " << employeeArray[i].getName() << "  "
            << "Badge: " << employeeArray[i].getBadge() << "  "
            << "Monthly Wages: " << (employeeArray[i].getSalary() / 12.0) << "  "
            << "SSN: " << employee[i].getSSN() << endl << endl ;
    }
    */

    return 0 ;
}

