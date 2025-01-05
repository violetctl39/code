
// Book.java
// import java.util.Arrays;

class Book implements Comparable<Book> {
    private int ID;
    private String title;
    private String author;
    private int year;

    public Book(int ID, String title, String author, int year) {
        this.ID = ID;
        this.title = title;
        this.author = author;
        this.year = year;
    }

    @Override
    public int compareTo(Book other) {
        // int yearComparison = Integer.compare(this.year, other.year);
        int IDComparison = Integer.compare(this.ID, other.ID);
        return IDComparison;

    }

    @Override
    public String toString() {
        return "Book [title=" + title + ", author=" + author + ", year=" + year +
                "]";
    }
}

