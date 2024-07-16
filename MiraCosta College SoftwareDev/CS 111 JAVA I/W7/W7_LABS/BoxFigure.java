/*----------------------------------
* Program Name: BoxFigure.java
* Programmer Name: Josh Clemens
* Description: uses Rectangle as Base class
* Date: 07-30-22
-----------------------------------*/

//inherits values from Rectanle class
public class BoxFigure extends Rectangle{
	double height;
    //default constructor using super() for default values from Rectangle class or base class
    public BoxFigure(){
        super();
    	height = 0;
    }

     //parameterized constructor
     public BoxFigure(double l, double w, double h){
     	setDimension(l, w, h);

     }
     //sets values only if not <= 0, calling l and w from base class
     public void setDimension(double l, double w, double h){
        setDimension(l, w);
     	if(h >= 0)
     		height = h;
     	else
     		height = 0;
     }
     //returns height
     public double getheight(){
     	return height;
     }


     //returns BoxFigure area
     public double areaBox(){
     	return 2 * (getLength() * getWidth() + getLength() * height + getWidth() * height);
     }
     //returns volume
     public double volume(){
     	return (area() * getheight());
     }
     //prints class object values
     public void print(){
     	System.out.println("Length = " + getLength()
     				       + " Width = " + getWidth()
     				       + " Height = " + getheight()
                                       + "\nArea = " + areaBox()
                                       + " Volume = " + volume());
     }
}//end of class