/*----------------------------------
* Program Name: ExceptionWithTryCatch.java
* Programmer Name: Josh Clemens
* Description: test input values with try catch block to validate input of whole numbers and numbers less than 0
* Date: 07-30-22
-----------------------------------*/

import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
    	Scanner scan = new Scanner(System.in);

    	int divident, divisor, quotient;

    	System.out.print("Enter the divident: ");

    	divident = scan.nextInt();
    	System.out.println();

        try{
            System.out.print("Enter the divisor: ");

    	    divisor = scan.nextInt();
    	    System.out.println();
            quotient = divident/divisor;

    	    System.out.print("Quotient =  " + quotient);
            
        }
        catch (InputMismatchException e){
            System.err.println("Error, not a whole number!");
        }
        catch (Exception e){
            System.err.println("Error, can't divide by 0!");
        }
    	
   }//end of main()

}//end of class