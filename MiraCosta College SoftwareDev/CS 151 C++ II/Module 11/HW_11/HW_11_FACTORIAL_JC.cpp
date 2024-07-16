/*______________________________________
* FILE: HW_11_FACTORIAL_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 11
* PROJECT: HW_1
* LAST MODIFIED: November 06, 2022
* PROBLEM STATEMENT: Write an iterative version of the factorial recursive function shown in the book. Output with both to compare.
* ALGORITHM:
*    INITIALIZE iterative and recursive factorial functions
*    LOOP while input != 2
*        PROMPT number to calculate factorial
*        CALCULATE factorial of number with both iterative and recursive functions
*    END input == 2
*______________________________________*/

#include <iostream>

using namespace std;
//use long to return as int does not hold large enough number
long factorial(int);
long iterativeFact(int);

int main() {

    int input = 0;
    int num = 0;
    while (input != 2){//while condition to end loop

        cout << "Enter number to find factorial: ";
        cin >> num;
        cout << endl;
        
        cout << "Factorial using recursion function: " << factorial(num) << endl;
        cout << "Factorial using iterative function: " << iterativeFact(num) << endl;

        //while condition
        cout << "\nEnter 1 continue or 2 to exit: ";
        cin >> input;
        cout << endl;
    }
    return 0;
}

//function definitions

long factorial(int num){//recursive factorial function
    if(num == 0){ //base case
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

long iterativeFact (int num){//iterative factorial function
    long temp = 1;
    for (int i = num; i > 1; i--){
        temp = temp * i;
    }
    if (num == 0){ //handles factorial of 0
        temp = 1;
    }
    return temp;
}