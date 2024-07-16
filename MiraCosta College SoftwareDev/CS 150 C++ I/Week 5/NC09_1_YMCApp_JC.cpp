/*______________________
* AUTHOR: <Josh Clemens>
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: <NC09_1>
* LAST MODIFIED: <02/23/22>
*_______
* YMCApp 
*_____________________
* PROGRAM DESCRIPTION:
* Offers six membershiip choices with joiner fees. Invalid choices will display "Invalid Choice."
*___________
* ALGORITHM:
* PROMPT Membership Choices
* OUTPUT invalid for incorrect inputs
* PROMPT Membership months wanting to purchase
* PROMPT New member (y/n)
* CALCULATE Membership fee per month * months purchased (if new member add new membership fee)
* OUTPUT the membership chosen and amount of months chosen, if new member or existing, total cost
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
int main(int argc, char *argv[]) {

    /***** CONSTANT SECTION *****/
    // no constant
 
    /***** DECLARATION SECTION *****/

    int choice;
    int newMemFee; // $60
    int newMemFeeTeen; // $30
    string newMem;
    bool valid; // for while loop
    double monthlyFee; // fee amount per chosen membership
    double memMonths; // number of months to register
 
    /***** INITIALIZATION SECTION *****/
    
    newMemFee = 60;
    newMemFeeTeen = 30;
           
    /***** INTRO SECTION *****/

    cout << " Welcome to the \n"
         << "  _   _ _ __ ___   ___ __ _ \n"
         << " | | | | '_ ` _ \\ / __/ _` |\n"
         << " | |_| | | | | | | (_| (_| |\n"
         << "  \\__, |_| |_| |_|\\___\\__,_|\n"
         << "   __/ |\n"
         << "  |___/\n";
    cout << " \n";

     
    /***** INPUT SECTION *****/
    
    cout << "Joe and Mary Mottino Falimy Center\n";
    cout << " \n";
    cout << "Please choose your membership option:\n";
    cout << "1 - Family I (1 adult and children 25 and under)\n";
    cout << "2 - Adult (ages 26-64)\n";
    cout << "3 - Dual Adult (2 adults at the same address)\n";
    cout << "4 - Family II (2 adult and children 25 and under)\n";
    cout << "5 - Teen/Young Adult (ages 13 - 25)\n";
    cout << "6 - Senior (Ages 65+)\n";
    cout << "Choice: ";
    cin >> choice;
    cout << " \n";
                
    /***** PROCESSING SECTION *****/
    
    valid = false;    
    while (!valid) 
    {
        switch (choice)
        {   case 1:
                monthlyFee = 75;
                valid = true;
                break; 
            case 2:
                monthlyFee = 54;
                valid = true;
                break;
            case 3:
                monthlyFee = 84;
                valid = true;
                break;
            case 4:
                monthlyFee = 94;
                valid = true;
                break;
            case 5:
                monthlyFee = 37;
                valid = true;
                break;
            case 6:
                monthlyFee = 47;
                valid = true;
                break;
            default:
                cout << "Invalid option, Please try again\n";
                cout << "Choice: ";
                cin >> choice;
                cout << endl;
        }
    }
    
    /***** INPUT SECTION *****/
    
    cout << "How many months would you month(s) would you like to purchase? ";
    cin >> memMonths;
    cout << "Are you a new member? (y/n) ";
    cin >> newMem;
    cout << endl;
    
    /***** PROCESSING & OUTPUT SECTION *****/
    
    if (choice == 1)
    {   monthlyFee *= memMonths;
        cout << "You chose the Family I membership for " << memMonths << " month(s)." << endl; 
    }
        
    else if (choice == 2)
    {   monthlyFee *= memMonths;
        cout << "You chose the Adult membership for " << memMonths << " month(s)." << endl; 
    }
        
    else if (choice == 3)
    {   monthlyFee *= memMonths;
        cout << "You chose the Dual Adult membership for " << memMonths << " month(s)." << endl; 
    }
        
    else if (choice == 4)
    {   monthlyFee *= memMonths;
        cout << "You chose the Family II for " << memMonths << " month(s)." << endl; 
    }
        
    else if (choice == 5)
    {   monthlyFee *= memMonths;
        cout << "You chose the Teen/Young Adult membership for " << memMonths << " month(s)." << endl; 
    }
        
    else if (choice == 6)
    {   monthlyFee *= memMonths;
        cout << "You chose the Senior membership for " << memMonths << " month(s)." << endl; 
    }

    if (newMem == "n" || newMem == "N")
    {   cout << "You are a returning member, welcome back!" << endl;
        cout << "Your total cost is $" << monthlyFee << endl;
    }
        
    else if (newMem == "y" || newMem == "Y")
    {   if (choice == 5) //option 5 is the only option with $30 joiners fee
        {   newMemFee -= newMemFeeTeen;
            newMemFee += monthlyFee;
        }
        else
            newMemFee += monthlyFee;
        cout << "You are a new member, welcome!" << endl;
        cout << "Your total cost is $" << newMemFee << endl;
    }
                         
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}
