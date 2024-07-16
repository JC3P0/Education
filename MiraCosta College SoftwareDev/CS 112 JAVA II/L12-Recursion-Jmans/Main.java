import java.util.Scanner; //to grab and print info to and from the console

class Main
{
  public static void main(String[] args) 
  {

    /*Main menu will prompt user for principal, rate, and years for calculation. */
    double amount, rate;
    int years;
    Scanner keyboard = new Scanner(System.in);

    System.out.println("Enter the intital deposit amount: ");
    amount = keyboard.nextDouble();
    keyboard.nextLine();
    System.out.println("Enter the rate (in decimal form):" );
    rate = keyboard.nextDouble();
    keyboard.nextLine();
    System.out.println("Enter the amount of years until withdrawl:" );
    years = keyboard.nextInt();
    keyboard.nextLine();

    /*Output of interestCalc methods*/
    System.out.println("\nIterative Output");
    System.out.println("-----------------");
    System.out.printf("Your investment will be $%.2f after %d year(s) at a rate of %.1f%%", iterativeInterestCalc(amount, rate, years), years, rate*100);


    //Uncomment this section to see your recursive method in action!
    
    System.out.println("\n\nRecursive Output");
    System.out.println("-----------------");
    System.out.printf("Your investment will be $%.2f after %d year(s) at a rate of %.1f%%", recursiveInterestCalc(amount, rate, years), years, rate*100);
  }

  /*iterativeInterestCalc method uses a for loop to calulate the new balance in your investment account.*/
  public static double iterativeInterestCalc(double amount, double rate, int years)
  { 
    /*Take a percentage of the amount to get the compound interest by multiplying the amount by the rate. Then add that compound interest to the amount to get the updated amount. Do this calculation for each year the investment stays in the account. For an investment in the account for 3 years, you would perform this calulation 3 times.*/
    for(int i = 0; i < years; i++)
    {
      amount += amount * rate;
    }

    return amount;
  }


  //Start coding here!!
  /*recursiveInterestCalc method uses recursion to calulate the new balance in your investment account*/

    public static double recursiveInterestCalc(double amount, double rate, int years) { 

        if (years == 0) { //base case
            return amount;
        }
        else { //recusrsive case(s)
            double newBalance = amount + (amount * rate);
            System.out.printf("** recursive call for year %d, amount = $%.2f%n", years, newBalance);
            return recursiveInterestCalc(newBalance, rate, years - 1); //chip away at years
        }
    
    }

}