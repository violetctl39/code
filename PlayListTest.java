/* CMPINF 0401 Summer 2024
 * This example (along with files PlayList.java and Song.java) demonstrates a lot
 * of things, which will be covered as the term progresses.  After we cover
 * a topic in lecture, come back to this handout to see it demonstrated.
 * 1) Creating a new class and determining the correct instance variables
 *    and methods
 * 2) Using the process of COMPOSITION to build a new class using data that
 *    is previously defined in one or more other classes
 * 3) Using arrays of objects to store multiple values in a single variable
 * 4) Using a text file for input data
 * 5) Using the wrapper class method Integer.parseInt to convert from a String
 *    to an int
 * 6) Returning a reference to an instance variable vs. returning a copy of the
 *    data stored.
*/
import java.util.*;
import java.io.*;
public class PlayListTest
{
	public static void main (String [] args) throws IOException
	{
		// See songs.txt file for input format
		Scanner fScan = new Scanner(new File("song.txt"));
		// First get number of PlayLists in the file, and make the PlayList array
		// of the proper size.
		int numAlbums = Integer.parseInt(fScan.nextLine());
		PlayList [] myPlayLists = new PlayList[numAlbums];
		// Now read in the PlayLists themselves.  For each PlayList we read in the title,
		// release date and all of the songs from a file, then create the PlayList
		// object and add it to the array.
		for (int i = 0; i < myPlayLists.length; i++)
		{
			String aTitle = fScan.nextLine();
			String rDate = fScan.nextLine();
			int numSongs = Integer.parseInt(fScan.nextLine());
			Song [] theSongs = new Song[numSongs];
			for (int j = 0; j < theSongs.length; j++)
			{
				// Read the song information in as a single string, then
				// split it into its 4 parts and create the new Song.  Then
				// add the song to the array for the current PlayList.
				String songString = fScan.nextLine();
				String [] songInfo = songString.split(",");
				Song currSong = new Song(songInfo[0], songInfo[1], songInfo[2],
					songInfo[3]);
				theSongs[j] = currSong;
			}
			PlayList thePlayList = new PlayList(aTitle, rDate, theSongs);
			myPlayLists[i] = thePlayList;
		}

		System.out.println("Here are your PlayLists:");
		for (int i = 0; i < myPlayLists.length; i++)
			System.out.println(myPlayLists[i].toString());
		System.out.println("\nNow Sorting the PlayLists");
		Arrays.sort(myPlayLists);
		System.out.println("\n");
		System.out.println("Here are your PlayLists:");
		for (int i = 0; i < myPlayLists.length; i++)
			System.out.println(myPlayLists[i].toString());

		if (myPlayLists[0].compareTo(myPlayLists[1]) > 0)

			System.out.println(myPlayLists[0] + "\n is > \n\n" + myPlayLists[1]);
		else
			System.out.println(myPlayLists[0] + "\n is not > \n\n" + myPlayLists[1]);
		
		// Now we will allow the user to enter a new song in a single playlist.  Think
		// about how you could modify this to allow more complex / interesting updates 
		// (such as allowing the user to select the playlist and allowing the user to
		// add as many songs as he / she wants to add.  You may also want to do some
		// error checking on the user's input.
		Scanner inScan = new Scanner(System.in);
		PlayList current = myPlayLists[0];
		System.out.println("Here is your current playlist:\n" + current);
		System.out.println("Would you like to add a new Song? (y/n)");
		String ans = inScan.nextLine();
		if (ans.toLowerCase().equals("y"))
		{
			System.out.print("Title: "); 
			String sTitle = inScan.nextLine();
			System.out.print("Length: (mm:ss) ");
			String sLength = inScan.nextLine();
			System.out.print("Artist: ");
			String sArtist = inScan.nextLine();
			System.out.print("Genre: ");
			String sGenre = inScan.nextLine();
			Song newSong = new Song(sTitle, sLength, sArtist, sGenre);
			current.addSong(newSong);
		}
		System.out.println("Here is your current playlist:\n" + current);
	}
}