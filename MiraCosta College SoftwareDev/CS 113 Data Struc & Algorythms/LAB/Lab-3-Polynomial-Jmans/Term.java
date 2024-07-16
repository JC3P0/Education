
// public class Term{
public class Term implements Comparable<Term>{

    //const variables
    private static final int DEFAULT_COEFICIENT = 1;
    private static final int DEFAULT_EXPONENT = 1;

    //instant variables 
    private int coefficient;
    private int exponent;

    //default constructor
    public Term(){
        this.setCoefficient(DEFAULT_COEFICIENT);
        this.setExponent(DEFAULT_EXPONENT);
    }

    //full constructor
    public Term(int coefficient, int exponent){
        setAll(coefficient, exponent);
    }

    //copy constructor
    public Term(Term original){
        if(original != null){
            this.setAll(original.getCoefficient(), original.getExponent());
        }
        
    }

    //string
    //contains(), subString(), indexOf(), length()
    // public Term(String term){
    //     if(term.equals("")){
    //         this.coefficient = 0;
    //         this.exponent = 0;
    //     } else if (!term.contains("x")){
    //         this.coefficient = Integer.parseInt(term);
    //         this.exponent = 0;
    //         // if(getCoefficient() < 0){
    //         //     term = "-" + this.coefficient;
    //         // } else {
    //         //     term = "+" + this.coefficient;
    //         // }
    //     } else if (term.contains("x") && !term.contains("^")){
    //         if(term.equals("+x")){
    //             this.coefficient = 1;
    //         } else if (term.equals(""))
    //         // if(getCoefficient() < 0){
    //         //     term = "-" + this.coefficient + "x";
    //         // } else {
    //         //     term = "+" + this.coefficient + "x";
    //         // }
            
    //     } else if (term.contains("x") && term.contains("^")){
    //         if(getCoefficient() < 0){
    //             if(getExponent() > 0){
    //                 term = "-" + this.coefficient + "x" + "^" + this.exponent;
    //             } else {
    //                 term = "-" + this.coefficient + "x" + "^" + "-" + this.exponent;
    //             }
                
    //         } else {
    //             if(getExponent() < 0){
    //                 term = "+" + this.coefficient + "x" + "^" + "-" + this.exponent;
    //             } else {
    //                 term = "+" + this.coefficient + "x" + "^" + this.exponent;
    //             }
                
    //         }
    //     }
    // }
    public Term(String term){
        if(term.equals("")){
          this.coefficient = 0;
          this.exponent = 0;
            
        } else if(!term.contains("x")){ // term -> "+5", "-3"
          this.coefficient = Integer.parseInt(term);
          this.exponent = 0;
            
        } else if(term.contains("x") && !term.contains("^")){
            
          if(term.equals("+x")){
            this.coefficient = 1;
            this.exponent = 1;
              
            } else if(term.equals("-x")){
              this.coefficient = -1;
              this.exponent = 1;
            } else{
            // "+6x", "-9x", subtring(0, 4) getting the character from index 0 to index 3
            // this.coefficient = Integer.parseInt(term.substring(0, term.indexOf("x"))); 
              String coefficientTerm = term.substring(0, term.length()-1);
              this.coefficient = Integer.parseInt(coefficientTerm);
              this.exponent = 1;
            }
          
        } else if(term.contains("x") && term.contains("^")){
            String coefficientTerm = term.substring(0, term.indexOf("x")+1);
            // String coefficientTerm = term.substring(0, term.indexOf("x"));
            String exponentTerm = term.substring(term.indexOf("^")+1, term.length());
            this.exponent = Integer.parseInt(exponentTerm);
            
            if(coefficientTerm.equals("+x")){
              this.coefficient = 1;
                
            } else if(coefficientTerm.equals("-x")){
              this.coefficient = -1;
                
            } else{
            // "+6x", "-9x", subtring(0, 4) getting the character from index 0 to index 3
                // System.out.println("This is coef: " + coefficient);
                // this.coefficient = Integer.parseInt(coefficientTerm); // you had this
                this.coefficient = Integer.parseInt(coefficientTerm.substring(0,coefficientTerm.length()-1)); 
                // System.out.println("This is coef term: " + coefficientTerm);
                // System.out.println("This is term: " + term);
                // System.out.println("This is coef: " + coefficient);
                // this.coefficient = 1;
            }
          // this.exponent = Integer.parseInt(exponentTerm);
        }
    }

