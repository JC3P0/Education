


import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.NoSuchElementException;

/**
 * ArrayListStack: Stores data using the abstract data type of a stack, utilizing the two main methods for
 * data manipulation push() and pop().
 *
 * @param <E> data type of elements to be stored in the arrayList
 *

 */
public class ArrayListStack<E> implements StackInterface<E> {

    //data field
    private ArrayList<E> arrayStack;


    /**
     * Default Constructor, initializes an empty arrayList.
     */
    public ArrayListStack(){
        this.arrayStack = new ArrayList<>();
    }

    /**
     * Returns true if the stack is empty; otherwise, returns false
     *
     * @return true if empty, false otherwise
     */
    public boolean empty(){
        return arrayStack.isEmpty();
    }

    /**
     * Returns the object at the top of the stack without removing it
     *
     * @return reference (shallow copy) of object at top of stack
     */
        public E peek(){
            if(arrayStack.size() == 0){
                throw new EmptyStackException();
            }
            // return stackArrayList.get(stackArrayList.size() - 1);
            int topElement = arrayStack.size() - 1;
            return arrayStack.get(topElement);
        }

    /**
     * Returns the object at the top of the stack and removes it
     *
     * @return reference of removed object from top of stack
     */

    public E pop(){
        if(arrayStack.size() == 0){
            throw new EmptyStackException();
        }
        int topElement = arrayStack.size() - 1;
        return arrayStack.remove(topElement);
    }

    
    /**
     * Pushes an item onto the top of the stack and returns the item pushed.
     *
     * @param obj object to push onto top of stack
     * @return item that was pushed
     */
    public E push(E obj){
        arrayStack.add(obj);
        return obj;
    }

    /**
     * Returns the number of elements in the stack.
     *
     * @return number of elements in the stack
     */
    public int size(){
        return arrayStack.size();
    }
    
}
