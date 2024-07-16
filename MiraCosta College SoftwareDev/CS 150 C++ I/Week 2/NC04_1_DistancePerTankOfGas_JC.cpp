/****************************************************
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC04_1>
* LAST MODIFIED: <02/05/22>
*****************************************************************************
* Distance Per Tank Of Gas
*****************************************************************************
PROGRAM DESCRIPTION:
* Calculates and displays the distance a car can travel on one tank of gas when driven in town or the highway.
****************************************************************************
ALGORITHM:
* Enter Variables - gallonsOfGas, cityMPG, highwayMPG, pricePerGallons
* CALCULATE cityRange, highwayRange, totalCost
* OUTPUT Variables
* OUTPUT caityRange, highwayRange, totalCost
*****************************************************************************
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
*****************************************************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    /***** CONSTANT SECTION *****/
    // no constant
    
    /***** DECLARATION SECTION *****/

    double gallonsOfGas;
    double cityMPG;
    double highwayMPG;
    double pricePerGallons;
    double cityRange;
    double highwayRange;
    double totalCost;
    
    /***** INITIALIZATION SECTION *****/

    gallonsOfGas = 12.0;
    cityMPG = 20.4;
    highwayMPG = 27.1;
    pricePerGallons = 4.49;
       
    /***** INTRO SECTION *****/

    cout << "Welcome to the Gas Calculator!" << endl;
     
    /***** INPUT SECTION *****/
    //no input
    
    /***** PROCESSING SECTION *****/

    cityRange = cityMPG * gallonsOfGas;
    highwayRange = highwayMPG * gallonsOfGas;
    totalCost = gallonsOfGas * pricePerGallons;

    /***** OUTPUT SECTION *****/

    cout << "Gas tank capacity in gallons: "<< gallonsOfGas << endl;
    cout << "City MPG: " << cityMPG << endl;
    cout << "Highway MPG: " << highwayMPG << endl;
    cout << "Price per Gallon: " << pricePerGallons << "\n" << endl;
    
    cout << "Your city range is " << cityRange
         << " miles and your highway range is "
         << highwayRange << " miles" << endl;
    cout << "A tank of gas costs $" << totalCost << endl;
   
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}