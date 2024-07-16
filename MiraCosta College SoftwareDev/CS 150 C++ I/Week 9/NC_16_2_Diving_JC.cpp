/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_16_02
* LAST MODIFIED: March 28, 2022
*_______
* Diving
*_____________________
* PROGRAM DESCRIPTION:
* Uses an array to input 7 judges scores then calculates the score.
*___________
* ALGORITHM:
* PROMPT dive difficulty
* PROMPT 7 judges scores
* CALCULATE (sum of judges score * dive difficulty) * 0.6
* OUTPUT total score
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
*____________________________________________*/

#include <cstdlib>
#include <iostream>
using namespace std;

double total(double score[], int length);
double highest(double array[], int length);
double lowest(double array[], int length);

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    
    const int TOTAL_SCORES = 7;
 
    /***** DECLARATION SECTION *****/ 

    double scores[TOTAL_SCORES];
    double dif = 0;
    double var = 0;
    
    /***** INITIALIZATION SECTION *****/
    

    /***** INTRO SECTION *****/

    cout << "Welcome to the judge diver program.\n";
    
    /***** INPUT SECTION *****/

    cout << "Enter the difficulty of the dive (1.2-3.8): ";
    cin >> dif;
    while (dif < 1.2 || dif > 3.8){
        cout << "Invalid entry." << endl;
        cout << "Enter the difficulty of the dive (1.2 - 3.8): ";
        cin >> dif;
    }
        
    
        
    
    /***** PROCESSING SECTION *****/ 

    for(int i = 0; i < TOTAL_SCORES; i++){
        cout << "Enter judge " << i+1 << " score: ";
        cin >> scores[i];
    }

    var = highest(scores, TOTAL_SCORES) + lowest(scores, TOTAL_SCORES);
    
    /***** OUTPUT SECTION *****/

    cout << "\nThe total score for the dive is " << ((total(scores, TOTAL_SCORES) - var) * dif) * 0.6 << "." << endl; 
    //cout << "highest " << highest(scores, TOTAL_SCORES) << " lowest " << lowest(scores, TOTAL_SCORES) << endl; //test line
    //cout << var; //test line
       
    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

double lowest(double array[], int length){
    int smallIndex = 0;
    for (int i = 1; i < length; i++){
        if (array[smallIndex] > array[i]){
            smallIndex = i;
        }
    }
    return array[smallIndex];
}

double highest(double array[], int length){
    int highIndex = 0;
    for (int i = 1; i < length; i++){
        if (array[highIndex] < array[i]){
            highIndex = i;
        }
    }
    return array[highIndex];
}

double total(double score[], int length){
    double sum = 0;
    for(int i = 0; i < length; i++){
        sum += score[i];
    }
    return sum;
}




