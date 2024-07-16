#ifndef TIMEDATE_H
#define TIMEDATE_H

class TimeDate{
private:
    int hour, minute, day;
    string month;

public:
    TimeDate(int hour, int minute, int day, string month):
        hour(hour),
        minute(minute),
        day(day),
        month(month){ };

    string getTimeDate(){
        string printHour = to_string(hour);
        // if hour is under 12 then the left side is true if hour is more than 12 then the right side is true
        string amPm = (hour < 12 ? "am" : "pm");
        if (hour == 0){
            printHour = "12";
        }
        //calculate for 12 hour clock
        if (hour > 12){
            printHour = to_string(hour - 12);
        }
        //if minute is less than 10 then 0 will return, if more than 10 nothing returns
        return month + " " + to_string(day) + " at " + printHour + ":" + (minute < 10 ? "0" : "")
            + to_string(minute) + amPm;
    }
};

#endif TIMEDATE_H