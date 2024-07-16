import java.util.Scanner;
// import java.lang.*;
// import java.util.*;

public class Main{
	public static void main(String[] args){

        //tester
        // GameCharacterTester.main(null);
        // GameCharacter goku = new GameCharacter("Smog", "Wizard", "Chaotic Evil", 75000, 90, 120, 10, new Weapon("Air Staff", 24, 365, 12), null);
        // System.out.println(goku);

        Scanner keyboard = new Scanner(System.in);

        // /* //testing for player one and two
        GameCharacter playerOne = new Dwarf("Cptn Stumps", "Barbarian", "Chaotic Evil", 50000, 90, 100, 5, new Weapon("Axe", 25, 2, 15), null);
        GameCharacter playerTwo = new Elf("Elroy", "Ranger", "Lawful Evil", 75000, 110, 120, 15, new Weapon("LongBow", 7, 250, 32), Elf.DEFAULT_WEAPON_ONE);

        // GameCharacter playerOne = new Dwarf("Officer Stumps", "Barbarian", "Chaotic Evil", 50000, 90, 100, 5, new Weapon("Hammer", 25, 2, 15), Dwarf.DEFAULT_WEAPON_ONE);
        // GameCharacter playerTwo = new Elf("Elroy", "Ranger", "Lawful Evil", 75000, 110, 120, 15, new Weapon("LongBow", 7, 250, 32), Elf.DEFAULT_WEAPON_ONE);
        // */

        /*
        GameCharacter[] inventory = new GameCharacter[10];
        int players = 0;
        String name = null;
        int heroClass = 0;
        String alignment = null;
        String weaponName = null;
        String specializedClass = null;
        int gold = 0;
        int xp = 0;
        int hp = 0;
        int armor = 0;
        int weaponDamage = 0;
        int weaponRange = 0;
        int attackBonus = 0;

        System.out.println("\nEnter how many players (max 2)");
        System.out.print(">>");
        players = keyboard.nextInt();
        //validate players input (current version is only for 2 players)
        while (players != 2){
            System.out.println("\nCurrnet number of players must be 2");
            System.out.println("\nEnter how many players (max 2)");
            System.out.print(">>");
            players = keyboard.nextInt();
        }
        
        for (int i = 0; i < players; i++){
            System.out.print("\nPlayer " + (i + 1) + ") Enter Name: ");
            name = keyboard.nextLine();
            keyboard.nextLine(); //clean the \n buffer
            
            System.out.print("\nPlayer " + (i + 1) + ") Choose a Class: \n1) Elf\n2) Dwarf\n>>");
            heroClass = keyboard.nextInt();
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter Specialized Class: \n\t\tBarbarian, Bard, Clerc, Droid\n\t\tFighter, Monk, Paladin, Ranger, Rouge, Sorcerer, Warlock, Wizard\n");
            System.out.print(">>");
            specializedClass = keyboard.nextLine();
            keyboard.nextLine(); //clean the \n buffer
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter Alignment: \n\t\tLawful Good, Neutral Good, Chaotic Good\n\t\tLawful Neutral, Neutral, Chaotic Neutral, Lawful Evil, Neutral Evil, Chaotic Evil, Unaligned\n");
            System.out.print(">>");
            alignment = keyboard.nextLine();
            keyboard.nextLine(); //clean the \n buffer
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter Gold: ");
            gold = keyboard.nextInt();
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter XP: ");
            xp = keyboard.nextInt();
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter HP: ");
            hp = keyboard.nextInt();
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter AC: ");
            armor = keyboard.nextInt();
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter WeaponName: ");
            weaponName = keyboard.nextLine();
            keyboard.nextLine(); //clean the \n buffer
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter Weapon Damage: ");
            weaponDamage = keyboard.nextInt();
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter Weapon Range: ");
            weaponRange = keyboard.nextInt();
            
            System.out.print("\nPlayer " + (i + 1) + ") Enter Weapon Attack Bonus: ");
            attackBonus = keyboard.nextInt();

            Weapon tempWeapon = new Weapon(weaponName, weaponDamage, weaponRange, attackBonus);
            
            switch (heroClass){
                case 1:
                    inventory[i] = new Elf(name, specializedClass, alignment, gold, xp, hp, armor, tempWeapon, null);
                case 2:
                    inventory[i] = new Dwarf(name, specializedClass, alignment, gold, xp, hp, armor, tempWeapon, null);
                default:
                    System.out.println("Error, enter from Elf or Dwarf classes.");
                    System.exit(0);
            }
            
        }

        */
        
        boolean battleDone = false;
        GameCharacter winner = null;
        GameCharacter loser = null;
        GameCharacter offense;
        GameCharacter defense;
        GameCharacter temp;
        int menuChoice;

        System.out.println("\nFlipping Coin!!!");
        int simulateFlip = (int)(Math.random() * 2); //0 or 1 value
        if(simulateFlip == 0) { //heads
            System.out.println("Heads!!!");
            offense = playerOne; //using initialized for testing
            defense = playerTwo;
            // offense = inventory[0]; //using user entered data
            // defense = inventory[1];
        } else {
            System.out.println("Tails!!!");
            offense = playerTwo; //using initialized for testing
            defense = playerOne;
            // offense = inventory[1]; //using user entered data
            // defense = inventory[0];
        }
        System.out.println(offense.getName() + " won the coin toss!!!\n");

        //*** INPUT / PROCESSING / OUTPUT SECTIONS ***//

        do{
            Main.printSideBySide(offense, defense);
            System.out.println();
            //print menu + input choice
            System.out.println(offense.getName() + ", what would you like to do?\n");
            System.out.println("1) Attack!");
            System.out.println("2) Assist? - Attempt to :) befriend <3");
            System.out.println("3) Run Away!!!");
            System.out.print("Enter choice> ");
            menuChoice = keyboard.nextInt();
            System.out.println();

            switch(menuChoice){
                case 1:
                    battleDone = Main.attackChoice(offense, defense);
                    if(battleDone){
                        winner = offense;
                        loser = defense;
                        System.out.println("\n" + winner.getName() + " has KO'd " + loser.getName() + "!!!");
                    }
                    break;

                case 2:
                    Main.assistChoice(offense, defense);
                    System.out.println(offense.getName() + " Assisted " + defense.getName() + "!");
                    break;

                case 3:
                    System.out.println(offense.getName() + " Ran Away!!");
                    battleDone = true;
                    winner = defense;
                    loser = offense;
                    break;

                default:
                    System.out.println("\nError: please enter a valid choice 1-3");
                    break;
            }

            //switch for next round
            System.out.println();
            temp = offense;
            offense = defense;
            defense = temp;
        } while (!battleDone);
        
        keyboard.close();  // close scanner

        System.out.println("\n!!! " + winner.getName() + " defeated " + loser.getName() + " !!!\n\n");

        System.out.println("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
        System.out.println("┃                FINAL STATS                 ┃");
        System.out.println("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
        System.out.println();
        System.out.println("Winner: \n" + winner.toAscii() + "\n");
        System.out.println(("Loser: \n" + loser.toAscii() + "\n"));

            System.out.println("Thank you for playing!!! :)");
        
    }

    public static void assistChoice(GameCharacter assister, GameCharacter reciever){
        assister.assist(reciever);
    }

    //return true is defender is defeated, false if still has HP
    public static boolean attackChoice(GameCharacter attacker, GameCharacter defender){

        boolean successfulAttack = attacker.attack(defender);
        if(successfulAttack){
            System.out.println("It was a hit! " + defender.getName() + " Took some damage...");
        } else {
            System.out.println("It was a miss... " + defender.getName() + " Took no damage...");
        }

        return defender.getHitPoints() == 0;
    }

    public static void printSideBySide(GameCharacter left, GameCharacter right){
        String[] leftParts = left.toAscii().split("\n");
        String[] rightParts = right.toAscii().split("\n");

        for(int i = 0; i < leftParts.length; i++){
            System.out.print(leftParts[i]);

            if(i == leftParts.length / 2){
                System.out.print("-->");
            } else {
                System.out.print("   ");
            }

            System.out.println(rightParts[i]);
        }
    }
}