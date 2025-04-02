@SuppressWarnings("unchecked")
public class MyDeque<T> implements DequeInterface<T> {
    protected T[] theDeque;
    protected int size, front, back;

    public MyDeque(int initsize) {
        theDeque = (T[]) new Object[initsize];
        size = 0;
        front = 0;
        back = -1;
    }

    public MyDeque(MyDeque<T> old) {
        theDeque = old.theDeque.clone();
        size = old.size;
        front = old.front;
        back = old.back;
    }

    protected int nxt(int i) {
        return i == theDeque.length - 1 ? 0 : i + 1;
    }

    protected int pre(int i) {
        return i == 0 ? theDeque.length - 1 : i - 1;
    }

    protected void resize() {
        T[] newDeque = (T[]) new Object[theDeque.length * 2];
        for (int i = front, j = 0;; i = nxt(i), ++j) {
            newDeque[j] = theDeque[i];
            if (i == back)
                break;
        }
        front = 0;
        back = size - 1;
        theDeque = newDeque;
    }

    public void addToFront(T newEntry) {
        if (size == theDeque.length - 1)
            resize();
        front = pre(front);
        size++;
        theDeque[front] = newEntry;
        if (back == -1)
            back = front;
    }

    public void addToBack(T newEntry) {
        if (size == theDeque.length - 1)
            resize();
        back = back == -1 ? 0 : nxt(back);
        size++;
        theDeque[back] = newEntry;

    }

    public T removeFront() {
        if (size == 0)
            return null;
        if (size == 1) {
            T theFront = theDeque[front];
            size = 0;
            front = 0;
            back = -1;
            return theFront;
        }
        T theFront = theDeque[front];
        front = nxt(front);
        size--;
        return theFront;
    }

    public T removeBack() {
        if (size == 0)
            return null;
        if (size == 1) {
            T theBack = theDeque[back];
            size = 0;
            front = 0;
            back = -1;
            return theBack;
        }
        T theBack = theDeque[back];
        back = pre(back);
        size--;
        return theBack;
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

    public boolean equals(MyDeque<T> rhs) {
        if (size != rhs.size)
            return false;
        int lpos = front, rpos = rhs.front;
        for (int i = 0; i < size; ++i) {
            if (theDeque[lpos] != rhs.theDeque[rpos])
                return false;
            lpos = nxt(lpos);
            rpos = nxt(rpos);
        }
        return true;
    }

    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append("Contents: ");
        if (size == 0)
            return s.toString();
        for (int i = front;; i = nxt(i)) {
            s.append(theDeque[i] + " ");
            if (i == back)
                break;
        }
        return s.toString();
    }
}