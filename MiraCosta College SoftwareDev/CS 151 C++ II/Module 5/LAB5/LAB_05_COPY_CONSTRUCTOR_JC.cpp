/*______________________________________
* FILE: LAB_05_COPY_CONSTRUCTOR_JC
* AUTHOR: Josh Clemens
* MODULE: 5
* PROJECT: 2
* LAST MODIFIED: September 24, 2022
* PROBLEM STATEMENT: Uses a copy constructor and change() function to copy string objects.
* ALGORITHM:
*     INITIALIZE String class with default constructor and copy constructor to copy string objects.
*     INITIALIZE String class objects, first with default constructor then copy constructor.
*     CALCULATE copy one String class object to equal another using change() function.
*     OUTPUT both String objects.
*______________________________________*/

#include "String.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

    //create String class objects
    cout << "Create two strings, one using constructor and an assignment statement.\n";
    String str1("MiraCosta College"); //regular constructor
    String str2 = str1; // copy constructor

    //print both String objects
    str1.print();
    str2.print();

    //use the change function and print
    cout << "\nAfter changing string 2 using change()\n";
    str2.change("Cal State San Marcos");

    //print both String objects
    str1.print();
    str2.print();

    //use the change function on string 1 and print
    cout << "\nAfter changing string 1 using change()\n";
    str1.change("UCSD");

    //print both String objects
    str1.print();
    str2.print();

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}