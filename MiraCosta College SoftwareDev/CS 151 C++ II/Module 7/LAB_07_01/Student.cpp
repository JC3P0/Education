/* Student.cpp - Function definitions for Student class, child of PersonAtMCC
 * Author:     <Josh Clemens>
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Student.h"
#include <iostream>
using namespace std;

/**** WRITE THE MISSING CONSTRUCTORS, USE SETTERS FOR PARENT,
      ASSIGNMENT FOR CHILD CLASS MEMBERS ****/

Student::Student(){ //default constructor
    setId(0);
    setName("No name entered.");
    setAddress("No Address entered.");
    setPhone("No Phone # entered.");
    major = "No major.";
    credits_received = 0;
    applied_to_4_year = false;
    is_veteran = false;
}

//full constructor
Student::Student(long long id, string name, string address, string phone, string major, int credits_received, bool applied_to_4_year, bool is_veteran){
    setId(id);
    setName(name);
    setAddress(address);
    setPhone(phone);
    this -> major = major;
    this -> credits_received = credits_received;
    this -> applied_to_4_year = applied_to_4_year;
    this -> is_veteran = is_veteran;
}
//Student(long, string, string, string, string, int, bool, bool)
// string major;
// int credits_received;
// bool applied_to_4_year;
// bool is_veteran;

// Getters for this class only
string Student::getMajor() const{
    return major;
}

int Student::getCreditsReceived() const{
    return credits_received;
}

bool Student::getAppliedTo4Year() const{
    return applied_to_4_year;
}

bool Student::getIsVeteran() const{
    return is_veteran;
}

// Setters
void Student::setMajor(string new_major) {
    major = new_major;
}

void Student::setCreditsReceived(int new_credits_received) {
    credits_received = new_credits_received;
}

void Student::setAppliedTo4Year(bool new_has_applied) {
    applied_to_4_year = new_has_applied;
}

void Student::setIsVeteran(bool new_is_veteran) {
    is_veteran = new_is_veteran;
}

void Student::showInfo() {

    //check for true false bool values to output yes or no
    string fourYear = "";
    string isVeteran = "";
    if(getAppliedTo4Year()){
        fourYear = "Yes";
    } else {
        fourYear = "No";
    }
    if(getIsVeteran()){
        isVeteran = "Yes";
    } else {
        isVeteran = "No";
    }
    cout << "ID: " << getId()
         << "  Name: " << getName()
         << "  Address: " << getAddress() << endl
         << "    Phone: " << getPhone() << endl
         << "    Major: " << getMajor()
         << ", Credits: " << getCreditsReceived()
         << ", 4-Year? " << fourYear
         << ", Veteran? " << isVeteran << endl << endl;

}