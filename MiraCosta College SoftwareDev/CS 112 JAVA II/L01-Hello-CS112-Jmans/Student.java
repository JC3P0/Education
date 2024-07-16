public class Student{
    private String name;
    private int id;

    //default constructor
    public Student(){
        name = "";
        id = 0;
    }

    //copy constructor
    public Student (Student student){
        name = student.name;
        id = student.id;
    }

    public Student(String n, int i){
        setStudent(n, i);
    }

    public void setStudent(String n, int i){
        name = n;
        id = i;
    }

    public String getName(){
        return name;
    }

    public int getId(){
        return id;
    }

    public void print(){
     	System.out.print("\nStudent name: " + name + "\nStudent id: " + id);
    }

    public boolean equals(Student obj){
        if(name.equals(obj.name) && id == obj.id){
            return true;
        }
        else return false;
    }
}