/*----------------------------------
* Program Name: CalculatorModified2.java
* Programmer Name: Josh Clemens
* Description: This program modifies the previous calculator project to use methods in two files.
* Date: 07-16-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main{

    /*
    // used in part 1
    // methods used to process inputs and displays result
    public static double add(double num1, double num2){
        return (num1 + num2);
    }

    public static double sub(double num1, double num2){
        return (num1 - num2);
    }

    public static double mult(double num1, double num2){
        return (num1 * num2);
    }

    public static double div(double num1, double num2){
        return (num1 / num2);
    }
    
    public static void display(double result){
        System.out.println ( "The answer is: " + result);
    }
    */
    
    public static void main(String[] args){

        // create object from Calc class with default constructor
        Calc anInput = new Calc();

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
            System.out.println ( "\nA.) Add\nB.) Subtract\nC.) Multiply\nD.) Divide\nX.) Exit" );

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
                    //calculate and display result
                    result = anInput.add(input1, input2);
                    anInput.display(result);
                    break;
    
                case 'B':
                case 'b':
                    result = anInput.sub(input1, input2);
                    anInput.display(result);
                    break;
                  
                case 'C':
                case 'c':
                    result = anInput.mult(input1, input2);
                    anInput.display(result);
                    break;
                  
                case 'D':
                case 'd':
                    result = anInput.div(input1, input2);
                    anInput.display(result);
                    break;
    
                case 'X':
                case 'x':
                    System.out.println("\nGood Bye!");
	          		System.exit(0);
    
                default:
                    System.out.printf("%c is an invalid selection", operator);
                    System.exit(0);
                  
            }
        }while (operator != 'x' || operator != 'X');

    scan.close();// close scanner
 
    }
}