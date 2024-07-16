/*______________________________________
* FILE: HW_11_RECURSIVE_TEST_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 11
* PROJECT: HW_2
* LAST MODIFIED: November 06, 2022
* PROBLEM STATEMENT: Write a isMember recursive function to check for numbers entered into an int array.
* ALGORITHM:
*    INITIALIZE isMember recursive function to search int array and return true if number is found and false is number is not found
*    PROMPT user to fill array of integers
*    LOOP while input != 2
*        PROMPT user to enter number to be searched in integer array
*        CALCULATE call isMember function to verify if number exists in the int array
*        OUTPUT if true or false
*        PROMPT menu input 1 continue or 2 to exit
*    END input == 2
*______________________________________*/

#include <iostream>

using namespace std;
//recursive function to return true or false 
bool isMember(int[], int, int);

int main(){
    
    const int SIZE = 5;
	int array[SIZE];
	int num = 0;
    int input = 0;
    //fill the int array with user input
    cout << "Enter " << SIZE << " integers.\n";
    for (int i = 0; i < SIZE; i++){
        cout << "#" << i + 1 << ": ";
        cin >> array[i];
    }


    while (input != 2){
        // Ask user to enter an integer
	    cout << "Enter a value to search for: ";
    	cin  >> num;
    
    	// Display the result of function isMember
    	if (isMember(array, SIZE, num)){
    		cout << num << " is a member of the array.\n"; //function returned true
    	} else {
    		cout << num << " is not a member of the array.\n"; //function returned false
        }
        //while condition
        cout << "\nEnter 1 to continue or 2 to exit. \nChoice: ";
        cin >> input;
        cout << endl;
    }
	return 0;
}
//recursive function to check array
bool isMember(int array[], int size, int num){
	if (*array == array[size]){
        return false;
    }
	if (*array == num){//base case
		return true;
	} else {
		return isMember(array + 1, size, num);//recursive function call
	}	
}