/*----------------------------------
* Program Name: ArrayListClass.java
* Programmer Name: Josh Clemens
* Description: This program uses the Array class from attached PDF and then re writes the code to use ArrayList class.
* Date: 07-23-22
-----------------------------------*/


class Main {

    public static int countOccurrences(char [] array, char ch) {
        int chCount=0;
        for (int loopCount=0; loopCount<array.length; loopCount++) {
            if( array[loopCount] == ch ) {
                chCount=chCount+1;
            }
        }
        return chCount;
    }
    public static void main(String[] args) {
        char [] myChars = new char[4];
        myChars[0]='c'; myChars[1]='b'; myChars[2]='b'; myChars[3]='a';
        char myCh = 'b';
        int count = countOccurrences(myChars,myCh);
        System.out.println("The number of occurrences is: "+ count);

    }
}