public interface QueueInterface<T>  // Textbook author's QueueInterface
{
  public void enqueue(T newEntry);  // add to logical back of queue
  
  public T dequeue();  // remove and return logical front item
  
  public T getFront();  // return front item without removing it
  
  public boolean isEmpty();  // is queue empty?
  
  public void clear();  // reset queue to empty state

} // end QueueInterface
