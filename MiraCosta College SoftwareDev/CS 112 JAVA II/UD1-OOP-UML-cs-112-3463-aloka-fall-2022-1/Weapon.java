/*
*Weapon.java : 
*Author: Josh Clemens
*/
public class Weapon{
    //const
    public static final String DEFAULT_TYPE = "Mele";
    public static final String DEFAULT_NAME = "Sword";
    public static final double DEFAULT_DAMAGE = 100;
    public static final double DEFAULT_DISTANCE = 5;
    public static final double DEFAULT_ACCURACY = 75;

    //instance variables
    private String type, name;
    private double weaponDamage, weaponDistance, weaponAccuracy;

    //default constructor
    public Weapon(){
        this(DEFAULT_TYPE, DEFAULT_NAME, DEFAULT_DAMAGE, DEFAULT_DISTANCE, DEFAULT_ACCURACY);
    }

    //full constructor
    public Weapon(String type, String name, double weaponDamage, double weaponDistance, double weaponAccuracy){
        if(!this.setAll(type, name, weaponDamage, weaponDistance, weaponAccuracy)){
            System.out.println("ERROR: invalid data given to Weapoin full constructor");
            System.exit(0);
        }
    }

    // copy constructor
    public Weapon( Weapon original ){
        if(original != null){
            this.setAll(original.type, original.name, original.weaponDamage, original.weaponDistance, original.weaponAccuracy);
        } else {
            System.out.println("ERROR: null data given to copy Weapon constructor.");
            System.exit(0);
        }
    }

    //setters

    public boolean setType(String type){
        if(type != null && type.length() != 0) {
            this.type = type;
            return true;
        } else {
            return false;
        }
    }
    
    public boolean setName(String name){
        if(name != null && name.length() != 0) {
            this.name = name;
            return true;
        } else {
            return false;
        }
    }
    
    public boolean setWepDamage(double weaponDamage){
        if(weaponDamage >= 0) {
            this.weaponDamage = weaponDamage;
            return true;
        } else {
            return false;
        }
    }

    public boolean setWepDistance(double weaponDistance){
        if(weaponDistance >= 0) {
            this.weaponDistance = weaponDistance;
            return true;
        } else {
            return false;
        }
    }

    public boolean setWepAccuracy(double weaponAccuracy){
        if(weaponAccuracy >= 0) {
            this.weaponAccuracy = weaponAccuracy;
            return true;
        } else {
            return false;
        }
    }

    public boolean setAll(String type, String name, double weaponDamage, double weaponDistance, double weaponAccuracy){
        return this.setType(type) && this.setName(name) && this.setWepDamage(weaponDamage) && this.setWepDistance(weaponDistance) && this.setWepAccuracy(weaponAccuracy);
    }

    //mutators
    public String getType() {
        return this.type;
    }
    
    public String getName() {
        return this.name;
    }

    public double getWepDamage() {
        return this.weaponDamage;
    }
    public double getWepDistance() {
        return this.weaponDistance;
    }
    public double getWepAccuracy() {
        return this.weaponAccuracy;
    }

    @Override
    public String toString(){
        return String.format("Type: %s, Weapon: %s, Damage: %.2f, Distance: %.2f, Accuracy: %.2f",
            this.type, this.name, this.weaponDamage, this.weaponDistance, this.weaponAccuracy);
    }

    @Override
    public boolean equals(Object other){
        if (other == null || other instanceof Weapon){
            return false;
        }
        Weapon otherWeapon = (Weapon) other;
        return this.type.equals(otherWeapon.type) && this.name.equals(otherWeapon.name) && 
            this.weaponDamage == otherWeapon.weaponDamage &&
            this.weaponDistance == otherWeapon.weaponDistance && this.weaponAccuracy == otherWeapon.weaponAccuracy;
    }
    
}