/*______________________________________
* FILE: HW_08_WORD_COUNTER_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 8
* PROJECT: 1
* LAST MODIFIED: October 16, 22
* PROBLEM STATEMENT: Uses a function that takes a C-string as an argument and return the number of words is contains.
* ALGORITHM:
*    INITIALIZE numWords function to accept char array and the size. then calculate the total words it contains.
*    LOOP do while condition to enter 'q' to exit program
*        INPUT ask for users input to enter a sentence
*        VALIDATE input with 'q' to quit the program
*        CALCULATE total words in sentence
*        OUTPUT total words the sentence contains
*______________________________________*/

#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int numWords(char*, int);

int main() {

    //intro
    cout << "Welcome to the Word Counter program!!!\n\n";
    //used for user input
    char input[100];

    do{
        cout << "(Enter 'q' to exit) \nEnter a sentence to count the words: ";
        cin.get(input, 100);
        cin.clear();
        cin.ignore();

        //validate input for 'q' to break out of loop and end program
        if(input[0] == 'q'){
            break;
        }

        cout << "The sentence contains: " << numWords(input, strlen(input)) //call the numWords function
                << " word(s)" << endl << endl;

    } while (input[0] != 'q');

    //exit message
    cout << "\nThank you for using the Word Counter program!!!\n";

    return 0;
}

//counts spaces += 1 for total words
int numWords(char* sentence, int length){
    int wordCount = 0;

    if(length == 0){
        return wordCount;
    } else {
        wordCount++; //if there are characters word count starts at 1
    }

    for (int i = 0; sentence[i] != '\0'; i++){
        if (sentence[i] == ' '){
            wordCount++; //counts how many spaces + the 1 to start with to = total words
        }
    }
    return wordCount; //return the spaces counted + 1 for total words
}