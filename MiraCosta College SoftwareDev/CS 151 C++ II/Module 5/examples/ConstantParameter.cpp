/* ConstantParameter.cpp - Demonstrate calling with a constant parameter specfied
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Problem statement:  Create a function with a constant parameter with a default
 *    value, then show what happens when the parameter tries to be changed.
 *
 * Algorithm:
 *   1. Create a Student structure with the following elements
 *
 *                the student's name (string)
 *                the student's gpa (grade-point-average) (int)
 *                a constructor for both data elements
 *
 *   2. Create two functions with the following headers
 *
 *               void myFunction(const &a_student)
 *               void myFunction(const *a_student)
 *
 *      Both functions take a Student structure object and attempt to change the
 *      student's gpa
 *
 *   3. In each function, try to change the gpa of the parameter student object
 *      - Both functions cause compiler errors when the lines changing the gpa
 *        are uncommented
 *   4. In main:
 *      4a. Create two Student objects
 *      4b. Call the call-by-reference version using one object, and the
 *          call using a pointer by the other
 *
 * Discussion:
 *    * Neither call (by reference or by pointer) will creates a duplicate object
 *      - Calling by reference doesn't call copy constructor
 *      - Calling by pointer creates a duplicate pointer, not object
 *    * Comment the two lines which change the student's gpa so program compiles.
 */

#include <iostream>
using namespace std ;

struct Student {
    string name ;
    double gpa ;
    Student(string name, double gpa) {
        this->name = name ;
        this->gpa = gpa ;
    }
} ;

void myFunction(const Student &who) {

    // Try to change the value of the gpa of the Student
    // who.gpa = 4.0 ;

    cout << "By reference: Student: " << who.name << "  GPA: "
         << who.gpa << endl << endl ;
}

void myFunction(const Student *who) {

    // Try to change the value of the gpa of the Student
    // who->gpa = 4.0 ;

    cout << "By pointer:   Student: " << who->name << "  GPA: "
         << who->gpa << endl << endl ;
}

int main() {

    // Create two Student to pass to a function
    Student maria = Student("Maria Quiros", 3.5) ;
    Student joe = Student("Joe Smith", 3.2) ;

    // Call the function passing the Student by reference and by pointer
    myFunction(maria) ;
    myFunction(&joe) ;

    return 0 ;
}
