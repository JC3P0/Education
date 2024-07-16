/* Downcasting.cpp - Demonstrate downcasting capabilities of C++
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Problem statement:  Create Animal, Dog, and Cat classes.  Determine
 *   when downcasting from one class to another works.
 *
 * Algorithm:
 *   1. Start with the Upcating demonstration
 *      - Remove the Poodle class from project (only need 2 levels, not 3)
 *      - Add Cat class (now Animal is parent to 2 classes, Dog and Cat)
 *        - Define a string for noise, set to "meow"
 *        - Define a function named "meow" which displays:
 *                      Cat "<name>" meows
 *   2. Create Animal, Cat, and Dog pointer variables, and assign to
 *      Cat, Dog, and Animal objects created using new operator
 *      - No polymorphism here.
 *   3. Determine which of the following statements will compile:
 *
 *                   cat = new Animal(...) ;
 *                   cat = animal ;
 *                   cat = static_cast<Cat *> animal
 *
 *   4. If any of the above compile, then what happens with the following
 *
 *                   cat.meows() ;
 *
 *   5. What happens when we do the following:
 *
 *                   animal = new Animal(*dog) ;          (should compile)
 *                   dog = static_cast<Dog *> animal      (should compile)
 *                   dog.bark() ;                         ????
 *
 * Discussion:
 *  - The following statements don't compile
 *
 *                    cat = new Animal(...) ;
 *                    cat = animal ;
 *
 *  - Static casting to anything doesn't seem to stop the program, but
 *    can produce unexpected results when the cast doesn't make sense.
 *  - Is it safe to delete dog, cat, and animal objects at the end?
 *      - Hint: What happened to the memory allocated to the original animal
 *        object after performing step 5 above?
 *      - What happened to the original dog object?
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
    private:
        string noise = "barks" ;
    public :
        Dog(string name) : Animal(name) {} ;    // normal constructor
        Dog(Dog &aDog) : Animal(aDog) {} ;      // copy constructor
        void bark()                             // all dogs can bark
            { cout << "Dog \"" << getName() << "\" " << noise << endl ; }

} ;

class Cat : public Animal {
    private:
        string noise = "meows" ;
    public :
        Cat(string name) : Animal(name) {} ;    // normal constructor
        Cat(Cat &aCat) : Animal(aCat) {} ;      // copy constructor
        void meow()                             // all cats can say Meow
            { cout << "Cat \"" << getName() << "\" " << noise << endl ; }

} ;

int main() {

    // No polymorphism here, just inheritance
    Animal *animal = new Animal("An Animal") ;
    Dog *dog = new Dog("Your Dog") ;
    Cat *cat = new Cat("Your Cat") ;

    // Can we assign a new Animal to a Cat pointer?
    // cat = new Animal("An Animal") ;                      // No

    // Can we assign an animal pointer to a Cat pointer?
    // cat = animal ;                                       // No

    // Can we typecast an animal object to a Cat?
    // cat = static_cast<Cat *>(animal) ;                   // Compiles, but...
    // cat->meow() ;

    // What happens when using an Animal constructor on a Dog object?  Do
    // we lose information?
    animal = new Animal(*dog) ;
    dog = static_cast<Dog *>(animal) ;                  // We loose information
    dog->bark() ;                                       // but it still compiles

    // delete animal ;
    // delete dog ;
    // delete cat ;

    return 0 ;
}
