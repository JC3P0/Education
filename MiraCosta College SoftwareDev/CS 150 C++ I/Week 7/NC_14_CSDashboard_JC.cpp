/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC14
* LAST MODIFIED: 03/07/22
*____________
* CSDashboard
*_____________________
* PROGRAM DESCRIPTION:
* Uses several functions to ask for input and display various student success rates.
*___________
* ALGORITHM:
* PROMPT Ethnicity, Gender, age
* OUTPUT invalid entries
* PROMPT success rate by age, ethnicity, gender or quit
* OUTPUT results or quit per user input
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
*____________________________________________*/

#include <cstdlib>
#include <iostream>
using namespace std;

void dashboardMenu();

void ethnicityMenu();
double successByEthnicity(int ethnicityInput);
bool valEthnicityMenu(int ethnicityInput);

void genderMenu();
double successByGender(int genderInput);
bool valGenderMenu(int genderInput);

void ageInputMenu();
double successByAgeGroup(int genderInput);  
bool valAgeInputMenu(int ageInput);

int ethnicityInput = 0;
int genderInput = 0;
int ageInput = 0;

int main() 
{
    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/

    int input;
    
    /***** INITIALIZATION SECTION *****/
    // no init.
    
    /***** INTRO SECTION *****/ 

    cout << "Welcome to the MiraCosta Data Dashboard and the CS Success Dashboard.\n";
    
    /***** INPUT SECTION *****/ /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/
 
    do 
    {
        dashboardMenu();
        cin >> input;
        if (input != 7)
        {
            while (input == 1)
            {
                ethnicityMenu();
                cin >> ethnicityInput;      
                break;
            }
            while (input == 2)
            {
                genderMenu();
                cin >> genderInput; 
                break;
            }
            while (input == 3)
            {
                ageInputMenu();
                cin >> ageInput;
                break;
            }
            while (input == 4)
            {
                if (valAgeInputMenu(ageInput))
                {
                    successByAgeGroup(ageInput); 
                }
                else 
                {
                    cout << "Age Not Entered\n";
                }
                break;
            }
            while (input == 5)
            {
                if (valEthnicityMenu(ethnicityInput))
                {
                    successByEthnicity(ethnicityInput);
                }
                else 
                {
                    cout << "Ethnicity Not Entered\n";
                }
                break;
            }
            while (input == 6)
            {
                if (valGenderMenu(genderInput))
                {
                    successByGender(genderInput); 
                }
                else 
                {
                    cout << "Gender Not Entered\n";
                }
                break;
            }
        }
    }while (input != 7);

    cout << "\nThank you for using the Data Dashboard.\n";

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

void dashboardMenu()
{
    cout << "\nPlease enter your following choice:\n";
    cout << "1 - Ethnicity Choice\n";
    cout << "2 - Gender Choice\n";
    cout << "3 - Age Input\n";
    cout << "4 - Success By Age Group\n";
    cout << "5 - Success By Ethnicity\n";
    cout << "6 - Success By Gender\n";
    cout << "7 - Quit\n";
    cout << "Please enter your choice: \n";
}

void ethnicityMenu()
{
    cout << "\nEthnicity:\n";
    cout << "1 - American Indian/Alaska Native\n";
    cout << "2 - Asian\n";                        
    cout << "3 - Black/African American\n";
    cout << "4 - Hispanic\n";
    cout << "5 - Pacific Islander\n";
    cout << "6 - Two or More Races\n";
    cout << "7 - White\n";
    cout << "8 - Unknown\n";
    cout << "Please enter your choice:\n";
}

double successByEthnicity(int ethnicityInput)
{
    switch (ethnicityInput)
    {
        case 1:
            cout << "The student success for American Indian/Alaska Native is 66.7 %\n";
            break;
        case 2:
            cout << "The student success for Asian is	67.2 %\n";
            break;
        case 3:
            cout << "The student success for Black/African American is 39.2 %\n";
            break;
        case 4:
            cout << "The student success for Hispanic is 48.5 %\n";
            break;
        case 5:
            cout << "The student success for Pacific Islander is 20.0 %\n";
            break;
        case 6:
            cout << "The student success for Two or More Races is 58.7 %\n";
            break;
        case 7:
            cout << "The student success for White is 62.8 %\n";
            break;
        case 8:
            cout << "The student success for Unknown is 53.0 %\n";
            break;                
    }    
    return ethnicityInput;
}

bool valEthnicityMenu(int ethnicityInput)
{
    bool status;
    if (ethnicityInput > 0)
        status = true;
    else
        status = false;
    return status;
}

void genderMenu()
{
    cout << "\nGender:\n";
    cout << "1 - Male\n";
    cout << "2 - Female\n";                        
    cout << "3 - Unknown\n";
    cout << "Please enter your choice:\n";
}

double successByGender(int genderInput)
{
    switch (genderInput)
    {
        case 1:
            cout << "The student success for Male is 58.4 %\n";
            break;
        case 2:
            cout << "The student success for Female is 70.1 %\n";
            break;
        case 3:
            cout << "The student success for Unknown is 53 %\n";
            break;               
    }    
    return genderInput;
}

bool valGenderMenu(int genderInput)
{
    bool status;
    if (genderInput > 0)
        status = true;
    else
        status = false;
    return status;
}

void ageInputMenu()
{
    cout << "\nAge:\n";
    cout << "1) 17 and under\n";
    cout << "2) 18 - 20\n";                        
    cout << "3) 21 - 24\n";
    cout << "4) 25 - 29\n";
    cout << "5) 30 - 34\n";                        
    cout << "6) 35 - 39\n";
    cout << "7) 40 - 44\n";
    cout << "8) 45 - 54\n";                        
    cout << "9) 55 - 64\n";
    cout << "10) 65 and Older\n";
    cout << "Please enter your choice:\n";
}

double successByAgeGroup(int ageInput)
{
    switch (ageInput)
    {
        case 1:
            cout << "The student success for 17 and under is 71.4 %\n";
            break;
        case 2:
            cout << "The student success for 18 - 20 is 60.8 %\n";
            break;
        case 3:
            cout << "The student success for 21 - 24 is 54.6 %\n";
            break;        
        case 4:
            cout << "The student success for 25 - 29 is 57.9 %\n";
            break;
        case 5:
            cout << "The student success for 30 - 34 is 62.5 %\n";
            break;
        case 6:
            cout << "The student success for 35 - 39 is 61.7 %\n";
            break; 
        case 7:
            cout << "The student success for 40 - 44 is 47.1 %\n";
            break;
        case 8:
            cout << "The student success for 45 - 54 is 65.9 %\n";
            break;
        case 9:
            cout << "The student success for 55 - 64 is 60.7 %\n";
            break; 
        case 10:
            cout << "The student success for 65 and Older is 33.3 %\n";
            break;
    }    
    return ageInput;
}

bool valAgeInputMenu(int ageInput)
{
    bool status;
    if (ageInput > 0)
        status = true;
    else
        status = false;
    return status;
}
