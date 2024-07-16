/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_20
* LAST MODIFIED: April 13, 2022
*_______________
* Soccer Players
*_____________________
* PROGRAM DESCRIPTION:
* Uses a structure to store soccer player's name, number, and goals scored. The program keeps an array of 11 soccer players. The program will display all players/number/goals (entered by user), total goals, and the player with the most goals.
*___________
* ALGORITHM:
* INIT. GLOBAL CONST soccerPlayers = 11
* PROMPT players name, number, goals scored. (store in sturcture)
* VALIDATE do not accept negative numbers for player's number or goals scored.
* CALCULATE total goals scored.
* CALCULATE player with most goals scored.
* DISPLAY all players name, number, goals scored, total goals, player with most goals scored.
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <iomanip> setw()
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

struct SoccerPlayer{
    string name;
    int number;
    int goals;
};

const int SOCCER_PLAYERS = 11;

//function prototypes
//getinfo
void getData(SoccerPlayer* players, const int count); 
//displaychart
void displayData(SoccerPlayer* players, const int count);
//get total
int calTotal(SoccerPlayer* players, const int count);
//lead scoreer
void topScorer(SoccerPlayer* players, const int count);

int main(int argc, char* argv[]){

    /***** CONSTANT SECTION *****/
    //no const.
 
    /***** DECLARATION SECTION *****/ 
    //no dec.
    
    /***** INITIALIZATION SECTION *****/

    SoccerPlayer players[SOCCER_PLAYERS];

    /***** INTRO SECTION *****/
    //in function
    
    /***** INPUT SECTION *****/

    getData(players, SOCCER_PLAYERS);
       
    /***** PROCESSING SECTION *****/ /***** OUTPUT SECTION *****/

    displayData(players, SOCCER_PLAYERS);
    cout << "Total goals " << calTotal(players, SOCCER_PLAYERS);
    cout << endl << endl;
    topScorer(players, SOCCER_PLAYERS);
     
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

void getData(SoccerPlayer* players, const int count){

    int counter = 0;
    system("clear");
    for (int i = 0; i < count; i++) {
        cout << "FC Bayern Munich Roster\n";
        cout << endl;
        //counts and displays the number of player's info entered
        cout << "Enter Player " << (counter + 1) << "'s info.\n";
        cout << "\nEnter player name: "; 
        //doing this will remove whitespace from the line,
        //this happens on the second iteration of the loop
        getline(cin >> ws, players[i].name); 
        // "cin >> ws" removes whitespace characters (enter)
        //getline(cin, players[i].name); //testing line
        cout << "Enter player number: ";
        cin >> players[i].number;
        cout << "Enter player goals: ";
        cin >> players[i].goals;
        //validate for negative goal entries
        while(players[i].goals < 0){
            cout << "Invalid Entry.\n";
            cout << "Negative numbers not accepted!\n";
            cout << "Enter player goals: ";
            cin >> players[i].goals;
        }
            
        counter++;//counts and displays the number of players entered
    }   
}

void displayData(SoccerPlayer* players, const int count){

    system("clear");
    cout << "FC Bayern Munich Roster\n";
    cout << endl;
    cout << "Name\t\t\t\tNumber\t\tGoals\n";
    for (int i = 0; i < count; i++) {
        cout << setw(20) << left << players[i].name;
        cout << setw(12) << left << players[i].number;
        cout << players[i].goals << endl;
    }
    cout << endl;
}

int calTotal(SoccerPlayer* players, const int count){
    int total = 0;
    for (int i = 0; i < count; i++){
        total += players[i].goals;
    }
    return total;
}

void topScorer(SoccerPlayer* players, const int count){
    string topName;
    int topGoal = 0;
    for (int i = 0; i < count; i++){
        if (topGoal < players[i].goals){
            
            topGoal = players[i].goals;
            topName = players[i].name;
        }
    }
    cout << "Leading Scorer - " << topName << "- " << topGoal;
}
    


