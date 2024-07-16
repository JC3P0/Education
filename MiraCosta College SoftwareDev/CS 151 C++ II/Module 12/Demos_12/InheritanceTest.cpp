/* InheritanceTest.cpp - Demonstrate use of the "is_base_of" template
 * Author:     Chris Merrill
 * Module:     12
 * Project:    Exercise 1
 * Problem statement:  How to determine if one class is an ancestor of another.
 * Algorithm
 *    1. Create three classes, Animal, Cat, Dog, and Poodle
 *    2. Using the "is_base_of" template, determine if:
 *
 *                 Animal is an ancestor of Cat and Dog
 *                 Cat and dog are ancestors of Poodle
 *                 Animal is an ancestor of Poodle
 *                 Poodle is an ancestor of Dog
 *                 Cat is an ancestor of Cat
 *                 int is an ancestor of int
 *
 * Discussion:
 *   * The template returns true when the two classes are the same class
 *     to model the "is-a" relationship (T is-a T).
 *   * The template also allows structures, since they essentially are classes in C++.
 *   * The template returns false if either is not a class or structure.
 *   * The test is independent of whether the access modifier between the
 *     two classes is public, protected, or private.
 */

#include <iostream>
using namespace std ;

// Create class where Animal, Cat, Dog, and Poodle.  Use the public,
// private, and protected base access modifier to show it has no
// impact on the template
class Animal {} ;                     // Top class
class Cat : public Animal {} ;        // Descendants of Animal
class Dog : protected Animal {} ;
class Poodle : private Dog {} ;       // Descendant of Dog

int main() {

    cout << boolalpha ;         // convert bool 0's and 1's to false and true in output
    cout << "is_base_of relationship:" << endl << endl ;

    // These relationships ar ok
    cout << "   Valid relationships:" << endl ;
    cout << "      Animal and Cat:    " << is_base_of<Animal, Cat>::value << endl ;
    cout << "      Animal and Dog:    " << is_base_of<Animal, Dog>::value << endl ;
    cout << "      Dog and Poodle:    " << is_base_of<Dog, Poodle>::value << endl ;
    cout << "      Animal and Poodle: " << is_base_of<Animal, Poodle>::value << endl ;
    cout << "      Animal and Animal: " << is_base_of<Animal, Animal>::value << endl << endl ;

    // These are upside-down or make no sense
    cout << "   Invalid relationsips:" << endl ;
    cout << "      Cat and Poodle:    " << is_base_of<Cat, Poodle>::value << endl ;
    cout << "      Poodle and Dog:    " << is_base_of<Poodle, Dog>::value << endl ;
    cout << "      Poodle and Animal: " << is_base_of<Poodle, Animal>::value << endl << endl ;

    // What if the arguments aren't classes?
    cout << "      int and int:       " << is_base_of<int, int>::value << endl ;

    return 0 ;
}

