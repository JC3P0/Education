/* Textbook.cpp - The use of a textbook and headcount common across all students
 * Author:     Chris Merrill
 * Module:     5
 * Project:    Demonstration
 * Problem statement:  Create a static variables "textbook" across all student
 *      objects, "headcount" to count all active students, and "lastId" to
 *      track the last id assigned to a student.
 *
 * Algorithm:
 *   1. Create a Student class with:
 *      -- data members name (string) and id (int)
 *      -- static members head-count (int), last_id (int) and textbook (string)
 *   2. In constructor
 *      -- pass the new student's name as a parameter
 *      -- set the student's id to last_id and increment last_id
 *      -- increment head_count
 *   3. In destructor
 *      -- decrement head_count
 *   4. Provide getters and setters for student name and id
 *   5. Outside of class, initialize static variables
 *      -- headcount to 0
 *      -- last_id to 10000
 *      -- textbook to "C++ primer"
 *   5. In main:
 *      -- Create three Student objects, with different names
 *      -- Display the three student's names, id, and textbook, and the total
 *         headcount
 *      -- Change one of the student's names
 *      -- Delete another student
 *      -- Change the textbook to "C++ Early Objects"
 *      -- Display the names, id's, and textbook of the two remaining students
 *      -- Cleanup (delete two remaining students)
 *
 * Discussion:
 *    * Must initialize the static variables outside of the class or structure
 *    * Static functions can be accessed either by an object of the
 *      class (using . or ->) or by the class name (using ::)
 *    * Use of const in getters for instance variables (doesn't work with static)
 */

#include <iostream>
#include <string>
using namespace std ;

class Student {

    private:
        string name ;
        int id ;

        static int head_count ;           // declaration
        static int last_id ;
        static string textbook ;

    public:
        Student(string name) {
            this->name = name ;
            id = last_id++ ;
            head_count++ ;
        }
        ~Student() {
            head_count-- ;
        }
        string getName() const {         // notice use of const
            return name ;
        }
        int getId() const {
            return id ;
        }
        int static getHeadCount() {
            return head_count ;
        }
        string static getTextbook() {
            return textbook ;
        }
        void static setTextbook(const string new_book) {
            textbook = new_book ;
        }

} ;

int Student::head_count = 0 ;             // definition (initialization)
int Student::last_id = 10000 ;
string Student::textbook = "C++ primer" ;

int main() {

    // Show the textbook using Student::
    cout << "The textbook for everyone is: "
         << Student::getTextbook() << endl << endl ;

    // Create three students, show their name and id
    Student *jacque = new Student("Jacque Alberjois") ;
    Student *mike = new Student("Mike Hanly") ;
    Student *nala = new Student("Nala Lopez") ;

    cout << jacque->getId() << "  " << jacque->getName()
         << " created, textbook: " << Student::getTextbook() << endl ;
    cout << mike->getId() << "  " << mike->getName()
         << " created, textbook: " << Student::getTextbook() << endl ;
    cout << nala->getId() << "  " << nala->getName()
         << " created, textbook: " << Student::getTextbook() << endl << endl ;

    // Access headcount through an object
    cout << "After creating 3 students, headcount is : "
         << nala->getHeadCount() << endl << endl ;

    // One student leaves.  Access headcount through class name.
    delete jacque ;
    jacque = nullptr ;
    cout << "When Jacque left, headcount is now:       "
         << Student::getHeadCount() << endl << endl ;

    // Change the textbook and show info for remaining 2 students
    mike->setTextbook("C++ Early Objects") ;           // Changes for everyone!
    cout << "After we changed the textbook" << endl ;
    cout << mike->getId() << "  " << mike->getName()
         << " still here, textbook: " << Student::getTextbook() << endl ;
    cout << nala->getId() << "  " << nala->getName()
         << " still here, textbook: " << Student::getTextbook() << endl << endl ;

    // Clean up the heap
    delete mike ;
    delete nala ;
    mike = nala = nullptr ;

    return 0 ;
}
