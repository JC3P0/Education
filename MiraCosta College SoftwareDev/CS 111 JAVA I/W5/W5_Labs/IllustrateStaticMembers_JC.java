/*----------------------------------
* Program Name: IllustrateStaticMembers.java
* Programmer Name: Josh Clemens
* Description: This program demonstrates using class objects and chaning class values
* Date: 07-16-22
-----------------------------------*/

class Main {
    
    public static void main(String[] args) {

        // create objects from Illustrate class
        Illustrate obj1 = new Illustrate(3);
        Illustrate obj2 = new Illustrate(5);

        //call method from class level
        Illustrate.incrementY();
        //increment count in Illustrate class
        Illustrate.count++;
        //display both objects
        System.out.println("Illustrate object 1 " + obj1.toString());
        System.out.println("Illustrate object 2 " + obj2.toString());

        System.out.println("\n**** Increment y using Obj1 ****\n");
        obj1.incrementY();
        obj1.setX(8);
        //display both objects
        System.out.println("Illustrate object 1 " + obj1.toString());
        System.out.println("Illustrate object 2 " + obj2.toString());

        System.out.println("\n**** Increment y using Obj2 ****\n");
        obj2.incrementY();
        obj2.setX(23);
        //display both objects
        System.out.println("Illustrate object 1 " + obj1.toString());
        System.out.println("Illustrate object 2 " + obj2.toString());
    }
}