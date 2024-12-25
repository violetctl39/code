package leture17;
// CMPINF 0401 Summer 2024
// Simple class to represent a music playlist.

// The class here is fairly simple -- containing only a few methods as shown
// below.  As an exercise you may want to add some additional constructors, 
// accessors and mutators to add some more functionality to the class.

// See PlayListTest.java for a simple test program.  If you add to this class you
// can also add to PlayListTest.java to demonstrate the new features.

import java.util.*;  // needed for Date
import java.text.*;  // needed for DateFormat
public class PlayList implements Comparable<PlayList> // See more info below
{
	// Note that the primary instance variable within the PlayList class
	// is an ArrayList of Song, which is a different class (see Song.java).  
	// The process of using a variable of one class as instance data in
	// another class is COMPOSITION.  The idea is that we are using pre-existing
	// classes to compose a new class.  The functionality of the new class is
	// at least partially based on the functionality of the classes used to build
	// it.
	private String title;
	private ArrayList<Song> songList;
	private Date releaseDate;  // We are storing the release date as a
	             // Date object.  This will allow us to manipulate it
	             // as a Date if we so choose.  Note that this could be
	             // stored in various ways.  This also demonstrates the idea
	             // of composition.
	private int tracks;  // how many tracks in the PlayList?
	private int length;  // in seconds
	
	public PlayList(String t, String d, Song [] songs)
	{
		title = new String(t);

		// Code below is used to convert a String representation of a
		// date (ex: 2004/10/21) into a Date object.  Don't worry too
		// much about the details at this point (i.e. the
		// DateFormat class and the try - catch block).  We may cover
		// these later.
		DateFormat df = DateFormat.getDateInstance(DateFormat.SHORT);
		try
		{
			releaseDate = df.parse(d);
		}
		catch (ParseException e)
		{
			releaseDate = null;
		}
		tracks = songs.length;
		// Note that the number of tracks is equal to the length of the songs
		// parameter array.  If we add any Songs to our PlayList we must also
		// update the tracks value.
		
		length = 0;
		// Make an ArrayList for the songs, then copy the songs from the parameter
		// into it.  Use getLength() method from each Song to get track lengths
		// in seconds.
		
		songList = new ArrayList<Song>();
		
		
		for (int i = 0; i < songs.length; i++)
		{
			songList.add(songs[i]);
			length += songs[i].getLength();
		}
	}

	public PlayList()
	{
	}

	public String toString()
	{
		// Note how the resulting String is created here:  We append many
		// values to a StringBuilder and then output the StringBuilder as a
		// String.  If the object were simpler we could probably avoid
		// using the StringBuilder.
		StringBuilder S = new StringBuilder();
		S.append("PlayList: " + title + "\n");

		// As we discussed in lecture, it is good to set reference
		// variables to null if they are not referring to a valid object.
		// That way we can still test the reference.
		if (releaseDate != null)
		{
			S.append("Release Date: " + releaseDate.toString() + "\n");
		}
		else
		{
			S.append("No release date \n");
		}

		// Even though the length is stored as a single integer, users don't
		// typically want to see it represented that way.  Thus, we instead
		// show it as minutes and seconds.
		int min = length / 60;
		int sec = length % 60;
		S.append("Number of tracks: " + tracks + "\n");
		S.append("Length: " + min + " min. " + sec + " sec. \n");
		S.append("Songs: \n");
		// Note here that the toString() for a PlayList includes a call to toString()
		// for each Song in the PlayList.  Even though the method name is the same,
		// the methods are different, since they are called from different
		// objects.
		for (int i = 0; i < songList.size(); i++)
			S.append(songList.get(i).toString() + "\n");
			
		return S.toString();  // return the String to use as we wish.  Note that
			// toString() is NOT printing out the String.  Rather it is just
			// returning it to the coller.
	}
	
	// This mutator method will add a new Song to the end of the PlayList.  If the
	// Song is already present it will report an error to the user and not add it.
	public void addSong(Song newSong)
	{
		if (songList.contains(newSong))
			System.out.println("Song:\n\t" + newSong + "\nis already in the list -- not added\n");
		else
		{
			System.out.println("Song:\n\t" + newSong + "\nis added to the list\n");
			songList.add(newSong);  // add Song to ArrayList
			tracks++;				// update tracks
			length += newSong.getLength();  // update length
		}
	}
	
	// This accessor method will return an array of the Songs in the PlayList.
	public Song [] getSongs()
	{
		Song [] newList = new Song[songList.size()];
		for (int i = 0; i < newList.length; i++)
			  newList[i] = songList.get(i);
		return newList;	
	}
	
	// We will discuss this method later in the term
	public ArrayList<Song> getSongs2()
	{
		return songList;
	}
	
	// This method allows us to compare PlayLists in a regular way.  See how it is
	// used in this example.  We will discuss it more formally later.
	public int compareTo(PlayList rhs)
	{
		return (length - rhs.length);
		//return (this.title.compareTo(rhs.title));
	}
}