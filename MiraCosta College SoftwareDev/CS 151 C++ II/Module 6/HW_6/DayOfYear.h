#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <iostream>

using namespace std;

class DayOfYear{
private:
    int day;

public:
    static const string monthNames[]; //defined in main
    static const int monthValues[]; //defined in main
    DayOfYear(int day); //constructor accepting single data type
    DayOfYear(string month, int day); //constructor accepting two data types
    int getDay() const;
    void setDay(int day);
    DayOfYear operator++(); //prefix
    DayOfYear operator++(int); //postfix
    DayOfYear operator--(); //prefix
    DayOfYear operator--(int); //postfix
    friend ostream& operator<<(ostream& out, const DayOfYear& t);
};

//constructor accepting single data type
DayOfYear::DayOfYear(int day){
    //validate for days out of range
    if(day <= 0 || day > 365){
        cout << "You must enter a valid day (1 - 365)" << endl;
        exit(0);
    }
    this -> day = day;
}

//constructor accepting two data types
DayOfYear::DayOfYear(string month, int day){
    //validate for days out of range
    if(day <= 0 || day > 31){
        cout << "You must enter a valid day (1 - 28), (1 - 30), (1 - 31) depending on the month. \n"
                << day << " was entered." << endl;
        exit(0);
    }
    //use tempValue to calculate daysOfYear to begining of each month, then add days to set the day variable.
    int tempMonthValue = 0;
    if(month == "January"){
        tempMonthValue = 0;
        this -> day += (tempMonthValue + day);
    } else if (month == "February"){
        //validate for days out of range (at this point only months with 28 or 30 total days needs to be validated)
        if(day > 28){
            cout << "There are 28 days in February, " << day << " was entered." << "\nEnter a value (1 - 28) for February" << endl;
            exit(0);
        }
        tempMonthValue = 31;
        this -> day += (tempMonthValue + day);
    } else if (month == "March"){
        tempMonthValue = 59;
        this -> day += (tempMonthValue + day);
    } else if (month == "April"){
        //validate for days out of range
        if(day > 30){
            cout << "There are 30 days in April, " << day << " was entered." << "\nEnter a value (1 - 30) for April" << endl;
            exit(0);
        }
        tempMonthValue = 90;
        this -> day += (tempMonthValue + day);
    } else if (month == "May"){
        tempMonthValue = 120;
        this -> day += (tempMonthValue + day);
    } else if (month == "June"){
        //validate for days out of range
        if(day > 30){
            cout << "There are 30 days in June, " << day << " was entered." << "\nEnter a value (1 - 30) for June" << endl;
            exit(0);
        }
        tempMonthValue = 151;
        this -> day += (tempMonthValue + day);
    } else if (month == "July"){
        tempMonthValue = 181;
        this -> day += (tempMonthValue + day);
    } else if (month == "August"){
        tempMonthValue = 212;
        this -> day += (tempMonthValue + day);
    } else if (month == "September"){
        //validate for days out of range
        if(day > 30){
            cout << "There are 30 days in September, " << day << " was entered." << "\nEnter a value (1 - 30) for September" << endl;
            exit(0);
        }
        tempMonthValue = 243;
        this -> day += (tempMonthValue + day);
    } else if (month == "October"){
        tempMonthValue = 273;
        this -> day += (tempMonthValue + day);
    } else if (month == "November"){
        //validate for days out of range
        if(day > 30){
            cout << "There are 30 days in November, " << day << " was entered." << "\nEnter a value (1 - 30) for November" << endl;
            exit(0);
        }
        tempMonthValue = 304;
        this -> day += (tempMonthValue + day);
    } else if (month == "December"){
        tempMonthValue = 334;
        this -> day += (tempMonthValue + day);
      //validate month name, must match an if else above
    } else {
        cout << "Enter a valid month\n";
        exit(0);
    }
}


int DayOfYear::getDay() const{
    return day;
}

void DayOfYear::setDay(int day){
    this->day = day;
}

//++dayObjOne
DayOfYear DayOfYear::operator++(){
    if(getDay() > 364){
        setDay(1);
    } else {
        setDay(getDay()+1);
    }
    return *this;
}

//dayObjOne++
DayOfYear DayOfYear::operator++(int){
    DayOfYear temp(1);
    temp.setDay(getDay());
//    cout << "Temp obj " << temp; //testing line
    if(getDay() > 364){
        setDay(1);
    } else {
        setDay(getDay()+1);
    }
    return temp;
}

//--dayObjOne
DayOfYear DayOfYear::operator--(){
    if(getDay() == 1){
        setDay(365);
    } else {
        setDay(getDay() - 1);
    }
    return *this;
}

//dayObjOne--
DayOfYear DayOfYear::operator--(int){
    DayOfYear temp(1);
    temp.setDay(getDay());
//    cout << "Temp obj: " << temp; //testing line
    if(getDay() == 1){
        setDay(365);
    } else {
        setDay(getDay() - 1);
    }
    return temp;
}

//output stream
ostream& operator<<(ostream &out, const DayOfYear &t){
    int findMonth = 0;

    //starting at 0 with incrementing to test each monthValue till monthValues are greater than day
    while (DayOfYear::monthValues[findMonth] < t.day) {
        findMonth += 1; // increment for each pass through while loop
//        cout << "Testing findMonth: " << findMonth << endl; //testing lines
//        cout << "Testing monthValues[month] in while loop: " << DayOfYear::monthValues[findMonth] << endl; //testing lines
    }
    return out << DayOfYear::monthNames[findMonth - 1] << ", " << t.day - DayOfYear::monthValues[findMonth - 1] << " (Day: " << t.day << ")" << endl;
}

#endif DAYOFYEAR_H