import java.util.*; //used for scanner

class Main {

    public static void printHello(){
        System.out.println("Welcome to CS 112!");
    }

    public static double add(double num1, double num2){
        double total = 0;
        total = num1 + num2;
        return total;
    }
    
    public static void main(String[] args){

        //Instantiating Scanner Object to scan and store user input
 		Scanner scan = new Scanner(System.in);
        double input1, input2, result = 0.0;
 
        System.out.println("Welcome to CS 112!");
        printHello();

        // ask user to enter numbers
        System.out.print("Enter the first number: ");
        input1 = scan.nextDouble();
    
        System.out.print("Enter the second number: ");
        input2 = scan.nextDouble();

        //call method to add both inputs
        result = add(input1, input2);

        //display reslut of input 1 + input 2
        System.out.print("The sum of both numbers is: " + result);

        //create instance varialbe objects from Student class
        Student student1 = new Student("Josh", 442);
        Student student2 = new Student("Bob", 559);
        //create student 3 with copy constructor
        Student student3 = new Student(student1);

        //display student objects
        System.out.println("");
        System.out.println("\nThis is student object 1");
        student1.print();
        System.out.println("");
        System.out.println("\nThis is student object 2");
        student2.print();
        System.out.println("");
        System.out.println("\nThis is student object 3, copied from student 1");
        student3.print();
        System.out.println("");
        //use equals method to compare objects
        System.out.println("\nDoes Student object 1 equal object 2?: ");
        System.out.print(student1.equals(student2));
        System.out.println("\nDoes Student object 1 equal object 3?: ");
        System.out.print(student1.equals(student3));
        
        //close scanner object
        scan.close();

    }
}