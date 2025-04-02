public class IndexAddRemoveDeque<T> extends IndexDeque<T> implements IndexableAddRemove<T> {
    public IndexAddRemoveDeque(int initsize) {
        super(initsize);
    }

    public void addToFront(int i, T item) {
        if (i < 0 || i > size)
            throw new IndexOutOfBoundsException("Illegal access!");
        if (size == theDeque.length - 1)
            resize();
        int targetPosition = front + i >= theDeque.length ? front + i - theDeque.length : front + i;
        back = nxt(back);
        size++;
        for (int j = back; j != targetPosition; j = pre(j))
            theDeque[j] = theDeque[pre(j)];
        theDeque[targetPosition] = item;
    }

    public void addToBack(int i, T item) {
        addToFront(size - i, item);
    }

    public T removeFront(int i) {
        if (i < 0 || i > size - 1)
            throw new IndexOutOfBoundsException("Illegal access!");
        int targetPosition = front + i >= theDeque.length ? front + i - theDeque.length : front + i;
        T theItem = theDeque[targetPosition];
        for (int j = targetPosition; j != back; j = nxt(j))
            theDeque[j] = theDeque[nxt(j)];
        back = pre(back);
        size--;
        if(size==0){front=0;back=-1;}
        return theItem;
    }

    public T removeBack(int i) {
        return removeFront(size - i - 1);
    }
}