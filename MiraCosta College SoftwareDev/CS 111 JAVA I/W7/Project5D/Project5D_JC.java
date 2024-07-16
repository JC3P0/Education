/*----------------------------------
* Program Name: Project5D.java
* Programmer Name: Josh Clemens
* Description: This program combines project 4c and 5c to use for loops to initialize all Event objects in an array and if else statements to initialize objects per user input.
* Date: 07-30-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main {

    // constants
    static final double CORP_RATE = 75.99;
    static final double PRI_RATE = 47.99;
    static final double NON_PROF_RATE = 40.99;
    
    public static void main(String[] args) {

        //create an array of objects
        Event[] eventObj;
        eventObj = new Event[5];
        
        //Declaring and initializing char variable with default value
 		char menuOption = ' ';

        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);

        //intro
        System.out.println("Welcome to the CHOOSEMANAGER program!");

        //for loop to initialize all objects in array
        for (int i=0; i < eventObj.length; i++){
            
            System.out.println("\nEnter type of event you are scheduling");
            //Displaying menu
            System.out.println ( "\nC.) Corporate event\nP.) Private event\nN.) Non-profit event" );

            //get user input
            System.out.print("\nEvent Type you Choose is: ");
            menuOption = scan.next().charAt(0);	
            //initialize event objects per users input with defined constants
            if (menuOption == 'c' || menuOption == 'C' ){
                // set the menuOption and Rate
                eventObj[i] = new Event ('C', CORP_RATE);
            }
                else if(menuOption == 'p' || menuOption == 'P' ){
                    // set the menuOption and Rate
                    eventObj[i] = new Event ('P', PRI_RATE);
                }
                    else if(menuOption == 'n' || menuOption == 'N' ){
                        // set the menuOption and Rate
                        eventObj[i] = new Event ('N', NON_PROF_RATE);
                }
                    else // if user does not choose from a menu option an error in displayed
        			    System.err.println ( "Invalid option selected!" );
        }

        //add new line before display all events
        System.out.println(" ");
        //print all objects in array
        for (int i=0; i < eventObj.length; i++){
            System.out.println("Event " + (i+1) + " " + eventObj[i].getEventType() + " " +  eventObj[i].getEventMinRate());      
        }

        // goodbye message
        System.out.println ("\nThank you for using the CHOOSEMANAGER program!");
        
        scan.close(); // close scanner
    }
}