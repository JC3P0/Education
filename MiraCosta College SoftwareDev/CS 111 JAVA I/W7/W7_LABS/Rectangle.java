/*----------------------------------
* Program Name: BoxFigure.java
* Programmer Name: Josh Clemens
* Description: Rectangle class to be used as base class to Box Figure class
* Date: 07-30-22
-----------------------------------*/
//base class
public class Rectangle
{
        //class variables
	private double length;
	private double width;

    //default constructor
    public Rectangle(){
    	length = 0;
    	width = 0;
    }

    //parameterized constructor
    public Rectangle(double l, double w){
     	setDimension(l, w);
    }

    //sets values only if not <= 0
    public void setDimension(double l, double w){
     	if(l >= 0)
     		length = l;
     	else
     		length = 0;

     	if(w > 0)
     		width = w;
     	else
     		width = 0;
    }

    //returns length
    public double getLength(){
        return length;
    }

     //returns width
     public double getWidth(){
     	return width;
    }

    // returns area
    public double area(){
     	return length * width;
    }

   //returns perimeter
    public double perimeter(){
     	return 2 * (length + width);
    }

    //prints class object values
    public void print(){
     	System.out.println("Length = " + length + " Width = " + width + "\n" + "Area = " + area());
    }

}//end of class