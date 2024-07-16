/*----------------------------------
* Program Name: ExceptionWithIfElse.java
* Programmer Name: Josh Clemens
* Description: test input values with if else statement to validate divisor input to not be less than 0.
* Date: 07-30-22
-----------------------------------*/

import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
    	Scanner scan = new Scanner(System.in);

    	int divident;
        int divisor;
        int total;

    	System.out.print("Enter the divident: ");

    	divident = scan.nextInt();
    	System.out.println();

    	System.out.print("Enter the divisor: ");

    	divisor = scan.nextInt();
    	System.out.println();

        if (divisor > 0){
            total = divident/divisor;
    	    System.out.print("Quotient =  " + total);
        }
            else
                System.err.println("Error, can't divide by 0!");

    	

   }//end of main()

}//end of class