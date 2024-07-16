/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_21_01
* LAST MODIFIED: April 16, 2022
*_____________________
* Weather Observations
*_____________________
* PROGRAM DESCRIPTION:
* This program uses a structure to record weather observations. Uses a functions to display the structure per measurment system.
*___________
* ALGORITHM:
* INITIALIZE structure for imperial and metric
* OUTPUT using one fuction and call with either imperial or metric
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

enum class Units {IMPERIAL, METRIC};

struct WxObservation {
    string date;
    string time;
    string zipcode;
    int temperature;
    int humidity;
    double visibility;
    Units unit;
};

//function prototypes
void displayWeatherObservation(const WxObservation &wo);

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/ 

    WxObservation imperial;
    WxObservation metric;
       
    /***** INITIALIZATION SECTION *****/

    imperial.date = "1/25/2022";
    imperial.time = "11:00 PDT";
    imperial.zipcode = "92056";
    imperial.temperature = 75;
    imperial.humidity = 51;
    imperial.visibility = 7.0;
    imperial.unit = Units::IMPERIAL;

    metric.date = "1/25/2022";
    metric.time = "11:00 PDT";
    metric.zipcode = "92056";
    metric.temperature = 24;
    metric.humidity = 51;
    metric.visibility = 11.3;
    metric.unit = Units::METRIC;

    /***** INTRO SECTION *****/
    //infuction
        
    /***** INPUT SECTION *****/
    //initialized
    
    /***** PROCESSING SECTION *****/ 
    //noprocessing
   
    /***** OUTPUT SECTION *****/

    displayWeatherObservation(imperial);
    cout << endl;
    displayWeatherObservation(metric);
        
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

void displayWeatherObservation(const WxObservation &wo) {
    string strDistance;
    string strTemp;
    
    if (wo.unit == Units::IMPERIAL) {
        strDistance = "miles";
        strTemp = "F";
    }
    else if (wo.unit == Units::METRIC) {
        strDistance = "km";
        strTemp = "C";
    }
    cout << "Welcome to the weather program.\n";
    cout << "On " << wo.date << " @ " << wo.time
        << ", zipcode " << wo.zipcode << " experienced a temperature of " 
        << wo.temperature << " " << strTemp << ", humidity " 
        << wo.humidity << "% and visibility of " << wo.visibility
        << " " << strDistance << "." << endl;
}





