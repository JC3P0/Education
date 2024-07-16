
/**
 * PolynomialDriver.java: 
 *
 * @version 1.0
 *
 */
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
    // // System.out.println("Hello World");
        // Term term1 = new Term(3,5);
        // Term term2 = new Term(3,4);
        // Term term3 = new Term(-2,4);
        // System.out.println(term1.equals(term2));
        // System.out.println(term1.compareTo(term2));
        // System.out.println(term2.compareTo(term1));
        // System.out.println(term2.compareTo(term3));
        // Term term1 = new Term ("+3x^+6");
        // System.out.println(term1);
        Polynomial poly1 = new Polynomial();
        Polynomial poly2 = new Polynomial();
        int menu = 0;
        Scanner enter = new Scanner(System.in);

        while (menu != 5){
            System.out.println("Menu" + "\n1. Add 1st Poly" + "\n2. Add 2nd Poly" + "\n3. Add both Polynomials" + "\n4. Clear Poly" + "\n5. Exit Program\n");

            menu = enter.nextInt();
            switch (menu){
                case 1:
                    System.out.println("\ncreate first Poly: ");
                    enter.nextLine();
                    String stringTerm1 = enter.nextLine();
                    Term term1 = new Term(stringTerm1);
                    poly1.addTerm(term1);
                    System.out.println("\n");
                    break;

                case 2:
                    System.out.println("\ncreate second Poly: ");
                    enter.nextLine();
                    String stringTerm2 = enter.nextLine();
                    Term term2 = new Term(stringTerm2);
                    poly2.addTerm(term2);
                    System.out.println("\n");
                    break;

                case 3:
                    System.out.println("\nPoly1: " + poly1 + " + Poly2: " + poly2);
                    poly1.add(poly2);
                    System.out.println("This is the sum of both Polynomials: " + poly1);
                    System.out.println("\n");
                    break;


                case 4:
                    System.out.println("\nClearing");
                    poly1.clear();
                    poly2.clear();
                    break;

                case 5:
                    System.out.println("\nThank you for using the Polynomial program!");
                    break;

                default:
                    System.out.println("\nEnter 1-5");
                    break;
            }
        }
        
    }
}