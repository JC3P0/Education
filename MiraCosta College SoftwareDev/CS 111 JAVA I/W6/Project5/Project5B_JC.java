/*----------------------------------
* Program Name: Project5B.java
* Programmer Name: Josh Clemens
* Description: This program is an update from 5A to use array initialize list and output with for loop
* Date: 07-20-22
-----------------------------------*/

import java.util.*; //used for array.length

class Main {
    
    public static void main(String[] args){

        //initialization list
        double[] salary = {5.25, 6.55, 10.25, 16.85};
        //used in partA
        //declare and initialize salary array with hard coded values one by one
        // salary[0] = 5.25;
        // salary[1] = 6.55;
        // salary[2] = 10.25;
        // salary[3] = 16.85;

        //output each element of array one by one in for loop
        for (int i = 0; i < salary.length; i++){
            System.out.println("Salary " + (i + 1) + " is $" + salary[i]);
        }
        //used in partA
        //output each element of array one by one
        // System.out.println("Salary 1 is: " + salary[0]);
        // System.out.println("Salary 2 is: " + salary[1]);
        // System.out.println("Salary 3 is: " + salary[2]);
        // System.out.println("Salary 4 is: " + salary[3]);
        
    }
}