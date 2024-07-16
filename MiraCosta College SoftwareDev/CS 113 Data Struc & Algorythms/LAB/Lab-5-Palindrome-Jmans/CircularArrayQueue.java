


import java.util.*;

/**
 * CircularArrayQueue: Stores data using the abstract data type of a queue, implements all the methods
 * of the java.util.Queue class
 *
 * @param <E> data type of elements to be stored in the arrayList
 *
 */
public class CircularArrayQueue<E> implements Queue<E> {


    private E[] queueArray;
    int head;
    int tail;
    int capacity;
    int size;
    

    /**
     * Initializes an array using the abstract data type queue.
     *
     * @param maxSize the size of the array
     */
    public CircularArrayQueue(int maxSize){
        this.capacity = maxSize;
        this.queueArray = (E[]) new Object[capacity];
        this.head = -1;
        this.tail = -1;
        this.size = 0;
    }


    /**
     * Inserts the specified element into this queue if it is possible to do
     * so immediately without violating capacity restrictions.
     * When using a capacity-restricted queue, this method is generally
     * preferable to {@link #add}, which can fail to insert an element only
     * by throwing an exception.
     *
     * @param o the element to add
     * @return {@code true} if the element was added to this queue, else
     *         {@code false}
     * @throws NullPointerException if the specified element is null.
     */
    public boolean offer(E obj){
        if(obj == null){
            throw new NullPointerException();
        }
        if(size == capacity){
            reallocate(); //create a bigger array and transfer every element to the new bigger array
        }
        if(head == -1){
            head++;
        }
        tail = (tail +1) % capacity;
        queueArray[tail] = obj;
        size++;
        return true;
    }


    /**
     * Inserts the specified element into this queue if it is possible to do so
     * immediately without violating capacity restrictions, returning
     * {@code true} upon success and throwing an {@code IllegalStateException}
     * if no space is currently available.
     *
     * @param o the element to add
     * @return {@code true} (as specified by {@link Collection#add})
     * @throws IllegalStateException if the element cannot be added at this
     *         time due to capacity restrictions
     */

    public boolean add (E obj){
        if(tail == capacity){
            throw new IllegalStateException();
        }
        return offer(obj);
    }


    /**
     * Retrieves and removes the head of this queue,
     * or returns {@code null} if this queue is empty.
     *
     * @return the head of this queue, or {@code null} if this queue is empty
     */
    public E poll(){
        if(size == 0){
            return null;
        }

        E returnElement = queueArray[head];
        head = (head + 1) % capacity;
        size--;
        return returnElement;
    }


    /**
     * Retrieves and removes the head of this queue.  This method differs
     * from {@link #poll() poll()} only in that it throws an exception if
     * this queue is empty.
     *
     * @return the head of this queue
     * @throws NoSuchElementException if this queue is empty
     */
    public E remove(){
        if(size == 0){
            throw new NoSuchElementException();
        }
        return poll();
    }


    /**
     * Retrieves, but does not remove, the head of this queue.  This method
     * differs from {@link #peek peek} only in that it throws an exception
     * if this queue is empty.
     *
     * @return the head of this queue
     * @throws NoSuchElementException if this queue is empty
     */
    public E element(){
        if(head == -1){
            throw new NoSuchElementException();
        }
        return this.queueArray[head];
    }

    /**
     * Returns the element at the head of the queue. Returns null if
     * the queue is empty.
     *
     * @return element at the head of the queue.
     */
    public E peek(){
        if(head == -1){
            return null;
        }
        return this.queueArray[head];
    }

    /**
     * Helper method that creates an array twice the size of the
     * original array.
     */
    public void reallocate(){
        int newCapacity = this.capacity * 2;
        int j = head;
        E[] newArray = (E[]) new Object[newCapacity];
        for(int i = 0; i < capacity; i++){
            newArray[i] = queueArray[j];
            j = (j + 1) % capacity;
        }
        head = 0;
        tail = capacity - 1;
        capacity = newCapacity;
        queueArray = newArray;
    }






    /**
     * The following methods were inherited from java.util.Collectoins and
     * were not implemented in this homework assignment.
     * size(), isEmpty(), contatins(Object o), iterator(), toArray(), toAarray(Object[] a), remove(Object o), addAll(Collection c), clear(), retainAll(Collection c), removeAll(Collection c), containsAll(Collection c)
     */
    public int size(){
        return size;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public void clear(){
        this.head = -1;
        this.tail = -1;
        size = 0;
    }

    public boolean contains(Object o){
        return false;
    }

    public Iterator iterator(){
        return null;
    }

    public Object[] toArray(){
        return new Object[0];
    }

    public Object[] toArray(Object[] a){
        return new Object[0];
    }

    public boolean remove (Object o){
        return false;
    }
    
    public boolean addAll(Collection c){
        return false;
    }

    public boolean retainAll(Collection c){
        return false;
    }

    public boolean removeAll(Collection c){
        return false;
    }

    public boolean containsAll(Collection c){
        return false;
    }

    
}
