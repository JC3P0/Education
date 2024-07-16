/*----------------------------------
* Program Name: Project5C.java
* Programmer Name: Josh Clemens
* Description: This program creates an array of objects using the Event Class file, initializes them all to default values then displays.
* Date: 07-23-22
-----------------------------------*/

class Main {
    public static void main(String[] args) {

        //create an array of objects
        Event[] eventObj;
        eventObj = new Event[5];

        //for loop to initialize all objects in array to default values
        for (int i=0; i < eventObj.length; i++){
            eventObj[i] = new Event('x', 0.0);
        }

        //print all objects in array
        for (int i=0; i < eventObj.length; i++){
            System.out.println(eventObj[i].getEventType());
            System.out.println(eventObj[i].getEventMinRate());        
        }
    }
}