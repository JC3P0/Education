// TODO: Step 2 - Import file input statements here
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;

public class Main 
{
	public static void main(String[] args) 
	{
		//TEST FOR STEP 1 (you can delete/comment this out after completing step 1)
		Plant test = new Plant("Stinging Nettle,65,anti-inflammatory and culinary");
		System.out.println("test plant:\n" + test + "\n\n");


		//TODO: Step 2 - Declare + initialize variables for file input here
        Scanner inputFile = null;
        ArrayList<Plant> myPlants = new ArrayList<Plant>();
        
		
		//TODO: Step 2 - Connect input stream to file (dont forget the try/catch!)
        try{
            inputFile = new Scanner(new FileInputStream("Forage.csv"));
        }
        catch (FileNotFoundException fnfe){
            System.out.println("Error: cannot open file Forage.csv for input.");
            System.exit(0);
        }


		//TODO: Step 2 - create loop to read through whole file
        while(inputFile.hasNextLine()){
            // System.out.println(inputFile.nextLine());
            Plant currentPlant = new Plant(inputFile.nextLine());
            myPlants.add(currentPlant);
            System.out.println("*** Added new plant with following info: " + currentPlant.getName());
        }

        System.out.println("Added a total of " + myPlants.size() + " records from file.\n\n");

			//TODO: Step 3 - build Plant Objects and store into ArrayList



		//TODO: Step 2 - close the input stream
        inputFile.close();

		//TODO: Step 3 - print contents of ArrayList
        System.out.println("Plants in my collection:\n");
        for (Plant p : myPlants) {
            System.out.println(p + "\n");
        }
	}
}