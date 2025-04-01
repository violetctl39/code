// CS 0445 Spring 2025
// IndexableAddRemove<T> interface
// This interface extends Indexable to allow inserting and removing at an
// arbitrary location.
// Note: For an array implementation of this interface you are allowed to
// use shifting. 

public interface IndexableAddRemove<T> extends Indexable<T>
{
	// Add the value at logical location i from the front of the
	// collection, where the front position is logical index 0.  The relative locations of
	// the remaining items should be adjusted accordingly.  If the collection
	// has fewer than i items, or if i < 0, throw an IndexOutOfBoundsException 
	public void addToFront(int i, T item);

	// Add the value at logical location i from the back of the
	// collection, where the back postion is logical index 0.  The relative locations of
	// the remaining items should be adjusted accordingly.  If the collection
	// has fewer than i items, or if i < 0, throw an IndexOutOfBoundsException 	
	public void addToBack(int i, T item);

	// Remove and return the item at logical location i from the front of the
	// collection, where the front position is logical index 0.  The relative locations of
	// the remaining items should be adjusted accordingly.  If the collection has fewer
	// than (i+1) items, or if i < 0, throw an IndexOutOfBoundsException 
	public T removeFront(int i);

	// Remove and return the item at logical location i from the back of the
	// collection, where the back position is logical index 0.  The relative locations of
	// the remaining items should be adjusted accordingly.  If the collection has fewer
	// than (i+1) items, or if i < 0, throw an IndexOutOfBoundsException 
	public T removeBack(int i);
	
}