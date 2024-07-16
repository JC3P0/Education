
class Main {

    public static void main(String[] args) {
    DoubleLinkedList  myList = new DoubleLinkedList();

      myList.add("John");
      myList.add("Juan");
      myList.add("Jon");
      myList.add("Jean");
      myList.add("Jonas");
      myList.add("Johnny");
      myList.add("Joao");
      myList.add("Jani");
      myList.add("Giovanni");
      myList.add("Hans");
      System.out.println(myList);
      myList.set(3, "Ivan");
      System.out.println(myList);
      myList.add("Jhon");
      System.out.println(myList);
      myList.add(5, "Jan");
      System.out.println(myList);
      myList.remove(4);
      System.out.println(myList);
      // myList.set(6, lastItemReturned);
      // System.out.println(myList.set());
        
    }
    
}