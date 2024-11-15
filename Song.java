//CMPINF 0401 Summer 2024
//Simple class to represent a Song.  Note that this class could be much more
//complex if we wanted it to be.  We will talk about the Comparable interface
//later.
public class Song implements Comparable<Song>
{
	private String title;
	private String length;
	private String artist;
	private String genre;

	public Song(String t, String l, String a, String g)
	{
		title = new String(t);
		artist = new String(a);
		length = new String(l);
		genre = new String(g);
	}

	public String toString()
	{
		StringBuilder S = new StringBuilder();
		S.append("Title: " + title + "   ");
		S.append("Length: " + length + "   ");
		S.append("Artist: " + artist + "   ");
		S.append("Genre: " + genre);
		return S.toString();
	}

	// Convert length to an int and return it.  It is assumed that the String that
	// is the length is formatted: M:S where M and S are both integers.  For more
	// info on the split() method, see the Java API.
	public int getLength()
	{
		String [] MinSec = length.split(":");
		int sec = Integer.parseInt(MinSec[1]);
		sec += (60 * Integer.parseInt(MinSec[0]));
		return sec;
	}

	// Compare 2 songs using their titles
	public int compareTo(Song rhs)
	{
		return (this.title.compareTo(rhs.title));
	}
	
	// Two songs are equal if their titles match.  This method is defined
	// to match the spec of equals() in class Object.  It is thus overriding
	// the equals method in Object.  We will discuss method overriding later
	// in the term.
	public boolean equals(Object rhs)
	{
		Song rSide = (Song) rhs;
		return (this.title.equals(rSide.title));
	}
}
