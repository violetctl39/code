public interface DequeInterface<T>  // Text author's DequeInterface<T>
{
   public void addToFront(T newEntry);  // add at front
   public void addToBack(T newEntry);   // add at back
   
   public T removeFront();   // remove from front
   public T removeBack();    // remove from back
   
   public T getFront();   // get front item
   public T getBack();    // get back item
   
   public boolean isEmpty();  // is deque empty?
   
   public void clear();   // reset dequee
} // end DequeInterface
