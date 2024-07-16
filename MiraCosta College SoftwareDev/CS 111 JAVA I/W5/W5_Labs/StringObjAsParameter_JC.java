/*----------------------------------
* Program Name: StringObjAsParameter.java
* Programmer Name: Josh Clemens
* Description: This program declares and initializes String object to be passes to a method to be changed, displaying results through each step of program.
* Date: 07-16-22
-----------------------------------*/

class Main {

    public static void stringParameter(String str){
        
        System.out.println("\nIn the method stringParameter");
	//display string object before changing
        System.out.println("Passed String value before changing its value: " + str);
	//change the string object
        str = "SunnyDay";
	//display the changed string object
        System.out.println("Passed String value after changing its value: " + str);
    } 
    
    public static void main(String[] args) {

	//create string object
        String str = "Hello";
	//display string before calling object
        System.out.println("String value before calling the method stringParameter: " + str);

	//call method using string object
        stringParameter(str);
        //display string after calling object
        System.out.println("\nString value after calling the method stringParameter: " + str);
    }
}