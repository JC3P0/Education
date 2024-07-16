/*______________________________________
* FILE: LAB_07_INHERITANCE_02_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 7
* PROJECT: 2
* LAST MODIFIED: October 08, 2022
* PROBLEM STATEMENT: Create a base Animal class with Name variable and two derived classes Owl that adds its own variable breed and fox that only takes name derived from Animal class.
* ALGORITHM:
*   INITIALIZE base Animal class with name value, and fuctions nap(), makeNoise(), and showInfo().
*   INITIALIZE Fox(name) and Owl(name, breed) classes derived from Animal class with public access and their own makeNoise(), and showInfo() functions.
*   INITIALIZE Animal, Fox and owl objects in main.
*   OUTPUT object names, nap, and noise.
*______________________________________*/
//Review questions
/*______________________________________
 * 1Q. What is/are the names of the base classes?
 * 1A = Animal
 * 2Q. What is/are the names of the derived classes?
 * 2A = Fox, Owl
 * 3Q. Does  Animal  have a parent class?
 * 3A = no
 * 4Q. Is the function  showInfo  overridden?  Is  makeNoise?  Is  nap?
 * 4A = showInfo = yes, makeNoise = yes, nap = no
 * 5Q. If the instance member  name  in the  Animal  class were made  protected  (instead of  private), would you need to use getters in the  showInfo  function of the child classes  Fox  and  Owl?
 * 5A = No, you could just name instead of getName() function.
 * 6Q. What if the instance members were left  private,  but the base access modifiers to the  Animal  class in both child classes were made  protected, would you need to use getters in the  showInfo  function of the child classes  Fox  and  Owl?
 * 6A = No, protected would need to be declared in the base Animal class
 *______________________________________*/

#include "Animal.h"
#include "Fox.h"
#include "Owl.h"
#include <iostream>

using namespace std;


int main() {

    //intro
    cout << "Welcome to the Inheritance program!!!\n\n";

    //create animal, owl and fox objects
    Animal *oscar = new Animal("Oscar");
    Owl *errol = new Owl("Errol", "Great Grey");
    Fox *foxy = new Fox("Foxy");

    //display names
    cout << "Displaying object names: \n";
    oscar->showInfo();
    errol->showInfo();
    foxy->showInfo();
    cout << endl;

    //display noises
    cout << "Displaying object noises: \n";
    oscar->makeNoise();
    errol->makeNoise();
    foxy->makeNoise();
    cout << endl;

    //display nap using base class function
    cout << "Displaying objects napping: \n";
    oscar->nap();
    errol->Animal::nap();
    foxy->Animal::nap();
    cout << endl;

    //exit message
    cout << "Thank you for using the Inheritance program!!!\n";

    return 0;
}