/*
*Tea.java : one tea containing all data from CaffeinatedBeverage and brew temp in Celsius
*Author: Josh Clemens
*/

public class Tea extends CaffeinatedBeverage{
    //const
    public static final int DEFAULT_BREW_TEMP = 90;

    //inst variables
    private int brewTemp;

    //constructors
    //full constructor
    public Tea(String name, int ounces, double price, int brewTemp){
        super(name, ounces, price);
        if(!this.setBrewTemp(brewTemp)){
            System.out.println("ERROR: Bad data given to full constructor.");
        }
    }

    //default constructor
    public Tea(){
        super();
        this.setBrewTemp(DEFAULT_BREW_TEMP);
    }
    
    //copy constructor
    public Tea(Tea original){
        if(original != null){
            this.setAll(original.getName(), original.getOunces(), original.getPrice(), original.brewTemp);
        } else {
            System.out.println("Error: Null data given to copy Tea constructor.");
            System.exit(0);
        }
    }

    //setter
    public boolean setBrewTemp(int brewTemp){
        if(brewTemp > 0){
            this.brewTemp = brewTemp;
            return true;
        } else {
            return false;
        }
    }

    public boolean setAll(String name, int ounces, double price, int brewTemp){
        return super.setAll(name, ounces, price) && this.setBrewTemp(brewTemp);
    }

    //getter
    public int getBrewTemp(){
        return this.brewTemp;
    }

    @Override
    public boolean equals(Object other){
        if (other == null || other instanceof Tea){
            return false;
        }
        Tea otherTea = (Tea) other;
        return super.equals(otherTea) && this.brewTemp == otherTea.brewTemp;
    }
    

    @Override
    public String toString(){
        String caffeineString = super.toString();
        int colonLocation = caffeineString.indexOf(":");
        caffeineString = caffeineString.substring(colonLocation + 2); //cut off front label from caffeinatedBeverage

        return String.format("Tea: %s, brewed @ %d°C",
            caffeineString, this.brewTemp);
    }
}