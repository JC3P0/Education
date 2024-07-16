//
// Created by JoshC on 10/9/2022.
//

#ifndef PSTRING_H
#define PSTRING_H

#include <iostream>

using namespace std;

class PString: public string{ //derived from string class

private:

public:

    PString(string);
    bool isPalindrome(string str);
};

//constructor that takes STL string object
PString::PString(string sentence) : string(sentence){}

bool PString::isPalindrome(string str){

    // remove all spaces and some characters for testing
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(remove(str.begin(), str.end(), '-'), str.end());
    str.erase(remove(str.begin(), str.end(), ','), str.end());
    str.erase(remove(str.begin(), str.end(), '\''), str.end());
    str.erase(remove(str.begin(), str.end(), '!'), str.end());

    // make lowercase
    for (int i = 0; i <= right; i++){
        str[i] = tolower(str[i]);
    }

    // cout << "\nTesting in isPalindrome after removing special characters, spaces and lowercase: " << str;
    // cout << endl << endl;

    // create objects to be compared
    string s1 = str;
    string s2 = str;
    // reverse an object to compare
    reverse(s1.begin(), s1.end());

    //if true is palindrome, if false is not palindrome
    return s1 == s2;
}

#endif PSTRING_H