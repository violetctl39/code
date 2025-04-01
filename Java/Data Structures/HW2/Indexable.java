// CS 0445 Spring 2025
// Indexable<T> interface
// This interface will allow an implementing class to access the data in the
// collection by index -- both to set and get the data at a given location.  This
// access will be allowed from both the front and the rear location point of
// view.  Note that the index values in this interface should translate into 
// logical locations in the underlying collection.  In other words, index i in
// the methods below does not necessarily map to location i in the underlying 
// array.

public interface Indexable<T>
{
	// Get and return the value located at logical location i from the front of the
	// collection, where the front position is logical index 0.  If the collection
	// has fewer than (i+1) items, or if i < 0, throw an IndexOutOfBoundsException 
	public T getFront(int i);

	// Get and return the value located at logical location i from the back of the
	// collection, where the back position is logical index 0.  If the collection
	// has fewer than (i+1) items, or if i < 0, throw an IndexOutOfBoundsException 	
	public T getBack(int i);
	
	// Set the value located at logical location i from the front of the
	// collection, where the front position is logical index 0.  If the collection
	// has fewer than (i+1) items, or if i < 0, throw an IndexOutOfBoundsException 
	public void setFront(int i, T item);

	// Set the value located at logical location i from the back of the
	// collection, where the back position is logical index 0.  If the collection
	// has fewer than (i+1) items, or if i < 0, throw an IndexOutOfBoundsException 	
	public void setBack(int i, T item);
	
	// Return the logical size of this Indexable.  Note that this is the same method
	// that is specified in DequeInterface<T>.  It is also part of this interface so
	// that we can iterate through the Indexable using the interface as the reference.
	public int size();
}