/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_26
* LAST MODIFIED: May 07, 2022
*__________________
* Alien Inheritance
*_____________________
* PROGRAM DESCRIPTION:
* This is an object oriented program that was re-written code that was not as object oriented. This program initiates three alien types, displays total count of aliens and total damage count.
*___________
* ALGORITHM:
* INITIATE Alien class for derived alt aliens to be created - Alien(health, name, damage)
* INITIATE mashmallow, snake, and orge aliens with 100 health and different damages
* CALCULATE and display - total aliens, total damage
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include "AlienPack.h"
#include "Alien.h"
#include "SnakeAlien.h"
#include "OrgeAlien.h"
#include "MarshAlien.h"

using namespace std;

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.

    /***** DECLARATION SECTION *****/
    //no dec.

    /***** INITIALIZATION SECTION *****/

    AlienPack alienPack;

    SnakeAlien snake(100, "Snake");
    OrgeAlien orge(100, "Orge");
    MarshAlien marsh(100, "Marsh");

    alienPack.addAlien(snake, 0);
    // alienPack.addAlien(snake, 1);
    alienPack.addAlien(orge, 1);
    alienPack.addAlien(marsh, 2);
    // alienPack.addAlien(marsh, 4);
    // alienPack.addAlien(marsh, 5);

    /***** INTRO SECTION *****/

    cout << "Welcome to the Alien Inheritance program.\n\n";

    /***** INPUT SECTION *****/
    //no input

    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    cout << "Alien count: " << alienPack.getAlienCount() << endl;
    cout << "Damage: " << alienPack.calculateDamage(alienPack.getAliens(), alienPack.getAlienCount()) << endl;

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}