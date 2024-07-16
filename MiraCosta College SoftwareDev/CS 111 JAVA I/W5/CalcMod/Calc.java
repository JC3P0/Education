/*----------------------------------
* Program Name: Calc.java
* Programmer Name: Josh Clemens
* Description: This program modifies the previous calculator project to use methods in two files.
* Date: 07-16-22
-----------------------------------*/

public class Calc{

    private double input1 = 0; // users inputs
    private double input2 = 0; 

    // Calc default constructor
    public Calc(){
        input1 = 0;
        input2 = 0;
    }

    // Calc constructor
    public Calc(double inp1, double inp2){
        input1 = inp1;
        input2 = inp2;
    }

    // methods used to process inputs and displays result
    public double add(double num1, double num2){
        return (num1 + num2);
    }

    public double sub(double num1, double num2){
        return (num1 - num2);
    }

    public double mult(double num1, double num2){
        return (num1 * num2);
    }

    public double div(double num1, double num2){
        return (num1 / num2);
    }
    
    public void display(double result){
        System.out.println ( "The answer is: " + result);
    }
}