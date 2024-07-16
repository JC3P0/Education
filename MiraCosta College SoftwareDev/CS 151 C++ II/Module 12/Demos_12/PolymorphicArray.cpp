/* PolymorphicArray.cpp - Create an array of one animal and 4 specialized animals
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Demonstration
 * Problem statement:  Create an Animal class, parent to the Dog, Cat, and Horse.
 *     Each of those subclasses also has a child:  Puppy, Kitten, and Colt.
 *
 *     Each class has it's own version of the speak function except Colt, which
 *     inherits from Horse.
 *
 *     Create an array of one of each type of animal, then make each "speak".
 *
 * Algorithm:
 *   1. Create an Animal class with virtual "speak" function that prints
 *                       The animal speaks!
 *   2. Create Dog, Cat, and Horse classes which are children of Animal
 *      with concrete function "speak" that  override the abstract "speak"
 *      function from Animal
 *   3. Create a Puppy class, child of Dog which overrides "speak"
 *   4. Create a Kitten class, child of Cat which overrides "speak"
 *   5. Create a Colt class which,  is a child of Horse, with no "speak" function
 *   6. Create an array of Animal objects with one of each type (Dog, Cat,
 *      Horse, Puppy, Kitten, Colt, and Animal)
 *   7. Make changes described below in "Discussion" to determine the
 *      effect of making changes to this program
 *
 * Discussion:
 *   - All animals have their own version of speak except Colt, which inherits
 *     from Horse.
 *   - Making speak virtual in Animal makes it virtual in all subclasses
 *       -> This includes subclasses to subclasses (Puppy and Kitten).
 *   - What happens when we make speak NOT virtual in Animal
 *       -> The "override" on Dog prohibits compilation
 *          -> Remove "override" on Dog and it now compiles
 *       -> Good programming practice says all should be "virtual" and
 *          put the "override" tags on all "speak" functions
 *   - What happens when "final" is added to speak in Dog?
 *       -> Puppy version no longer compiles
 *   - We didn't need to make destructors virtual, since there aren't any
 *     data members to clean up...
 */

#include <iostream>
#include <typeinfo>                    // May be needed in some versions of C++
using namespace std ;

// Abstract class with a virtual function named "speak"
class Animal {
    public:
        virtual void speak() const
            { cout << "The Animal speaks!\n" ; }
} ;

// Concrete classes must override speak
class Dog : public Animal {
    public:
        void speak() const override
            { cout << "The Dog says:    Woof! Woof!\n" ; }
} ;

class Puppy : public Dog {
    public:
        void speak() const
            { cout << "The Puppy says:  yip. yap.\n" ; }
} ;

class Cat : public Animal {
    public:
        void speak() const
            { cout << "The Cat says:    Meow!\n" ; }
} ;

class Kitten : public Cat {
    public:
        void speak() const
            { cout << "The Kitten says: meow.\n" ; }

} ;

class Horse : public Animal {
    public:
        void speak() const
            { cout << "The Horse says:  Neigh! Neigh!\n" ; }
} ;

class Colt : public Horse {
    public:
} ;

int main() {

    // Create an array holding an object of each type of animal
    Animal *myPack[] { new Dog,
                       new Puppy,         // speak is overridden from Dog
                       new Cat,
                       new Kitten,        // speak is overridden from Cat
                       new Horse,
                       new Colt,          // speak is not overridden from Horse
                       new Animal } ;

    int size = sizeof(myPack) / sizeof(*myPack) ;
    for (int i = 0 ; i < size ; i++) {
        myPack[i]->speak() ;
    }
    cout << endl ;

    return 0 ;
}

