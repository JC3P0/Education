/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC07_1>
* LAST MODIFIED: <02/14/22>
*________________________
* Roman Numeral Converter
*_____________________
* PROGRAM DESCRIPTION:
* Enter a number 1-10 to display the Roman numeral version of that number.
*___________
* ALGORITHM:
* CALCULATE if and else statements for only inputs of 1-10 (num >= 1 && <= 10)
* OUTPUT "Invalid input" for incorrect entries
* CALCULATE if statement (num == 1)
* OUTPUT Roman numeral version "I"
* REPEAT for numbers 2-10
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
*____________________________________________*/

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{

    /***** CONSTANT SECTION *****/
    //no constant
          
    /***** DECLARATION SECTION *****/

    int number;
    
    /***** INITIALIZATION SECTION *****/
    //no init.
      
    /***** INTRO SECTION *****/
    
    cout << "Roman Numeral Conversion\n";
    
    /***** INPUT SECTION *****/
    
    cout << "What number would you like to see? (1-10):\n";
    cin >> number;
        
    /***** PROCESSING SECTION *****/

    if (number >= 1 && number <= 10) 
    {
        if (number == 1) 
        { cout << "I" << endl; }
            else if (number == 2) 
        { cout << "II" << endl; } 
            else if (number == 3) 
        { cout << "III" << endl; } 
            else if (number == 4) 
        { cout << "IV" << endl; } 
            else if (number == 5) 
        { cout << "V" << endl; }  
            else if (number == 6) 
        { cout << "VI" << endl; }  
            else if (number == 7) 
        { cout << "VII" << endl; }  
            else if (number == 8) 
        { cout << "VIII" << endl; }  
            else if (number == 9) 
        { cout << "IX" << endl; }  
            else if (number == 10) 
        { cout << "X" << endl; }
     } 

    /***** OUTPUT SECTION *****/
        
    else 
    { cout << "Invalid input" << endl; }
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;    
 }