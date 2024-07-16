/*
*Weapon.java : 
*Author: Josh Clemens
*/

public class Weapon{

    //const
    public static final String DEFAULT_NAME = "Club";
    public static final int DEFAULT_DAMAGE = 1;
    public static final int DEFAULT_RANGE = 1;
    public static final int DEFAULT_ATTACK_BONUS = 0;

    //instance variables
    private String name;
    private int damage, range, attackBonus;

    // constructors
    // full constructor
    public Weapon(String name, int damage, int range, int attackBonus){
        if(!this.setAll(name, damage, range, attackBonus)){
            System.out.println("ERROR: invalid data given to Weapoin full constructor");
            System.exit(0);
        }
    }

    //default constructor
    public Weapon(){
        this(DEFAULT_NAME, DEFAULT_DAMAGE, DEFAULT_RANGE, DEFAULT_ATTACK_BONUS);
    }

    //copy constructor
    public Weapon( Weapon original ){
        if(original != null){
            this.setAll(original.name, original.damage, original.range, original.attackBonus);
        } else {
            System.out.println("ERROR: null data given to copy Weapon constructor.");
            System.exit(0);
        }
    }


    //setters

    public boolean setName(String name){
        if(name != null && name.length() != 0) {
            this.name = name;
            return true;
        } else {
            return false;
        }
    }

    public boolean setDamage(int damage){
        if(damage >= 0) {
            this.damage = damage;
            return true;
        } else {
            return false;
        }
    }

    public boolean setRange(int range){
        if(range >= 0) {
            this.range = range;
            return true;
        } else {
            return false;
        }
    }

    public boolean setAttackBonus(int attackBonus){
        if(attackBonus >= 0) {
            this.attackBonus = attackBonus;
            return true;
        } else {
            return false;
        }
    }

    public boolean setAll(String name, int damage, int range, int attackBonus){
        return this.setName(name) && this.setDamage(damage) && this.setRange(range) && this.setAttackBonus(attackBonus);
    }


    //mutators
    public String getName() {
        return this.name;
    }

    public int getDamage() {
        return this.damage;
    }
    public int getRange() {
        return this.range;
    }
    public int getAttackBonus() {
        return this.attackBonus;
    }

    @Override
    public String toString(){
        return String.format("Weapon: %s, Damage: %d, Range: %d, AttackBonus: %d",
            this.name, this.damage, this.range, this.attackBonus);
    }

    @Override
    public boolean equals(Object other){
        if (other == null || other instanceof Weapon){
            return false;
        }
        Weapon otherWeapon = (Weapon) other;
        return this.name.equals(otherWeapon.name) && this.damage == otherWeapon.damage &&
            this.range == otherWeapon.range && this.attackBonus == otherWeapon.attackBonus;
    }

}