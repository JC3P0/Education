/*----------------------------------
* Program Name: CableCompanyLab.java
* Programmer Name: Josh Clemens
* Description: This program prompts user for account number and account type. Then prompts for premium channels and or service connections for business accounts. Then process and displays total bill.
* Date: 07-11-22
-----------------------------------*/

import java.util.*; //used for scanner
import java.text.DecimalFormat; // format decimal places and start with $

class Main {
    
    public static void main(String[] args) {

        // format decimal places to 2 also staring with $
        DecimalFormat bill = new DecimalFormat("$#.00");
        
        //instantiating Scanner Object
        Scanner scan = new Scanner(System.in);

        //declare and initialize variables
        int accountNumber = 0;
        char accountType = ' ';
        int premiumChannels = 0;
        int basicServices = 0;
        double billAmount = 0;

        //intro
        System.out.println("Welcome to the Cable Company Billing program!\n");

        //get user input
        System.out.print("Enter your account number: ");
        accountNumber = scan.nextInt();

        //Displaying menu
        System.out.println ( "\nMenu: \nA.) Residential\nB.) Business" );
        
        //Prompt for accountType
        System.out.print ( "Please select a menu option (a/b):  " );
        //scan and store to memory
        accountType = scan.next().charAt(0);				        

        switch (accountType){

            case 'A':
            case 'a':
                //get user input
                System.out.print("\nEnter how many premium channels to purchase: ");
                premiumChannels = scan.nextInt();
                premiumChannels *= 7.5; //price per premium channel
                billAmount += (4.5 + 20.5); // add processing and service fees
                billAmount += premiumChannels; //get total
                System.out.println("\nBilling Amount for account " + accountNumber + " is: " + bill.format(billAmount));
                break;

            case 'B':
            case 'b':   
                //get user input
                System.out.print("\nEnter how many premium channels to purchase: ");
                premiumChannels = scan.nextInt();
                premiumChannels *= 50; //price per premium channel
                System.out.print("Enter how many basic service connections are needed?: ");
                basicServices = scan.nextInt();
                if (basicServices <= 10){//for cases 10 and under
                    basicServices *= 75; //calculates each connection 10 and under at $75 each   
                }
                if (basicServices > 10){//for cases over 10
                    basicServices -= 10;//remove the inital 10 (at $75 each) for processing
                    basicServices *= 5; // calculates the $5 per connection over 10
                    basicServices += 750;//adds the 10 (at $75 each) that was subtracted to calculate $5 per service over 10
                }
                billAmount += 15; // add processing fee
                billAmount += premiumChannels; //get total
                billAmount += basicServices; //get total
                System.out.println("\nBilling Amount for account " + accountNumber + " is: " + bill.format(billAmount));
                break;

            default:
                System.out.printf("%c is an invalid selection", accountType);
                System.exit(0);

        }//end of switch

        //goodbye message
        System.out.println ("\nThank you for using the Cable Company Billing program!");

        scan.close(); // close scanner
    }//end main method
}//end main class