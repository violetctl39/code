// CS 0445 Spring 2025
// AssigB driver program.  This program tests your IndexDeque<T> and
// IndexAddRemoveDeque<T> classes.
// See also AssigA.java for testing of your MyDeque<T> class.

// This program must work as is with your IndexDeque<T> and IndexAddRemoveDeque<T>
// classes.  Look carefully at all of the method calls so that you implement
// your methods correctly.  Also refer back to the document for
// some information on the functionality of these classes.

// Note: The methods in the IndexableAddRemove interface will require shifting
// due to mutations in the middle of the array.  Think carefully about how you
// will implement these given the circular array implementation of your deque.
// Note that the simple deque methods MUST NOT have any shifting and the
// IndexAddRemoveDeque<T> class should inherit the basic deque methods without
// changing them and without adding any new instance variables.

// The output should be identical to my sample output.  See the output in 
// AssigB-out.txt
 
public class AssigB
{
	public static void main(String [] args)
	{
		System.out.println("Initializing a new IndexDeque...");
		IndexDeque<Integer> D1 = new IndexDeque<Integer>(10);
		for (int i = 1; i < 8; i++)
		{
			D1.addToBack(Integer.valueOf(i));
		}
		System.out.println(D1.toString());
		System.out.println();


		System.out.println("Removing 3 items then adding 1");
		Integer bogus = D1.removeFront();
		bogus = D1.removeFront();
		bogus = D1.removeFront();
		D1.addToBack(Integer.valueOf(8));
		System.out.println(D1.toString());
		System.out.println();
		
		Indexable<Integer> DX = (Indexable<Integer>) D1;
		System.out.println("Testing Indexable...");
		System.out.print("Front to back: ");
		for (int i = 0; i < DX.size(); i++)
		{
			Integer item = DX.getFront(i);
			System.out.print(item + " " );
			item++;  // using autoboxing to increment Integer
			DX.setFront(i, item);
		}
		System.out.println();	
		System.out.println(D1.toString());
		
		System.out.print("Back to front: ");
		for (int i = 0; i < DX.size(); i++)
		{
			Integer item = DX.getBack(i);
			System.out.print(item + " " );
			item++;  // using autoboxing to increment Integer
			DX.setBack(i, item);
		}
		System.out.println();	
		System.out.println(D1.toString());	
		try
		{
			Integer item = DX.getFront(DX.size());
			System.out.println("Item is " + item);
		}
		catch (IndexOutOfBoundsException e)
		{
			System.out.println(e.toString());
		}
		System.out.println();
		
		System.out.println("Testing IndexableAddRemove");
		IndexAddRemoveDeque<Integer> D2 = new IndexAddRemoveDeque<Integer>(10);
		System.out.println("Capacity is " + D2.capacity());
		for (int i = 1; i <= 6; i++)
		{
			D2.addToBack(Integer.valueOf(i));
		}
		System.out.println(D2.toString());
		System.out.println();
		System.out.println("Adding some data...");
		System.out.println("Add at index 1 from front");
		System.out.println("Add at index 1 from back");
		D2.addToFront(1, Integer.valueOf(88));
		D2.addToBack(1, Integer.valueOf(77));
		System.out.println(D2.toString());
		System.out.println();
		
		System.out.println("Removing some data...");
		Integer X = D2.removeFront(2);
		System.out.println("Removed " + X + " at index 2 from front");
		X = D2.removeBack(2);
		System.out.println("Removed " + X + " at index 2 from back");
		System.out.println(D2.toString());
		System.out.println();
		
		// Testing resizing together with indexing
		System.out.println("More adding (causing a resize)");
		for (int i = 1; i <= 5; i++)
		{
			Integer item = Integer.valueOf(10*i);
			System.out.println("Adding " + item + " at index " + i + " from front");
			D2.addToFront(i, Integer.valueOf(item));
		}
		System.out.println(D2.toString());
		System.out.println("Capacity is " + D2.capacity());
		System.out.println();
		
		System.out.println("Deleting everything (in perhaps an inefficient way)");
		while (!D2.isEmpty())
		{
			Integer item = D2.removeBack(D2.size()-1);
			System.out.println("Removed " + item);
		}
		System.out.println(D2.toString());
		
		System.out.println("Adding some items back");
		D2.addToFront(0, Integer.valueOf(10));
		D2.addToBack(0, Integer.valueOf(20));
		System.out.println(D2.toString());
	}
}
