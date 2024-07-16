#include "Time.h"
#include <iomanip>

//this will only work with C++ 11 and later
Time::Time() :  Time(12, 0, AM) {}

Time::Time(unsigned int hour, unsigned int minute, Meridiem meridiem) {
    this->hour = hour;
    this->minute = minute;
    this->meridiem = meridiem;
}

unsigned int Time::getHour() const {
    return hour;
}

unsigned int Time::getMinute() const {
    return minute;
}

Meridiem Time::getMeridiem() const {
    return meridiem;
}

bool Time::setHour(unsigned int hour) {
    if (hour > 12 || hour < 1) {
        return false;
    }
    this->hour = hour;
    return true;
}

bool Time::setMinute(unsigned int minute) {
    if (minute > 59){
        return false;
    }
    this->minute = minute;
    return true;
        
}

bool Time::setMeridiem(Meridiem meridiem) {
    if(meridiem != AM|| meridiem != PM) {
        return false;
    }
    this->meridiem = meridiem;
    return true;
}

void Time::operator++(int) {
    bool incrementHour = false;
    if(minute == 59) {
        setMinute(0);
        incrementHour = true;
    } else {
        setMinute(getMinute()+1);
    }
    bool changeMeridian = false;
    if (incrementHour) {
        if(hour == 11) {
            changeMeridian = true;
        }
        if(hour == 12) {
            setHour(1);
        }
        setHour(getHour()+1);
    }
    if(changeMeridian) {
        if(meridiem == AM) {
            meridiem = PM;
        } else {
            meridiem = AM;
        }
    }
}

void Time::operator--(int) {
    bool decrementHour = false;
    if(minute == 0) {
        setMinute(59);
        decrementHour = true;
    } else {
        setMinute(getMinute()-1);
    }
    bool changeMeridian = false;
    if (decrementHour) {
        if(hour == 12) {
            changeMeridian = true;
        }
        if(hour == 1) {
            setHour(12);
        }
        setHour(getHour()-1);
    }
    if(changeMeridian) {
        if(meridiem == AM) {
            meridiem = PM;
        } else {
            meridiem = AM;
        }
    }
}

// friend declaration does not declare a member function
// this operator<< still needs to be defined, as a non-member
ostream& operator<<(ostream& out, const Time& t)
{
    string strMeridiem = " AM";
    if(t.meridiem == PM) {
        strMeridiem = " PM";
    }
    return out << "Time [" << t.hour << ":" << setw(2)
        << setfill('0') << t.minute 
        << strMeridiem << "]";
}

 bool operator==(Time a, Time b) {
     return ((a.hour == b.hour) &&
         (a.minute == b.minute) &&
         (a.meridiem == b.meridiem));
 }