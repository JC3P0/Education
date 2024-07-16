/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC07_2>
* LAST MODIFIED: <02/14/22>
*____
* BMR
*_____________________
* PROGRAM DESCRIPTION:
* Extension of previous BMR calculator. Display only male or female formula
*___________
* ALGORITHM:
* INPUT gender, weight, height, age, activityLevel
* CALCULATE if and else statements to determine male or female
* CALCULATE bmrFactor to activty level
* CALCULATE male and female bmr
* CALCULATE bmr * bmrFactor
* OUTPUT Calories and chocolate bars per day (output only male or female results per input)
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
* <iomanip> update cout fixed setprecision(2)
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {

    /***** CONSTANT SECTION *****/
    // no constant
    
    /***** DECLARATION SECTION *****/

    string gender;
    bool isFemale;
    int activityLevel;
    double bmrFactor;
    double weight;
    double height;
    double age;
    double bmrFemale; //BMR=655 +(4.35 * weight) + (4.7 * height) - (4.7 * age)
    double bmrMale; //BMR=66 + (6.23 * weight) + (12.7 * height) -(6.8 * age)
    double chocolateBars; //chocolateBar = 230 calories
    
    /***** INITIALIZATION SECTION *****/
    //no init.
           
    /***** INTRO SECTION *****/

    cout << "Welcome to the Basal Metabolic Rate calculator!" << "\n" << endl;
     
    /***** INPUT SECTION *****/

    cout << "Enter your gender: ";
    cin >> gender;
    cout << "Enter your weight in pounds: ";
    cin >> weight;
    cout << "Enter your height in inches: ";
    cin >> height;
    cout << "Enter your age: ";
    cin >> age;
    cout << "" << endl;
    cout << "Enter your activity level: " << endl
         << "1. Sedentary (not active)" << endl
         << "2. Somewhat active (exercise occasionally)" << endl
         << "3. Active (exercise 3-4 times per week)" << endl
         << "4. Highly Active (exercise every day)" << endl;
    cout << "Activity Level? ";
    cin >> activityLevel;
    cout << "" << endl;

    /***** PROCESSING SECTION *****/
    
    if(gender == "male")
        { isFemale = false; }
    if(gender == "female")
        { isFemale = true; }
    if (activityLevel == 1)
        { bmrFactor = 1.2; }
        else if (activityLevel == 2)
        { bmrFactor = 1.3; }
        else if (activityLevel == 3)
        { bmrFactor = 1.4; }
        else if (activityLevel ==4)
        { bmrFactor = 1.5; }
    
    bmrFemale = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
    bmrMale = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);

    if (isFemale == true)
        { bmrFemale *= bmrFactor; 
          chocolateBars = bmrFemale / 230; } //chocolateBar = 230 calories
        else
        { bmrMale *= bmrFactor; 
          chocolateBars = bmrMale / 230; } //chocolateBar = 230 calories
    
    /***** OUTPUT SECTION *****/
    
    cout << fixed << setprecision(2);
    if (isFemale)
        { cout << "To maintain your weight you will need " << bmrFemale << " calories." << endl;
          cout << "You should be abble to consume about " << chocolateBars << " chocolate bars per day." << endl; }
        else
        { cout << "To maintain your weight you will need " << bmrMale << " calories." << endl;
          cout << "You should be abble to consume about " << chocolateBars << " chocolate bars per day." << endl; }


    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}