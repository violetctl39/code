/**
 * LinkedBag.java
 * A class of bags whose entries are stored in a chain of linked nodes.
 * The bag is never full.
 * 
 * @author Frank M. Carrano
 * @author Timothy M. Henry
 * @version 4.0
 */
public final class LinkedBag<T> implements BagInterface<T> {
    private Node firstNode;
    private int numberOfEntries;

    public LinkedBag() {
        firstNode = null;
        numberOfEntries = 0;
    }

    /**
     * Tests whether this bag is empty.
     * 
     * @return True if this bag is empty, or false if not.
     */
    public boolean isEmpty() {
        return numberOfEntries == 0;
    }

    /**
     * Gets the capacity of this bag.
     * 
     * @return The integer number of entries that this bag can hold.
     */
    public int getCapacity() {
        return Integer.MAX_VALUE;
    }

    /**
     * Gets the number of entries currently in this bag.
     * 
     * @return The integer number of entries currently in this bag.
     */
    public int getCurrentSize() {
        return numberOfEntries;
    }

    /**
     * Adds a new entry to this bag.
     * 
     * @param newEntry The object to be added as a new entry
     * @return true if the addition is successful, or false if not.
     */
    public boolean add(T newEntry) // OutOfMemoryError possible
    {
        // Add to beginning of chain:
        Node newNode = new Node(newEntry);
        newNode.next = firstNode; // Make new node reference rest of chain
        // (firstNode is null if chain is empty)
        firstNode = newNode; // New node is at beginning of chain
        numberOfEntries++;
        return true;
    }

    /**
     * Retrieves all entries that are in this bag.
     * 
     * @return A newly allocated array of all the entries in this bag.
     */
    public T[] toArray() {
        // The cast is safe because the new array contains null entries
        @SuppressWarnings("unchecked")
        T[] result = (T[]) new Object[numberOfEntries]; // Unchecked cast
        int index = 0;
        Node currentNode = firstNode;
        while ((index < numberOfEntries) && (currentNode != null)) {
            result[index] = currentNode.data;
            index++;
            currentNode = currentNode.next;
        }
        return result;
    }

    /**
     * Counts the number of times a given entry appears in this bag.
     * 
     * @param anEntry The entry to be counted.
     * @return The number of times anEntry appears in this bag.
     */
    public int getFrequencyOf(T anEntry) {
        int frequency = 0;
        int counter = 0;
        Node currentNode = firstNode;
        while ((counter < numberOfEntries) && (currentNode != null)) {
            if (anEntry.equals(currentNode.data)) {
                frequency++;
            }
            counter++;
            currentNode = currentNode.next;
        }
        return frequency;
    }

    /**
     * Tests whether this bag contains a given entry.
     * 
     * @param anEntry The entry to locate.
     * @return true if the bag contains anEntry, or false otherwise.
     */
    public boolean contains(T anEntry) {
        boolean found = false;
        Node currentNode = firstNode;
        while (!found && (currentNode != null)) {
            if (anEntry.equals(currentNode.data)) {
                found = true;
            } else {
                currentNode = currentNode.next;
            }
        }
        return found;
    }

    // Locates a given entry within this bag.
    // Returns a reference to the node containing the entry, if located,
    // or null otherwise.
    private Node getReferenceTo(T anEntry) {
        boolean found = false;
        Node currentNode = firstNode;
        while (!found && (currentNode != null)) {
            if (anEntry.equals(currentNode.data)) {
                found = true;
            } else {
                currentNode = currentNode.next;
            }
        }
        return currentNode;
    }

    /**
     * Removes all entries from this bag.
     */
    public void clear() {
        while (!isEmpty()) {
            remove();
        }
    }

    /**
     * Removes one unspecified entry from this bag, if possible.
     * 
     * @return Either the removed entry, if removal was successful, or null.
     */
    public T remove() {
        T result = null;
        if (firstNode != null) {
            result = firstNode.data;
            firstNode = firstNode.next; // Remove first node from chain
            numberOfEntries--;
        }
        return result;
    }

    /**
     * Removes one occurrence of a given entry from this bag, if possible.
     * 
     * @param anEntry The entry to be removed.
     * @return true if the removal was successful, or false otherwise.
     */
    public boolean remove(T anEntry) {
        boolean result = false;
        Node nodeN = getReferenceTo(anEntry);
        if (nodeN != null) {
            // Replace located entry with entry in first node
            // then remove first node and adjust numberOfEntries.
            nodeN.data = firstNode.data;
            firstNode = firstNode.next;
            numberOfEntries--;
            result = true;
        }
        return result;
    }

    private class Node {
        private T data; // Entry in bag
        private Node next; // Link to next Node

        public Node(T dataPortion) {
            this(dataPortion, null);
        }

        public Node(
                T dataPortion,
                Node nextNode) {
            data = dataPortion;
            next = nextNode;
        }

        public Node clone() {
            Node newNode = new Node(this.data, this.next);
            return newNode;
        }
    }

    public LinkedBag<T> clone() {
        LinkedBag<T> newLinkedBag = new LinkedBag<T>();
        newLinkedBag.firstNode = this.firstNode.clone();
        newLinkedBag.numberOfEntries = this.numberOfEntries;
        Node currentNode = newLinkedBag.firstNode;
        while (currentNode != null) {
            if (currentNode.next != null)
                currentNode.next = currentNode.next.clone();
            currentNode = currentNode.next;
        }
        return newLinkedBag;
    }

    public BagInterface<T> union(BagInterface<T> anotherBag) {
        LinkedBag<T> results = this.clone();
        Node currentNode = ((LinkedBag<T>) anotherBag).firstNode;
        while (currentNode != null) {
            results.add(currentNode.data);
            currentNode = currentNode.next;
        }
        return results;
    }

    public BagInterface<T> intersection(BagInterface<T> anotherBag) {
        LinkedBag<T> results = new LinkedBag<T>();
        LinkedBag<T> copyOfAnotherBag = ((LinkedBag<T>) anotherBag).clone();
        Node currentNode = this.firstNode;
        while (currentNode != null) {
            Node anotherCurrentNode = copyOfAnotherBag.firstNode;
            while (anotherCurrentNode != null) {
                if (anotherCurrentNode.data != null && currentNode.data.equals(anotherCurrentNode.data)) {
                    results.add(currentNode.data);
                    anotherCurrentNode.data = null;
                }
                anotherCurrentNode = anotherCurrentNode.next;
            }
            currentNode = currentNode.next;
        }
        return results;
    }

    public BagInterface<T> difference(BagInterface<T> anotherBag) {
        LinkedBag<T> results = new LinkedBag<T>();
        LinkedBag<T> copyOfAnotherBag = ((LinkedBag<T>) anotherBag).clone();
        Node currentNode = this.firstNode;
        while (currentNode != null) {
            Node anotherCurrentNode = copyOfAnotherBag.firstNode;
            boolean exist = false;
            while (anotherCurrentNode != null) {
                if (anotherCurrentNode.data != null && currentNode.data.equals(anotherCurrentNode.data)) {
                    anotherCurrentNode.data = null;
                    exist = true;
                    break;
                }
                anotherCurrentNode = anotherCurrentNode.next;
            }
            if (!exist)
                results.add(currentNode.data);
            currentNode = currentNode.next;
        }
        return results;
    }
}
