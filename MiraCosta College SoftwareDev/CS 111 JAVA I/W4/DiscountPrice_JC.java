/*----------------------------------
* Program Name: DiscountPrice.java
* Programmer Name: Josh Clemens
* Description: This program asks user for the original price of an item and to chose a discount amount to apply.
* Date: 07-11-22
-----------------------------------*/

import java.util.*; // used for scanner

class Main 
{
  public static void main(String[] args) 
  {

      //intro
      System.out.println("Welcome to the discount price program!");

      //instantiating Scanner Object
      Scanner scan = new Scanner(System.in);

      // declare and initialize 
      double regularPrice = 0.0, discountPrice = 0.0, discountAmount = 0.0;
      char menuSelection = ' '; //declaring and initializing char variable

      System.out.print("Enter regular price for an item: ");
      regularPrice = scan.nextDouble();

      System.out.println("\n\n\t ************* Dicount Code Menu *************");

      System.out.println("\t H: \t\t 50%");
      System.out.println("\t F: \t\t 40%");
      System.out.println("\t T: \t\t 33%");
      System.out.println("\t Q: \t\t 25%");
      System.out.println("\t Z: \t\t 0%");

      System.out.print("\n\t Enter the Discount Code (H/F/T/Q/Z) --> ");

      menuSelection = scan.next().charAt(0);
      
      //switch statement using menuSelection
      switch(menuSelection){
          case 'H':
          case 'h':
              //calculates discount amount
              discountAmount = regularPrice * 0.50;
              discountPrice = regularPrice - discountAmount;
              System.out.printf("Discount Amount is: %.2f", discountAmount);
              System.out.printf("\nDiscount Price is: %.2f", discountPrice);
              break;

          case 'F':
          case 'f':
               discountAmount = regularPrice * 0.40;
               discountPrice = regularPrice - discountAmount;
               System.out.printf("Discount Amount is: %.2f", discountAmount);
               System.out.printf("\nDiscount Price is: %.2f", discountPrice);
               break;
              
          case 'T':
          case 't':
               discountAmount = regularPrice * 0.33;
               discountPrice = regularPrice - discountAmount;
               System.out.printf("Discount Amount is: %.2f", discountAmount);
               System.out.printf("\nDiscount Price is: %.2f", discountPrice);
               break;

              
          case 'Q':
          case 'q':
               discountAmount = regularPrice * 0.25;
               discountPrice = regularPrice - discountAmount;
               System.out.printf("Discount Amount is: %.2f", discountAmount);
               System.out.printf("\nDiscount Price is: %.2f", discountPrice);
               break;

          case 'Z':
          case 'z':               
               System.out.println("\n\nNo Discount Applied!");
               System.out.printf("\nRegular Price is: %.2f", regularPrice);
               break;

          default:
              System.out.printf("%c is an invalid selection", menuSelection);
              System.exit(0);
              
      }
      
    scan.close();
    
  }
}