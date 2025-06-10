/**
   An interface for the ADT deque.
   @author Frank M. Carrano
   @author Timothy M. Henry
   @version 5.0
*/

// Author's Deque with iterator added to it.  You will need
// this interface for Assignment of Iterator

import java.util.*;
public interface DequeWithIteratorInterface<T>
{
   /** Adds a new entry to the front/back of this deque.
       @param newEntry  An object to be added. */
   public void addToFront(T newEntry);
   public void addToBack(T newEntry);
   
   /** Removes and returns the front/back entry of this deque.
       @return  The object at the front/back of the deque.
       @throws  EmptyQueueException if the deque is empty before the
                operation. */
   public T removeFront();
   public T removeBack();
   
   /** Retrieves the front/back entry of this deque.
       @return  The object at the front/back of the deque.
       @throws  EmptyQueueException if the deque is empty. */
   public T getFront();
   public T getBack();
   
   /** Detects whether this deque is empty.
       @return  True if the deque is empty, or false otherwise. */
   public boolean isEmpty();
   
   /*  Removes all entries from this deque. */
   public void clear();
   
   // This method simply returns a new Iterator<T> object that is built
   // on top of this deque.
   public Iterator<T> iterator();
} // end DequeInterface
