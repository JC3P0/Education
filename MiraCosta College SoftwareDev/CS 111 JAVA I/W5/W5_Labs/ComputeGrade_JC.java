/*----------------------------------
* Program Name: ComputeGrade.java
* Programmer Name: Josh Clemens
* Description: This program uses methods and DoubleClass to get users input for course score and calculates the letter grade for the score
* Date: 07-16-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main {

    //gets user input and sets the number is DoubleClass
    public static void getScore(DoubleClass obj){

        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);

        //Declare variables for input
        double input = 0;
        
        // ask user to enter score
        System.out.print("Enter the course score: ");
        input = scan.nextDouble();

        //set score in DoubleClass
        obj.setNum(input);
        //display course score
        System.out.println ("The course score is " + input);

        scan.close();// close scanner
    }

    //Calculates grade and displays per input
    public static void printGrade(DoubleClass obj){
        
        double result = 0;
        result = obj.getNum();
        if (result >= 90 && result <= 100){
            System.out.println ("Your letter grade for the course is A");
        }
            else if (result >= 80 && result <= 89){
                System.out.println ("Your letter grade for the course is B");
            }
                else if (result >= 70 && result <= 79){
                    System.out.println ("Your letter grade for the course is C");
                }
                    else if (result >= 60 && result <= 69){
                        System.out.println ("Your letter grade for the course is D");
                    }
                        else if (result <= 59 && result >= 0){
                            System.out.println ("Your letter grade for the course is F");
                        }
                            else
                                System.out.println ("Invalid input!");    
    }

    public static void main(String[] args) {

        // create object from DoubleClass class with default constructor
        DoubleClass obj = new DoubleClass();

        //intro
        System.out.println("Welcome to the ComputeGrade program!\n");
        
        //call methods to get users input, display score, calculate letter grade and display
        getScore(obj);
        printGrade(obj);

        System.out.println("\nThank you for using the ComputeGrade program!");
    }
}