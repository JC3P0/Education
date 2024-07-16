/*______________________________________
* FILE: HW_09_SENTENCE_FILTER_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 9
* PROJECT: 1
* LAST MODIFIED: October 29, 2022
* PROBLEM STATEMENT: Reads from file and changes the first letter to capital and the rest of the sentence lowercase up to the period.
* ALGORITHM:
*    INITIALIZE input and output file
*    READ file that contains capital sentences with periods at the end
*    PROCESS convert the first letter to capital and the rest of the sentence to lowercase up to the next period.
*    OUTPUT the converted sentences to the output file
*______________________________________*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string input_file;  // To hold input file name
    string output_File; // To hold output file name
    char currentChar = ' '; // To hold character
    fstream inputFile;
    fstream outputFile;
    bool newSentence = true; //verify start of next sentence

    //get users input for input and output files
    cout << "Enter input file name: " << endl;
    cin >> input_file;

    cout << "Enter output file name: " << endl;
    cin >> output_File;

    //open files
    outputFile.open(output_File, ios::out);
    inputFile.open(input_file, ios::in);

    //validate if file can be opened
    if (inputFile) {
        while (inputFile.get(currentChar)) { //go through the file char by char
            if (currentChar == '.') {
                newSentence = true; //after each '.' start new sentence with capital
            }

            if(isalpha(currentChar)){
                if (newSentence) { //if this is the start of a new sentence then make the current char capital, otherwise make lower case
                    currentChar = toupper(currentChar);
                    newSentence = false;
                }
                else {
                    currentChar = tolower(currentChar);
                }
            }
            //write to outputfile
            outputFile.put(currentChar);
        }
        //close files
        inputFile.close();
        outputFile.close();
    }
    else {
        cout << "Cannot open file(s)." << endl;
    }

    cout << "\nFile conversion complete." << endl;
    return 0;
}