/*______________________________________
* FILE: LAB_09_IO_BINARY_01_JC.cpp
* AUTHOR: Josh Clemens
* MODULE: 9
* PROJECT: 1
* LAST MODIFIED: October 23, 22
* PROBLEM STATEMENT: Create 10 integers 1-10 in a binary file and the square root of each integer as 10 doubles.
* ALGORITHM:
*    INITIALIZE file to store data
*    INITIALIZE ofstream variable for binary output
*    INITIALIZE 10 integers 1-10 as binary numbers and the square root of each integer as 10 doubles
*    OUTPUT the 10 integers and 10 square roots to binary file
*    END close file and exit program
*______________________________________*/
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {

    const string fileName = "array.dat"; // data file name
    ofstream dataFile; //variable to write to file
    dataFile.open(fileName, ios::binary | ios::out);
    if(!dataFile){ //validate if file can be opened
        cout << "Error, file not found\n";
        exit(1);
    }
    
    //write 1-10 to binary file
    for (int i = 1; i <= 10; i++){
        dataFile.write(reinterpret_cast <char *>(&i), sizeof(int));
        // cout << i << "\n"; //testing line
    }
    
    //write the square root of 1-10 to binary file
    for (int i = 1; i <= 10; i++){
        double sqRoot;
        sqRoot = sqrt(i);
        cout << sqRoot << endl; //testing line
        dataFile.write((char *)&sqRoot, sizeof(double));
    }
    
    dataFile.close();
    return 0;
}