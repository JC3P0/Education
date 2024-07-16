/*______________________________________
* FILE: LAB_07_INHERITANCE_01_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 7
* PROJECT: 1
* LAST MODIFIED: October 08, 2022
* PROBLEM STATEMENT: Use PersonAtMCC class as base to Student, Staff, and Instructor classes using Inheritance.
* ALGORITHM:
*    INITIALIZE PersonAtMCC as base class to include name, address and phone values.
*    INITIALIZE Student, Staff, and Instructor classes as derived classes to PersonAtMCC with public access.
*    INITIALIZE Instructor to use base class values along with its own: department, is_permanent, pay_Rate, and hours.
*    INITIALIZE Staff to use base class along with its own values: extension, hire_date, pay_rate.
*    INITIALIZE Student to use base class along with its own values: major, credits_received, applied_to_4_year, is_veteran.
*    INITIALIZE Objects of each class in main.
*    OUTPUT objects of each class.
*    OUTPUT a student object with base class showInfo function.
*______________________________________*/

#include "PersonAtMCC.h"
#include "Student.h"
#include "Staff.h"
#include "Instructor.h"
#include <iostream>
using namespace std;

int main() {

    // Create Student objects for Amerlia Earhart and Muhammed Ali.
    Student *amelia = new Student(940392,
                                "Amelia Earhart",
                                "123 Main Street, Oceanside, CA",
                                "760.213.4930",
                                "Computer Science",
                                240,
                                true,
                                true);
    Student *muhammed = new Student(840392,
                                "Muhammed Ali",
                                "294A West 4th Ave., Escondido, CA",
                                "760.294.4932",
                                "Math Credits",
                                134,
                                false,
                                false);

    // Show the information for both students
    cout << "*** TWO STUDENTS ***" << endl;
    amelia->showInfo();
    muhammed->showInfo();

    // How about a friendly instructor?
    Instructor *professorJudy = new Instructor(6294032,
                                "Juanita Ramirez",
                                "843 C St., Apt 43, San Diego, CA",
                                "619.427.4933",
                                "English",
                                false,
                                59.85,
                                160);

    cout << "*** A FRIENDLY INSTRUCTOR ***" << endl;
    professorJudy->showInfo();

    // And the facilities guy
    Staff *elliot = new Staff(84920493,
                            "Eliot Ness",
                            "12 East Ramona Way, Ramona, CA",
                            "760.583.3911",
                            "x5923",
                            "Nov. 15, 2015",
                            49.25);
                        
    cout << "*** STAFF MEMBER ***" << endl;
    elliot->showInfo();

    // Just a plain old PersonAtMCC
    PersonAtMCC *ralph = new PersonAtMCC(10000000,
                                        "Ralph Kramden",
                                        "999 Yellow Brick Road",
                                        "555-BANG-ZOOM");
                                        
    cout << "*** JUST ANOTHER PERSON AT MCC ***" << endl;
    ralph->showInfo();

    // Just use the base class version of showInfo for Amelia Earhart
    cout << "*** BASE CLASS SHOWINFO FOR MS. EARHART ***" << endl;
    
    amelia->PersonAtMCC::showInfo();
    
    return 0 ;
}