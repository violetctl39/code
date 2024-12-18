/* CMPINF 0401 Summer 2024 Java Example 12a
This example demonstrates direct and sequential access of Java arrays of primitive
types. It also demonstrates SEQUENTIAL SEARCH, a simple algorithm for finding
an item within an array.  */

import java.util.*;
public class ex12a
{
	// Make a static Scanner object so that all of the methods can access
	// it.  This is in effect making a "global" variable so that we don't
	// have to pass the Scanner into each method that uses it.  Note that
	// the variable must be static in order to be accessed within static
	// methods.  Try removing the static and note the error.
	public static Scanner inScan = new Scanner(System.in);

	// This method will input double values into an array.  Important note:
	// Recall that Java parameters are value parameters, meaning that copies
	// of arguments are passed to the parameters.  However, since array
	// variables are references, we can still change the contents of an array
	// within a method.  See notes for more details.
	public static void getData(double [] data)
	{
		System.out.println("=== GetData: ===");
		for (int i = 0; i < data.length; i++)
		{
			System.out.print("Enter number " + i + ": ");
			data[i] = inScan.nextDouble();
		}
	}

	public static void showData(double [] data)
	{
		System.out.println("=== ShowData: ===");
		System.out.println("Index : Data");
		System.out.println("-----   ----");
		for (int i = 0; i < data.length; i++)
			System.out.println("  " + i + "   : " + data[i]);
		System.out.println();
	}

	// This method will search for a value within the array.  It is called
	// SEQUENTIAL SEARCH because it is checking each index in the array
	// in sequence until it either finds the value or it gets to the end
	// of the array.  See other important comments below.
	public static int find(double x, double [] data)
	{
		System.out.println("=== Find: ===");
		int i = 0;
		boolean found = false;

		// Note the two conditions being checked and how the boolean expression
		// is written below.  The idea is that we need to stop if
		// i == data.length since that index is past the end of the array.  We
		// also need to stop if we actually find the item.  Since the loop will
		// stop for two different reasons, after the loop we need to check to
		// see which condition stopped it.
		while (i < data.length && !found )
		{
			double diff = x - data[i];		// Since values are double we do
			if (Math.abs(diff) < 0.001)		// not check for equality, but
				found = true;				// rather check for a small diff.
			else							// in values.
				i++;
		}
		if (found)		// If data was found, return its index
			return i;
		else
			return -1;	// otherwise return an invalid index
	}

	public static int find2(double x, double [] data)
	{
		System.out.println("=== Find2: ===");
		// In this loop we return directly from the loop body if the item is
		// found.  If the item is not found, we drop out of the loop normally
		// and return -1 to indicate that it was not found.  Note how different
		// this looks from find above -- yet logically they are the same.
		//return 0;
		for (int i = 0; i < data.length; i++)
		{
			double diff = x - data[i];		// Since values are double we do
			if (Math.abs(diff) < 0.001)		// not check for equality, but
				return i;			// rather check for a small diff.
		}
		return -1;
	}
	
	// Change a location in the array -- note that we make sure the index
	// selected is valid!
	public static void change(double [] data)
	{
		int index; // declare variable here since I need it after loop
		do
		{
			System.out.print("Enter index to change: ");
			index = inScan.nextInt();
		} while (index < 0 || index >= data.length);
		System.out.print("Enter new value: ");
		data[index] = inScan.nextDouble();
	}
	
	// Most of the work in this program is done through methods -- the main
	// below is fairly simple and readable.  This is how modular, procedural
	// programming should be done.
	public static void main (String [] args)
	{
		double [] scores1 = null;
		int num;
		System.out.print("How many numbers are there? ");
		num = inScan.nextInt();
		scores1 = new double[num];	// Create array of desired size
		getData(scores1);			// Fill it with values
		System.out.println();
		showData(scores1);			// Show the data

		System.out.print("Enter a value to search for: ");
		double val = inScan.nextDouble();
		int loc = find(val, scores1);	// Search for a value
		if (loc >= 0)
			System.out.println(val + " was found at loc " + loc);
		else
			System.out.println(val + " was not found ");

		int loc2 = find2(val, scores1);	// Search for a value
		if (loc2 >= 0)
			System.out.println(val + " was found at loc " + loc2);
		else
			System.out.println(val + " was not found ");

		double [] scores2 = scores1;	// Now we have two variables but still
										// only one object
		showData(scores2);
		change(scores1);		// Note that since both array variables
		showData(scores1);		// reference the same object, changing a
		showData(scores2);		// location in one affects the other
		
		System.out.println("About to sort array");
		Arrays.sort(scores2);	// Again, we see that the shared object
		showData(scores1);		// is sorted and displayed using both
		showData(scores2);		// references

		scores1 = new double[2];	// Now we have a new array assigned to
									// scores1 -- does not affect scores2
		showData(scores1);
		showData(scores2);
	}
}