/*______________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC13_1
* LAST MODIFIED: 03/07/22
*__________
* FUNctions
*_____________________
* PROGRAM DESCRIPTION:
* Tests four different functions including, counting capital and lower case letters as well as counting vowels and constants within the users input.
*___________
* ALGORITHM:
* PROMPT input sentence from user
* CALCULATE four functions for capital, lowercase, vowels and consonants
* OUTPUT the total amount of; capital, lowercase, vowel and consonants
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <ctype.h> counts capital and lowercase letters
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <ctype.h>
using namespace std;

int countCapitals(string inputStr);
int countLowercaseLetters(string inputStr);
int countVowels(string inputStr);
int countConstants(string inputStr);


int main() 
{
    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/

    string input;

    /***** INITIALIZATION SECTION *****/
    //no init.
    
    /***** INTRO SECTION *****/ 

    cout << "Welcome to the character counter program we will count all sorts of strings." << endl;
    cout << endl;
    
    /***** INPUT SECTION *****/

    cout << "Please enter your string:" << endl;
    getline(cin, input);
    cout << endl;
 
    /***** PROCESSING SECTION *****/
    //see functions

    /***** OUTPUT SECTION *****/

    cout << "Number of capitols = " << countCapitals(input) << endl;
    cout << "Number of lowercase = " << countLowercaseLetters(input) << endl;
    cout << "Number of vowels = " << countVowels(input) << endl;
    cout << "Number of consonants = " << countConstants(input) << endl;
    
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

int countCapitals(string inputStr)
{
    int count = 0;
    for (int i = 0; i < inputStr.size(); i++)
    {
        if (isupper(inputStr[i]))
        {
            count++;
        }
    }

    return count;
}

int countLowercaseLetters(string inputStr)
{
    int count = 0;
    for (int i = 0; i < inputStr.size(); i++)
    {
        if (islower(inputStr[i]))
        {
            count++;
        }
    }
    return count;
}

int countVowels(string inputStr)
{
    int count = 0;
    for (int i = 0; i < inputStr.size(); i++)
    {
        if (inputStr[i] == 'a' || inputStr[i] == 'e' || inputStr[i] == 'i' || inputStr[i] == 'o' ||              
            inputStr[i] == 'u' || inputStr[i] == 'A' || inputStr[i] == 'E' || inputStr[i] == 'I' ||              
            inputStr[i] == 'O' || inputStr[i] == 'U')
        {
        count++;
        }
    }
    return count;
}

int countConstants(string inputStr)
{
    int count = 0;
    for (int i = 0; i < inputStr.size(); i++)
    {
        if (inputStr[i] != 'a' || inputStr[i] != 'e' || inputStr[i] != 'i' || inputStr[i] != 'o' ||              
            inputStr[i] != 'u' || inputStr[i] != 'A' || inputStr[i] != 'E' || inputStr[i] != 'I' ||              
            inputStr[i] != 'O' || inputStr[i] != 'U')
        {
        count++;
        }
    }
    return count;
}
