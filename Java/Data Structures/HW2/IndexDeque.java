public class IndexDeque<T> extends MyDeque<T> implements Indexable<T> {
    public IndexDeque(int initsize) {
        super(initsize);
    }

    public T getFront(int i) {
        if (i < 0 || i >= size)
            throw new IndexOutOfBoundsException("Illegal Index " + i);
        return front + i < theDeque.length ? theDeque[front + i] : theDeque[i - theDeque.length + front];
    }

    public T getBack(int i) {
        if (i < 0 || i >= size)
            throw new IndexOutOfBoundsException("Illegal Index " + i);
        return back - i >= 0 ? theDeque[back - i] : theDeque[theDeque.length - i + back];
    }

    public void setFront(int i, T item) {
        if (i < 0 || i >= size)
            throw new IndexOutOfBoundsException("Illegal Index " + i);
        int position = front + i < theDeque.length ? front + i : i - theDeque.length + front;
        theDeque[position] = item;
    }

    public void setBack(int i, T item) {
        if (i < 0 || i >= size)
            throw new IndexOutOfBoundsException("Illegal Index " + i);
        int position = back - i >= 0 ? back - i : theDeque.length - i + back;
        theDeque[position] = item;
    }

    public int size() {
        return size;
    }
}