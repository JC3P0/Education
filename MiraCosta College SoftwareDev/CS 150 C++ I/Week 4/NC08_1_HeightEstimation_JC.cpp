/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC08_1>
* LAST MODIFIED: <02/16/22>
*__________________
* Height Estimation
*_____________________
* PROGRAM DESCRIPTION:
* Finds the estimated adult height of a child based on height of the parents
*___________
* ALGORITHM:
* PROMPT gender, motherHeight, fatherHeight
* CALCULATE estimated adult height based on gender in inches
* OUTPUT estimated adult height in feet and inches based on gender
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
* <iomanip> update cout fixed setprecision(0)
* <cmath> used for floor function
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {

    /***** CONSTANT SECTION *****/
    // no constant
    
    /***** DECLARATION SECTION *****/

    string gender;
    float feet;
    float inches;
    double motherHeight;
    double fatherHeight;
    double hMA; //male estimated adult height
    double hFA; //female estimated adult height
        
    /***** INITIALIZATION SECTION *****/
    //no init.
           
    /***** INTRO SECTION *****/

    cout << "Welcome to the Height Estimation calculator!" << "\n" << endl;
     
    /***** INPUT SECTION *****/

    cout << "Enter the gender of the child [Ex. m, f, male, female]: ";
    cin >> gender;
    cout << "Enter the height of the child's mother: ";
    cin >> motherHeight;
    cout << "Enter the height of the child's father: ";
    cin >> fatherHeight;
    cout << "" << endl;

    /***** PROCESSING SECTION *****/
    
    if (gender == "f" || gender == "female") //calculate based on gender
    { hFA = ((fatherHeight * 12 / 13) + motherHeight) / 2;
      feet = floor(hFA / 12);
      inches = hFA - (feet * 12); }
    else if (gender == "m" || gender == "male")
    { hMA = ((motherHeight * 13 / 12) + fatherHeight) / 2;
      feet = floor(hMA / 12);
      inches = hMA - (feet * 12);}

    /***** OUTPUT SECTION *****/
    
    cout << fixed << setprecision(0);
    if (gender == "f" || gender == "female") //output based on gender
    { cout << "The calculated height of the child is " << feet << " feet and " << inches << " inches." << endl;}
    else if (gender == "m" || gender == "male")
    { cout << "The calculated height of the child is " << feet << " feet and " << inches << " inches." << endl; }
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}
