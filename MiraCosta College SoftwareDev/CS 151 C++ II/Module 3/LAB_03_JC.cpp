/*______________________________________
* FILE: LAB_03_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 3
* PROJECT: Dangling Pointers
* LAST MODIFIED: September 10, 2022
* PROBLEM STATEMENT: Investigate how dangling pointers can be created and the possible issues they can cause.
* ALGORITHM:
*     INITIALIZE int pointers - intptr, never_used
*     CALCULATE call function first(intptr) with int pointer and assign the pointer to the address of local variable in function
*     OUTPUT int pointer
*     CALCULATE call function second(never_used) and set the value of a local int to varable 99 then stop
*     OUTPUT int pointer
*     CALCULATE call funtion third() to define and initialize variable to 29 and returns the address of that variable
*     OUTPUT int pointer
*     CALCULATE call funtion fourth() declared but does not initialize variable and prints its value
*______________________________________*/

#include <cstdlib>
#include <iostream>
// #pragma clangdiagnosticpush
// #pragma clangdiagnosticignored "-wreturn-stack-address"
using namespace std;

void first(int*&ptr_to_intptr);
void second(int *&dummy);
int *third();
int *fourth();

int main() {

    // int *ptr ;
    // int square = 16 ;  
    // ptr = &square ;  
    // cout << ptr << endl;
    
    int *intptr, *never_used; //initialize int pointers for testing
    first(intptr); // intptr with point to de-Alloacted memory (Dangling!)
    cout << "Part 1: " << endl
         << " Return from first(), *intptr is "
         << *intptr << endl;

    second(never_used); // intptr is still dangling
    cout << " Return from second(), *intptr is "
         << *intptr << endl << endl;

    intptr = third();
    cout << "Part 2: " << endl
         << " Returned address " << intptr << " from third()" << endl
         << " Value in that address is " << *intptr << endl;

    cout << " Setting memory at " << intptr << " to 109" << endl;
    *intptr = 109;
    fourth();

    return 0;
    
}

/***** Function Definitions *****/

void first(int*&ptr_to_intptr){
    int a = 5;
    ptr_to_intptr = &a; // 'a' is deallocated
}

void second(int *&dummy){
    int b = 99; //overlays original memory for 'a'
    dummy = &b;
}

//defines and initializes variable 'x' and returns address of 'x'
int *third(){
    int x = 29;
    cout << "In third(), the value of x is " << x << endl;
    return &x;
}

//declares but does not initialize variable 'y'
int *fourth(){
    int y;
    cout << "In fourth(), the value of y is " << y << endl;
    return &y;
}