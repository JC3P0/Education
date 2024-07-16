/* strftimeDemo.cpp - Demonstrate strftime function
 * Author:     Chris Merrill
 * Module:     4
 * Project:    Exercise #2
 * Problem statement: Using today's date, demonstrate several of the
 *    format specifiers from the strftime function
 *
 * Algorithm:
 *   1. Create a tm structure and set to today's time and date
 *   2. Use the following strftime specifiers on today's date
 *
 *                  %I - hours in 12-hour format
 *                  %M - minutes
 *                  %c - date in mm/dd/yy h:m:s
 *                  %j - the day of the year (Jan 1 = 1)
 *                  %A - full day name
 *                  %B - full month name
 *                  %Z - time zone name
 */

#include <iostream>
#include <ctime>            // for tm structure and strftime function
using namespace std ;

int main() {

    // If running on repl.it, set to Pacific Standard / Daylight time zone
    // setenv("TZ", "PST08PDT", 1) ;
    // tzset() ;

    // Create time_t variable and initialize with current time (seconds from epoch)
    time_t rawtime ;
    time(&rawtime) ;

    // Create a tm structure and populate with the current time's values
    struct tm *time_info ;
    time_info = localtime(&rawtime) ;

    // Use the strftime function to format the current time
    char output[80] ;
    strftime(output, 80, "The time is %I:%M%p.", time_info) ;
    cout << output << endl << endl ;

    strftime(output, 80, "Today is %c.", time_info) ;
    cout << output << endl << endl ;

    strftime(output, 80, "That's day %j of year %Y.", time_info) ;
    cout << output << endl << endl ;

    strftime(output, 80, "Day of the week is %A", time_info) ;
    cout << output << endl << endl ;

    strftime(output, 80, "The month is %B", time_info) ;
    cout << output << endl << endl ;

    // Finally print the time zone we are in.
    strftime(output, 80, "We are in the %Z time zone", time_info) ;
    cout << output << endl ;

    return 0 ;
}
