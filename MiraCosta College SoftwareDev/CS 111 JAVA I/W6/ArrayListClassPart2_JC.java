/*----------------------------------
* Program Name: ArrayListClass.java
* Programmer Name: Josh Clemens
* Description: This program uses the Array class from attached PDF and then re writes the code to use ArrayList class.
* Date: 07-23-22
-----------------------------------*/

import java.util.*; //used for ArrayList class

class Main {

    public static int countOccurrences(ArrayList<Character> myChars, char ch) {
        int chCount=0;
        for (int loopCount=0; loopCount < myChars.size(); loopCount++) {
            if( myChars.get(loopCount) == ch ) {
                chCount=chCount+1;
            }
        }
        return chCount;
    }
    public static void main(String[] args) {
        // char [] myChars = new char[4]; //part1
        ArrayList<Character> myChars = new ArrayList<Character>();
        // myChars[0]='c'; myChars[1]='b'; myChars[2]='b'; myChars[3]='a'; //part1
        myChars.add('c');
        myChars.add('b');
        myChars.add('b');
        myChars.add('a');
        char myCh = 'b';
        int count = countOccurrences(myChars,myCh);
        System.out.println("The number of occurrences is: "+ count);

    }
}