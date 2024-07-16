/*----------------------------------
* Program Name: JavaExpressions.java
* Programmer Name: Josh Clemens
* Description: finds the value of the following expressions
* Date: 06-20-22
-----------------------------------*/
class Main {
  public static void main(String[] args) 
  {
        int a = (101 + 0) / 3; //int as double not needed
        double b = 3.0e-6 * 10000000.1; //double for decimal places
        boolean c = true && true; //boolean for true or false value
        boolean d = false && true;
        boolean e = (false && false) || (true && true);
        boolean f = (false || false) && (true && true);

        System.out.println("(101 + 0) / 3)\t\t\t\t " + a);
        System.out.println("(3.0e-6 * 10000000.1)\t\t\t\t " + b);
        System.out.println("(true && true)\t\t\t\t " + c);
        System.out.println("(false && true)\t\t\t\t " + d);
        System.out.println("(false && false) || (true && true)\t\t\t\t " + e);
        System.out.println("(false || false) && (true && true)\t\t\t\t " + f);

  }
}
