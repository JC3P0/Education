/* Upcasting.cpp - Demonstrate upcasting capabilities of C++
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Problem statement:  Create Animal, Dog, and Poodle classes.  See
 *   when upcasting from one class to another works.
 *
 * Algorithm:
 *   1. Create an Animal class with data member "name", constructor, copy
 *      constructor, getters and setters
 *      1a. Add a function named "eat" which prints on the console:
 *                     Animal "<name>" is eating
 *   2. Create a Dog class, child of Animal
 *      2a. Constructor uses initialization list
 *      2b. Add a function named "bark" which prints on the console:
 *                     Dog "<name>" is barking
 *   3. Create a Poodle clas, child of Dog
 *      3a. Constructor uses initialization listj
 *      3b. Add a function named "pose" which prints on the console:
 *                     Poodle "<name>" is posing
 *   4. Create Animal, Dog, and Poodle pointers to Animal, Dog, and Poodle
 *      objects created using "new" (i.e., from the heap)
 *   5. Make the animal object eat
 *   6. Make the dog object eat and bark
 *   7. Make the poodle object each, bark, and pose
 *   8. Downcast the animal variable to the Dog object
 *      - Make the animal eat
 *   9. Downcast the animal variable to the Poodle object
 *      - Make the animal eat
 *  10. Determine if a Dog object can be passed to the Animal copy constructor
 *      - Will it still eat?
 *  11. Determine if a Poodle object canb be passed to the Animal copy constructor
 *      - Will it still eat?
 *  12. Determine if animal variables used in steps 10 and 11 above can bark
 *      and/or eat.
 *
 * Discussion:
 *  - First part of main function is just inheritance.
 *  - A dog object and a poodle object can be used anywhere that an
 *    animal object is expected.
 *  - An animal pointer does not see functions in the Dog or Poodle class,
 *    even if the object is a Dog or Poodle object.
 *  - In the series of delete statements at the end, what goes wrong?
 *    -- We forget to delete the original animal object before assigning
 *       the animal variable to the dog and poodle objects in steps 8 and 9.
 */

#include <iostream>
using namespace std ;

class Animal {
    private:
        string name ;
    public :
        Animal(string name)                      // normal constructor
            { setName(name) ; }
        Animal(Animal &anAnimal)                 // copy constructor
            { setName(anAnimal.getName()) ; }
        string getName()                         // getters and setters
            { return name ; }
        void setName(string name)
            { this->name = name ; }
        void eat()                               // all animals must eat
            { cout << "Animal \"" << getName() << "\" is eating." << endl ; }
} ;

class Dog : public Animal {
    public :
        Dog(string name) : Animal(name) {} ;    // normal constructor
        Dog(Dog &aDog) : Animal(aDog) {} ;      // copy constructor
        void bark()                             // all dogs can bark
            { cout << "Dog \"" << getName() << "\" is barking." << endl ; }

} ;

class Poodle : public Dog {
    public :
        Poodle(string name) : Dog(name) {} ;           // normal constructor
        Poodle(Poodle &aPoodle) : Dog(aPoodle) {} ;    // copy constructor
        void pose()                                    // vain...
            { cout << "Poodle \"" << getName() << "\" is posing." << endl ; }
} ;

int main() {

    // No polymorphism here, just inheritance
    Animal *animal = new Animal("An Animal") ;
    Dog *dog = new Dog("Your Dog") ;
    Poodle *poodle = new Poodle("My Poodle") ;

    // Make them eat, bark, and pose.  Again, just inheritance
    animal->eat() ;
    cout << endl ;

    dog->eat() ;
    dog->bark() ;
    cout << endl ;

    poodle->eat() ;
    poodle->bark() ;
    poodle->pose() ;
    cout << endl ;

    // Does upcasting work?
    cout << "Dog object assigned to animal variable." << endl ;
    animal = dog ;
    animal->eat() ;
    cout << "Poodle object assigned to animal variable." << endl ;
    animal = poodle ;
    animal->eat() ;
    cout << endl ;

    // Can we use Dog and Poodle objects to create Animal objects (upcasting)?
    cout << "Passing a Dog and a Poodle to the Animal copy constructor" << endl ;
    Animal *animal2 = new Animal(*dog) ;              // Yes
    Animal *animal3 = new Animal(*poodle) ;           // Yes
    animal2->eat() ;
    animal3->eat() ;

    // Animal pointer can point to a Poodle object, but then sees only Animal functions!
    // animal3->bark() ;         // No, compiler only sees functions in Animal class
    // animal3->pose() ;         // No

    delete animal ;              // Which object is this deleting?
    delete animal2 ;
    delete animal3 ;
    delete dog ;
    // delete poodle ;           // Already deleted!

    return 0 ;
}
