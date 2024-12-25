package leture17;
// CMPINF 0401 Summer 2024
// Demonstration of "generic" operations in Java
// We are sorting various different Comparable objects using the same
// sort method.

// NOTE: Originally Java allowed generic operations via interfaces and
// superclass access.  However, with JDK 1.5 they refined this by
// introducing parameterized classes and interfaces. These allow for more
// compile-time type checking.  

// This handout demonstrates generics in the "old" way.  To show how it
// "should" be done now, I have provided an alternate version.  See the 
// same class names with the letter T behind them: ex21T.java, SortAllT.java.

import java.io.*;
import java.util.*;
public class ex21
{
	// This method is another (simple) example of a generic method.
	// I am using it here to display all of my arrays, since it
	// relies only on the toString() method, which is defined in
	// class Object and overridden by most other classes (including
	// those used in this example)
	public static void showData(Object [] Ar, int perLine)
	{
		System.out.println("The data is: ");
		for (int i = 0; i < Ar.length-1; i++)
		{
			System.out.print(Ar[i] + ", ");
			if ((i+1) % perLine == 0)
				System.out.println();
		}
		if (Ar.length > 0)
			System.out.println(Ar[Ar.length-1]);
		System.out.println();
	}

	public static void main(String [] args)
	{
		String [] S = {	"Talking Heads", "Midnight Oil", "Beatles", 
						"Metallica", "U2", "Tori Amos", "Sarah McLachlan",
						"NIN", "Cranberries", "Garbage"};
		Integer [] A = new Integer[23];
		for (int i = 0; i < A.length; i++)
			A[i] = Integer.valueOf((i * 11)%(A.length));
		
		showData(S, 5); System.out.println();
		showData(A, 12); System.out.println();

		// Calling the selectionSort method in the SortAll class.
		SortAll.selectionSort(S);
		SortAll.selectionSort(A);

		showData(S, 5); System.out.println();
		showData(A, 12); System.out.println();

		// Below is code coped from the PlayListTest handout.  Now I am using
		// the compareTo method that I told you not to worry about when
		// we first discussed the PlayList class.  Note also that had I so chosen, 
		// I could have defined compareTo in the PlayList class to compare by any 
		// of the fields in the class.  Here it is just comparing by the title.
		
		// One other change I have made is the try / catch block below.
		// Creating the Scanner on a File can cause IOException, which must
		// be explicitly handled in the program.  In the PlayListTest program, I
		// added the line "throws IOException" to the main method, which is
		// basically handling the exception by saying that we are not handling
		// it.  Below, I am still not really handling it, since the body of
		// the "catch" block is empty.  We will briefly talk about exceptions
		// later, and there we will see some real handlers.
	
		Scanner fScan = null;
		try
		{
			fScan = new Scanner(new File("songs.txt"));
		}
		catch (IOException e)
		{}
		
		int numAlbums = Integer.parseInt(fScan.nextLine()); 
		PlayList [] myPlayLists = new PlayList[numAlbums];
		for (int i = 0; i < myPlayLists.length; i++)
		{
			String aTitle = fScan.nextLine();
			String rDate = fScan.nextLine();
			int numSongs = Integer.parseInt(fScan.nextLine());
			Song [] theSongs = new Song[numSongs];
			for (int j = 0; j < theSongs.length; j++)
			{
				String songString = fScan.nextLine();
				String [] songInfo = songString.split(",");
				Song currSong = new Song(songInfo[0], songInfo[1], songInfo[2],
					songInfo[3]);
				theSongs[j] = currSong;
			}
			PlayList thePlayList = new PlayList(aTitle, rDate, theSongs);
			myPlayLists[i] = thePlayList;
		}

		showData(myPlayLists, 1);
	    System.out.println();
		SortAll.selectionSort(myPlayLists);
		showData(myPlayLists, 1);

		// The code below will cause a run-time error.  Even though the
		// Comparable interface allows us to use the same sorting method with
		// different data types, if we try to mix types in a single array, we
		// will likely run into problems.  In the case below, the compareTo
		// method causes an exception since it is not defined for mixed types.
		// However, it COULD work on mixed types if they are all within the
		// same inheritance chain and the compareTo method is defined for the
		// superclass type.
		/*
		Comparable [] A2 = new Comparable[4];
		A2[0] = new String("Wacky");
		A2[1] = new Integer(40);
		A2[2] = new Float(55.5);
		A2[3] = myPlayLists[0];
		SortAll.selectionSort(A2);
		*/
	}
}
