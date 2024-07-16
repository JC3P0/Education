/* DogStructure.cpp - Demonstrate the use of the -> pointer
 * Author:     Chris Merrill
 * Module:     4
 * Project:    Demonstration
 * Problem statement:  Create a structure describing a Dog, then access and update
 *    the structure using the -> operator.  Also demonstrate creating a structure 
 *    using the heap and passing a structure to a function by reference and by value.
 *
 * Algorithm:
 *   1. Create a Dog class with name, breed, age, and weight
 *   2. In the Dog class, provide a default and a full constructor
 *   3. Create a Dog structure named fido (name: Fido, breed: Shephard, age: 5, weight: 53 lbs.
 *      3a. Use default structure, then assign variables directly using dot notation
 *   4. Create another Dog named lassie (name: Lassie, breed: Collie, age: 3, weight: 25.3 lbs.
 *      4a. Use full constructor
 *   5. Create a third Dog on the heap using the "new" operator and a pointer
 *      named scooby (name: Scooby-Don't, breed: G/D, age: 7, weight: 60 lbs.
 *   5. Create a pointer to the fido, lassie, and scooby structures
 *   6. Using those pointers and pointer (dog) notation
 *      6a. Change fido's weight to 51
 *      6b. Change lassie's age to 4
 *      6c. Change scooby's weight to 70.
 *   7. Using the arrow notation
 *      7a. Change fido's age to 6
 *      7b. Change lassie's weight to 28.4
 *      7c. Fix scooby's name
 *   8. Provide two versions of a function to print a Dog's vital stat's, one that takes
 *       a pointer to a Dog, and one that passes by reference.
 *
 * Discussion:
 *   *  Also look at a version which takes a Dog object, then calls the version
 *      which takes a pointer.
 */

#include <iostream>
using namespace std ;

// Define a stucture for a dog with 4 properties
struct Dog {
    string name ;
    string breed ;
    int age ;
    double weight ;

    // Must provide a no-arg constructor, since another constructor also is provided
    Dog() 
        { } ;
    Dog(string new_name, string new_breed, int new_age, double new_weight) {
        name = new_name ;
        breed = new_breed ;
        age = new_age ;
        weight = new_weight ;
    }
} ;

// Prototypes
void show(const Dog &) ;           // requires a Dog object in call to this function
void show(const Dog *) ;           // requires pointer to a Dog object in this function

int main() {

    // Create a dog object (using default constructor), update its properties using . operator
    Dog fido ;
    fido.name = "Fido" ;
    fido.breed = "Shephard" ;
    fido.age = 5 ;
    fido.weight = 53 ;

    // Use the constructor (still using the stack)
    Dog lassie("Lassie", "Collie", 3, 25.3) ;

    // Create a third dog in the heap for Scooby (have to use a pointer here)
    // Use data that will be corrected below.
    Dog *scooby_ptr = new Dog("Scooby-Don't", "Great Dane", 7, 60) ;

    // Create a pointer to fido and use the -> operator.
    Dog *fido_ptr = &fido ;
    fido_ptr->weight =51 ;

    // Create a pointer to lassie and do the same thing. (Notice that we need to
    // use parenthesis, since . has a higher precedence than *
    Dog *lassie_ptr = &lassie ;
    (*lassie_ptr).age = 4 ;

    // Scooby is already a pointer...
    (*scooby_ptr).weight = 70 ;

    // Use the -> operator to change a few key items
    fido_ptr->age = 6 ;
    lassie_ptr->weight = 28.4 ;
    scooby_ptr->name = "Scooby-Doo" ;

    // Print the vitals for our three pooches
    show(fido) ;                    // Calls 1st prototype
    show(lassie_ptr) ;              // Calls 2nd prototype
    show(scooby_ptr) ;              // Calls 2nd prototype

    // Don't forget to delete any objects allocated from the heap.
    delete scooby_ptr ;

    return 0 ;
}

void show(const Dog &myDog) {
    cout << myDog.name << " is a " << myDog.breed
         << " who is " << myDog.age << " years old"
         << " and weighs " << myDog.weight << " lbs." << endl ;
}

/*
// Call with a Dog object, passes address of that object
void show(const Dog &myDog) {
    Dog *ptr = &myDog ;
    show(ptr) ;            // call the version that takes a pointer
}
*/

// Function to show all info for a dog (call with a pointer to a Dog object)
void show(const Dog *myDog) {
    cout << myDog->name << " is a " << myDog->breed
         << " who is " << myDog->age << " years old"
         << " and weighs " << myDog->weight << " lbs." << endl ;
}


