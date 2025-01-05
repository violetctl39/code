// CMPINF 0401 Summer 2024
// Subclass of SimpleAList that keeps the data sorted.  See SimpleAList.java and additional
// comments below.
public class SortAList extends SimpleAList
{
	// no new data.  Data inherited from SimpleAList is
	// protected String [] data;
	// protected int size;
	
	// All methods are also inherited from SimpleAList.  However, some of them are
	// overridden as shown below.  This means that the new definition in this class
	// will replace the one from the superclass.  In order for this to work the method
	// specification in the superclass and the subclass must be IDENTICAL.
	
	// Call superclass constructors.  Since there is no new data in SortAList, we
	// don't need any new assignments within the subclass.
	public SortAList(int init)
	{
		super(init);
	}
	
	public SortAList()
	{
		super();
	}
	
	// Override the add() method to now add the item into the correct
	// location by sorted order.  This method is in effect doing a single iteration
	// of the insertion sort algorithm.  Note that this utilizes the fact that String
	// objects have the compareTo() method.  This is true because String in Java
	// implements the Comparable interface.  We will discuss the Comparable interface
	// in lecture soon.
	public boolean add(String val)
	{
		if (size == data.length)	// resize if necessary (the resize method is
			resize(2 * size);		// inherited from SimpleAList)
		// Start in the back of the array.  Push the new item down into the array as
		// long as it is less than the current item.
		int loc = size;
		for (int i = size-1; i >= 0; i--)
		{
			// compareTo will return a negative if val < data[i]
			// compareTo will return 0 if val == data[i]
			// compareTo will return a positive if val > data[i]
			int result = val.compareTo(data[i]);
			if (result >= 0)	// New item is >= current item, so the new item should
			{					// go in current loc. Break out of loop
				break;
			}
			else
			{	// New item is < current item so move that item down one and keep going
				data[i+1] = data[i];
				loc--;
			}
		}
		data[loc] = val;	// Place new item and increment size
		size++;
		return true;
	}
	
	// This version of add() must also be overridden, but in this case we override it
	// to throw an exception, since we can no longer add an item into an arbitrary location
	public boolean add(int loc, String val)
	{
		throw new UnsupportedOperationException("Cannot add to arbitrary index in SortedList");
	}
	
	// We must override this method to move the item that has been set into its correct
	// location by sorted order.  This can be done in various ways.  Note that here I am
	// doing it by simply removing and then adding the item -- not a very efficient way
	// (think about why this is the case) but definitely the easiest to code.  Alternatively,
	// the programmer may prefer to not allow this operation at all, similar to what is done
	// with the add(loc, val) method above.
	public String set(int loc, String val)
	{
		if (loc >= 0 && loc < size)
		{
			String old = remove(loc);
			add(val);
			return old;
		}
		return null;
	}
}		
