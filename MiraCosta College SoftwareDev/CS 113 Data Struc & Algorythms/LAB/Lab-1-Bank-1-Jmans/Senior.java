/*
 * Senior.java
 */
// create Senior class that extends from Customer
public class Senior extends Customer{
    public static final double SAVINGS_INTEREST = 0.04;
    public static final double CHECK_INTEREST = 0.01;
    public static final double CHECK_CHARGE = 0.01;
    public static final double OVERDRAFT_PENALTY = 25;

    public Senior (String cName, String cAddress, int cAge, String cPhoneNumber){
        super(cName, cAddress, cAge, cPhoneNumber);
    
    }

    public String getType(){
        return "Adult";
    }
    public double getSavingsInterest(){
        return SAVINGS_INTEREST;
    }
    public double getCheckInterest(){
        return CHECK_INTEREST;
    }
    public double getCheckCharge(){
        return CHECK_CHARGE;
    }
    public double getOverdraftPenalty(){
        return OVERDRAFT_PENALTY;
    }
}


 /** Creates a new instance of Senior */

 /** getter for getType return "Senior" */

 /** getter for Savings Interest */

 /** getter for Check Interest */

 /** getter for Check Charge */

 /** getter for OverdraftPenalty */
