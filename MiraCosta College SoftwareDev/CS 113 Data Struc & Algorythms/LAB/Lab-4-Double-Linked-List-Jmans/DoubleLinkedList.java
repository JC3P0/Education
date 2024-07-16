
import java.util.*;

public class DoubleLinkedList<E> extends AbstractSequentialList<E>{
    //data fields
    private Node<E> head = null;
    private Node<E> tail = null;
    private int size = 0;

    public void add(int index, E element){
        listIterator(index).add(element);
    }

    public void addFirst(E element){
        add(0, element);
    }

    public void addLast(E element){
        add(size, element);
    }

    public E getFirst(){
        return head.data;
    }

    public E getLast(){
        return tail.data;
    }

    public int size(){
        return size;
    }

    public E get(int index) throws IndexOutOfBoundsException{
        if(index < 0 || index >= size){
            throw new IndexOutOfBoundsException();
        }
        ListIterator<E> iter = listIterator(index);
        return iter.next();
    }

    public E remove (int index){
        E returnValue = null;
        ListIterator<E> iter = listIterator(index); 
        if(iter.hasNext()){
            returnValue = iter.next();
            iter.remove();
        } else {
            throw new IndexOutOfBoundsException();
        }
        return returnValue;
    }
    
    public Iterator iterator(){
        return new ListIter(0);
    }

    public ListIterator listIterator(){
        return new ListIter(0);
    }

    public ListIterator listIterator(int index){
        return new ListIter(index);
    }

    public ListIterator listIterator(ListIterator iter){
        return new ListIter((ListIter) iter);
    }

    ///inner class node
    private static class Node<E> {
        
        private E data;
        private Node<E> next = null;
        private Node<E> prev = null;

    //constructor
        private Node(E dataItem){
            data = dataItem;
        }
    }

    //inner class ListIter
    public class ListIter implements ListIterator<E>{
        
        private Node<E> nextItem;
        private Node<E> lastItemReturned;
        private int index = 0;

        //constructor
        public ListIter(int i){
            if(i < 0 || i > size){
                throw new IndexOutOfBoundsException("Invalid index " + i);
            }
            lastItemReturned = null;
            if (i == size){
                index = size;
                nextItem = null;
            } else {
                nextItem = head;
                for(index = 0; index < i; index++){
                    nextItem = nextItem.next;
                }
            }
        }

        //copy constructor
        public ListIter(ListIter other){
            nextItem = other.nextItem;
            index = other.index;
        }

        public boolean hasNext(){
            return index < size;
        }

        public boolean hasPrevious(){
            return index > 0;
        }

        public int previousIndex(){
            return index - 1;
        }

        public int nextIndex(){
            return index;
        }

        public void set(E e) throws IllegalStateException{
            if(lastItemReturned == null){
                throw new IllegalStateException();
            } else {
                lastItemReturned.data = e;
            }
        }

        public void remove() throws IllegalStateException{
            if(lastItemReturned == null){
                throw new IllegalStateException();
            } else {

                if(size == 1){
                    head = null;
                    tail = null;
                    nextItem = null;
                } else if (lastItemReturned == head) {
                    head = lastItemReturned.next;
                    head.prev = null;
                } else if (lastItemReturned == tail){
                    tail = lastItemReturned.prev;
                    lastItemReturned.prev.next = null;
                } else {
                    lastItemReturned.prev.next = lastItemReturned.next;
                    lastItemReturned.next.prev = lastItemReturned.prev;
                }


                lastItemReturned = null;
                index--;
                size--;
            }
            
        }

        public E next() throws NoSuchElementException{
            if(!hasNext()){
                throw new NoSuchElementException();
            }
            E nextElement = nextItem.data;
            lastItemReturned = nextItem;
            nextItem = nextItem.next;
            index++;
            return nextElement;
        }

        public E previous() throws NoSuchElementException{
            if(!hasPrevious()){
                throw new NoSuchElementException();
            }
            if(nextItem == null){
                nextItem = tail;
            } else {
                nextItem = nextItem.prev;
            }
            lastItemReturned = nextItem;
            index--;
            return lastItemReturned.data;
        }

        public void add(E e){
            Node newNode = new Node(e);
            if(head == null){
                head = newNode;
                tail = head;
                nextItem = head;
            } else if (nextItem == head){
                nextItem.prev = newNode;
                newNode.next = nextItem;
                head = newNode;
            } else if ( nextItem == null){
                tail.next = newNode;
                newNode.prev = tail;
                tail = newNode;
            } else {
                newNode.next = nextItem;
                newNode.prev = nextItem.prev;
                nextItem.prev.next = newNode;
                nextItem.prev = newNode;
            }


            lastItemReturned = null;
            size++;
            index++;
            
        }
    }
    
}