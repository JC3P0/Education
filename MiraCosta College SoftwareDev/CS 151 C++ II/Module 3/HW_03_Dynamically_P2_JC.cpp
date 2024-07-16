/*______________________________________
* FILE: HW_03_Dynamically_P2_JC
* AUTHOR: Josh Clemens
* MODULE: 3
* PROJECT: 2
* LAST MODIFIED: September 12, 2022
* PROBLEM STATEMENT: Initialize a dynamically allocated integer array that holds data from 15 people. User to input the amount of pie eaten in a year, then calculate the mode of users inputs.
* ALGORITHM:
*     INITIALIZE array to hold user input for 15 people
*     LOOP to initialize all elements of array
*         INPUT pie eaten
*         VALIDATE for negative entry
*     CALCULATE sort and find mode of array
*     OUTPUT loop through all elements of array and output
*     OUTPUT mode of array
*______________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip> //setprecision(2)

using namespace std;

//function prototypes
void sort(int n, int *ptr);
int getMode(int list[], int arraySize);


int main() {

    /***** DECLARATION & INITIALIZATION SECTION *****/
    
    int *ptr = nullptr; //pointer to dynamicaly allocate an array
    int counter = 0; //used to validate input
    int numOfPeople = 15;
    
    //dynamically allocate an array large enough to hold 15 people
    // ptr = (new int + numOfPeople);
    ptr = new int[numOfPeople];

    /***** INTRO SECTION *****/

    cout << "Welcome to the Dynamic Pie program!!!\n";

    /***** INPUT SECTION *****/

    do{
        int tempPie = 0;
        counter = numOfPeople; //while condition to validate negative input
        
        cout << "\nNegative scores will not be accepted.\n";
        
        for (int i = 0; i < numOfPeople; i++) { 

            cout <<"\n" << i + 1 << ".Enter Pie eaten: ";
            cin >> tempPie;

            //validate for negative input
            //uses pointer notation
            if ( tempPie < 0){
                counter++; //changes while condition to validate negative input
                cout << "\nInvalid Entry!";
                cout << "\nEnter a score above 0.";
                cout << "\nRe-enter PIE!!!";
                cout << "\nEnter any key to continue. . .\n";
                cin.ignore(); //ignore next input(void next input for user to continue the program)
                cin.get(); //makes user enter any key to continue
                break;
            }

            (*(ptr + i)) = tempPie; //add user input to array using pointer notation

        }        
    }while (counter != numOfPeople);


    /***** PROCESSING / OUTPUT SECTION *****/

    cout << "\nPie eaten sorted lowest to highest.\n";
    sort(numOfPeople, ptr);      
    cout << setprecision(2) << fixed << showpoint; 
    cout << endl;

    // cout << "This is the output section in main\n";
    for (int i = 0; i < numOfPeople; i++){
        cout << (*(ptr + i));
        cout << endl;
    }

    cout << "\nMode of test scores: " << getMode(ptr, numOfPeople);
    cout << endl;

    //Free dynamically allocated memory 
    delete [] ptr; 
    ptr = nullptr; 

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;

}

/***** Function Definitions *****/

void sort(int n, int* ptr){ //bubble sort
    int i = 0;
    int j = 0;
    int t = 0;

    // Sort the numbers using pointers
    for (i = 0; i < n; i++) {  
        for (j = i + 1; j < n; j++) {  
            if (*(ptr + j) < *(ptr + i)) {
  
                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    } 

    // print the numbers
    // for (i = 0; i < n; i++)
    //     printf("%d ", *(ptr + i));
}

//calculate mode
//if more than one mode, will return the first found mode
int getMode(int array[], int arraySize){

    int count = 0;
    int findMode = 0;
    int mode = 0;
    for(int j = 0; j < arraySize; j++){
        for(int i = 0; i < arraySize; i++){
                //uses pointer notation
                if( *(array + i) == *(array + j)){
                    //counts when two of the same numbers occur
                    count++; 
                }
        }
        
        //if the new count is higher than the previous, then a new value is made
        if(count > findMode){ 
                //uses pointer notation
                mode = *(array + j);//sets the most recently found mode
                findMode=count;
        }
        count = 0;//resets to find a new possible mode
    }
    if(findMode > 1){
        return mode;
    }
    return -1;
}