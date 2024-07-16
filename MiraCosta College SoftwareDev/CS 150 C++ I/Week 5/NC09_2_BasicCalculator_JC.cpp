/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC09_2>
* LAST MODIFIED: <02/24/22>
*_________________
* Basic Calculator 
*_____________________
* PROGRAM DESCRIPTION:
* Ask user to enter an operator (+, -, *, /, % or ^) and two operands, then calculates and displats the answer.
*___________
* ALGORITHM:
* PROMPT Num1, Num2, operands
* OUTPUT invalid for incorrect operand input
* CALCULATE (Num1) (operand) (Num2)
* OUTPUT Num1, Num2, operand, Answer
*____________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout)
* <cmath> used for pow()
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {

    /***** CONSTANT SECTION *****/
    // no constant
 
    /***** DECLARATION SECTION *****/

    char input;
    double num1, num2;

    /***** INITIALIZATION SECTION *****/

    bool valid = false;
      
    /***** INTRO SECTION *****/

    cout << " Josh's Ultra Spectacular Basic Calculator! \n"
         << "  _        _       _\n"
         << " / |      | |     / |\n"
         << "   |   _ _| |_ _    |\n"
         << "   |  |_ _   _ _|   |\n"
         << "  _|_     |_|      _|_\n";
    cout << " \n";

    
    /***** INPUT SECTION *****/

    cout << "Enter operand 1: ";
    cin >> num1;
    cout << "Enter operand 2: ";
    cin >> num2;
    cout << "Enter operator (+, -, *, /, % or ^): ";
    cin >> input;
    
    /***** PROCESSING & OUTPUT SECTION *****/

    while(!valid) 
    {
        switch (input) 
        {   case '+':
                cout << "Your answer is: " << (num1 + num2) << "." << endl;
                valid = true;
                break;
            case '-':
                cout << "Your answer is: " << (num1 - num2) << "." << endl;
                valid = true;
                break;
            case '*':
                cout << "Your answer is: " << (num1 * num2) << "." << endl;
                valid = true;
                break;
            case '/':
                cout << "Your answer is: " << (num1 / num2) << "." << endl;
                valid = true;
                break;
            case '%':
                cout << "Your answer is: " << (int(num1) % int(num2)) << "." << endl;
                valid = true;
                break;
            case '^':
                cout << "Your answer is: " << pow(num1,num2) << "." << endl;
                valid = true;
                break;
            default:
                cout << "Invalid input, try again.\n";
                cout << "Enter operator (+, -, *, /, % or ^): ";
                cin >> input;
                break;
        }
    }
            
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}
