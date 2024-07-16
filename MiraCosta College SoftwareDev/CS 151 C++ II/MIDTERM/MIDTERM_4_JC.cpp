/* Inheritance.cpp - Create a Person / Teacher / MathTeacher hierarchy of classes (Midterm)
 * Author:     <your name>
 * Module:     10
 * Project:    Midterm Problem 4
 * Problem statement: Create a hierarchy of Person / Teacher / MathTeacher, each
 *   with a profession (string) and age (int) stored in Person, and which inherit
 *   getters and setters for those two properties.  In addition, the Teacher
 *   and MathTeacher classes have a "teach" function.
 */

#include <iostream>
using namespace std ;

class Person {
    private:
        string profession ;
        int age ;

    public:

    Person(string nprofession, int nage){
        profession = nprofession;
        age = nage;
    }
        // Add constructor which takes a profession and age, and uses an initialization
        // list to initialize both instance members

    string getProfession() const{
        return profession;
    }
    int getAge() const{
        return age;
    }
    void setProfession(string newProfession){
        profession = newProfession;
    }
    void setAge(int newAge){
        age = newAge;
    }
        // Add getters and setters
} ;

class Teacher : public Person {                 // make a child of Person
    private:

    public:

    Teacher(int nage) : Person(){
        age = nage;
    }
    Teacher(string nprofession, int nage) : Person(){
        profession = nprofession;
        age = nage;
    }

    void teach(){
        cout << "The " << getProfession() << " is teaching.\n";
    }
        // Add a constructor which takes an age, calls Person constructor with "Teacher" as profession
        // Add another constructor which takes both a profession and an age, then passes
        // both up to Person constructor

        // Create a function teach() which prints on the console:
        //      The <profession> is teaching
} ;

class MathTeacher : public Teacher {            // make a child of Teacher
    private:

    public:

    MathTeacher::MathTeacher(int nage) : Teacher(){
        profession = "Math Teacher";
        age = nage;
    }
        // Add a constructor which takes an age, calls Teacher constructor with "Math Teacher" as profession

} ;

int main() {

    // Create a Person object, a Teacher object, and a MathTeacher object
    Person person("Worker", 27) ;
    Teacher teacher(42) ;
    MathTeacher mathTeacher(39) ;

    cout << "The person's profession is: " << person.getProfession()
         << " and is " << person.getAge() << " years old" << endl ;
    cout << "The teacher's profession is: " << teacher.getProfession()
         << " and is " << teacher.getAge() << " years old" << endl ;
    cout << "The mathTeacher's profession is: " << mathTeacher.getProfession()
         << " and is " << mathTeacher.getAge() << " years old" << endl << endl ;

    teacher.teach() ;
    mathTeacher.teach() ;

    return 0 ;
}
