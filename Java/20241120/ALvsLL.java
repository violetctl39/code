package testPro;
// CS 0401 Summer 2024
// Demonstration of a simple array list and a simple linked list.  Note
// that both classes have the same functionality.  However, each implementation
// has its benefits and its drawbacks:
// -- The SimpleAList has direct access so the get() method takes a single
//    operation.  It can also add() at the end very easily since that index
//    is known in advance
// -- The SimpleLList has dynamic nodes and will never need to be resized.
//    It can also add() in the front very easily since no shifting is needed
// More specific comparisons between these implementations will be made in the
// CS 0445 course.
//
// If abstracting out the implementation details, these classes are equivalent.
// In Java we will see later how they can be implemented in a more uniform way
// (to better utilize the idea of abstraction).

// Note also that both SimpleAList and SimpleLList are lists of String objects.
// We will see later how to make these generic -- so that the underlying data in
// the lists can be any Java reference type.

public class ALvsLL
{
	static String [] data = {"here", "is", "some", "string", "data"};
	
	public static void main(String [] args)
	{
		SimpleAList alist = new SimpleAList(2);
		SimpleLList llist = new SimpleLList();
		
		System.out.println("Adding at the end...");
		for (int i = 0; i < data.length; i++)
		{
			alist.add(data[i]);
			llist.add(data[i]);
		}
		showLists(alist, llist);
		
		System.out.println("Adding in the front...");
		alist.add(0, "over");
		llist.add(0, "over");
		showLists(alist, llist);
		
		System.out.println("Adding in the middle...");
		alist.add(4, "more");
		llist.add(4, "more");
		showLists(alist, llist);
		
		System.out.println("Changing a value...");
		alist.set(2, "are");
		llist.set(2, "are");
		showLists(alist, llist);
	
		System.out.println("Removing from middle...");
		alist.remove(5);
		llist.remove(5);
		showLists(alist, llist);
		
		System.out.println("Removing from front...");
		alist.remove(0);
		llist.remove(0);
		showLists(alist, llist);
	}
	
	public static void showLists(SimpleAList A, SimpleLList L)
	{
		System.out.print("Array List: ");
		for (int i = 0; i < A.size(); i++)
			System.out.print(A.get(i)+ " ");
		System.out.println();
		System.out.print("Linked List: ");
		for (int i = 0; i < L.size(); i++)
			System.out.print(L.get(i)+ " ");
		System.out.println("\n");
	}
}
