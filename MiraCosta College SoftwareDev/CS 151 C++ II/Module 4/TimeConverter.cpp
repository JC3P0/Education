/* TimeConverter.cpp - Print the current month and day using various formats
 * Author:     Chris Merrill
 * Module:     4
 * Project:    Demonstration
 * Problem statement:  Using the current time, print the current day of the week.
 *      hour, minute, and whether we are using daylight savings time.
 *
 * Algorithm:
 *   1. Create a time_t variable and set to the current time (seconds from epoch)
 *   2. Create an array of days-of-the-week, starting with Sunday
 *   3. Create a tm structure using the current time
 *   4. Print the current day-of-the-week, the current hour, and the current minute
 *   5. Print whether the time zone is currently using daylight savings time or not
 */

#include <iostream>
#include <time.h>
using namespace std ;

int main() {

    // Get the current time in seconds from epoch
    // Note that data type "time_t" is defined by your version of C++
    time_t now_in_seconds ;
    time(&now_in_seconds) ;                     // Technique #1
    // now_in_seconds = time(NULL) ;            // Technique #2

    cout << "It has been " << now_in_seconds
         << " seconds since January 1, 1970" << endl << endl ;

    // Create an array of days of the week
    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
                     "Friday", "Saturday"} ;

    // Convert to a structor of days representing the month, day, seconds, day-ot-the-week,
    // year, etc.

    tm *local_time = localtime(&now_in_seconds) ;
    cout << "Today is:       " << days[local_time->tm_wday] << endl ;
    cout << "Current hour:   " << local_time->tm_hour << endl ;
    cout << "Minute is:      " << local_time->tm_min << endl ;
    cout << "Daylight Savings Time? " << (local_time->tm_isdst ? "Yes" : "No") << endl << endl ;

    return 0 ;
}

