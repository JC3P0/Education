//
// Created by JoshC on 10/9/2022.
//

#ifndef ENCRYPTABLESTRING_H
#define ENCRYPTABLESTRING_H

#include <iostream>

using namespace std;

class EncryptableString: public string{ //derived from string class

private:

public:

    EncryptableString(string);
    void encrypt(string str);
};

//constructor that takes STL string object
EncryptableString::EncryptableString(string sentence) : string(sentence){}

//adds 1 to the ASCII value to encrypt the string, skips spaces and punctuation
void EncryptableString::encrypt(string str) {

    //loop through entire string
    for (int i = 0; i <= str.length() - 1; i++){
        //check for lower and uppercase char a - x and numbers 0 - 7 then add 1.
        //8 and y get set to 9 and z after all other checks are complete
        if(str[i] >= 'a' && str[i] <= 'x'){
            str[i]++;
        } else if (str[i] >= 'A' && str[i] <= 'X') {
            str[i]++;
        } else if (str[i] >= '0' && str[i] <= '7') {
            str[i]++;
        }

        //check for char at end of letters and numbers 9 to 0, and z to a
        //must handle the char before 9 and z (ex. 8 and y) after handling 9 and z
        if (str[i] == 'z'){
            str[i] = 'a';
        } else if (str[i] == 'Z'){
            str[i] = 'A';
        } else if (str[i] == 'y'){
            str[i] = 'z';
        } else if (str[i] == 'Y'){
            str[i] = 'Z';
        } else if (str[i] == '9'){
            str[i] = '0';
        } else if (str[i] == '8'){
            str[i] = '9';
        }
    }
    //output encrypted string
    cout << str;
}

#endif ENCRYPTABLESTRING_H