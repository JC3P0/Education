/*
*Elf.java : 
*Author: Josh Clemens
*/

public class Elf extends GameCharacter{
    public static final String DEFAULT_NAME = "Legloss";
    public static final String DEFAULT_CLASS = "Druid";
    public static final String DEFAULT_ALIGNMENT = "Lawful Neutral";
    public static final int DEFAULT_GOLD = 9999;
    public static final int DEFAULT_EXP_POINTS = 100;
    public static final int DEFAULT_HIT_POINTS = 100;
    public static final int DEFAULT_ARMOUR_CLASS = 50;
    public static final Weapon DEFAULT_WEAPON_ONE = new Weapon("Crossbow", 6, 30, 3);
    public static final Weapon DEFAULT_WEAPON_TWO = new Weapon();

    //constructors
    //full constructor
    public Elf(String name, String characterClass, String alignment, int gold, int expPoints, int hitPoints, int armourClass, Weapon weaponOne, Weapon weaponTwo) {
        super(name, characterClass, alignment, gold, expPoints, hitPoints, armourClass, weaponOne, weaponTwo);
    }

    //default constructor
    public Elf(){
        this(Elf.DEFAULT_NAME, Elf.DEFAULT_CLASS, Elf.DEFAULT_ALIGNMENT, Elf.DEFAULT_GOLD, Elf.DEFAULT_EXP_POINTS, Elf.DEFAULT_HIT_POINTS, Elf.DEFAULT_ARMOUR_CLASS, Elf.DEFAULT_WEAPON_ONE, Elf.DEFAULT_WEAPON_TWO);
    }

    //copy constructor
    public Elf(Elf original){
        super(original);
    }

    @Override
    public void assist(GameCharacter other){

        if (other instanceof Elf){
            int healed = other.getHitPoints() + 10;
            other.setHitPoints(healed);
            System.out.println("Assisted by healing 10");
        } else {
            int goldUpdated = other.getGold() + 5;
            other.setGold(goldUpdated);
            System.out.println("Assisted by giving 5 gold");
        }
    }

    @Override
    public boolean attack(GameCharacter other){
        int diceRoll = (int)(Math.random() * 20) + 1; //random int 1-20
        //calculate base dmg
        int attackDamage = this.getExpPoints() / other.getArmourClass();
        int updatedHitPoints = other.getHitPoints();

        //modify damage based on character type
        if (other instanceof Elf){
            attackDamage /= 2;
            diceRoll += 5;
        }

        // if over damage, make sure the HP doesnt go below 0
        if(attackDamage > updatedHitPoints){
            attackDamage = updatedHitPoints;
        }

        //determine if hit successful, if so update hp
        if (diceRoll > 10){
            updatedHitPoints -= attackDamage;
            other.setHitPoints(updatedHitPoints);
            System.out.println("Attacked for " + attackDamage + " Damage!"); //testing line
            return true;
        } else {
            return false;
        }
        
    }
    
}
