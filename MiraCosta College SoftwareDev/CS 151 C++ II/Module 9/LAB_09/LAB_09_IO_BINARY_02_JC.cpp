/*______________________________________
* FILE: LAB_09_IO_BINARY_MULTIPLY_02_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 9
* PROJECT: 2
* LAST MODIFIED: October 29, 22
* PROBLEM STATEMENT: Create 10 integers 1-10 in a binary file and the square root of each integer as 10 doubles.
*                    Then the program asks the user to enter a number to multiply each of the numbers by and write to binary file.
* ALGORITHM:
*    INITIALIZE file to store data
*    INITIALIZE fstream variable for input and output
*    INITIALIZE 10 integers 1-10 as binary numbers and the square root of each integer as 10 doubles
*    PROMPT user to enter a number (double) to multiply each of the int and doubles by
*    OUTPUT the 10 integers and 10 square roots multiplied by users input to file
*    END close file and exit program
*______________________________________*/
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {

    const string fileName = "array.dat"; // data file name
    fstream dataFile;
    double sqRoot = 0;
    double multiplier = 0;
    dataFile.open(fileName, ios::binary | ios::in | ios::out);
    if(!dataFile){ //validate if file can be opened
        cout << "Error, file not found\n";
        exit(1);
    }

    cout << "Enter the multiplier: ";
    cin >> multiplier;

    //read int from data file, multiply, and store back in the file
    cout << "Reading and updating ints...\n";
    for(int i = 1; i <= 10; i++){
        //read the next int in the file, save read pointer position
        int data = 0;
        long long position = dataFile.tellg();
        dataFile.read(reinterpret_cast<char *>(&data), sizeof(int));

        //display on screen and multiply
        cout << data << " -> ";
        data = round(data * multiplier);
        cout << data << endl;

        //set write pointer to read pointer's position, re-write on file
        dataFile.seekp(position, ios::beg);
        dataFile.write(reinterpret_cast<char *>(&data), sizeof(int));
    }
    
    //read double from data file, multiply, and store back in the file
    cout << "\nReading doubles...\n";
    for(int i = 0; i < 10; i++){
        //read the next double in the file, save read pointer position
        double datas = 0;
        long long position = dataFile.tellg();
        dataFile.read(reinterpret_cast<char *>(&datas), sizeof(double));

        //display on screen and multiply
        cout << datas << " -> ";
        datas = (datas * multiplier);
        cout << datas << " (root of " << datas * datas << ")" << endl;

        //set write pointer to read pointer's position, re-write on file
        dataFile.seekp(position, ios::beg);
        dataFile.write(reinterpret_cast<char *>(&datas), sizeof(double));
    }

    dataFile.close();
    return 0;
}
