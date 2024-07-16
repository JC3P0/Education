/* EmployeeDemo.cpp - Deomonstrate the use of the derived Employees classes
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Problem Statement: Demonstrates the used of the derived Employee classes,
 *     HourlyEmployee and SalariedEmployee.
 *
 * Algorithm:
 *   1. Use the default constructor to create one hourly employee
 *   2. Use setters from both the parent and child class to set values
 *   3. Use the full constructor to create one salaried employee
 *   4. Print a check for each employee using the printCheck() function
 *      in each child class
 *      4a. Provide a printCheck() function in Employee class which
 *          shows an error
 *
 * Discussion:
 *   * Hourly employee created using default constructors in main
 *   * Salaried employee created using full constructors in main
 *   * Employee class has no mention (is independent) of child classes
 *   * Syntax of parent / child relationship in .h files of child classes
 *   * Syntax of constructors in .cpp files of child classes
 *     -- still using assignment statements and setters
 *     -- assumes existence of default constructor in parent class
 */

#include <iostream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
using namespace std ;

int main() {

    // Define an hourly employee using the default constructor (no params)
    // Use a pointer as recommended by textbook
    HourlyEmployee *joe = new HourlyEmployee() ;
    joe->setName("Mighty Joe") ;                       // from parent class
    joe->setSSN("123-45-6789") ;                       // from parent class
    joe->setRate(20.50) ;                              // from child class
    joe->setHours(40) ;                                // from child class

    // Print the check for Joe
    cout << "Check for " << joe->getName()
         << " for " << joe->getHours() << " hours:" << endl ;
    joe->printCheck() ;                                // from child class
    cout << endl ;

    // Create a salaried employee using the full constructor
    // Uses printCheck from child class
    SalariedEmployee *boss = new SalariedEmployee("Mr. Big Shot", "999-45-3456", 10500.50) ;
    cout << "Check for " << boss->getName() << ":" << endl ;
    boss->printCheck() ;                               // from child class
    cout << endl ;

    return 0 ;
}


