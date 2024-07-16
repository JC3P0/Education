/*----------------------------------
* Program Name: BoxFigure.java
* Programmer Name: Josh Clemens
* Description: This program uses Rectangle as the base class and Boxfigure as the derived class to create objects from both classes and display values.
* Date: 07-30-22
-----------------------------------*/

class Main {
    public static void main(String[] args) {
        //create objects of classes
        Rectangle rec = new Rectangle(10,2);
        Rectangle shapeRef = new Rectangle();
        BoxFigure box = new BoxFigure(10,2,5);

        //assign values and display
        shapeRef = rec;
        shapeRef.print();
        shapeRef = box;
        shapeRef.print();
        
    }
}