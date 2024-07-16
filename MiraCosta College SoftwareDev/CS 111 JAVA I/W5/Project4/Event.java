/*----------------------------------
* Program Name: Project4B.java
* Programmer Name: Josh Clemens
* Description: This "Event" class defines an event constructor also with a default constructor and get/set methods to set and return values
* Date: 07-16-22
-----------------------------------*/

public class Event{

    private char menuOption = ' '; //menu option
    private double eventMinRate = 0; //minimum rate of event

    // Event default constructor
    public Event(){
        menuOption = ' ';
        eventMinRate = 0;
    }

    // Event constructor
    public Event(char menOpt, double evntMR){
        menuOption = menOpt;
        eventMinRate = evntMR;
    }

    // sets users menuOption
    public void setMenuOption(char menOpt){
        menuOption = menOpt;
    }

    // set users eventMinRate
    public void setEventMinRate(double evntMR){
        eventMinRate = evntMR;
    }

    // gets users menuOption
    public char getEventType(){
        return menuOption;
    }

    // gets users eventMinRate
    public double getEventMinRate(){
        return eventMinRate;
    }
}

