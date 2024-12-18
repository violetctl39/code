//CMPINF 0401 Summer 2024
//Class to store and manipulate scores (use with ex12b.java).  This handout
//also demonstrates sharing of arrays across objects and resizing arrays.
//See more details below.

import java.util.*;
public class Scores
{
	private double [] theData;  // Now the array is an instance variable
	private Scanner inScan;     // Allows input scanner to be accessed
								// from within the class

	public Scores(int size, Scanner s)
	{
		theData = new double[size];
		inScan = s;
	}

	// This constructor can make a new object that shares the array
	// (shallow copy) or a new object that has its own array (deep
	// copy).  See the difference in the effect in the ex12b.java program.  
	// We will discuss this in lecture soon. 
	public Scores(Scores oldOne, int flag)
	{
		if (flag == 0)
		{
			theData = oldOne.theData;  // Share the same array
			inScan = oldOne.inScan;
		}
		else	// Make a new array and copy into it
		{
			theData = new double[oldOne.theData.length];
			for (int i = 0; i < theData.length; i++)
				theData[i] = oldOne.theData[i];
			inScan = oldOne.inScan;
		}
	}

	// Note that the access methods below are very similar to those
	// in ex12a.java.  However, some important differences exist:
	// 1) The methods are now instance methods (not static as in
	//    ex12a.java)
	// 2) The array is implicit data, so it is not passed in as a
	//    parameter.  Since the array and the method are both part
	//    of the same object, the array can be directly accessed
	//    from within the method.

	public void getData()
	{
		for (int i = 0; i < theData.length; i++)
		{
			System.out.print("Enter number " + i + ": ");
			theData[i] = inScan.nextDouble();
		}
	}

	public void showData()
	{
		System.out.println("Index : Data");
		System.out.println("-----   ----");
		for (int i = 0; i < theData.length; i++)
			System.out.println("  " + i + "   : " + theData[i]);
		System.out.println();
	}

	// Same search as in ex12a.java.  See that handout for comments.
	public int find(double x)
	{
		int i = 0;
		boolean found = false;

		while (i < theData.length && !found)
		{
			double diff = x - theData[i];
			if (Math.abs(diff) < 0.001)
				found = true;
			else
				i++;
		}
		if (found)
			return i;
		else
			return -1;
	}

	// This change is logically equivalent to the change method in ex12a.  It
	// only allows the user to select an index that is valid
	public void change()
	{
		int index;
		do
		{
			System.out.print("Enter index to change: ");
			index = inScan.nextInt();
		} while (index < 0 || index >= theData.length);
		System.out.print("Enter new value: ");
		theData[index] = inScan.nextDouble();
	}

	// In this change, we are now allowing an index >= the length of the
	// array.  In this case, we resize the array to enable it to hold the
	// new item.  Note that the resize method is private and is abstracted
	// out of the user's required knownledge.  Note also that if a new
	// array is allocated, it will separate that array from any Scores
	// objects that it may have previously been sharing with.  See more info 
	// below in the resize method.
	public void change2()
	{
		int index;
		do
		{
			System.out.print("Enter index to change: ");
			index = inScan.nextInt();
		} while (index < 0);
		if (index >= theData.length)
			resize(index+1);
		System.out.print("Enter new value: ");
		theData[index] = inScan.nextDouble();
	}

	// Method to logically resize the Scores array.  Note that we are actually
	// making a new array object and copying the old data into it (because
	// array objects themselves cannot change in size once created).  However,
	// this process is transparent to the user, and the resize method is in
	// fact private.  Thus, the resize is abstracted out and the user of the
	// Scores object does not even know it exists.
	private void resize(int n)
	{
		int min = n;
		if (theData.length < n) min = theData.length;
		double [] temp = new double[n];		// create array of new size
		for (int i = 0; i < min; i++)
		{
			temp[i] = theData[i];			// copy old data into it
		}
		theData = temp;			// set theData reference to new array
	}

	// Note that the sort instance method is simply calling the predefined sort
	// method.  Even though the method here is simple (one line) it is still
	// useful, since it now makes sorting a part of the Scores class rather than
	// keeping it external.
	public void sort()
	{
		Arrays.sort(theData);
	}
}