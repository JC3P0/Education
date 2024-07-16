
/*
 * Transaction.java
 *
 */
public class Transaction {

    private String customerNumber;
    private int transactionType;
    private double amount;
    private String date;
    private String fees;
 /** Creates a new instance of Transaction */

    public Transaction(String customerNumber, int tranType, double amount, String fees){
        this.customerNumber = customerNumber;
        this.transactionType = tranType;
        this.amount = amount;
        this.fees = fees;
    }


    public void processTran(){
        
    }

 
}