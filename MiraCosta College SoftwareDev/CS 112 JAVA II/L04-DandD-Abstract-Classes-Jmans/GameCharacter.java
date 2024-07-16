/*
*GameCharacter.java : 
*Author: Josh Clemens
*/


public abstract class GameCharacter{
    
    //const
    public static final String DEFAULT_NAME = "Biggins";
    public static final String DEFAULT_CLASS = "Paladin";
    public static final String DEFAULT_ALIGNMENT = "Lawful Evil";
    public static final int DEFAULT_GOLD = 99;
    public static final int DEFAULT_EXP_POINTS = 10;
    public static final int DEFAULT_HIT_POINTS = 10;
    public static final int DEFAULT_ARMOUR_CLASS = 50;
    public static final Weapon DEFAULT_WEAPON_ONE = new Weapon();
    public static final Weapon DEFAULT_WEAPON_TWO = null;

    public static final String[] VALID_CLASSES = {"Barbarian", "Bard", "Clerc", "Droid", "Fighter", "Monk", "Paladin", "Ranger", "Rouge", "Sorcerer", "Warlock", "Wizard"};
    public static final String[] VALID_ALIGNMENTS = {"Lawful Good", "Neutral Good", "Chaotic Good", "Lawful Neutral", "Neutral", "Chaotic Neutral", "Lawful Evil", "Neutral Evil", "Chaotic Evil", "Unaligned"};

    //instance variables
    private String name;
    private String characterClass;
    private String alignment;
    private int gold;
    private int expPoints;
    private int hitPoints;
    private int armourClass;
    private Weapon weaponOne;
    private Weapon weaponTwo;

    //constructors
    //full constructor
    public GameCharacter(String name, String characterClass, String alignment, int gold, int expPoints, int hitPoints, int armourClass, Weapon weaponOne, Weapon weaponTwo) {
        if(!this.setAll(name, characterClass, alignment, gold, expPoints, hitPoints, armourClass, weaponOne, weaponTwo)){
            System.out.println("Error: bad datta given to full GameCharacter constructor.");
            System.exit(0);
        }
    }

    //default constructor
    public GameCharacter(){
        this( DEFAULT_NAME, DEFAULT_CLASS, DEFAULT_ALIGNMENT, DEFAULT_GOLD, DEFAULT_EXP_POINTS, DEFAULT_HIT_POINTS, DEFAULT_ARMOUR_CLASS, DEFAULT_WEAPON_ONE, DEFAULT_WEAPON_TWO);
    }

