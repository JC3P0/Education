/* PersonAtMCC.cpp - Function definitions for parent class
 * Author:     Josh Clemens
 * Module:     7
 * Project:    Lab, Part 1
 * Description:  Function definitions for parent class - constructor,
 *     getters, setters, and showInfo
 */

#include "PersonAtMCC.h"
#include <iostream>
using namespace std;

// constructors
PersonAtMCC::PersonAtMCC() { //default constructor
    PersonAtMCC(0, "no name yet", "no address yet", "no phone yet") ;
}

PersonAtMCC::PersonAtMCC(long long id, string name) { //id and name constructor
    PersonAtMCC(id, name, "no address yet", "no phone yet") ;
}

/*** WRITE THE MISSING CONSTRUCTOR USING SETTERS ***/
//full constructor
PersonAtMCC::PersonAtMCC(long long id, string name, string address, string phone) :
    id(id),
    name(name),
    address(address),
    phone(phone) {};

// getters and setters
long long PersonAtMCC::getId() const{
    return id;
}

string PersonAtMCC::getName() const{
    return name;
}

string PersonAtMCC::getAddress() const{
    return address;
}

string PersonAtMCC::getPhone() const{
    return phone;
}

// Setters
void PersonAtMCC::setId(long long new_id) {
    id = new_id;
}

void PersonAtMCC::setName(string new_name) {
    name = new_name;
}

void PersonAtMCC::setAddress(string new_address) {
    address = new_address;
}

void PersonAtMCC::setPhone(string new_phone) {
    phone = new_phone;
}

// show person's info on screen
void PersonAtMCC::showInfo() {
    cout << "ID: " << this -> id
         << "  Name: " << this -> name
         << "  Address: " << this -> address << endl
         << "    Phone: " << this -> phone << endl << endl;
}