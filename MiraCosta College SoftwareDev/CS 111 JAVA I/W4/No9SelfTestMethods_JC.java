/*----------------------------------
* Program Name: No9SelfTestMethods.java
* Programmer Name: Josh Clemens
* Description: identifies the following items: method heading, method body, method definition, formal parameters, actual parameters, method call, and local variables.
* Date: 07-11-22
-----------------------------------*/

public class Main
{
    public static void main(String[] args)//method heading
    {
    	int x;   
    	double y;//local variables lines 12, 13, 14
    	char z;
   
    	hello(x, y, z);//method call              //method body line 11 to 20
    	//actual parameters are (x, y, z)
    	hello(x+2, y - 3.5, 'S');//method call
    	//actual parameters are (x+2, y - 3.5, 'S')
    }//end of main()

    //formal parameters are (int first, double second, char ch) - line 24
    //method definition is void - line 24
    public static void hello(int first, double second, char ch) //method heading
    {
    	int num;                                  //method body line 25 to 30
    	double y;//local variables lines 26, 27

    }//end of hello()
}//end of class