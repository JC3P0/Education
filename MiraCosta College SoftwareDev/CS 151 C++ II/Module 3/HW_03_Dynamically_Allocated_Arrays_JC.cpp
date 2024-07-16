/*______________________________________
* FILE: HW_03_Dynamically_Allocated_Arrays_JC
* AUTHOR: Josh Clemens
* MODULE: 3
* PROJECT: Part 1 (Challenge 1 & 2) - Dynamically Allocated Arrays
* LAST MODIFIED: September 12, 2022
* PROBLEM STATEMENT: Create an array of Class objects to hold users defined name and test scores then calculate the total, average and sort in ascending order.
* ALGORITHM:
*     INITIALIZE a Dynamic array of objects to hold per users input
*     VALIDATE for negative inputs
*     LOOP to initialize all elements of array
*         INPUT Student name and score
*         VALIDATE for negative inputs
*         INITIALIZE a Student object with user input for name and score
*     CALCULATE total test scores, average test scores and sort test score in ascending order
*     OUTPUT loop through array of objects to output each object
*______________________________________*/

#include <cstdlib>
#include <iostream>
#include <iomanip> //setprecision(2)
#include "Student.h"
using namespace std;

//function prototypes
void selectionSort(Student *ptr, int size);
double getAverage(double total, double input);
// void swap(int *a, int *b);
void swap(Student& a, Student& b);
int main() {

    /***** DECLARATION & INITIALIZATION SECTION *****/
    
    int *ptr = nullptr; //pointer to dynamicaly allocate an array
    double total = 0; //to calculate average
    int numTests = 0; //user input for number of tests to input
    int counter = 0; //used to validate input

    //testing class lines
    // Student S1("Bob", 99);
    // cout << "This is S1 " << S1 << endl;
    // Student S2;
    // Student S3("Josh", 69);
    // S2 = S1;
    // cout << "S2 now = S1 " << S2 << endl;
    // S1 = S3;
    // cout << "S1 now = S3 " << S1 << endl;
    // S3 = S2;
    // cout << "S3 now = S2 " << S3 << endl;

    /***** INPUT SECTION *****/

    cout << "\nEnter the amount of test scores to process: ";
    cin >> numTests;
    while (numTests < 0){
        cout << "\nInvalid Entry.";
        cout << "\nEnter a score above 0, negative scores not accepted.";
        cout << "\nEnter the amount of test scores to process: ";
        cin >> numTests;
    }

    //dynamically allocate an array large enough to hold test scores per user input
    Student *ptrStudent[numTests];
    *ptrStudent = new Student[numTests];

    do{
        string tempName = " ";
        int tempScore = 0;
        counter = numTests; //while condition to validate negative input
        cout << "\nNegative scores will not be accepted.\n";
        
        
        for (int count = 0; count < numTests; count++) { 
            cout <<"Enter name ";
            cin >> tempName;
            cout <<"Enter score ";
            cin >> tempScore;

            //validate for negative input
            //uses pointer notation
            if ( tempScore < 0){
                counter++; //changes while condition to validate negative input
                cout << "\nInvalid Entry!";
                cout << "\nEnter a score above 0.";
                cout << "\nRe-enter test scores!!!";
                cout << "\nEnter any key to continue. . .\n";
                cin.ignore(); //ignore next input(void next input for user to continue the program)
                cin.get(); //makes user enter any key to continue
                break;
            }
            
            *(ptrStudent + count) = new Student (tempName, tempScore);
        }        
    }while (counter != numTests);


    /***** PROCESSING SECTION *****/ 

    //Calculate the total
    for (int count = 0; count< numTests; count++){
        total += (*(ptrStudent + count))->getScore();
    }
    

    /***** OUTPUT SECTION *****/

    // cout << "\nTest scores sorted lowest to highest.\n";
    // selectionSort(*ptrStudent, numTests);      
    cout << setprecision(2) << fixed << showpoint; 
    cout << endl;
    // cout << "This is the output section in main\n";
    for (int i = 0; i < numTests; i++){
        cout << (*(ptrStudent + i))->getName();
        cout << endl;
        cout << (*(ptrStudent + i))->getScore();
        cout << endl;
    }

    cout << "\nTotal: " << total;
    cout << endl;
    cout << "\nAverage score: "<< getAverage(total, numTests); 
    cout << endl;

    //Free dynamically allocated memory 
    delete [] ptr; 
    ptr = nullptr; 

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
    
}

/***** Function Definitions *****/


void selectionSort(Student *ptr, int size){
    
    int minIndex = 0;
    int minScore = 0;
    string minScoreName = "";
    
    for (int i = 0; i < (size); i++){  
        minIndex = i;
        minScore = (*(ptr + i)).getScore();
        minScoreName = (*(ptr + i)).getName();
        for (int index = i + 1; index < size; index++){
            if ((*(ptr + index)).getScore() < minScore){
                minScore = (*(ptr + index)).getScore();
                minScoreName = (*(ptr + index)).getName();
                minIndex = index;
            }
            
        }
        swap(*(ptr + minIndex), *(ptr + i));
        // swap((*(ptr + minIndex)).getScore(), (*(ptr + i)).getScore());
        // swap((*(ptr + minIndex)).getName(), (*(ptr + i)).getName());
    }
}

void swap(Student& a, Student& b){
    Student temp = a;
    a = b;
    b = temp;
}


// void swap(int *a, int *b)
// {
//     int *temp = a;
//     a = b;
//     b = temp;
// }

// void swap(String *a, String *b)
// {
//     String *temp = a;
//     a = b;
//     b = temp;
// }

// void sort(int count, Student *ptr){ 

    // int i = 0;
    // int j = 0;
    // int temp = 0;

    // Sort the numbers using pointers
    // for (int i = 0; i < count; i++) {  
    //     for (int j = i + 1; j < count; j++) {  
    //         if ((*(ptr + j)).getScore() < (*(ptr + i)).getScore()) {
  
    //             // t = (*(ptr + i)).getScore();
    //             // (*(ptr + i)).getScore() = (*(ptr + j)).getScore();
    //             // (*(ptr + j)).getScore() = t;
                
    //             temp = (*(ptr + i)).getScore();
    //             (*(ptr + i)).setScore((*(ptr + j)).getScore());
    //             (*(ptr + j)).setScore(temp);
    //         }
    //     }
    // } 

//calculate avg score
double getAverage(double total, double input){

    double average = 0;
    average = total / input;

    return average;
}