/* CMPINF 0401 Summer 2024 Java Example 12b
Compare to ex12a

This handout has similar functionality to that of ex12a, but now
the array is within a class and the functionality is implemented
in a more object-oriented way.  Through the Scores class it also
demonstrates sharing an array across objects and resizing an array.

We will consider this handout again later when we discuss shallow
vs. deep copies of objects.

See also file Scores.java
*/
import java.util.*;
public class ex12b
{
	public static void main (String [] args)
	{
		Scanner scan = new Scanner(System.in);
		int num;
		System.out.print("How many numbers are there? ");
		num = scan.nextInt();
		Scores data = new Scores(num, scan);	// Create object
		data.getData();							// Fill it with values
		System.out.println();
		data.showData();						// Show the data

		System.out.print("Enter a value to search for: ");
		double val = scan.nextDouble();
		int loc = data.find(val);			// Search for a value
		if (loc >= 0)
			System.out.println(val + " was found at loc " + loc);
		else
			System.out.println(val + " was not found ");

		// We will look at this part of this handout a bit later in the
		// term, after discussing shallow and deep copies of objects.
		Scores shareData = new Scores(data, 0); // shareData and data will
							// both share the same array object
		Scores sepData = new Scores(data, 1);	// sepData and data will have
							// distinct array objects
		shareData.showData();	// right now the two objects have the same
		sepData.showData();		// data, so we cannot tell if the data is
								// shared or not.
				
		data.change();			// However, if we now update data, we see that
		data.showData();		// the shareData object has also changed,
		shareData.showData();	// whereas the sepData object is not
		sepData.showData();
		data.change2();		// We are now calling the change2 method, which allows
							// for index values past the end of the array.  In this
							// case, the array will be resized so that the item will
							// fit.  The details are abstracted out so the user just
							// sees that the update works.  However, since resizing
							// requires a new array to be created, if this is done the
							// array is no longer shared with the other Scores object.
							// Try it both with a valid index and one outside the
							// range and see the result of the two objects below.
		data.showData();
		shareData.showData();
		
		// Sorting demonstrates the sharing issue again
		System.out.println("About to sort sharedData Scores object");
		shareData.sort();
		data.showData();
		shareData.showData();
		sepData.showData();
	}
}