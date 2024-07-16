/* Overridden.cpp - Overridden function and access to base class version
 * Author:     Chris Merrill
 * Module:     7
 * Project:    Demonstration
 * Problem statement:  Create an overridden function called "getName" in a derived
 *    class which returns the name of a person plus any surname or suffix
 *
 * Algorithm:
 *   1. Create two TitlePerson and one Person objects
 *
 *             John Adams (no prefix or suffix) - Person
 *             Ms. Alicia Gonzalez (no suffix) - Titled Person
 *             Dr. Maximillian Million III - Titled Person
 *
 *   2. Create a columnar report that shows each person's first name, last
 *      name, untitled full name (use Person version of getName using scope
 *      resolution operator) and another full name based on data type of variable.
 */

#include <iostream>
#include <iomanip>
using namespace std ;

// Base class just holds the first and last names of a person
class Person {

    string first_name = "",
           last_name = "" ;

    public:
        Person(string first_name, string last_name) :
            first_name(first_name),
            last_name(last_name) { }
        string getFirstName() const { return first_name ; }
        string getLastName() const {return last_name ; }

        // This function is overridden in the child class (TitledPerson)
        string getName() const { return first_name + " " + last_name ; }
} ;

// A person with a title (Mr., Mrs. Ms., Dr., etc) and an optional suffix
class TitledPerson : public Person {

    string title = "",
           suffix = "" ;

    public:
        TitledPerson(string title, string first_name,
                     string last_name, string suffix) :
            Person(first_name, last_name),
            title(title),
            suffix(suffix) { }
        string getTitle() const { return title ; }
        string getSuffix() const { return suffix ; }

        // Overrides the Person version, includes prefix and suffix
        string getName() const ;
} ;

string TitledPerson::getName() const {

    // Get full name (excluding title or suffix) from base class
    string titled_name = Person::getName() ;         // base (Person) class version
    if (title != "") {
        titled_name = title + " " + titled_name ;    // add title (if present)
    }
    if (suffix != "") {
        titled_name += " " + suffix ;               // add suffix (if present)
    }
    return titled_name ;
}

int main() {

    // Create a few titled names.
    Person *john = new Person("John", "Adams") ;
    TitledPerson *alicia = new TitledPerson("Ms.", "Alicia", "Gonzalez", "") ;
    TitledPerson *max = new TitledPerson("Dr.", "Maximillian", "Million", "III") ;

    // Print their first, last, untitled name (from Person), and
    // titled name (from TitledPerson).  For each person, the first call
    // to getName uses Person version, second call is to TitledPerson
    cout << left << endl
         << "   First        Last             Untitled                With Title??" << endl
         << "-----------  ------------  --------------------  ---------------------------" << endl
         << setw(13) << john->getFirstName() << setw(14) << john->getLastName()
         << setw(22) << john->Person::getName() << john->getName() << endl         // 1st is overridden

         << setw(13) << alicia->getFirstName() << setw(14) << alicia->getLastName()
         << setw(22) << alicia->Person::getName() << alicia->getName() << endl

         << setw(13) << max->getFirstName() << setw(14) << max->getLastName()
         << setw(22) << max->Person::getName() << max->getName() << endl << endl ;

     delete john ;
     delete alicia ;
     delete max ;

    return 0 ;
}
