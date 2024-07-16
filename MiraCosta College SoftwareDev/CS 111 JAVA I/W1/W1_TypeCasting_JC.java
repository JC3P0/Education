/*----------------------------------
* Program Name: TypeCasting.java
* Programmer Name: Josh Clemens
* Description: uses typecasting operator to convert data types
* Date: 06-20-22
-----------------------------------*/

class Main {
  public static void main(String[] args) 
  {
    System.out.println("(int)(7.9) = " + (int)(7.9) + " Integer Type");
    System.out.println("(int)(3.3) = " + (int)(3.3) + " Integer Type");
    System.out.println("(double)(25) = " + (double)(25) + " Double Type");
    System.out.println("(double)(5 + 3) = " + (double)(5 + 3) + " Double Type");
    System.out.println("(double)(15/2) = " + (double)15/2 + " Double Type");
    System.out.println("(double)((15)/2) = " + (double)((15)/2) + " Double Type");
    System.out.println("(int)(7.8+(15.0)/2) = " + (int)(7.8+(15.0)/2) + " Integer Type"); //had to add .0 to 15.0 for = 15
    System.out.println("(int)(7.8+(15)/2) = " + (int)(7.8+(15)/2) + " Integer Type");
  }
}