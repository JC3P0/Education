/*----------------------------------
* Program Name: Calculator_Part2.java
* Programmer Name: Josh Clemens
* Description: Modifies Calculator Part 1 to include a do...while loop that will continue to display the menu till they hit X to exit. convert IF...ELSE statements into a Switch statement.
* Date: 07-10-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main{
    public static void main(String[] args){

        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);

        //Declaring and initializing char variable with default value
 		char operator = ' ';
        //Declare variables for inputs and result
        double input1, input2, result = 0;

        //intro
        System.out.println("Welcome to the Calculator program!");

        // do while loop included in part 2 of assignment
        do{
 		    //Displaying menu
            System.out.println ( "A.) Add\nB.) Subtract\nC.) Multiply\nD.) Divide\nX.) Exit" );

            //Prompt for operator
            System.out.print ( "Please select a menu option (a/b/c/d/x):  " );
         	operator = scan.next().charAt(0);				        
            //scan and store to memory
            //checks for X input to exit before asking for input 1 and input 2
            if (operator == 'x' || operator == 'X'){
                System.out.println("Good Bye!");
                System.exit(0);    
            }
    
            // ask user to enter numbers
            System.out.print("Enter the first number: ");
            input1 = scan.nextDouble();
    
            System.out.print("Enter the second number: ");
            input2 = scan.nextDouble();
    
            //uses switch statement with (operator) to test for upper and lower case menu options
            switch(operator){
                case 'A':
                case 'a':
                    result = input1 + input2; //calculate and display result
                    System.out.println ( "The sum of " + input1 + " and " + input2 + " is " + result );
                    break;
    
                case 'B':
                case 'b':
                    result = input1 - input2;
                    System.out.println (input1 + " subtracted by " + input2 + " is " + result );
                    break;
                  
                case 'C':
                case 'c':
                    result = input1 * input2;
                    System.out.println (input1 + " Multiplied by " + input2 + " is " + result );
                    break;
                  
                case 'D':
                case 'd':
                    result = input1 / input2;
                    System.out.println (input1 + " Divided by " + input2 + " is " + result );    
                    break;
    
                case 'X':
                case 'x':
                    System.out.println("Good Bye!");
	          		System.exit(0);
    
                default:
                    System.out.printf("%c is an invalid selection", operator);
                    System.exit(0);
                  
            }
        }while (operator != 'x' || operator != 'X');

        
        /*
        //uses nested if else statements with the OR operator to test for upper and lower case menu options
        if (operator == 'a' || operator == 'A' )
        {
            result = input1 + input2; //calculate and display result
            System.out.println ( "The sum of " + input1 + " and " + input2 + " is " + result );
        }
            else if(operator == 'b' || operator == 'B' )
		    {
                result = input1 - input2;
                System.out.println (input1 + " subtracted by " + input2 + " is " + result );
		    }
				else if(operator == 'c' || operator == 'C' )
				{
					result = input1 * input2;
                    System.out.println (input1 + " Multiplied by " + input2 + " is " + result );
				}
                    else if(operator == 'd' || operator == 'D' )
				    {
					    result = input1 / input2;
                        System.out.println (input1 + " Divided by " + input2 + " is " + result );
				    }
        				else // if user does not choose from a menu option an error in displayed
        					System.err.println ( "Invalid option selected!" );
        */

    scan.close();
 
  }
}