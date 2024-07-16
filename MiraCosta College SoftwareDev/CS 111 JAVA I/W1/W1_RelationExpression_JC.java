/*----------------------------------
* Program Name: RelationExpression.java
* Programmer Name: Josh Clemens
* Description: evaluates expressions using relation operators
* Date: 06-20-22
-----------------------------------*/

class Main {
  public static void main(String[] args) 
  {
        int x = 50; //declare and initialize
        int y = 10;

        System.out.println(x + " == " + y + "\t" + (x == y)); //equals 
        System.out.println(x + " != " + y + "\t" + (x != y)); //not equals
        System.out.println(x + " < " + y + "\t\t" + (x < y)); //lessthan //needs double \t?
        System.out.println(x + " > " + y + "\t\t" + (x > y)); //greaterthan //needs double \t?
        System.out.println(x + " <= " + y + "\t" + (x <= y)); //less than or equal   
        System.out.println(x + " >= " + y + "\t" + (x >= y)); //greater than or equal
  }
}