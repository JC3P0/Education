#include "Month.h"
#include <iomanip>
 
Month::Month() : Month("January", 1){}

Month::Month(string name, int month){
    this-> name = name;
    this-> month = month;
          
}

string Month::getName() const{
    return name;
}

int Month::getNumber() const{
    return month;
}

void Month::setName(int month){
    switch (month){
        case 1: 
            this->name = "January";
            break;
        case 2:
            this->name = "Febuary";
            break;
        case 3:
            this->name = "March";
            break;
        case 4:
            this->name = "April";
            break;
        case 5:
            this->name = "May";
            break;
        case 6:
            this->name = "June";
            break;
        case 7:
            this->name = "July";
            break;
        case 8:
            this->name = "August";
            break;
        case 9:
            this->name = "September";
            break;
        case 10:
            this->name = "October";
            break;
        case 11:
            this->name = "November";
            break;
        case 12:
            this->name = "December";
            break;        
    }
}

void Month::setNumber(int month){
    switch (month){
        case 1: 
            this->month = 1;
            break;
        case 2:
            this->month = 2;
            break;
        case 3:
            this->month = 3;
            break;
        case 4:
            this->month = 4;
            break;
        case 5:
            this->month = 5;
            break;
        case 6:
            this->month = 6;
            break;
        case 7:
            this->month = 7;
            break;
        case 8:
            this->month = 8;
            break;
        case 9:
            this->month = 9;
            break;
        case 10:
            this->month = 10;
            break;
        case 11:
            this->month = 11;
            break;
        case 12:
            this->month= 12;
            break;        
    }
}

void Month::operator++(int){
    bool incrementMonth = false;
    if(month > 12){
        setNumber(1);
        incrementMonth = true;
    }else{
        setNumber(getNumber()+1);
    }
}

void Month::operator--(int){
    bool decrementMonth = false;
    if(month < 1){
        setNumber(12);
        decrementMonth = true;
    }else{
        setNumber(getNumber()-1);
    }
}

Month& Month::operator=(Month rhs){
    this->name = rhs.name;
    this->month = rhs.month;
    return *this;
}

ostream& operator<<(ostream& out, const Month& t){
    return out << "Month [" << t.name << "(" << t.month << ")]\n";   
}

bool operator==(Month a, Month b){
    return (a.month == b.month);  
}