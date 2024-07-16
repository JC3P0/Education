#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

enum Meridiem { AM, PM};

class Time {
    private:
        unsigned int hour;
        unsigned int minute;
        Meridiem meridiem;
        
    public:
        Time();
        Time(unsigned int hour, unsigned int minute, Meridiem meridiem);
        unsigned int getHour() const;
        unsigned int getMinute() const;
        Meridiem getMeridiem() const;
        bool setHour(unsigned int hour);
        bool setMinute(unsigned int minute);
        bool setMeridiem(Meridiem meridiem);
        void operator++(int);
        void operator--(int);
        friend ostream& operator<<(ostream& out, const Time& t);
        friend bool operator==(Time a, Time b);
};

#endif