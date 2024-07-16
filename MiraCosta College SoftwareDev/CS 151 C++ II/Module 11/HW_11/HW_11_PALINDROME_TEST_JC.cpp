/*______________________________________
* FILE: HW_11_PALINDROME_TEST_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 11
* PROJECT: HW_3
* LAST MODIFIED: November 06, 2022
* PROBLEM STATEMENT: Uses a recursive isPalindrome function to return true if the input is the same forward and backwards and return false if it does not.
* ALGORITHM:
*    INITIALIZE recursive isPalindrome function to check if input is the same forward and backwards.
*    LOOP while input != 0
*        PROMPT get users input to test if palindrome
*        CALCULATE call isPalindrome function
*        OUTPUT if true or false
*        PROMPT input 0 to exit
*    END input == 0
*______________________________________*/

#include <iostream>

using namespace std;
//recursive funtion to check string forward and backwards
bool isPalindrome(const string&, int, int);

int main() {

    string str = "";
    int input = 0;
    while (str != "0"){

        //while condition
        cout << "(Enter 0 to exit) \nEnter a Palindrome to test: ";
        getline(cin, str); //get user input

        if(str == "0"){ //while condition
            break;
        }

        if (isPalindrome(str, 0, str.size() - 1)){
            cout << str << ": is a Palindrome!!!\n\n"; //true
        } else {
            cout << str << ": is not a Palindrome...\n\n"; //false
        }
        
    }
    return 0;
}
//function definitions
//recursive function to check string forward and backwards
bool isPalindrome(const string& str, int lower, int upper){
    if (str.size() <= 1){
        return true;
    }
    if (lower >= upper){ //base case
        return true;
    }
    while (!isalpha(str[lower]) && lower < str.size() - 1){
        lower++;
    }
    while (!isalpha(str[upper]) && upper > 0){
        upper--;
    }
    return toupper(str[lower]) == toupper(str[upper]) && isPalindrome(str, lower + 1, upper - 1);
}