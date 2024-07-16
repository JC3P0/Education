/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC10_1>
* LAST MODIFIED: <02/26/22>
*_____________
* Magic 8 Ball
*_____________________
* PROGRAM DESCRIPTION:
* Simulates the Magic 8 Ball game. Generates one of eight responses.
*___________
* ALGORITHM:
* PROMPT question for magic 8 ball
* CALCULATE random number 1-20
* OUTPUT a positive, nuetral, negative answer based on the random number generated
* PROMTP ask user to keep playing (yes,no) (use a do loop to repeat)
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
    string input;
    string again;
    
    /***** INITIALIZATION SECTION *****/

    srand(time(NULL)); //random number
    
    /***** INTRO SECTION *****/ 

    cout << "Welcome to the Magic 8 ball!\n";
    cout << endl; 

    /***** INPUT SECTION *****/
    
    do
    {   
        cout << "What question would you like to ask the Magical 8 ball?\n";
        cout << endl;
        getline (cin, input); // to input the question as a sentence

    /***** PROCESSING SECTION *****/
        
        answer = rand() % 20 + 1;

    /***** OUTPUT SECTION *****/

        switch (answer)
        {   
            case 1:
                cout << "The Answer is: It is Certain!!!\n";
                cout << "This answer is: Positive!\n";
                break;
            case 2:
                cout << "The Answer is: It is Decidedly so...\n";
                cout << "This answer is: Positive!\n";
                break;
            case 3:
                cout << "The Answer is: Most likely...\n";
                cout << "This answer is: Positive!\n";
                break;
            case 4:
                cout << "The Answer is: Signs point to yes!\n";
                cout << "This answer is: Positive!\n";
                break;
            case 5:
                cout << "The Answer is: Reply hazy, try again...\n";
                cout << "This answer is: Neutral.\n";
                break;
            case 6:
                cout << "The Answer is: Ask again later...\n";
                cout << "This answer is: Neutral.\n";
                break;
            case 7:
                cout << "The Answer is: Don't count on it..\n";
                cout << "This answer is: Negative...\n";
                break;
            case 8:
                cout << "The Answer is: My sources say no..\n";
                cout << "This answer is: Negative...\n";
                break;
            case 9:
                cout << "The Answer is: As I see it, yes.\n";
                cout << "This answer is: Positive!\n";
                break;
            case 10:
                cout << "The Answer is: Outlook good!\n";
                cout << "This answer is: Positive!\n";
                break;
            case 11:
                cout << "The Answer is: Without a doubt.\n";
                cout << "This answer is: Positive!\n";
                break;
            case 12:
                cout << "The Answer is: Yes definitely.\n";
                cout << "This answer is: Positive!\n";
                break;
            case 13:
                cout << "The Answer is: Yes...\n";
                cout << "This answer is: Positive!\n";
                break;
            case 14:
                cout << "The Answer is: You may rely on it.\n";
                cout << "This answer is: Positive!\n";
                break;
            case 15:
                cout << "The Answer is: Better not tell you now.\n";
                cout << "This answer is: Neutral.\n";
                break;
            case 16:
                cout << "The Answer is: Cannot predict now.\n";
                cout << "This answer is: Neutral.\n";
                break;
            case 17:
                cout << "The Answer is: Don't count on it..\n";
                cout << "This answer is: Negative...\n";
                break;
            case 18:
                cout << "The Answer is: Concentrate and ask again...\n";
                cout << "This answer is: Neutral.\n";
                break;
            case 19:
                cout << "The Answer is: Very doubtful.\n";
                cout << "This answer is: Negative...\n";
                break;
            case 20:
                cout << "The Answer is: Outlook not so good.\n";
                cout << "This answer is: Negative...\n";
                break;
        }
        
        cout << "Would you like to play again? (yes or no) ";
        getline (cin, again);
        while (again != "yes" && again != "no")
        {   
            cout << "Invalid input, please enter yes or no\n";
            cout << "Would you like to play again? (yes or no) ";
            getline (cin, again);
        }
               
    } while (again == "yes");

        cout << "Thank you for playing the Magic 8 ball.\n";
        
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}
