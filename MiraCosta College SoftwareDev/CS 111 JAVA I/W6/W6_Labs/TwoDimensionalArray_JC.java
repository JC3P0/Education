/*----------------------------------
* Program Name: TwoDimensionalArray.java
* Programmer Name: Josh Clemens
* Description: This program gets users input for the amount of rows and columns to be entered into an array. the program then calculates the total elements to be entered into the array then the program displayes all elements of the array in the rows and columns as entered.
* Date: 07-23-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main {
    public static void main(String[] args) {

        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);

        //gets users input for rows and columns to create array
        System.out.print("Enter rows for the array (max 10): ");
        int rows = scan.nextInt();
        System.out.print("Enter columns for the array (max 10): ");
        int columns = scan.nextInt();

        //create array with users input for rows and columns
        int array[][]= new int[rows+1][columns+1];

        //calculate total amount of array elements to be entered by user
        System.out.println("Enter " + (rows * columns) + " Array Elements");

        //loop through each element of array for users input and store to array
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++) {

                System.out.print("Enter row [" + (i+1) + "] and column [" + (j+1) + "]: ");
    	        array[i][j]=scan.nextInt();
            }
            // System.out.println("test" + i);//testing line
        }

        System.out.println("Array contains: ");

        //loops through each element of array to display each element in rows and columns as entered
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++) {

        	    // System.out.println("Array [" + (i+1) + "][" + (j+1) + "] " + array[i][j]);//testing line
                
                //prints row by row and formats 1 to 01 for display
                System.out.printf("%02d", array[i][j]);
                // add spaces after each element is printed
                System.out.print("  ");
            }
    	    // System.out.println("test" + i);//testing line  
            
            //new line after each row is printed
            System.out.println("");
        }
        
        scan.close();// close scanner
    }
}