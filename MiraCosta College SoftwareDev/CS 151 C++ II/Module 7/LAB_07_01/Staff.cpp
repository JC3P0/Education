/* Staff.cpp - Function definition file for Staff, child of PersonAtMCC
 * Author:     <Josh Clemens>
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Staff.h"
#include <iostream>
using namespace std ;

/**** WRITE THE MISSING CONSTRUCTORS, USE SETTERS FOR PARENT,
      ASSIGNMENT FOR CHILD CLASS MEMBERS ****/
Staff::Staff(){ //default constructor
    setId(0);
    setName("No name entered.");
    setAddress("No Address entered.");
    setPhone("No Phone # entered.");
    extension = "No extension.";
    hire_date = "No hire date.";
    pay_rate = 0.0;
}

//full constructor
Staff::Staff(long long id, string name, string address, string phone, string extension, string hire_date, double pay_rate){
    setId(id);
    setName(name);
    setAddress(address);
    setPhone(phone);
    this -> extension = extension;
    this -> hire_date = hire_date;
    this -> pay_rate = pay_rate;
}
//(long long id, string name, string address, string phone)
// string extension;
// string hire_date;
// double pay_rate;

// Getters for this class only
string Staff::getExtension() const{
    return extension;
}

string Staff::getHireDate() const{
    return hire_date;
}

double Staff::getPayRate() const{
    return pay_rate;
}

// Setters for this class only
void Staff::setExtension(string new_extension) {
    extension = new_extension;
}

void Staff::setHireDate(string new_hire_date) {
    hire_date = new_hire_date;
}

void Staff::setPayRate(double new_pay_rate) {
    pay_rate = new_pay_rate;
}

void Staff::showInfo() {
    
    cout << "ID: " << getId()
         << "  Name: " << getName()
         << "  Address: " << getAddress() << endl
         << "    Phone: " << getPhone() << endl
         << "    Extension: " << getExtension()
         << ", Hire Date: " << getHireDate()
         << ", Pay Rate: " << getPayRate() << endl << endl;

}