    //copy constructor
    public GameCharacter(GameCharacter original){
        if(original != null){
            this.setAll(original.name, original.characterClass, original.alignment, original.gold, original.expPoints, original.hitPoints, original.armourClass, original.weaponOne, original.weaponTwo);
        } else {
            System.out.println("ERROR: null data given to copy GameCharacter constructor.");
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

    public boolean setCharacterClass(String characterClass){
        if(GameCharacter.isInArray(VALID_CLASSES, characterClass) ) {
            this.characterClass = characterClass;
            return true;
        } else {
            return false;
        }
    }

    public boolean setAlignment(String alignment){
        if(GameCharacter.isInArray(VALID_ALIGNMENTS, alignment)) {
            this.alignment = alignment;
            return true;
        } else {
            return false;
        }
    }
    
    public boolean setGold(int gold){
        if(gold >= 0) {
            this.gold = gold;
            return true;
        } else {
            return false;
        }
    }

    public boolean setExpPoints(int expPoints){
        if(expPoints >= 0) {
            this.expPoints = expPoints;
            return true;
        } else {
            return false;
        }
    }

    public boolean setHitPoints(int hitPoints){
        if(hitPoints >= 0) {
            this.hitPoints = hitPoints;
            return true;
        } else {
            return false;
        }
    }

    public boolean setArmourClass(int armourClass){
        if(armourClass >= 0) {
            this.armourClass = armourClass;
            return true;
        } else {
            return false;
        }
    }

    public boolean setWeaponOne(Weapon weapon){
        if(weapon != null){
            this.weaponOne = new Weapon(weapon);
            return true;
        } else {
            return false;
        }
    }

    public boolean setWeaponTwo(Weapon weapon){
        if(weapon == null){
            this.weaponTwo = null;
        } else {
            this.weaponTwo = new Weapon(weapon);
        }
        return true;
    }

    public boolean setAll(String name, String characterClass, String alignment, int gold, int expPoints, int hitPoints, int armourClass, Weapon weaponOne, Weapon weaponTwo){
        return this.setName(name) && this.setCharacterClass(characterClass) && this.setAlignment(alignment) && this.setGold(gold) && this.setExpPoints(expPoints) && this.setHitPoints(hitPoints) && this.setArmourClass(armourClass) && this.setWeaponOne(weaponOne) && this.setWeaponTwo(weaponTwo);
    }

    public String getName() {
        return this.name;
    }
    public String getCharacterClass() {
        return this.characterClass;
    }
    public String getAlignment() {
        return this.alignment;
    }
    public int getGold() {
        return this.gold;
    }
    public int getExpPoints() {
        return this.expPoints;
    }
    public int getHitPoints() {
        return this.hitPoints;
    }
    public int getArmourClass() {
        return this.armourClass;
    }
    public Weapon getWeaponOne(){
        return new Weapon(this.weaponOne);
    }
    public Weapon getWeaponTwo(){
        if(this.weaponTwo == null){
            return null;
        } else {
            return new Weapon (weaponTwo);
        }
    }
    
    //checks if weaponTwo is empty and displays only if weaponTwo has data
    @Override
    public String toString(){
        String weapons = "Equipped = {" + this.weaponOne + "}";
        if(this.weaponTwo != null){
            weapons += "+ {" + this.weaponTwo + "}";
        }
        return String.format("GameCharacter: \nName = %s\nClass = %s\nAlignment = %s\nGold = %d\nXP = %d\nHP = %d\nArmourClass = %d\n%s",
            this.name, this.characterClass, this.alignment, this.gold, this.expPoints, this.hitPoints, this.armourClass, weapons);
    }

    @Override
    public boolean equals(Object other) {
        if(other == null || other instanceof GameCharacter){
            return false;
        }
        GameCharacter otherGameCharacter = (GameCharacter) other;
        boolean secondWeaponEqual = (this.weaponTwo == null && otherGameCharacter.weaponTwo == null) || this.weaponTwo.equals(otherGameCharacter.weaponTwo);
        return this.name.equals(otherGameCharacter.name) && this.characterClass.equals(otherGameCharacter.characterClass) && this.alignment.equals(otherGameCharacter.alignment) && this.gold == otherGameCharacter.gold && this.expPoints == otherGameCharacter.expPoints && this.hitPoints == otherGameCharacter.hitPoints && this.armourClass == otherGameCharacter.armourClass && this.weaponOne.equals(otherGameCharacter.weaponOne) && this.weaponTwo.equals(otherGameCharacter.weaponTwo) && secondWeaponEqual;
    }

    //helper method
    public static boolean isInArray(String[] values, String value){
        if (values == null || value == null){
            return false;
        }
        int location = 0;
        boolean isPresent = false;

        while(!isPresent && location < values.length){
            isPresent = values[location].equalsIgnoreCase(value);
            location++;
        }

        return isPresent;
    }

    public String toAscii(){
        final String BAR = "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
        final String DIVIDER = "┣" + BAR + "┫";
        final int BAR_LENGTH = BAR.length();
        // .getCanonicalName()
        String identity = this.name + " (" + this.getClass().getCanonicalName() + " / " + this.characterClass + ")";
        String hp = "HP: " + this.hitPoints, xp = "XP: " + this.expPoints, armor = "AC: " + this.armourClass, gold = String.format("%,dG", this.gold);
        int identityCenterWidth = (identity.length() + BAR_LENGTH) / 2;
        int alignmentCenterWidth = (this.alignment.length() + BAR_LENGTH) / 2;
        int specWidth = BAR.length() / 4;

        //top of box with name, race, class, and alignment
        String ascii = "┏" + BAR + "┓\n";
        ascii += String.format("┃%" + identityCenterWidth + "s%" + (BAR_LENGTH - identityCenterWidth) + "s┃%n", identity, "" ); //center identity in ascii box
        ascii += String.format("┃%" + alignmentCenterWidth + "s%" + (BAR_LENGTH - alignmentCenterWidth) + "s┃%n", this.alignment, ""); //center alignment in ascii box
        ascii += DIVIDER + "\n";

        //add on each of the stats on same row (note -2-1 because of extra space added after ┃)
        ascii += String.format("┃ %-" + (specWidth-2) + "s", hp);
        ascii += String.format("┃ %-" + (specWidth-2) + "s", xp);
        ascii += String.format("┃ %-" + (specWidth-2) + "s", armor);
        ascii += String.format("┃ %" + (specWidth-2) + "s ┃\n", gold);

        //bottom of box
        ascii += "┗" + BAR + "┛";
        
        return ascii;
    }

    
    //abstract methods
    public abstract void assist(GameCharacter other);
    public abstract boolean attack(GameCharacter other);
}