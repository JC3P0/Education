/*----------------------------------
* Program Name: Palindrome.java
* Programmer Name: Josh Clemens
* Description: This program determines whether an integer is palindrome or if it reads the same forward as it does backwards, ignoring and leading minus sign.
* Date: 07-23-22
-----------------------------------*/

import java.util.*; //used for scanner

class Main {
    public static void main(String[] args) {

        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);

        //gets users input
        System.out.print("Enter an integer (postitive or negative): ");
        int num = scan.nextInt();
        
        //to store the number entered in reverse
        int reversedNum = 0; 
        
        //used to store the % return value
        int remainder;
        
        //used to compare the number entered with reversed number
        int storeNum = num;

        //loop to reverse number entered to determine if palindrome
        //divide num by 10 till condition meets 0. ex. num = 1331, after the fourth loop num will = 0.1331 and loop will end
        while (num != 0) {
            
            // % returns the decimal value of division by 10 as an integer. ex 1331 % 10 returns the ".1" in "133.1" returns as "1" (taking the last number entered to store as first or to reverse the order)
            remainder = num % 10;
            // System.out.println(remainder);//testing line
            
            //store the number in reverse ( * 10 to add another tens, hundres, thousands placement for each loop)
            reversedNum = reversedNum * 10 + remainder;
            // System.out.println(reversedNum);//testing line

            //moves the decimal placement over left by one each loop for processing
            num /= 10;
            // System.out.println(num);//testing line
        }    

        //verify and display if number entered is Palindrome or not.
        if (storeNum == reversedNum) {
            System.out.println(storeNum + " is Palindrome.");
        }
        else {
          System.out.println(storeNum + " is not Palindrome.");
        }

        scan.close();// close scanner
    }
}