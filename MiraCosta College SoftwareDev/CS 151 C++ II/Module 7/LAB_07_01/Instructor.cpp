/* Instructor.cpp - Definition of functions for the Instructor subclass to PersonAtMCC
 * Author:     <Josh Clemens>
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Instructor.h"
#include <iostream>
using namespace std;

/**** WRITE THE MISSING CONSTRUCTORS, USE SETTERS FOR PARENT,
      ASSIGNMENT FOR CHILD CLASS MEMBERS ****/
Instructor::Instructor(){ //default constructor
    setId(0);
    setName("No name entered.");
    setAddress("No Address entered.");
    setPhone("No Phone # entered.");
    department = "No department.";
    is_permanent = false;
    pay_rate = 0.0;
    hours = 0.0;
}

//full constructor
Instructor::Instructor(long long id, string name, string address, string phone, string department, bool is_permanent, double pay_rate, double hours){
    setId(id);
    setName(name);
    setAddress(address);
    setPhone(phone);
    this -> department = department;
    this -> is_permanent = is_permanent;
    this -> pay_rate = pay_rate;
    this -> hours = hours;
}
//(long long, string, string, string, string, bool, double, double)
// string department;
// bool is_permanent;
// double pay_rate;
// double hours;

// Getters for this class only
string Instructor::getDepartment() const{
    return department;
}

bool Instructor::getIsPermanent() const{
    return is_permanent;
}

double Instructor::getPayRate() const{
    return pay_rate;
}

double Instructor::getHours() const{
    return hours;
}

// Setters for this class only
void Instructor::setDepartment(string new_department) {
    department = new_department;
}

void Instructor::setIsPermanent(bool new_is_permanent) {
    is_permanent = new_is_permanent;
}

void Instructor::setPayRate(double new_pay_rate) {
    pay_rate = new_pay_rate;
}

void Instructor::setHours(double new_hours) {
    hours = new_hours;
}

void Instructor::showInfo() {

    //check for true false bool values to output yes or no
    string isPermanent = "";
    if(getIsPermanent()){
        isPermanent = "Yes";
    } else {
        isPermanent = "No";
    }
    
    cout << "ID: " << getId()
         << "  Name: " << getName()
         << "  Address: " << getAddress() << endl
         << "    Department: " << getDepartment()
         << ", Permanent? " << isPermanent
         << ", Pay Rate: " << getPayRate()
         << ", Hours: " << getHours() << endl << endl;

    /**** COMPLETE THE OUTPUT ****/
}
