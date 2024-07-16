/*----------------------------------
* Program Name: SalesData.java
* Programmer Name: Josh Clemens
* Description: This program uses a for loop to get 12 months of sales data from user, then calculates each quarter and total annual sales from each input. Will also display the month with the highest volume and dollar amount of that month.
* Date: 07-30-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main {

    static final int MONTHS_IN_YEAR = 12;

    public static void main(String[] args) {

        //declare and initialize variables and array for processing
        double [] salesArray = new double[MONTHS_IN_YEAR];
        double firstQt = 0;
        double secondQt = 0;
        double thirdQt = 0;
        double fourthQt = 0;
        double total = 0;
        double highest = 0;
        int monthOfHighest = 0;
        
        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);

        //intro
        System.out.println("Welcome to the River's End Sales Data program!");

        //for loop to initialize all objects in array
        for (int i = 0; i < salesArray.length; i++){

            //get user input
            System.out.print("\nEnter the data for month: " + (i+1) + " $");
            salesArray[i] = scan.nextDouble();
            
        }

        //find 1,2,3,4 quarter totals
        firstQt = salesArray[0] + salesArray[1] + salesArray[2];
        secondQt = salesArray[3] + salesArray[4] + salesArray[5];
        thirdQt = salesArray[6] + salesArray[7] + salesArray[8];
        fourthQt = salesArray[9] + salesArray[10] + salesArray[11];
        
        //find total
        for (int i=0; i < salesArray.length; i++){
            total += salesArray[i];
        }

        //display totals and highest month values
        System.out.println("\nThe first quarter total is $" + firstQt);
        System.out.println("The second quarter total is $" + secondQt);
        System.out.println("The third quarter total is $" + thirdQt);
        System.out.println("The fourth quarter total is $" + fourthQt);
        System.out.println("The Annual sales total is $" + total);
        //calculate highest month and its value
        for (int i = 0; i < salesArray.length; i++){
            if(highest < salesArray[i]){
                highest = salesArray[i];
                monthOfHighest = (i+1);
            }
        }
        System.out.println("The highest volume was in month: " + monthOfHighest + " with $ " + highest);

        // goodbye message
        System.out.println ("\nThank you for using the River's End Sales Data program!");
        
        scan.close(); // close scanner
    }
}