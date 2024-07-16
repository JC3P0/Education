/*----------------------------------
* Program Name: Project4C.java
* Programmer Name: Josh Clemens
* Description: This program demonstrates calling of a constructor class and creating an object to be defined by users menu input.
* Date: 07-16-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main {

    // constants
    static final double CORP_RATE = 75.99;
    static final double PRI_RATE = 47.99;
    
    public static void main(String[] args) {

        // create object from Event class with default constructor
        Event anEvent = new Event();

        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);

        //Declaring and initializing char variable with default value
 		char menuOption = ' ';

        //intro
        System.out.println("Welcome to the CHOOSEMANAGER program!");
        
        System.out.println("Enter type of event you are scheduling");
        //Displaying menu
        System.out.println ( "\nC.) Corporate event\nP.) Private event" );

        //get user input
        System.out.print("\nEvent Type you Choose is: ");
        menuOption = scan.next().charAt(0);	

        if (menuOption == 'c' || menuOption == 'C' ){
            // set the menuOption and Rate
            anEvent.setMenuOption(menuOption);
            anEvent.setEventMinRate(CORP_RATE);
            System.out.println ( "\nThe manager for this event will be Dustin Britt" );
            System.out.println("Event type is: Corporate\nEvent rate is: " + anEvent.getEventMinRate());
        }
            else if(menuOption == 'p' || menuOption == 'P' ){
                // set the menuOption and Rate
                anEvent.setMenuOption(menuOption);
                anEvent.setEventMinRate(PRI_RATE);
                System.out.println ( "\nThe manager for this event will be Carmen Lindsey" );
                System.out.println("Event type is: Private\nEvent rate is: " + anEvent.getEventMinRate());
	    }
                else // if user does not choose from a menu option an error in displayed
        			System.err.println ( "Invalid option selected!" );

        // goodbye message
        System.out.println ("\nThank you for using the CHOOSEMANAGER program!");
        
        scan.close(); // close scanner
    }
}