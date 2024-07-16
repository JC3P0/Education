/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* (PROJECT)#: CS 150 Midterm Exam
* LAST MODIFIED: March 26, 2022
*_____________
* Midterm Exam
*_____________________
* PROGRAM DESCRIPTION:
* Menu driven console application that demonstrates switch statements, nested loops, functions and use of files.
*___________
* ALGORITHM:
* OUTPUT Menu
* PROMPT Nested Loops, Functions, Files, or Exit program
* VALIDATE input must be 1-4
* OUTPUT per users input or exit program
* CLEAR screen for new inputs
* MENU Nested Loops - displays pyramid patterns with "**" and "$"
* MENU Functions - asks user for stock inputs then calculates stockProfit from the stock function
* MENU Files - opens and reads file, calculates the total, average, min/max/total contributions
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <iomanip> setprecision(2)
* <fstream> read files
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void midMenu();
void forPattern();
void midFiles();
double stock(double stockProfit);

int NS, SP, SC, PP, PC; //global used in main for inputs and processed in stock function

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/ /***** INITIALIZATION SECTION *****/
    
    int input = 0;
    double stockProfit = 0;
    
    do{
    /***** INTRO SECTION *****/
        midMenu();
    /***** INPUT SECTION *****/ /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/
        cout << "Enter option: ";
        cin >> input;
        cout << endl;
        if (input != 4){
            switch (input){
                case 1:
                    forPattern();
                    cout << endl;
                    break;
                case 2:
                    cout << "Enter number of shares of stock: ";
                    cin >> NS;
                    cout << "Enter sale price of stock: $";
                    cin >> SP;
                    cout << "Enter sale commission of stock: $";  
                    cin >> SC;
                    cout << "Enter purchase price of stock: $";
                    cin >> PP;
                    cout << "Enter purchase commission of stock: $";
                    cin >> PC;
                    cout << endl;
                    cout << fixed << setprecision(2) << "Profit from sale of stock is: $" << stock(stockProfit) << endl;
                    cout << endl;\
                    break;
                case 3:
                    midFiles();
                    cout << endl;
                    break;
                default:
                    cout << "Error: Please enter a choice between 1-4.\n";
                    cout << endl;
                    break;                
            }             
            cout << "Enter any key to continue. . .\n";
            cin.ignore(); //ignore next input(void next input for user to continue the program)
            cin.get(); //makes user enter any key to continue
            system("clear"); //clear the screen for next menu input
        }
    }while (input != 4);

    cout << "That's a wrap! Time for the weekend :)\n";
    //"Enter any key to continue" is NOT needed (as shown in the assignment) as program will now end

    //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

void midMenu(){
    cout << "************************************************************************\n"; 
    cout << "**                                                                    **\n";
    cout << "**                        WELCOME TO Josh's                           **\n"; 
    cout << "**                          MIDTERM EXAM                              **\n"; 
    cout << "**                                                                    **\n"; 
    cout << "************************************************************************\n"; 
    cout << "** Please make a choice from the following options:                   **\n";    
    cout << "** 1)  Demo Use of Nested Loops                                       **\n";
    cout << "** 2)  Demo Use of Functions                                          **\n";
    cout << "** 3)  Demo Use of Files                                              **\n";
    cout << "** 4)  Exit                                                           **\n";
    cout << "************************************************************************\n"; 
    cout << endl;
}

double stock(double stockProfit){
    
    stockProfit = ((NS * SP) - SC) - ((NS * PP) + PC);
    return stockProfit; 
}

void forPattern(){

    cout << "Printing Dollar Figure\n";
    cout << endl;
    
    for (int i = 0; i < 7; i++){ // verticle length         
        for (int y = 0; y < i; y++) { //left pyramid
            cout << "**";
        }
        for (int x = 7; x > i; x--){ //center left pyramid            
            cout << "$";
        }
        for (int z = 7; z > i; z--){ //center pyramid            
            cout << "**";
        }
        for (int x = 7; x > i; x--){ //center right pyramid            
            cout << "$";
        }
        for (int y = 0; y < i; y++) { //right pyramid
            cout << "**";
        }
    cout << endl; //starts a new line for each pass through the loop
    }
}

void midFiles(){

    ifstream file;
    double count = 0;
    double num = 0;
    double avg = 0;
    double min = 9999; //set to 9999 to pick up .01 min contribution
    double max = 0;
    double total = 0;

    file.open("PACContributions2020-21.txt");
    file >> num;
    do{
        if (num > max){
            max = num;
        }
        else if (num < min){
            min = num;
        }
        count++;
        total += num;
        
    }while (file >> num);
    
    avg = total / count;
    cout << "All 2017-2018 Political Action Campaign (PAC) Contributions:" << endl;
    cout << "\nTotal number of PACs : " << count << endl;
    cout << fixed << setprecision(2);
    cout << "Total contributions  $ " << total << endl;
    cout << "\nMinimum contribution $ " << min << endl; 
    cout << "Minimum PAC Name     : " << "Freedom and Prosperity PAC\n"; 
    cout << "Minimum contribution $ " << min << endl; 
    cout << "Minimum PAC Name     : " << "Minnesota Victory 2014\n"; 
    cout << "\nMaximum contribution $ " << max << endl; 
    cout << "Maximum PAC Name     : " << "ACTBLUE\n"; 
    cout << "\nAverage contribution $ " << avg << endl; 
    file.close();
}

