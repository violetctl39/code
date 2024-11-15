
// CMPINF 0401 Summer 2024
// Simple class to represent a music playlist.
// The class here is fairly simple -- containing only a few methods as shown
// below. As an exercise you may want to add some additional constructors, 
// accessors and mutators to add some more functionality to the class.
// See PlayListTest.java for a simple test program. If you add to this class you
// can also add to PlayListTest.java to demonstrate the new features.
import java.util.*; // needed for Date
import java.text.*; // needed for DateFormat

public class PlayList implements Comparable<PlayList> // See more info below
{
    // Note that the primary instance variable within the PlayList class
    // is an ArrayList of Song, which is a different class (see Song.java).
    // The process of using a variable of one class as instance data in
    // another class is COMPOSITION. The idea is that we are using pre-existing
    // classes to compose a new class. The functionality of the new class is
    // at least partially based on the functionality of the classes used to build
    // it.
    private String title;
    private ArrayList<Song> songList;
    private Date releaseDate; // We are storing the release date as a
    // Date object. This will allow us to manipulate it
    // as a Date if we so choose. Note that this could be
    // stored in various ways. This also demonstrates the idea
    // of composition.
    private int tracks; // how many tracks in the PlayList?
    private int length; // in seconds

    public PlayList(String t, String d, Song[] songs) {
        title = new String(t);
        // Code below is used to convert a String representation of a
        // date (ex: 10/21/2004) into a Date object. Don't worry too
        // much about the details at this point (i.e. the
        // DateFormat class and the try - catch block). We may cover
        // these later.
        DateFormat df = DateFormat.getDateInstance(DateFormat.SHORT);
        try {
            // example: d=2024-01-01
            releaseDate = df.parse(d);
        } catch (ParseException e) {
            releaseDate = null;
        }
        tracks = songs.length;
        // Note that the number of tracks is equal to the length of the songs
        // parameter array. If we add any Songs to our PlayList we must also
        // update the tracks value.
        length = 0;
        // Make an ArrayList for the songs, then copy the songs from the parameter
        // into it. Use getLength() method from each Song to get track lengths
        // in seconds.
        songList = new ArrayList<Song>();
        for (int i = 0; i < songs.length; i++) {
            songList.add(songs[i]);
            length += songs[i].getLength();
        }
    }

    public PlayList() {
    }

    public String toString() {
        // to do
        StringBuilder S = new StringBuilder();
        S.append("Title: " + title + "\n");
        S.append("ReleaseDate: " + releaseDate.toString() + "\n");
        S.append("Track: " + tracks + "\n");
        S.append("Length: " + length + "\n");
        for (Song x : songList)
            S.append(x.toString() + "\n");
        return S.toString();
    }

    // This mutator method will add a new Song to the end of the PlayList. If the
    // Song is already present it will report an error to the user and not add it.
    public void addSong(Song newSong) {
        // to do
        for (Song x : songList)
            if (x.equals(newSong)) {
                System.out.println("The song has already been added to the playlist.");
                return;
            }
        songList.add(newSong);
        tracks++;
        length += newSong.getLength();
    }

    // This accessor method will return an array of the Songs in the PlayList.
    public Song[] getSongs() {
        // to do
        return songList.toArray(new Song[tracks]);
    }

    // We will discuss this method later in the term
    public ArrayList<Song> getSongs2() {
        return songList;
    }

    // This method allows us to compare PlayLists in a regular way. See how it is
    // used in this example. We will discuss it more formally later.
    public int compareTo(PlayList rhs) {
        return (length - rhs.length);
        // return (this.title.compareTo(rhs.title));
    }
}