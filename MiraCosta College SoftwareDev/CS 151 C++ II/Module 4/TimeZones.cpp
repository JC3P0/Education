/* TimeZones.cpp - Same as TimeConverter, but sets time zone to Pacific
 * Author:     Chris Merrill
 * Module:     4
 * Project:    Demonstration
 * Problem statement:  Take the TimeConverter program, then modify the TZ 
 *    environment variable to San Diego time and others.
 *
 * Algorithm:
 *   1. Start with TimeConverter program.
 *   2. Modify TZ environment variable to Pacific time (PST8PDT)
 *   3. Run again and verify that time and day is now correct
 *   4. Change to other time zones and run (Eastern, China, Spain)
 *
 * Discussion:
 *   * If running on repl.it, uncomment the appropriate statement which
 *     sets the timezone. 
 */

#include <iostream>
#include <ctime>
using namespace std ;

int main() {

    cout << "Current time zone (TZ): " 
         << "tz: " << tzname[0] << " - " << tzname[1] << endl << endl ;  

    // Use one of these selections for Dev-C++
    putenv("TZ=PST8PDT") ;                   // Pacific time zome Pacific
    // putenv("TZ=EST5EDT") ;                   // Eastern (Boston, New York, Miami)
	// putenv("TZ=CST-8") ;                     // China
    
    // Use one of these selections for repl.it
    // setenv("TZ", "PST8PDT", 1) ;             // Pacific time zone Pacific 
    // setenv("TZ", "EST5EDT", 1) ;             // Eastern (Boston, New York, Miami)
    // setenv("TZ", "CST-8", 1) ;               // China
    
    tzset() ;
    cout << "After setting TZ:       " 
         << "tz: " << tzname[0] << " - " << tzname[1] << endl << endl;    

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

