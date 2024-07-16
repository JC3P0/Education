#ifndef NUMBERS_H
#define NUMBERS_H

#include <cstring>
#include <iostream>
using namespace std;

class Numbers{
private:
    int number;

public:
    static const string lessThan20[];
    static const string tens[];
    static const string hundreds;
    static const string thousands;
    Numbers();
    Numbers(int number);
    double getNumber() const;
    void setNumber(int number);
    string numberToEnglish(int number);
    void print();
};

Numbers::Numbers() : Numbers(0){
    number = 0;
}

//constructor
Numbers::Numbers(int number){
    this-> number = number;
}

double Numbers::getNumber() const{
    return number;
}

void Numbers::setNumber(int number){
    this->number = number;
}

string Numbers::numberToEnglish(int number){
    
    int convert;
    string name;
    // handles numbers under 20
    if (number < 20){
        name = name + lessThan20[number];
        return name;
    // handles numbers over 20 and below 100    
    } else if (number < 100) {
        // cout << "\nTesting number less than 100 " << number; // testing line
        name = name + tens[number / 10] + " " + lessThan20[number % 10];
        return name;
    // handles numbers over 100 and below 1000    
    } else if (number < 1000) {
        convert = number;
        name = name + lessThan20[number / 100] + hundreds + " ";
        //calculate for tens placement, % 100 then / 10
        convert = convert % 100;
        convert /= 10;
	// cout << "\nTesting convert for 100's: " << convert; //testing line
        name = name + tens[convert] +  " " + lessThan20[number % 10];
        return name;
    // handles if number is to the thousand exactly ex. 3000 or 6000    
    } else if (number % 1000 <= 0) {
        name = name + lessThan20[number / 1000] + thousands;
        return name;
    // handles numbers in the 1000s with numbers in hundreds, tens and ones
    } else if (number % 10 >= 0){
        convert = number;
        //calculate for hundreds placement, % 1000 then / 100
        convert = convert % 1000;
        // cout << "\nTesting convert for 1000's after % 1000: " << convert;
        convert /= 100;
        // cout << "\nTesting convert for 1000's after /= 100: " << convert;
        // cout << "\nTesting convert for 1000's after % 100: " << number % 100;
        name = name + lessThan20[number / 1000] + thousands + " " + lessThan20[convert] + hundreds + " " + lessThan20[number % 10];
        return name;
    }

}

#endif