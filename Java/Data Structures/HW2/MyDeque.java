public class MyDeque<T> implements DequeInterface<T> {
    protected T[] theDeque;
    protected int size, front, back;

    @SuppressWarnings("unchecked")
    public MyDeque(int initsize) {
        theDeque = (T[]) new Object[initsize];
        size = 0;
        front = 0;
        back = -1;
    }

    public void addToFront(T newEntry) {
        if (size == theDeque.length)
            return;
        if (front == 0)
            front = theDeque.length - 1;
        else
            front--;
        size++;
        theDeque[front] = newEntry;
        if (back == -1)
            back = front;
    }

    public void addToBack(T newEntry) {
        if (size == theDeque.length)
            return;
        if (back == theDeque.length - 1)
            back = 0;
        else
            back++;
        size++;
        theDeque[back] = newEntry;

    }

    public T removeFront() {
        if (size == 0)
            return null;
        if (size == 1) {
            T temp = theDeque[front];
            front = 0;
            back = -1;
            return temp;
        }
        if (front == theDeque.length - 1) {
            front = 0;
            size--;
            return theDeque[theDeque.length - 1];
        }
        front++;
        size--;
        return theDeque[front - 1];
    }

    public T removeBack() {
        if (size == 0)
            return null;
        if (size == 1) {
            T temp = theDeque[back];
            front = 0;
            back = -1;
            return temp;
        }
        if (back == 0) {
            back = theDeque.length - 1;
            size--;
            return theDeque[0];
        }
        back--;
        size--;
        return theDeque[back + 1];
    }

    public T getFront() {
        if (size == 0)
            return null;
        return theDeque[front];
    }

    public T getBack() {
        if (size == 0)
            return null;
        return theDeque[back];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        size = 0;
        front = 0;
        back = -1;
    }

    public int size() {
        return size;
    }

    public int capacity() {
        return theDeque.length;
    }
}
