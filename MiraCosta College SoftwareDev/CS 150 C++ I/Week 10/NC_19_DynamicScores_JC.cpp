/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_19
* LAST MODIFIED: April 07, 2022
*_______________
* Dynamic Scores
*_____________________
* PROGRAM DESCRIPTION:
* Dynamicaly allocates an array to hold user defined test scores. Uses three functions to calculate and display the average, mode(if none return -1) and sorts test scores from lowest to highest.
*___________
* ALGORITHM:
* PROMPT user defined array of test scores.
* PROMPT (loop) user input test scores.
* VALIDATE for no negative test scores.
* CALCULATE average, mode(if none return -1), sort (lowest to highest)
* OUTPUT average, mode, sort (lowest to highest)
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
* <iomanip> setprecision(2)
* <algorithm> sort (lowest to highest)
*____________________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

//function prototypes
void sort(int n, int* ptr);
int getMode(int list[], int arraySize);
double getAverage(double total, double input);

int main(int argc, char* argv[]) {

    /***** CONSTANT SECTION *****/
    //no const.
  
    /***** DECLARATION SECTION *****/ 
    //no dec.
    
    /***** INITIALIZATION SECTION *****/

    int *ptr = nullptr; //pointer to dynamicaly allocate an array
    double total = 0; //to calculate average
    int numTests = 0; //user input for number of tests to input
    int counter = 0; //used to validate input
       
    /***** INTRO SECTION *****/

    cout << "Welcome to the Dynamic Scores program!!!\n";
        
    /***** INPUT SECTION *****/

    cout << "\nEnter the amount of test scores to process: ";
    cin >> numTests;
    while (numTests < 0){
        cout << "\nInvalid Entry.";
        cout << "\nEnter a score above 0, negative scores not accepted.";
        cin >> numTests;
    }
           
    //dynamically allocate an array large enough to hold test scores per user input
    ptr = new int[numTests];

    do{
        counter = numTests; //while condition to validate negative input
        cout << "\nNegative scores will not be accepted.\n";
        
        //get scores for each test
        for (int count = 0; count< numTests; count++) { 
            cout <<"Enter test "<< (count + 1) << " score: "; 
            cin >> ptr[count];
            
            //validate for negative input
            if (ptr[count] < 0){
                counter++; //changes while condition to validate negative input
                cout << "\nInvalid Entry!";
                cout << "\nEnter a score above 0.";
                cout << "\nRe-enter test scores!!!";
                cout << "\nEnter any key to continue. . .\n";
                cin.ignore(); //ignore next input(void next input for user to continue the program)
                cin.get(); //makes user enter any key to continue
                break;
            }
        }        
    }while (counter != numTests);
        
    /***** PROCESSING SECTION *****/ 

    //Calculate the total sales 
    for (int count = 0; count< numTests; count++){
        total += ptr[count];
    }
   
    /***** OUTPUT SECTION *****/

    cout << "\nTest scores sorted lowest to highest.\n";
    sort(numTests, ptr);//bubble sort        
    cout << setprecision(2) <<fixed<< showpoint; 
    cout << endl;
    cout << "\nAverage score: "<< getAverage(total, numTests); 
    cout << "\nMode of test scores: " << getMode(ptr,numTests);
    cout << endl;

    //Free dynamically allocated memory 
    delete [] ptr; 
    ptr = nullptr ; 
       
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
    for (i = 0; i < n; i++)
        printf("%d ", *(ptr + i));
}

//calculate mode
//if more than one mode, will return the first found mode
int getMode(int array[], int arraySize){

    int count = 0;
    int findMode = 0;
    int mode = 0;
    for(int j = 0; j < arraySize; j++){
        for(int i = 0; i < arraySize; i++){
                if(array[i] == array[j]){
                    //counts when two of the same numbers occur
                    count++; 
                }
        }
        
        //if the new count is higher than the previous, then a new value is made
        if(count > findMode){ 
                mode = array[j];//sets the most recently found mode
                findMode=count;
        }
        count = 0;//resets to find a new possible mode
    }
    if(findMode > 1){
        return mode;
    }
    return -1;
}

//calculate avg score
double getAverage(double total, double input){

    double average = 0;
    average = total / input;

    return average;
}


