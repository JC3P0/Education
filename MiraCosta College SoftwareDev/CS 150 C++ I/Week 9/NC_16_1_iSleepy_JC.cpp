/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_16_01
* LAST MODIFIED: March 28, 2022
*________
* iSleepy
*_____________________
* PROGRAM DESCRIPTION:
* Uses an array to gather users input for one week of sleep per night. Program will calculate the total and average hours slept then displays how many nights of "Recommended", "May be Appropriate" or "Not Recommended"
*___________
* ALGORITHM:
* PROMPT hours slept per night in a 7 day week
* CALCULATE nights by "Recommended", "May be Appropriate" or "Not Recommended"
* CALCULATE total / average hours slepts
* OUTPUT total / average hours slept and nights per "Recommended", "May be Appropriate" or "Not Recommended"
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
*____________________________________________*/

#include <cstdlib>
#include <iostream>
using namespace std;

double totalSleep(double sleep[], int length);
double avgSleep(double sleep[], int length);
double recSleep(double sleep[], int length);
double maySleep(double sleep[], int length);
double notSleep(double sleep[], int length);
int countSleep(double sleep[], int length, double min, double max);


int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    
    const int NIGHTS_OF_WEEK = 7;
 
    /***** DECLARATION SECTION *****/ 

    double sleepTimes[NIGHTS_OF_WEEK];
    
    /***** INITIALIZATION SECTION *****/    
    //no init.

    /***** INTRO SECTION *****/

    cout << "Welcome to the sleep recommendation program for young adults.\n";
    
    /***** INPUT SECTION *****/

    cout << "Enter your last 7 nights of sleep please.\n";
    
    /***** PROCESSING SECTION *****/ 

    for(int i = 0; i < NIGHTS_OF_WEEK; i++){
        cout << "Enter your sleep hours on night " << i+1 << ": ";
        cin >> sleepTimes[i];
    }
    
    /***** OUTPUT SECTION *****/

    cout << "You slept a total of " << totalSleep(sleepTimes, NIGHTS_OF_WEEK) << " hours, ";
        
    cout << "for a total average of " << avgSleep(sleepTimes, NIGHTS_OF_WEEK) << " hours.\n";
    cout << "You had " << recSleep(sleepTimes, NIGHTS_OF_WEEK) << " days of recommended sleep, "; 
    cout << maySleep(sleepTimes, NIGHTS_OF_WEEK) << " days of may be appropriate sleep, and "; 
    cout << notSleep(sleepTimes, NIGHTS_OF_WEEK) << " days of not recommended sleep." << endl; 
       
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

double totalSleep(double sleep[], int length){
    double sum = 0;
    for(int i = 0; i < length; i++){
        sum += sleep[i];
    }
    return sum;
}

double avgSleep(double sleep[], int length){
    return totalSleep(sleep, length) / static_cast<double>(length);
}

int countSleep(double sleep[], int length, double min, double max){
    int count = 0;
    for(int i = 0; i < length; i++){
        if (sleep[i] <= 9 && sleep[i] >= 7){
            count++;
        }
    }            
    return count;
}

double recSleep(double sleep[], int length){
    int count = 0;
    for(int i = 0; i < length; i++){
        if (sleep[i] <= 9 && sleep[i] >= 7){
            count++;
        }
    }            
    return count;
}

double maySleep(double sleep[], int length){
    int count = 0;
    for(int i = 0; i < length; i++){
        if (sleep[i] >= 6 && sleep[i] <= 7 || sleep[i] == 11){
            count++;
        }        
    } 
    return count;
}

double notSleep(double sleep[], int length){
    int count = 0;
    for(int i = 0; i < length; i++){
        if (sleep[i] < 6 && sleep[i] > 0){
        count++;
        }  
        if (sleep[i] < 24 && sleep[i] > 10){
        count++;
        } 
    } 
    return count;
}




 
