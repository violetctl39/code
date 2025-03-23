// CS 0445 Spring 2025
// Primitive implementation of author's QueueInterface that adds at 
// the rear of an array and removes from index 0 of the array.  Note
// that offer() method is just a couple of statements but the poll() 
// method requires a loop to shift the remaining items over to fill in 
// the gap at index 0.

// The spec of the interface is changed slightly in this implementation.
// For dequeue() or getFront() with an empty queue, this implementation
// will return null, while the author's spec is to throw an
// exception.

// Later we will look at a better implementation of this ADT.

public class SimpleQueue<T> implements QueueInterface<T>
{
	private T [] theQueue;  // Parameter used for array data
	private int size;
	//private int moves;

	public SimpleQueue(int initsize)
	{
		theQueue = (T []) new Object[initsize];
		size = 0;
	}

	// Easy to add at the end
	public void enqueue(T element)
	{
		if (size < theQueue.length)
		{
			theQueue[size] = element;
			size++;
		}
	}
	
	// Must shift to put new front at index 0
	public T dequeue()
	{
		if (size > 0)
		{
			T temp = theQueue[0];
			shift(size-1);
			theQueue[size-1] = null;
			size--;
			return temp;
		}
		else
			return null;
	}
	
	public T getFront()
	{
		if (size > 0)
			return theQueue[0];
		else
			return null;
	}
	
	public boolean isEmpty()
	{
		return size == 0;
	}
	
	public void clear()
	{
		theQueue = (T []) new Object[theQueue.length];
		size = 0;
	}
	
	// Method is private - not part of the interface
	private void shift(int amt)
	{
		for (int i = 0; i < amt; i++)
		{
			theQueue[i] = theQueue[i+1];
			moves++;
		}
	}
}