/*
*RedBull.java : one RedBull containing all data from CaffeinatedBeverage and flavor(sugarfree, watermelon, tropical, blueberry)
*Author: Josh Clemens
*/

public class RedBull extends CaffeinatedBeverage{
    //const
    public static final String DEFAULT_FLAVOR = "sugarFree";

    //inst variables
    private String flavor;

    //constructors
    //full constructor
    public RedBull(String name, int ounces, double price, String flavor){
        super(name, ounces, price);
        if(!this.setFlavor(flavor)){
            System.out.println("ERROR: Bad data given to RedBull full constructor.");
        }
    }

    //default constructor
    public RedBull(){
        super();
        this.setFlavor(DEFAULT_FLAVOR);
    }
    
    //copy constructor
    public RedBull(RedBull original){
        if(original != null){
            this.setAll(original.getName(), original.getOunces(), original.getPrice(), original.flavor);
        } else {
            System.out.println("Error: Null data given to copy RedBull constructor.");
            System.exit(0);
        }
    }

    //setter
    public boolean setFlavor(String flavor){
         if(flavor != null && flavor.length() > 0){
            this.flavor = flavor;
            return true;
        } else {
            return false;
        }
    }

    public boolean setAll(String name, int ounces, double price, String flavor){
        return super.setAll(name, ounces, price) && this.setFlavor(flavor);
    }

    //getter
    public String getFlavor(){
        return this.flavor;
    }

    @Override
    public boolean equals(Object other){
        if (other == null || other instanceof Tea){
            return false;
        }
        RedBull otherRedBull = (RedBull) other;
        return super.equals(otherRedBull) && this.flavor == otherRedBull.flavor;
    }
    

    @Override
    public String toString(){
        String redBullString = super.toString();
        int colonLocation = redBullString.indexOf(":");
        redBullString = redBullString.substring(colonLocation + 2); //cut off front label from caffeinatedBeverage

        return String.format("RedBull: %s, Flavor : %s",
            redBullString, this.flavor);
    }
}