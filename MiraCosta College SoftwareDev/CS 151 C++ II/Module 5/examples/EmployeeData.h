/* EmployeeData.h - Definition for EmployeeData class
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Description: Includes full defintion of Employee file
 */

#ifndef EMPLOYEE_DATA_H
#define EMPLOYEE_DATA_H

#include <string>
using namespace std ;

class EmployeeData {

    // The Payroll class can access all private data members and functions
    // of this class directly by making it a friend
    friend class Payroll ;

    // Data members
    private:
        string name ;
        int badge ;
        double salary ;
        int SSN ;

    // Functions available to all departments
    public:

        //Default Constructor Prototype
        EmployeeData() ;
        EmployeeData( string newName, int newBadge, double newSalary, int newSSN ) ;

        // public function Prototypes
        string getName() ;
        void setName(string newName) ;
        int getBadge() ;
        void setBadge(int theBadge) ;

    // We do NOT want to make salary and SSN information available to all
    // departments that use employee data EXCEPT the Payroll dept.
    // Make the Payroll class a friend class so it can access these functions.
    private:
        void setSalary(double theSalary) ;
        double getSalary() ;
        void setSSN(int theSSN) ;
        int getSSN() ;
        void display() ;
} ;

// Default Constructor
EmployeeData::EmployeeData() {
   name = "unknown" ;
   badge = -1 ;
   salary = -1.0 ;
   SSN = 0 ;
}
// Multi-arg Constructor
EmployeeData::EmployeeData(string newName, int newBadge, double newSalary, int newSSN ) {
   name = newName ;
   badge = newBadge ;
   salary = newSalary ;
   SSN = newSSN ;
}

// member functions
void EmployeeData::EmployeeData::setName(string theName) {
   name = theName ;
}
string EmployeeData::getName() {
   return name ;
}
void EmployeeData::setBadge(int newBadge) {
   badge = newBadge ;
}
int EmployeeData::EmployeeData::getBadge() {
   return badge ;
}
void EmployeeData::setSalary(double newSalary) {
   salary = newSalary ;
}
double EmployeeData::getSalary() {
   return salary ;
}
void EmployeeData::setSSN(int newSSN) {
   SSN = newSSN ;
}
int EmployeeData::getSSN() {
   return SSN ;
}
void EmployeeData::display() {
   cout << "Name: " << name << endl ;
   cout << "Badge: " << badge << endl ;
   cout << "Salary: " << salary << endl ;
   cout << "SSN: " << SSN << endl ;
}

#endif
