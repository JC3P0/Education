/*----------------------------------
* Program Name: LargerNumber.java
* Programmer Name: Josh Clemens
* Description: This program uses two methods to find the largest number of two and three number options.
* Date: 07-11-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main{

    // uses.max to find the largest number and returns that value
    public static double maxTwo(double num1, double num2){
        double max = 0;
        max = Math.max(num1, num2);
        return max;
    }

    // uses maxTwo method to first find the largest of num1 and num2 then finds the largerst from the result of first method and num3 and returns that value
    public static double maxThree(double num1, double num2, double num3){
        double test1 = 0;
        double max = 0;
        test1 = maxTwo(num1, num2);
        max = maxTwo(test1, num3);   
        return max;
    }

    public static void main(String[] args) {

        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);

        // declare and initialize variables for calculating
        double num1 = 5.6;
        double num2 = 10.8;
        double num3 = 23.5;
        double num4 = 34.6;
        double num5 = 12;
        double input1, input2 = 0.0;
        double result1, result2, result3 = 0.0;

        //calls maxTwo and stores result 
        result1 = maxTwo(num1, num2);

        //output result of first call to maxTwo method
        System.out.println("The larger of " + num1 + " and " + num2 + " is " + result1);

        // ask user to enter numbers
        System.out.print("Enter the first number: ");
        input1 = scan.nextDouble();
    
        System.out.print("Enter the second number: ");
        input2 = scan.nextDouble();

        //calls maxTwo and stores result
        result2 = maxTwo(input1, input2);

        //output result of first call to maxTwo method
        System.out.println("The larger of " + input1 + " and " + input2 + " is " + result2);

        //calls maxThree and stores result
        result3 = maxThree(num3, num4, num5);

        //output result of first call to maxThree method
        System.out.println("The larger of " + num3 + ", " + num4 + " and " + num5 + " is " + result3);

        //close scanner object
        scan.close();
    }
}


/*
Write a Java program containing three methods, Main method, a Larger method to compare the entered values and return which value is larger and a third method CompareThree, which will compare three values and return the larger of the three. Make sure within the CompareThree method you are calling the larger method, do not repeat the code. 

HINT: you can place a method call inside of another method call.
First pass two hard coded values in larger method and compare which one is larger, display the result. Then let the user enter in two values, pass in the user inputted values to larger method and compare which one is the larger, display the value. Then hard code three values, call the compareThree method, pass in the 
hard-coded values, compare which one is the larger value and display the result. 

MUST create main() method, larger(with two parameters), 
and compareThree(with three parameters) – within the 
compareThree method, call larger() and compare the value, 
use the HINT given. DO NOT rewrite the same code you have in 
larger in the compareThree() method

IPO chart, algorithm, code and comments required for full 
credit.

Expected Results: 

The larger of 5.6 and 10.8 is 10.8
Enter two numbers: 34 43
The larger of 34.0 and 43.0 is 43.0
The larger of 23.5, 34.6 and 12 is 34.6

*/