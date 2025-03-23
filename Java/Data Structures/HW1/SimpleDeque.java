public class SimpleDeque<T> implements DequeInterface<T> {
    private T[] theDeque;
    private int size;

    public SimpleDeque(int initsize) {
        theDeque = (T[]) new Object[initsize];
        size = 0;
    }

    public void addToFront(T element) {
        if (size < theDeque.length) {
            for (int i = size; i > 0; i--) {
                theDeque[i] = theDeque[i - 1];
            }
            theDeque[0] = element;
            size++;
        } else
            System.out.println("No room, " + element.toString() + " not added");
    }

    public void addToBack(T element) {
        if (size < theDeque.length) {
            theDeque[size] = element;
            size++;
        } else
            System.out.println("No room, " + element.toString() + " not added");
    }

    public T removeFront() {
        if (size > 0) {
            T temp = theDeque[0];
            for (int i = 0; i < size - 1; i++) {
                theDeque[i] = theDeque[i + 1];
            }
            theDeque[size - 1] = null;
            size--;
            return temp;
        } else
            return null;
    }

    public T removeBack() {
        if (size > 0) {
            T temp = theDeque[size - 1];
            theDeque[size - 1] = null;
            size--;
            return temp;
        } else
            return null;
    }

    public T getFront() {
        if (size > 0) {
            return theDeque[0];
        } else
            return null;
    }

    public T getBack() {
        if (size > 0) {
            return theDeque[size - 1];
        } else
            return null;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        for (int i = 0; i < size; i++) {
            theDeque[i] = null;
        }
        size = 0;
    }

    public String toString() {
        if (size == 0)
            return "Deque is Empty";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < size; i++)
            sb.append(theDeque[i] + (i!=size-1?", ":""));
        return sb.toString();
    }
}
