/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC10_2>
* LAST MODIFIED: <02/26/22>
*______________
* Guessing Game
*_____________________
* PROGRAM DESCRIPTION:
* Generates a random number between 1-100 and the user guesses till the correct number is chosen.
*___________
* ALGORITHM:
* CALCULATE a randomly generated number between 1-100
* PROMPT a guess (1-100)
* CALCULATE if guess is higher, lower or equal to the random number
* PROMPT guess until the user guesses the correct number
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
* <ctime> for time and date. Used to generate a new set of random numbers with srand()
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
int main(int argc, char *argv[]) {

    /***** CONSTANT SECTION *****/
    // no constant
 
    /***** DECLARATION SECTION *****/

    int answer;
    bool found = false;
    int guess;
    int counter;
    
    /***** INITIALIZATION SECTION *****/

    srand(time(NULL)); // random number
    answer = rand() % 100 + 1;
      
    /***** INTRO SECTION *****/

    cout << "Welcome to the Guessing Game! \n";
    cout << endl;
    
    /***** INPUT, PROCESSING, OUTPUT SECTIONS *****/

    cout << "How many guesses will you need to guess the number between 1 - 100?\n";
    cout << "Enter guess: ";
    cin >> guess;
    counter = 0;
    while (!found) 
    {   counter++;
        if (guess == answer) 
        {   found = true;
            cout << "Correct! you found the answer in " << counter << " guesses!\n";
        }
        else if (guess < answer)
        {   cout << "Too low! Guess again!\n";
            cout << "Enter guess: ";
            cin >> guess;
        }
        else if (guess > answer)
        {   cout << "Too high! Guess again!\n";
            cout << "Enter guess: ";
            cin >> guess;
        }
    }    
                         
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}
