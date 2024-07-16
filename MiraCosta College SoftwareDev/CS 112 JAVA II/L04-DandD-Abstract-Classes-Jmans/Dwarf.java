/*
*Dwarf.java : 
*Author: Josh Clemens
*/

public class Dwarf extends GameCharacter{
    
    public static final String DEFAULT_NAME = "Gimly";
    public static final String DEFAULT_CLASS = "Cleric";
    public static final String DEFAULT_ALIGNMENT = "Neutral";
    public static final int DEFAULT_GOLD = 99999;
    public static final int DEFAULT_EXP_POINTS = 750;
    public static final int DEFAULT_HIT_POINTS = 750;
    public static final int DEFAULT_ARMOUR_CLASS = 75;
    public static final Weapon DEFAULT_WEAPON_ONE = new Weapon("Axe", 22, 2, 15);
    public static final Weapon DEFAULT_WEAPON_TWO = new Weapon();

    //constructors
    //full constructor
    public Dwarf(String name, String characterClass, String alignment, int gold, int expPoints, int hitPoints, int armourClass, Weapon weaponOne, Weapon weaponTwo) {
        super(name, characterClass, alignment, gold, expPoints, hitPoints, armourClass, weaponOne, weaponTwo);
    }

    //default constructor
    public Dwarf(){
        this(Dwarf.DEFAULT_NAME, Dwarf.DEFAULT_CLASS, Dwarf.DEFAULT_ALIGNMENT, Dwarf.DEFAULT_GOLD, Dwarf.DEFAULT_EXP_POINTS, Dwarf.DEFAULT_HIT_POINTS, Dwarf.DEFAULT_ARMOUR_CLASS, Dwarf.DEFAULT_WEAPON_ONE, Dwarf.DEFAULT_WEAPON_TWO);
    }

    //copy constructor
    public Dwarf(Dwarf original){
        super(original);
    }

    @Override
    public void assist(GameCharacter other){

        if (other instanceof Dwarf){
            int armoredUp = other.getArmourClass() + 5;
            other.setArmourClass(armoredUp);
            System.out.println("Assisted by increasing armore by 5");
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
        if (other instanceof Dwarf){
            attackDamage = this.getExpPoints() / other.getArmourClass();
        } else {
            attackDamage = this.getExpPoints() * this.getArmourClass() / other.getArmourClass();
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
