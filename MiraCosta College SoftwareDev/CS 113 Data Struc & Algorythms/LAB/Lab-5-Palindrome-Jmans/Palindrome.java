import java.util.Stack;
import java.util.*;

public class Palindrome {

    /**
     * Utilizes stacks to determine if the given string is a palindrome. This method ignores whitespace and case
     * sensitivity, but does not ignore digits or symbols.
     *
     * @param s a string comprised of any character
     * @return returns true if a palindrome (ignoring whitespace and case sensitivity), false otherwise
     */

    public boolean isPalindrome(String s) {
        if(s == null){
            throw new IllegalArgumentException();
        }

        //create new stacks
        Stack<Character> leftCharStack = new Stack<>();
        Stack<Character> rightCharStack = new Stack<>();
        
        //only ignore whitespace and caps sensitivity
        s = s.replaceAll("\\s", "");
        s = s.toLowerCase();

        //find string length and half length
        int strLength = s.length();
        int halfStack = strLength / 2;

        //find even and odd cases
        if (strLength % 2 == 0){
            //even case
            
            //first load entire string to leftstack
            for (int i = 0; i < strLength; i++){
                char letter = s.charAt(i);
                leftCharStack.push(letter);
            }
            
            //now load rightStack with last half of leftStack
            for (int i = halfStack; i < strLength; i++){
                //pop off the end of left stack while pushing into rightStack
                rightCharStack.push(leftCharStack.pop());
            }

            //return true if they match
            if (leftCharStack.equals(rightCharStack)){
                return true;
            }             
            
        } else {
            //odd case
            
            //first load entire string to leftstack
            for (int i = 0; i < strLength; i++){
                char letter = s.charAt(i);
                leftCharStack.push(letter);
            }

            //now load rightStack with last half of leftStack
            //skip middle element with i = halfStack + 1 (we will pop the end off after loading)
            for (int i = halfStack + 1; i < strLength; i++){

                //pop off the end of left stack while pushing into rightStack
                rightCharStack.push(leftCharStack.pop());
            }
            
            //remove middle element from overall odd element
            leftCharStack.pop();

            //return true if they match
            if (leftCharStack.equals(rightCharStack)){
                return true;
            } 
        }

        return false;
    } // End of method isPalindrome
}