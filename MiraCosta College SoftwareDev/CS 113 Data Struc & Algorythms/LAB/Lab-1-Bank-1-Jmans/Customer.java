/*
 * Customer.java
 *
 */
abstract class Customer {


 /** Creates a new instance of Customer */

    private String name;
    private String address;
    private int age;
    private String telephoneNumber;
    private String customerNumber;
    protected static int custNumber = 0;

    public Customer(String cName, String cAddress, int cAge, String cPhoneNumber){
        this.name = cName;
        this.address = cAddress;
        this.age = cAge;
        this.telephoneNumber = cPhoneNumber;
        this.customerNumber = String.format("C%010d", ++custNumber);
    }
    @Override
    public String toString(){
        return "Name: " + this.name + " custNumber " + this.custNumber + " " + "CustomerNumber " + this.customerNumber;
    }

 

 /**
 * Return the type of customer.
 * @return the type of customer
 */
public abstract String getType();

 /*******************************************
 * Returns customer's name
 * @return String customer's name
 */
public String getName(){
    return name;
}


 /*******************************************
 * Returns customer's address
 * @return String customer's address
 */
public String getAddress(){
    return address;
}


 /*******************************************
 * Returns customer's age
 * @return int customer's age
 */
public int getAge(){
    return age;
}


 /*******************************************
 * Returns customer's phone number
 * @return String customer's phone number
 */
public String getTelephoneNumber(){
    return telephoneNumber;
}


 /*******************************************
 * Returns customer's number
 * @return String customer's number
 */
public String getCustomerNumber(){
    return customerNumber;
}


 /*******************************************
 * Changes customer's name
 * pre: name must be a not null string
 * post: customer's name changes to name
 * @param name New name
 */

public void setCustomerName(String cName){
    if(cName !=null){
        this.name = cName;
    }
}


 /*******************************************
 * Changes customer's address
 * pre: address must be a not null string
 * post: customer's address changes to address
 * @param address New address
 */
public void setAddress(String cAddress){
    if(cAddress !=null){
        this.address = cAddress;
    }
}

 /*******************************************
 * Changes customer's age
 * pre: age must be a positive value
 * post: customer's age changes to age
 * @param age New age
 */
public void setAge(int cAge){
    if(cAge != 0){
        this.age = cAge;
    }
}

 /*******************************************
 * Changes customer's phone number
 * pre: phone number must be a not null string
 * post: customer's phone number changed to phoneNumber
Programming Project Solutions
 * @param phoneNumber New number
 */
public void setTelephoneNumber(String cPhoneNumber){
    if(cPhoneNumber !=null){
        this.telephoneNumber = cPhoneNumber;
    }
}

 /*******************************************
 * Changes customer's number
 * pre: customerNumber must be a not null string
 * post: customer's number changes to customerNumber
 * @param customerNumber New customer number
 */
public void setCustomerNumber(String customerNumber){
    
    this.customerNumber = customerNumber;
    
}
    abstract double getSavingsInterest();
    abstract double getCheckInterest();
    abstract double getCheckCharge();
    abstract double getOverdraftPenalty();
}