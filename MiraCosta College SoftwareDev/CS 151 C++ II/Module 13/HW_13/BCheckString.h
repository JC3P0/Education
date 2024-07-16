#ifndef BCHECKSTRING_H
#define BCHECKSTRING_H

#include <iostream>
using namespace std;

// derived from STL string class
class BCheckString: public string {

private:
    string str; //holds the string

public:
    class BoundsException {};	// exception class

    //constructor
    BCheckString(string str): string(str) {
        this->str = str;
    }
    //return character at index, throw exception if out of bounds
    char operator[](int k){
        k--; //move back one to line up index
        if (k < 0 || k >= str.length()) {
            throw BoundsException(); //throw exception if negative or greater than the string length
        }
        return str[k];
    }
};

#endif 