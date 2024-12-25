class SortBooks {
    public static void main(String[] args) {
        Book[] books = {
                new Book(1, "The Great Gatsby", "F. Scott Fitzgerald", 1925),
                new Book(2, "1984", "George Orwell", 1949),
                new Book(3, "To Kill a Mockingbird", "Harper Lee", 1960),
                new Book(4, "Animal Farm", "George Orwell", 1945)
        };
        SortAll.selectionSort(books);
        // Arrays.sort(books);
        for (Book book : books) {
            System.out.println(book);
        }
    }
}