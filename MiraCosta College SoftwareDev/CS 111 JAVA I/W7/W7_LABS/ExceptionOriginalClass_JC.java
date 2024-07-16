/*----------------------------------
* Program Name: ExceptionOriginalClass.java
* Programmer Name: Josh Clemens
* Description: test input values to see exceptions thrown is any.
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

    	System.out.print("Enter the divisor: ");

    	divisor = scan.nextInt();
    	System.out.println();

    	quotient = divident/divisor;

    	System.out.print("Quotient =  " + quotient);

   }//end of main()

}//end of class