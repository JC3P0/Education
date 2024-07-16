
import java.io.FileInputStream;
import java.util.Scanner;

/**
 * MorseCodeTree :
 *
 * @author
 * @version 1.0
 */
public class MorseCodeTree extends BinaryTree<Character> {

    // TODO:
    // Build this class, which includes the parent BinaryTree implementation in addition to
    // the `translateFromMorseCode` and `readMorseCodeTree` methods. Documentation has been suggested for the former,
    // where said exceptional cases are to be handled according to the corresponding unit tests.
    private static String File_NAME = "BinaryCodes.txt";


    /**
     * Default constructor creates the Morse code binary tree.
     */
    public MorseCodeTree(){
      super(); // creating an empty BinaryTree
      readMorseCodeTree(); // adding all the nodes to our BinaryTree
    }

    /**
     * Non-recursive method for translating a String comprised of morse code values through traversals
     * in the MorseCodeTree.
     *
     * The given input is expected to contain morse code values, with '*' for dots and '-' for dashes, representing
     * only letters in the English alphabet.
     *
     * This method will also handle exceptional cases, namely if a given token's length exceeds that of the tree's
     * number of possible traversals, or if the given token contains a character that is neither '*' nor '-'.
     *
     * @param morseCode The given input representing letters in Morse code
     * @return a String representing the decoded values from morseCode
     */
    
    public String translateFromMorseCode(String morseCode) throws Exception {
      StringBuilder sb = new StringBuilder();
      Node<Character> current = root;
      // morseCode --> "**** * *-** *-** ---" which means "hello" or
      // --> {"****", "*", "*-**, *-**, "---"}
      if(morseCode.contains(" ")){
        String[] letters = morseCode.split(" ");
        validCodeCheck(letters);
        for(int i = 0; i < letters.length; i++){
          for(int j = 0; j<letters[i].length(); j++){
            char temp = letters[i].charAt(j);
            if(temp == '*'){
              current = current.left;
            }
            if(temp == '-'){
              current = current.right;
            }
          }
          sb.append(current.data);
          current = root;
        }
      } else {// morseCode --> "*-" which means "a"
        for(int i = 0; i < morseCode.length(); i++){
          if(morseCode.charAt(i) == '*'){
            current = current.left;
          }
          if(morseCode.charAt(i) == '-'){
            current = current.right;
          }
        }
        sb.append(current.data);
      }
      
      return sb.toString();
    }


    /**
     * Helper method that creates and populates the Morse code tree. Reads a text file and build the tree
     * based on the data and the codes in the text file. Method is called whenever the constructor is called.
     */
    private void readMorseCodeTree() {
      try{
        FileInputStream inFile = new FileInputStream(File_NAME);
        Scanner scan = new Scanner(inFile);

        this.root = new Node<Character>('0');
        while(scan.hasNext()){
          String readLine = scan.nextLine();
          // readLine --> "a *-"
          char dataToAdd = readLine.charAt(0); // a
          String morseCode = readLine.substring(2); // morseCode --> "*-"

          Node<Character> current = root;
          for(int i = 0; i < morseCode.length(); i++){
            if(morseCode.charAt(i) == '*'){
              if(current.left == null){
                current.left = new Node<>(dataToAdd);
              }
              current = current.left;
            }
            
            if(morseCode.charAt(i) == '-'){
              if(current.right == null){
                current.right = new Node<>(dataToAdd);
              }
              current = current.right;
            }
          }
        }
        scan.close();
        inFile.close();
      }catch( Exception e){
        System.out.println("Wrong input ... ");
      }
    }



    /**
     * Displays a formatted table of all the letters in the alphabet and there corresponding
     * morse code in this tree.
     */
    public void morseCodeTable() {
      String[] binaryCodes = {"*-", "-***", "-*-*", "-**", "*", "**-*", "--*", "****", "**", "*---", "-*-", "*-**", "--", "-*", "---", "*--*", "--*-", "*-*", "***", "-", "**-", "***-", "*--", "-**-", "-*--", "--**"};

      String[] letters = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
      System.out.println("Letter: Code\n");
      for(int i = 0; i<25; i++ ){
        System.out.printf("%4s : %4s", letters[i], binaryCodes[i] );
      }
    }


    /**
     * Helper method checks if the Morse codes comply with the depth
     * 4, and binary characters "*" "-".
     *
     * @param morseCode strings being tested
     * @throws Exception if conditions are not met.
     */
    // morseCode[i] --> "**-*"
    private void validCodeCheck(String[] morseCode) throws Exception {
      for(int i = 0; i < morseCode.length; i++){
        for(int j = 0; j < morseCode[i].length(); j++){
          char temp = morseCode[i].charAt(j);
          if(temp != '*' && temp != '-'){
            throw new Exception();
          }
        }
        if(morseCode[i].length() > 4){
          throw new Exception();
        }
      }

    }

} // End of class MorseCodeTree