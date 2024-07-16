/*
*CaffeinatedBeverage.java : represents one beverage, tracking name, amount of fluid ounces, and price
*Author: Josh Clemens
*/

public class CaffeinatedBeverage
{
    //const
    public static final String DEFAULT_NAME = "Caffeine Fix";
    public static final int DEFAULT_OUNCES = 16;
    public static final double DEFAULT_PRICE = 0.99;

    //instance variables
    private String name;
    private int ounces;
    private double price;

    //constructors
    //full constructor
    public CaffeinatedBeverage(String name, int ounces, double price) {
        if(!this.setAll(name, ounces, price)){
            System.out.println("Error: bad datta given to full CaffeinatedBeverage constructor.");
            System.exit(0);
        }
        // this.name = name;
        // this.ounces = ounces;
        // this.price = price;
    }

    //default constructor
    public CaffeinatedBeverage(){
        this( DEFAULT_NAME, DEFAULT_OUNCES, DEFAULT_PRICE );
    }

    //copy constructor
    public CaffeinatedBeverage(CaffeinatedBeverage original){
        if(original != null){
            this.setAll(original.name, original.ounces, original.price);
        } else {
            System.out.println("ERROR: null data given to copy CaffeinatedBeverage constructor.");
            System.exit(0);
        }
    }

    //setters

    public boolean setName(String name){
        if(name != null && name.length() > 0) {
            this.name = name;
            return true;
        } else {
            return false;
        }
    }

    public boolean setOunces(int ounces){
        if(ounces >= 0){
            this.ounces = ounces;
            return true;
        } else {
            return false;
        }
    }

    public boolean setPrice(double price){
        if(price >= 0){
            this.price = price;
            return true;
        } else {
            return false;
        }
    }

    public boolean setAll(String name, int ounces, double price){
        return this.setName(name) && this.setOunces(ounces) && this.setPrice(price);
    }

    public String getName() {
        return this.name;
    }

    
    public int getOunces() {
        return this.ounces;
    }

    public double getPrice() {
        return this.price;
    }

    // public void setName(String name) {
    //     this.name = name;
    // }

    // public void setOunces(int ounces) {
    //     this.ounces = ounces;
    // }

    // public void setPrice(double price) {
    //     this.price = price;
    // }

    // @Override
    // public boolean equals(Object o) {
    //     if (o == null || this.getClass() != o.getClass()) return false;
    //     CaffeinatedBeverage that = (CaffeinatedBeverage) o;
    //     return this.ounces == that.ounces &&
    //             Double.compare(this.price, that.price) == 0 &&
    //            this.name.equals(that.name);
    // }

    @Override
    public boolean equals(Object other) {
        if(other == null || other instanceof CaffeinatedBeverage){
            return false;
        }
        CaffeinatedBeverage otherCaffeine = (CaffeinatedBeverage) other;
        return this.ounces == otherCaffeine.ounces &&
            Double.compare(this.price, otherCaffeine.price) == 0 &&
               this.name.equals(otherCaffeine.name);
    }

    @Override
    public String toString(){
        return String.format("CaffeinatedBeverage: name = %s, %d fl.oz, $%.2f",
            this.name, this.ounces, this.price);
    }

    public boolean sip(int ounces){
        if(this.ounces >= ounces){
            this.ounces -= ounces;
        } else {
            this.ounces = 0;
        }
        return this.ounces > 0;
    }

    public boolean isEmpty(){
        return this.ounces == 0;
    }


}