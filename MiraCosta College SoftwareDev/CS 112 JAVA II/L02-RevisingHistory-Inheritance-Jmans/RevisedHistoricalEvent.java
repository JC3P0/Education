/*______________________
*
* RevisedHistoricalEvent.java - Adds to HistoricalEvent to add extra data to correct "historical" information.
*
______________________*/

public class RevisedHistoricalEvent extends HistoricalEvent{

    /*Constants*/
    
    public static final String DEFAULT_REVISED_DESCRIPTION = "Revised Historical event description default.";
    public static final String DEFAULT_CITATION = "Academic resource/citation.";

    /*InstanceVariables*/

    private String revisedDescription;
    private String citation;

    /*Constructors*/

    //full constructor
    public RevisedHistoricalEvent(String description, Date eventDay, String revisedDescription, String citation){
        super(description, eventDay);
        this.setRevisedDescription(revisedDescription);
        this.setCitation(citation);
    }

    //default constructor
    public RevisedHistoricalEvent(){
        this(HistoricalEvent.DEFAULT_DESCRIPTION, HistoricalEvent.DEFAULT_EVENT_DAY, DEFAULT_REVISED_DESCRIPTION, DEFAULT_CITATION);
    }

    //copy constructor
    public RevisedHistoricalEvent(RevisedHistoricalEvent original){
        if(original != null){
            this.setAll(original.getDescription(), original.getEventDay(), original.revisedDescription, original.citation);
        } else {
            System.out.println("ERROR: null data given to copy constructor");
            System.exit(0);
        }
    }

    /* Setters / Mutators*/

    public void setRevisedDescription(String revisedDescription){
        this.revisedDescription = revisedDescription;
    }

    public void setCitation(String citation){
        this.citation = citation;
    }

    public boolean setAll(String description, Date eventDay, String revisedDescription, String citation){
        if(super.setAll(description,eventDay)){
            this.setRevisedDescription(revisedDescription);
            this.setCitation(citation);
            return true;
        } else {
            return false;
        }
    }

    /*Getters / Setters*/

    public String getRevisedDescription(){
        return this.revisedDescription;
    }

    public String getCitation(){
        return this.citation;
    }


    /*OtherRequiredMethods*/

    @Override
    public String toString(){
        // return super.toString() + "\nRevised Historical Event: " + this.revisedDescription + "\nCitation/Resource: " + this.citation;
        return "The following \"history\" was told for many years:\n\n" + super.toString() + "\n\n\nBy correcting history, not rewriting it, we are revising it to embark on the process of righting a wrong.\nHere is the revised history:\n" + this.revisedDescription + "\n\nSource: " + this.citation;
    }


@Override
    public boolean equals(Object other){
        if(other == null){
            return false;
        } else if(this.getClass() != other.getClass()){
            return false;
        } else {
            RevisedHistoricalEvent otherEvent = (RevisedHistoricalEvent) other;
            return super.equals(other) &&
                this.revisedDescription.equals(otherEvent.revisedDescription) &&
                this.citation.equals(otherEvent.citation);
        }
    }

    public void teach(){
        System.out.println(this.toString());
        // System.out.println("The following \"history\" was told for many years:\n\n" + super.toString() + "\n\n\nBy correcting history, not rewriting it, we are revising it to embark on the process of righting a wrong.\nHere is the revised history:\n" + this.revisedDescription + "\n\nSource: " + this.citation)
    }



    

}