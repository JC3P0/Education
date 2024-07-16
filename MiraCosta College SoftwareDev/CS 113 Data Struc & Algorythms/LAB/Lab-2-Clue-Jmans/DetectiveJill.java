
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class DetectiveJill {

    public static void main() {
      System.out.println("Hello Detective Jill!");
         // DECLARATION + INITIALIZATION
        int answerSet, solution, murder, weapon, location;
        Theory answer;
        AssistantJack jack;
        Scanner keyboard = new Scanner(System.in);
        Random random = new Random();

        // INPUT
        System.out.print("Which theory would like you like to test? (1, 2, 3[random]): ");
        answerSet = keyboard.nextInt();
        keyboard.close();

        // PROCESSING
        jack = new AssistantJack(answerSet);

        ArrayList<Integer> weaponList = new ArrayList<>();
        for (int i = 1; i < 7; i++){
            weaponList.add(i);
        }
        // System.out.println(weaponList);

        ArrayList<Integer> loactionList = new ArrayList<>();
        for (int i = 1; i < 11; i++){
            loactionList.add(i);
        }
        // System.out.println(loactionList);

        ArrayList<Integer> murderList = new ArrayList<>();
        for (int i = 1; i < 7; i++){
            murderList.add(i);
        }
        // System.out.println(murderList);

        while (true) {
            //start at first index
            weapon = weaponList.get(0);
            location = loactionList.get(0);
            murder = murderList.get(0);
            //check solution
            int incorrect = jack.checkAnswer(weapon, location, murder);

            //remove first index if incorrect
            if (incorrect == 1){
                weaponList.remove(0);
                    
            } else if (incorrect == 2){
                loactionList.remove(0);
                    
            } else if (incorrect == 3){
                murderList.remove(0);

            //correct answer
            } else {
                answer = new Theory(weapon, location, murder);
                break;
            }
        }

        
        // do {
            // weapon = random.nextInt(6) + 1;
            // location = random.nextInt(10) + 1;
            // murder = random.nextInt(6) + 1;
        //     solution = jack.checkAnswer(weapon, location, murder);
        // } while (solution != 0);
        // answer = new Theory(weapon, location, murder);

        // OUTPUT
        System.out.println("Total Checks = " + jack.getTimesAsked() + ", Solution " + answer);

        if (jack.getTimesAsked() > 20) {
            System.out.println("FAILED!! You're a horrible Detective...");
        } else {
            System.out.println("WOW! You might as well be called Batman!");
        }
    }
}
