#ifndef EVENT_H
#define EVENT_H

class Event {
private:
    //uses TimeDate objects, composition
    TimeDate startTime, endTime;
    string description;

public:
    Event(int startHour, int startMinute, int startDay, string startMonth,
        int endHour, int endMinute, int endDay, string endMonth,
        string description ):
        //composition
        startTime(startHour, startMinute, startDay, startMonth),
        endTime(endHour, endMinute, endDay, endMonth),
        description(description){ };

    string getEvent(){
        return description + " starts at " + startTime.getTimeDate()
            + ", ends at " + endTime.getTimeDate();
    }
};

#endif EVENT_H
