/*----------------------------------
* Program Name: ReverseOrderArray.java
* Programmer Name: Josh Clemens
* Description: This program reads in five numbers, finds their total and displays the numbers in reverse order
* Date: 07-18-22
-----------------------------------*/

import java.util.*; //used for scanner


class Main {
    
    public static void main(String[] args){

        //declare and initialize variable to calculate total
        double total = 0;
        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);
        //declare and initialize new array to 5
        int[] arr = new int[5];

        // Get each number using for loop
        for (int i = 0; i < 5; i++){
            System.out.print("Number " + (i + 1) + ": ");
            arr[i] = scan.nextInt();
            total += arr[i];
        }
        
        // System.out.println(total); // testing line

        System.out.println("The total is: " + total);
        System.out.println("The numbers in reverse are!");
        
        //Loop through the array in reverse order using for loop
        for (int i = arr.length-1; i >= 0; i--) {  
            System.out.print(arr[i] + " ");  
        }
        
    }
}