/*______________________________________
* FILE: LAB_04_USING_TIME_JC
* AUTHOR: Josh Clemens
* MODULE: 4
* PROJECT: 1
* LAST MODIFIED: September 19, 2022
* PROBLEM STATEMENT: Manipulate a time variable and corresponding structure, print today's date and time in various formats and determine how to adjust the internal form of other dates.
* ALGORITHM:
*     INITIALIZE days[0-6] and months[0-11] arrays to reference individual elements of the local structure
*     INITIALIZE output[80] to store ino from strftime
*     INITIALIZE replit time zone, time_t variable and tm structure
*     OUTPUT todays date in various outputs
*     INITIALIZE tm event struct
*     OUTPUT event date
*     CALCULACTE total seconds in a week then subtract from event date
*     OUTPUT the date a week before the event
*______________________________________*/

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main() {

    /***** DECLARATION & INITIALIZATION SECTION *****/

    //days of the week(sun = 0, mon = 1, tue = 2...)
    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    //months of the year (jan = 0, feb = 1, mar = 2...)
    string months[] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    //use to store info from strftime
    char output[80];

    //replit time zone set
    setenv("TZ","PST8PDT", 1);
    tzset();

    //time_t variable and set current time
    time_t now = time(NULL);

    //tm structure and reference with pointer, assign to current time
    struct tm *local = localtime(&now);
    
    /***** INTRO SECTION *****/

    cout << "Welcome to the Using Time program!\n\n";

    /***** INPUT SECTION *****/
    //no input

    /***** PROCESSING / OUTPUT SECTION *****/

    cout << "Here is today's date in various formats:\n";
    cout << "   **** Format ****" << "       " << "*** Today ***\n";
    cout << "   m/d/yy:" << "                " << local ->tm_mon + 1 << "/" << local ->tm_mday << "/" << local ->tm_year - 100 << endl
         << "   January 1, 2020:" << "       " << months[local ->tm_mon] << " " << local ->tm_mday << ", " << (local ->tm_year - 100) + 2000 << endl
         << "   d-mmm-year:" << "            "; 
    strftime(output, 80, "%d-%b-%Y", local);
    cout << output<< endl;

    cout << "\nSame information using the strftime function:\n";
    cout << "   **** Format ****" << "       " << "*** Today ***\n";
    strftime(output, 80, "   m/d/yy:                %m/%d/%g\n   January 1, 2020:       %B %d, %G", local);
    cout << output << endl;
    strftime(output, 80, "   d-mmm-year:            %d-%b-%Y", local);
    cout << output<< endl;

    cout << "\nHere's the current time in two formats:\n";
    //use strftime function print today's date in 12 and 24 hour formats, stores in char output[80]
    strftime(output, 80, "%I:%M%p <12-hour>", local);
    cout << output << endl;
    strftime(output, 80, "%H:%M   <24-hour>", local);
    cout << output << endl;

    //new event struct
    tm event;
    event.tm_year = 1991 - 1900;
    event.tm_mon = 3;
    event.tm_mday = 28;
    event.tm_hour = 19;
    event.tm_min = 56;
    event.tm_sec = 42;
    event.tm_isdst = 1;

    //time_t variable to return reference of event
    time_t time_of_event = mktime(&event);

    //output event
    cout << "\nI was born on " << ctime(&time_of_event) << "this occured " << time_of_event << " seconds after epoch!\n";

    //calculate for seconds in a week
    cout << "There are " << 60*60*24*7 << " seconds in a week!\n";

    //subtract a weeks worth of seconds to show date a week before
    time_of_event -= 604800;
    cout << "The week before was " << ctime(&time_of_event);

    //set to original date to output correct day of the year
    time_of_event += 604800;
    strftime(output, 80, "The event was on a %A, day of the year: %j", &event);
    cout << output << endl;

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}

//create two string arrays
        //weeks of the day(sunday = 0, mon = 1, tue = 2)
        //months of the year (jan = 0, feb = 1, mar = 2)
    //replit time zone
        //setenv("TZ","PST8PDT");
        //tzset();
    //create time_t variable and set current time
    //establish a tm structure and reference with pointer, assign to current time
        //tm*local=localtime(&now);
    //print todays date using format. use individual elements of the local structure
        //1/1/22 (m/d/yy)
        //January 1, 2022
        //  1-Jan-2022
    //use strftime function print today's date in the same format 
    //Again using either the  strftime  function or the individual values in the  tm  structure, print the current time in the following format.  (If using individual values, make sure that if the number of minutes is less than 10, then you provide a leading zero for minutes, such as 5:05pm.)
        //17:30   (24-hour format)
        //5:30pm  (12-hour format)
//create another tm structure for and important event (such as your birthday or graduation day), assigning all variables appropriately
        //tmevent;
        //event.tm_year=
    //find the number of seconds in one week. * num days in a week by num hours in a day, by num min in an hour, by num sec in a min ( 60(1min) * 60(1hour) * 24(1day) * 7(1week) )
    //subtract num of seconds in a week from the time_of_event 
    //print the date and time occurring exactly on week before the big event using ctime function
    //use strftime function to print the day of week(mon, tue, wed using the array) and the day number (1-365) of the year on which the event occured