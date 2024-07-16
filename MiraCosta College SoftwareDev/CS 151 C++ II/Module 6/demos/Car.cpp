/* Car.cpp - A Car class includes an Engine class (composition)
 * Author:     Chris Merrill
 * Module:     6
 * Project:    Demonstration
 * Problem statement:  Using a Car, Engine, and Person class, demonstrate
 *    composition (Car and Engine) and aggregation (Car and Person)
 *
 * Algorithm:
 *   1. Create an Engine class with type ('d' - diesel, 'g' - gas) and an int
 *      for the number of cylinders in the engine
 *      -- Only need a constructor for this demo using an initialization list
 *   2. Create a Person class consisting of two strings containing the
 *      Person's first and last name
 *      -- Use an initialization list in the constructor
 *   3. Create a Car class with an Engine object (composition) and a pointer
 *      to a Person object (aggregation)
 *   4. In main:
 *      4a. Create a Person object for a person Jeane Quiros.  This object can
 *          exist separately from a Car object
 *      4b. Create a Car object with a gas 8-cylinder Engine that belongs
 *          to Jeane Quiros
 *
 * Discussion:
 *    * The relationship between Car and Person is aggregation, since objects of each class
 *      can exists separately.
 *      - Both the car and the owner are created and deleted independantly of each other
 *    * The relationship between Car and Engine is composition, since the engine object
 *      is created / destroyed when the Car object is created / destroyed
 *    * A car "has" both an engine and an owner, meaning aggregation
 *    * Initialization lists are preferred by many programmers
 *      - They start with a colon after the constructor heading
 *      - Name of instance members in the initialization lists can be the same as parameters.
 *           C++ can separate the two and put in right order
 *    * The body of the constructor is usually empty, as there isn’t anything else to do
 *      when using initialization lists
 */

#include <iostream>
using namespace std ;

class Engine {
    private:
        char type ;                           // 'd' - diesel, 'g' - gas
        int cylinders ;                       // 4, 6, 8...
    public:
        Engine(char type, int cylinders) :    // constructor
            type(type),                       // member initialization list
            cylinders(cylinders) { } ;        // empty constructor
} ;

class Person {
    private:
        string first_name ;
        string last_name ;
    public:
        Person(string fname, string lname) :  // constructor
            first_name(fname),                // member initialization list
            last_name(lname) { } ;            // empty constructor
} ;

class Car {
    private:
        Engine engine ;
        Person *owner ;
        string color ;
        int year ;
    public:
        Car(string color, int year, char type, int cylinders, Person *owner) :
            color(color),
            year(year),
            engine(type, cylinders),           // composition (creates an object)
            owner(owner) { } ;                 // aggregation (just a pointer)
} ;

int main() {

    Person jeane("Jeane", "Quiros") ;          // Person and Car objects exist separately
    Car("Blue", 2020, 'g', 8, &jeane) ;        // Car and Engine exist together

    return 0 ;
}
