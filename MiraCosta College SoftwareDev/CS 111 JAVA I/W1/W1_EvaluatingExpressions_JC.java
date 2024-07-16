/*----------------------------------
* Program Name: EvaluatingExpressions.java
* Programmer Name: Josh Clemens
* Description: prints the results of math operations
* Date: 06-20-22
-----------------------------------*/
class Main {
  public static void main(String[] args) 
  {
    int a, b, c, d;//initialize variables
    //variables hold equations
    a = -5 + 8 * 6;
    b = ((55+9) % 9);
    c = 20 + (-3*5) / 8;
    d = 5+15 / 3 * 2 - 8 % 3;
    //print variables
    System.out.println(a);
    System.out.println(b);
    System.out.println(c);
    System.out.println(d);
    //print variables with equation first
    System.out.println("-5 + 8 * 6 = " + a);
    System.out.println("((55 + 9) % 9) = " + b);
    System.out.println("20 + (-3 * 5) / 8 = " + c);
    System.out.println("5 + 15 / 3 * 2 - 8 % 3 = " + d);

  }
}