    // public Term(String term){
    //     if(term.equals("")){
    //         this.coefficient = 0;
    //         this.exponent = 0;
    //     } else if (!term.contains("x")) {
    //         this.coefficient = Integer.parseInt(term);
    //         this.exponent = 0;
    //     } else if
    // }


    // clone method
    public Term clone(){
        return new Term(this.coefficient, this.exponent);
    }

    //setters
    public void setCoefficient(int coef){
        this.coefficient = coef;
    }
    public void setExponent(int expo){
        this.exponent = expo;
    }

    public void setAll(int coef, int expo){
        this.setCoefficient(coef);
        this.setExponent(expo);
    }
    
    public void setTerm(int coef, int expo){
        //same as setAll
        this.setCoefficient(coef);
        this.setExponent(expo);
    }

    //getters
    public int getCoefficient(){
        return this.coefficient;
        
    }
    
    public int getExponent(){
        return this.exponent;
    }

    //equals
    // @Override
    public boolean equals(Object obj){
        if(obj instanceof Term){
            Term other = (Term) obj;
            return (other.coefficient == this.coefficient && other.exponent == this.exponent);
            // return this.coefficient == otherTerm.coefficient && this.exponent == otherTerm.exponent;
        }
        return false;
    }

    public int compareTo(Term term){
        if(this.exponent > term.exponent){
            return 1;
        } else if (this.exponent < term.exponent){
            return -1;
        } else {
            return 0;
        }
    }


    // public String toString(){
    //     String term = "";
    //     if(this.coefficient == 0){
    //         return "";
    //     } else if (this.exponent == 0){
    //         if(this.coefficient > 0){
    //             return "+" + this.coefficient;
    //         } else {
    //             return "" + this.coefficient;
    //         }
    //     } else if (this.exponent == 1){
    //         if (this.coefficient == 1){
    //             return "+x";
    //         } else if (this.coefficient == -1){
    //             return "-x";
    //         } else if (this.coefficient > 1){
    //             return "+" + this.coefficient + "x";
    //         } else {
    //             return "" + this.coefficient + "x";
    //         }
    //     } else {
    //         if (this.coefficient == 1){
    //             return "+x^" + this.exponent;
    //         } else if (this.coefficient == -1){
    //             return "-x^" + this.exponent;
    //         } else if (this.coefficient > 1){
    //             return "+" + this.coefficient + "x^" + this.exponent;
    //         } else {
    //             return "" + this.coefficient + "x^" + this.exponent;
    //         }

    //     }
    //     // return term;
        
    // }

    public String toString(){
        String term = "";
        if (this.coefficient ==0){
            return "";
        } else if (this.exponent == 0 && this.coefficient > 0){
            return "+" + this.coefficient;
        } else if (this.exponent == 0 && this.coefficient < 0){
            return "" + this.coefficient;
        } else if (this.exponent == 1 && this.coefficient == 1){
            return "+x";
        } else if (this.exponent == 1 && this.coefficient == -1){
            return "-x";
        } else if (this.exponent == 1 && this.coefficient > 1){
            return "+" + this.coefficient + "x";
        } else if (this.exponent == 1 && this.coefficient < 1){
            return "" + this.coefficient + "x";
        } else if (this.coefficient == 1){
            return "+x^" + this.exponent;
        } else if (this.coefficient == -1){
            return "-x^" + this.exponent;
        } else if (this.coefficient > 1){
            return "+" + this.coefficient + "x^" + this.exponent;
        } else if (this.coefficient < 1) {
            return "" + this.coefficient + "x^" + this.exponent;
        }
        return term;
    }

    
}