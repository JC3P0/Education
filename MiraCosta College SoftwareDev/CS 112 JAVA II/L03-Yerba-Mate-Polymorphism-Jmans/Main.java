import java.util.Scanner;

public class Main{
	public static void main(String[] args){

        //tester
        // CaffeinatedBeverageTester.main(null);

        
        ///*
		CaffeinatedBeverage[] inventory = new CaffeinatedBeverage[10];
		Scanner keyboard = new Scanner(System.in);
		// Prompt user with options in a loop
		int choice, ounces = 0, brewTemp = 0, count = 0;
		String name = null, flavor;
		double price = 0.0;
		
		do{
            System.out.println();
			System.out.println("1) Enter new Tea");
			System.out.println("2) Enter new Yerba Mate");
			System.out.println("3) Enter new RedBull");
            System.out.println("4) Exit");
			System.out.print(">>");
			choice = keyboard.nextInt();
            keyboard.nextLine(); //clean the \n buffer


            if(choice >= 1 && choice <= 3){
                System.out.print("Enter name       : ");
                name = keyboard.nextLine();
                System.out.print("Enter ounces     : ");
                ounces = keyboard.nextInt();
                System.out.print("Enter price      $ ");
                price = keyboard.nextDouble();
                keyboard.nextLine(); //clean the \n buffer
            }

            
			switch(choice){
                case 1:
			    case 2: // Tea or YerbaMate(1 drops to 2)

			        System.out.print("Enter brew temperature (in Celsius): ");
			        brewTemp = keyboard.nextInt();

                    if(choice == 1){
                        // Create a Tea, put into array
			            inventory[count] = new Tea(name, ounces, price, brewTemp);
                    } else {
                        // Create a YerbaMate, put into array
			            inventory[count] = new YerbaMate(name, ounces, price, brewTemp);
                    }

                    count++;
                    break;

                case 3: //RedBull
			
					System.out.print("Enter Flavor     : ");
			        flavor = keyboard.nextLine();

                    // Create a RedBull, put into array
			        inventory[count] = new RedBull(name, ounces, price, flavor);
                    
                    count++;
			        break;

                case 4:
                    //print all drinks
                    System.out.println("\n\nAll Drinks: ");
                    Main.printDrinks(inventory, count);

                    //print average price
                    System.out.printf("\nAverage Price = $%.2f%n",
                        Main.findAveragePrice(inventory, count));

                    //print highest priced yerba mate
                    YerbaMate mostExpensive = Main.findHighestPricedYerbaMate(inventory, count);
                    if(mostExpensive != null){
                        System.out.printf("\nHighest Priced Mate = %s%n", mostExpensive);
                    } else {
                        System.out.println("No Yerba Mate found in list of drinks");
                    }
			        break;
                default:
                    System.out.println("ERROR: not a valid choice. Please try again.\n");
			}

		} while (choice != 4);

        keyboard.close();// close scanner

        
        //*/

        
	}

    //print drinks
    public static void printDrinks(CaffeinatedBeverage[] drinks, int numDrinks){
        for(int i = 0; i < numDrinks; i++){
            System.out.println("Drink #" + (i+1) + " = " + drinks[i]);
        }
    }

    //get average
    public static double findAveragePrice(CaffeinatedBeverage[] drinks, int numDrinks){
        double totalPrice = 0;
        for(int i = 0; i < numDrinks; i++){
            totalPrice += drinks[i].getPrice();
        }
        return totalPrice / numDrinks;
    }

    //find highest price
    public static YerbaMate findHighestPricedYerbaMate(CaffeinatedBeverage[] drinks, int numDrinks){
        YerbaMate mate = new YerbaMate(), highestPrice = null;
        for(int i = 0; i < numDrinks; i++){
            if(drinks[i].getClass() == mate.getClass()){
                if(highestPrice == null){
                    highestPrice = (YerbaMate)drinks[i];
                } else if(highestPrice.getPrice() < drinks[i].getPrice()) {
                    highestPrice = (YerbaMate)drinks[i];
                } 
            }
        }
        return highestPrice;
    }
}