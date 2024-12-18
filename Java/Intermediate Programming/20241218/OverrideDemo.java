// CMPINF 0401 Summer 2024
// Demonstration of Method Overriding.  See also the following classes:
// SimpleAList (in SimpleAList.java) -- class to implement basic functionality of an ArrayList
// SortAList (in SortAList.java) -- subclass of SimpleAList that now requires the data in
//		the list to stay in sorted order

public class OverrideDemo
{
	public static String [] data = {"Here", "Are", "Some", "Java", "String", "Literals"};
	public static void main(String [] args)
	{
		SimpleAList regList = new SimpleAList();
		SortAList sortList = new SortAList();
		
		System.out.println("Adding data...");
		for (int i = 0; i < data.length; i++)
		{
			regList.add(data[i]);
			sortList.add(data[i]);
		}
		showData(regList);
		showData(sortList);
		System.out.println();
	
		System.out.println("Changing value at location 4...");
		regList.set(4, "Fun");
		sortList.set(4, "Fun");
		showData(regList);
		showData(sortList);
		System.out.println();
		
		// remove() was not overridden in SortAList so this method will have
		// the identical effect in both classes
		System.out.println("Removing value at location 2...");
		regList.remove(2);
		sortList.remove(2);
		showData(regList);
		showData(sortList);
		System.out.println();
		
		// Test the add(ind, val) method within a try catch block to see that an
		// exception is thrown in the SortAList version.  We will discuss try catch
		// blocks in a few more lectures.
		System.out.println("Adding at index 3...");
		try
		{
			regList.add(3, "Zephyr");
			sortList.add(3, "Zephyr");
		}
		catch (UnsupportedOperationException e)
		{
			System.out.println(e.toString());
		}
		showData(regList);
		showData(sortList);
	}
	
	// Note that the parameter to this method is type SimpleAList.  However, the SortAList
	// object also works fine here due to the "is a" relationship of a subclass with its
	// superclass.
	public static void showData(SimpleAList list)
	{
		System.out.print("Contents: ");
		for (int i = 0; i < list.size(); i++)
			System.out.print(list.get(i) + " ");
		System.out.println();
	}
}
