// CS 0445 Spring 2023
// Assignment of Recursion

// Read over the partial implementation of the DoubleRecList below.
// Run the main program (Recursion.java) and trace the constructor and
// toString() methods so that you fully understand how the recursion is 
// working.

// Note that even though the Node<T> class is a generic class, the
// DoubleRecList class is not generic -- it is fixed with a Node<String>
// as its data.  Note also that Node<T> is a separate, public class so
// we don't have access to its private data.  Thus, we need to use the
// accessor and mutator methods within the Node<T> class for access.
// See Node<T> for details.

// Add the reverse() method and test it using the same main program
// (after removing the comments)

public class DoubleRecList {
	private Node<String> front; // instance variable for front

	// Non-recursive method to meet the spec of the constructor. Since the
	// recursive method needs more parameters we will call it from this
	// non-recursive "stub".
	public DoubleRecList(String[] data) {
		front = null;
		if (data.length > 0) // if there is some data, call the recursive
			rec_init(data, 0); // method to initialize. The int here is the
								// current position in the data array.
	}

	// Recursive method to initialize the list with data. This will build
	// the list from back to front, putting each new Node at the front of
	// the list. See more comments below.
	private void rec_init(String[] data, int loc) {
		if (loc < data.length - 1) // up to the 2nd last value
		{
			// Recursively initialize the rest of the list
			rec_init(data, loc + 1);

			// Create a node for the new front
			Node<String> temp = new Node<String>(data[loc]);

			// Get back of list
			Node<String> back = front.getPrevNode();

			// Connect new front to the rest of the list and set the
			// front to the new node.
			temp.setPrevNode(back);
			back.setNextNode(temp);
			temp.setNextNode(front);
			front.setPrevNode(temp);
			front = temp;
		} else if (loc == data.length - 1) // last value (or only value)
		{
			// The end Node in the list will also be the first Node created
			// and is thus a special case -- we must link it back to itself
			// for next and previous.
			front = new Node<String>(data[loc]);
			front.setPrevNode(front);
			front.setNextNode(front);
		}
	}

	// Similar to the constructor, we have a non-recursive method to meet
	// the spec of the toString() method. This then calls / returns a
	// recursive method to actually generate the string.
	public String toString() {
		StringBuilder str = new StringBuilder();
		Node<String> curr = front;

		// Since our list is circular we need a way to detect that all Nodes
		// have been processed. We can do this by counting (if we know the
		// size of the list). We can also do this by checking to see when we
		// have circled all the way around the list back to the beginning. For
		// this approach we have a special case to process the front node BEFORE
		// calling the recursive method.
		if (curr != null) {
			str.append(curr.getData()); // Append data from first Node
			str.append(" ");
			return rec_toString(curr.getNextNode(), str); // Recurse to process
			// the rest of the list.
		} else
			return str.toString();
	}

	// Recursive method to convert the list into a String. This is using
	// a StringBuilder. Note that the StringBuilder was created above in the
	// non-recursive method, and then it is passed into the recursive method
	// as an argument.
	private String rec_toString(Node<String> curr, StringBuilder B) {
		// Base case is now getting back to the front node rather than getting
		// to null. Be careful if implementing in this way not to miss the front
		// Node or to count it twice.
		if (curr != front) {
			B.append(curr.getData());
			B.append(" ");
			return rec_toString(curr.getNextNode(), B);
		}
		// When we get back to the front all of the data has been added so just
		// return the String.
		else
			return B.toString();
	}

	// Method to reverse the data in the list.
	// You must implement this method. See comments in the document.
	public void reverse() {
		rec_reverse(front);
	}

	private void rec_reverse(Node<String> curr) {
		if (curr.getNextNode() == front) {
			Node<String> preNode = curr.getPrevNode();
			Node<String> nxtNode = curr.getNextNode();
			curr.setPrevNode(nxtNode);
			curr.setNextNode(preNode);
			front = curr;
			return;
		}
		rec_reverse(curr.getNextNode());
		Node<String> preNode = curr.getPrevNode();
		Node<String> nxtNode = curr.getNextNode();
		curr.setPrevNode(nxtNode);
		curr.setNextNode(preNode);
	}
}
