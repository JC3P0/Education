/*----------------------------------
* Program Name: Project5A.java
* Programmer Name: Josh Clemens
* Description: This program declares, initializes and prints elements of an array.
* Date: 07-18-22
-----------------------------------*/

class Main {
    
    public static void main(String[] args){

        //declare and initialize salary array with hard coded values one by one
        double[] salary = new double[4];
        salary[0] = 5.25;
        salary[1] = 6.55;
        salary[2] = 10.25;
        salary[3] = 16.85;
        //output each element of array one by one
        System.out.println("Salary 1 is: " + salary[0]);
        System.out.println("Salary 2 is: " + salary[1]);
        System.out.println("Salary 3 is: " + salary[2]);
        System.out.println("Salary 4 is: " + salary[3]);
        
    }
}