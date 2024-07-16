/*----------------------------------
* Program Name: Project4A.java
* Programmer Name: Josh Clemens
* Description: The program asks user for even type and displays the manager per option.
* Date: 07-12-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main {
    public static void main(String[] args) {

        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);

        //Declaring and initializing char variable with default value
 		char menuOption = ' ';

        //intro
        System.out.println("Welcome to the Project4 program!");
        
        System.out.println("Enter type of event you are scheduling");
        //Displaying menu
        System.out.println ( "\nC.) Corporate event\nP.) Private event" );

        //get user input
        System.out.print("\nEvent Type you Choose is: ");
        menuOption = scan.next().charAt(0);	

        if (menuOption == 'c' || menuOption == 'C' ){
            System.out.println ( "\nThe manager for this event will be Dustin Britt" );
        }
            else if(menuOption == 'p' || menuOption == 'P' ){
                System.out.println ( "\nThe manager for this event will be Carmen Lindsey" );
		    }
                else // if user does not choose from a menu option an error in displayed
        					System.err.println ( "Invalid option selected!" );


        //goodbye message
        System.out.println ("\nThank you for using the Project4 program!");
        
        scan.close();// close scanner
    }
}