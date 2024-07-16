import java.util.ListIterator;
import java.util.LinkedList;


public class Polynomial{



    private LinkedList<Term> polynomialList;


    public Polynomial(){
        this.polynomialList = new LinkedList<>();
    }


    public Polynomial(Polynomial otherPolyObj){
        if(otherPolyObj ==null){
            return;
        }
        LinkedList<Term> poly = otherPolyObj.polynomialList;
        this.polynomialList = new LinkedList<>(poly);
        this.addLikedTerms();
    }

    public void addTerm(Term term){
        this.polynomialList.add(term);
        this.addLikedTerms();
    }

    public void add(Polynomial otherPolyObj){
        LinkedList<Term> poly = otherPolyObj.polynomialList;
        this.polynomialList.addAll(poly);
        this.addLikedTerms();
    }

    public int getNumTerms(){
        return this.polynomialList.size();   
    }

    public Term getTerm(int index){
        return this.polynomialList.get(index);
    }

    public void clear(){
        this.polynomialList.clear();
    }


    public void addLikedTerms(){
















        

        LinkedList<Term> polynomialList2 = new LinkedList<>();
        while(this.polynomialList.size() > 0){


            
            Term term = this.polynomialList.removeFirst();
            int exponentTerm = term.getExponent();
            int coefficientSum = term.getCoefficient();
            ListIterator<Term> iterator = this.polynomialList.listIterator(0);
            while (iterator.hasNext()){
                
                Term temp = iterator.next();
                int expo = temp.getExponent();
                if(exponentTerm == expo){
                    coefficientSum = coefficientSum + temp.getCoefficient();
                    iterator.remove();
                }
            }
            if(coefficientSum != 0){
                Term newTerm = new Term(coefficientSum, exponentTerm);
                polynomialList2.add(newTerm);
            }
        }



        for(int i = 0; i < polynomialList2.size(); i++){
            for(int j = 1; j < polynomialList2.size(); j++){
                if(polynomialList2.get(j-1).getExponent() < polynomialList2.get(j).getExponent()){
                    Term maxTerm = polynomialList2.get(j);
                    Term minTerm = polynomialList2.get(j-1);
                    polynomialList2.set(j-1, maxTerm);
                    polynomialList2.set(j, minTerm);
                }
            }
        }
        this.polynomialList = polynomialList2;
        
    }

    
    public String toString(){
        String output = "";
        if(this.polynomialList.size() == 0){
            output = "0";
        } else {
            ListIterator<Term> iterator = this.polynomialList.listIterator(0);
            Term current = iterator.next();
            if(current.getCoefficient() > 0){
                output = current.toString().substring(1);
            } else {
                output = current.toString();
            }
            while(iterator.hasNext()){
                output = output + iterator.next().toString();
            }
        }
        return output;
    }
    
}