/*
 * Account.java
 *
 */
abstract class Account {

    
    /** Creates a new instance of Account, ++accNumber, balance = 0, upto 20 transactions limit, tranIndex = 0*/

    protected Customer customer;
    protected double balance;
    protected String accountNumber;
    protected Transaction[] transactions;
    protected static int accNumber = 0;
    protected int tranIndex;

    public abstract double deposit(double amount);
    public abstract double withdrawal(double amount);

    public Account(Customer customer){
        this.customer = customer;
        this.balance = 0;
        this.accountNumber = String.format("A%010d", ++accNumber);
        this.transactions = new Transaction[20];
        this.tranIndex = 0;
    }

    /*******************************************
     * Returns account balance
     * @return double Account balance
     */

    public double getBalance(){
        return this.balance;
    }

    /*******************************************
     * Returns account owner
     * @return Customer Account owner
     */    
    public Customer getCustomer(){
        return this.customer;
    }

    /*******************************************
     * Returns account number
     * @return String Account number
     */    
    public String getNumber(){
        return this.accountNumber;
    }

          
    /*******************************************
     * Converts Account object to a String object
     * @return String account information as String object
     */    
    //@Override


    @Override
    public String toString(){
        String message;
        String type;
        message = "Account: " + accountNumber + "\nOwner: " + customer.getName() + "\nType of customer: " + customer.getType() + "\nBalance: $" + balance;
        return message;
    }
    

    
}