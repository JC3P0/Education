/****************************************************
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC04_2>
* LAST MODIFIED: <02/05/22>
*****************************************************************************
* Basal Metabolic Rate
*****************************************************************************
PROGRAM DESCRIPTION:
* Estimates your BMR or the calories your body expends at rest (without exercise)
****************************************************************************
ALGORITHM:
* Identify variables- weight, height, age 
* CALCULATE bmrMale, bmrFemale, averageCalories, chocolateBars
* OUTPUT weight, height, age 
* OUTPUT bmrFemale, bmrMale, chocolateBars
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
    
    double weight;
    double height;
    double age;
    double bmrFemale; //BMR=655 +(4.35 * weight) + (4.7 * height) - (4.7 * age)
    double bmrMale; //BMR=66 + (6.23 * weight) + (12.7 * height) -(6.8 * age)
    double averageCalories; //average = (bmrFemale + bmrMale) / 2
    double chocolateBars; //chocolateBar =average / 230
    
    /***** INITIALIZATION SECTION *****/

    weight = 200;
    height = 72;
    age = 35;
           
    /***** INTRO SECTION *****/

    cout << "Welcome to the Basal Metabolic Rate calculator!" << "\n" << endl;
     
    /***** INPUT SECTION *****/
    // no input
    
    /***** PROCESSING SECTION *****/

    bmrFemale = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
    bmrMale = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
    averageCalories = (bmrFemale + bmrMale) / 2; //average = (bmrFemale + bmrMale) / 2
    chocolateBars = averageCalories / 230; //chocolateBar = average / 230
   
    /***** OUTPUT SECTION *****/

    cout << "Your weight in pounds: " << weight << endl;
    cout << "Your height in inches: " << height << endl;
    cout << "Your age: " << age << "\n" << endl;
    cout << "If you are a woman then to maintain your weight you will need " << bmrFemale << " calories." << endl;
    cout << "If you are a man then to maintain your weight you will need " << bmrMale << " calories." << endl;
    cout << "You should be able to consume about " << chocolateBars << " chocolate bars per day." << endl;

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}