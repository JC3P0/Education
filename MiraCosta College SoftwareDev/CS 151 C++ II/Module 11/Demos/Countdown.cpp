/* Countdown.cpp - Count down from a given number to 0
 * Author:     Textbook
 * Module:     11
 * Project:    Demonstration
 * Problem statement:  Write a recursive function that takes a positive
 *    number, then calls itself using that number -1 until it reaches 0
 *
 * Algorithm:
 *    1. The recursive function will take an int as a parameter, then
 *       use the following algorithm:
 *        1a. If the parameter is 0, then print "Blastoff"
 *        1b. Otherwise
 *               --print the number on the console
 *               -- sleep for one second
 *               -- call itself again with number - 1 as a parameter
 *    2. In main
 *        2a. Prompt for a positive number
 *        2b. Call the recursive function initially with that number
 *
 * Discussion:
 *   - Windows vs Unix functions to cause program to wait for one second
 */

#include <iostream>
#include <windows.h>           // Windows
// #include <unistd.h>         // Unix
using namespace std ;

// prototype
void countdown(int) ;

int main() {

    cout << "Enter a positive number: " ;
    int start_count ;
    cin >> start_count ;

    countdown(start_count) ;

    return 0 ;
}

// Recursive function to perform the countdown.
void countdown(int num) {

    if (num == 0) {
        cout << "Blastoff!\n\n" ;    // the "stopping" case
    } else {
        cout << num << "..." << endl ;
        Sleep(1000) ;                // Windows (include windows.h)
        // usleep(1000000) ;         // Unix (include unistd.h)

        countdown(num - 1) ;         // the recursive call
    }
}
