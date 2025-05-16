// CS 0445 Spring 2025
// Read this class and its comments very carefully to make sure you implement
// the class properly.  Note the items that are required and that cannot be
// altered!  Generally speaking you will implement your MyStringBuilder using
// a circular, doubly linked list of nodes.  See more comments below on the
// specific requirements for the class.

// You should use this class as the starting point for your implementation. 
// Note that all of the methods are listed -- you need to fill in the method
// bodies.  Note that you may want to add one or more private methods to help
// with your implementation -- that is fine.

// For more details on the general functionality of most of these methods, 
// see the specifications of the similar method in the StringBuilder class.  
public class MyStringBuilder {
	// These are the only two instance variables you are allowed to have.
	// See details of CNode class below. In other words, you MAY NOT add
	// any additional instance variables to this class. However, you may
	// use any method variables that you need within individual methods.
	// But remember that you may NOT use any variables of any other
	// linked list class or of the predefined StringBuilder or
	// StringBuffer class in any place in your code. You may only use the
	// String class where it is an argument or return type in a method.
	private CNode firstC; // reference to front of list. This reference is necessary
							// to keep track of the list
	private int length; // number of characters in the list

	// You may also add any additional private methods that you need to
	// help with your implementation of the public methods.

	// Create a new MyStringBuilder initialized with the chars in String s
	// Note: This method is implemented for you. See code below. Also read
	// the comments. The code here may be helpful for some of your other
	// methods.
	public MyStringBuilder(String s) {
		if (s == null || s.length() == 0) // special case for empty String
		{
			firstC = null;
			length = 0;
		} else {
			firstC = new CNode(s.charAt(0)); // create first node
			length = 1;
			CNode currNode = firstC;
			// Iterate through remainder of the String, creating a new
			// node at the end of the list for each character. Note
			// how the nodes are being linked and the current reference
			// being moved down the list.
			for (int i = 1; i < s.length(); i++) {
				CNode newNode = new CNode(s.charAt(i)); // create Node
				currNode.next = newNode; // link new node after current
				newNode.prev = currNode; // line current before new node
				currNode = newNode; // move down the list
				length++;
			}
			// After all nodes are created, connect end back to front to make
			// list circular
			currNode.next = firstC;
			firstC.prev = currNode;
		}
	}

	// Return the entire contents of the current MyStringBuilder as a String
	// For this method you should do the following:
	// 1) Create a character array of the appropriate length
	// 2) Fill the array with the proper characters from your MyStringBuilder
	// 3) Return a new String using the array as an argument, or
	// return new String(charArray);
	// Note: This method is implemented for you. See code below.
	public String toString() {
		char[] c = new char[length];
		int i = 0;
		CNode currNode = firstC;

		// Since list is circular, we cannot look for null in our loop.
		// Instead we count within our while loop to access each node.
		// Note that in this code we don't even access the prev references
		// since we are simply moving from front to back in the list.
		while (i < length) {
			c[i] = currNode.data;
			i++;
			currNode = currNode.next;
		}
		return new String(c);
	}

	// Create a new MyStringBuilder initialized with the chars in array s.
	// You may NOT create a String from the parameter and call the first
	// constructor above. Rather, you must build your MyStringBuilder by
	// accessing the characters in the char array directly. However, you
	// can approach this in a way similar to the other constructor.
	public MyStringBuilder(char[] s) {
		if (s == null || s.length == 0) {
			firstC = null;
			length = 0;
		} else {
			firstC = new CNode(s[0]);
			length = 1;
			CNode currNode = firstC;
			for (int i = 1; i < s.length; i++) {
				CNode newNode = new CNode(s[i]);
				currNode.next = newNode;
				newNode.prev = currNode;
				currNode = newNode;
				length++;
			}
			currNode.next = firstC;
			firstC.prev = currNode;
		}
	}

	// Copy constructor -- make a new MyStringBuilder from an old one. Be sure
	// that you make new nodes for the copy (traversing the nodes in the original
	// MyStringBuilder as you do)
	public MyStringBuilder(MyStringBuilder old) {
		if (old == null || old.length == 0) {
			firstC = null;
			length = 0;
		} else if (old.length == 1) {
			firstC = new CNode(old.firstC.data, firstC, firstC);
			length = 1;
		} else {
			firstC = new CNode(old.firstC.data, old.firstC.next, old.firstC.prev);
			length = old.length;
			CNode currNode = firstC;
			for (int i = 1; i < length; ++i) {
				CNode newNode = new CNode(currNode.next.data, currNode.next.next, currNode);
				currNode.next = newNode;
				currNode = newNode;
			}
			currNode.next = firstC;
			firstC.prev = currNode;
		}
	}

	// Create a new empty MyStringBuilder
	public MyStringBuilder() {
		firstC = null;
		length = 0;
	}

	// Append MyStringBuilder b to the end of the current MyStringBuilder, and
	// return the current MyStringBuilder. Be careful for special cases! Note
	// that you cannot simply link the two MyStringBuilders together -- that is
	// very simple but it will intermingle the two objects, which you do not want.
	// Thus, you should copy the data in argument b to the end of the current
	// MyStringBuilder.
	public MyStringBuilder append(MyStringBuilder b) {
		if (b == null || b.length == 0)
			return this;
		CNode currNode = firstC.prev, newNode;
		if (length == 0) {
			newNode = new CNode(b.firstC.data, b.firstC.next, b.firstC.prev);
			firstC = newNode;
		} else {
			newNode = new CNode(b.firstC.data, b.firstC.next, currNode);
			currNode.next = newNode;
		}
		currNode = newNode;
		length += b.length;
		for (int i = 1; i < b.length; ++i) {
			newNode = new CNode(currNode.next.data, currNode.next.next, currNode);
			currNode.next = newNode;
			currNode = newNode;
		}
		currNode.next = firstC;
		firstC.prev = currNode;
		return this;
	}

	// Append String s to the end of the current MyStringBuilder, and return
	// the current MyStringBuilder. Be careful for special cases!
	public MyStringBuilder append(String s) {
		if (s == null || s.length() == 0)
			return this;
		CNode currNode;
		CNode newNode = new CNode(s.charAt(0));
		if (length == 0)
			firstC = newNode;
		else {
			currNode = this.firstC.prev;
			currNode.next = newNode;
			newNode.prev = currNode;
		}
		currNode = newNode;
		length += s.length();
		for (int i = 1; i < s.length(); ++i) {
			newNode = new CNode(s.charAt(i));
			newNode.prev = currNode;
			currNode.next = newNode;
			currNode = newNode;
		}
		currNode.next = firstC;
		firstC.prev = currNode;
		return this;
	}

	// Append char array c to the end of the current MyStringBuilder, and
	// return the current MyStringBuilder. Be careful for special cases!
	public MyStringBuilder append(char[] c) {
		if (c == null || c.length == 0)
			return this;
		CNode currNode;
		CNode newNode = new CNode(c[0]);
		if (length == 0)
			firstC = newNode;
		else {
			currNode = this.firstC.prev;
			currNode.next = newNode;
			newNode.prev = currNode;
		}
		currNode = newNode;
		length += c.length;
		for (int i = 1; i < c.length; ++i) {
			newNode = new CNode(c[i]);
			newNode.prev = currNode;
			currNode.next = newNode;
			currNode = newNode;
		}
		currNode.next = firstC;
		firstC.prev = currNode;
		return this;
	}

	// Append char c to the end of the current MyStringBuilder, and
	// return the current MyStringBuilder. Be careful for special cases!
	public MyStringBuilder append(char c) {
		if (length == 0) {
			firstC = new CNode(c, firstC, firstC);
			length = 1;
			return this;
		}
		CNode currNode = this.firstC.prev;
		CNode newNode = new CNode(c, firstC, currNode);
		currNode.next = newNode;
		firstC.prev = newNode;
		length++;
		return this;
	}

	// Return the character at location "index" in the current MyStringBuilder.
	// If index is invalid, throw an IndexOutOfBoundsException.
	public char charAt(int index) {
		if (index < 0 || index >= length)
			throw new IndexOutOfBoundsException("Invalid index!");
		CNode currNode = firstC;
		while (index != 0) {
			currNode = currNode.next;
			index--;
		}
		return currNode.data;
	}

	// Delete the characters from index "start" to index "end" - 1 in the
	// current MyStringBuilder, and return the current MyStringBuilder.
	// If "start" is invalid or "end" <= "start" do nothing (just return the
	// MyStringBuilder as is). If "end" is past the end of the MyStringBuilder,
	// only remove up until the end of the MyStringBuilder. Be careful for
	// special cases!
	public MyStringBuilder delete(int start, int end) {
		end = end < length ? end : length;
		if (start < 0 || start >= end)
			return this;
		if (start == 0 && end == length) {
			firstC = null;
			length = 0;
			return this;
		}
		CNode currNode = firstC;
		CNode prevNode = null, nextNode = null;
		for (int i = 0; i < length; ++i) {
			if (i == start)
				prevNode = currNode.prev;
			if (i == end - 1)
				nextNode = currNode.next;
			currNode = currNode.next;
		}
		length -= end - start;
		prevNode.next = nextNode;
		nextNode.prev = prevNode;
		if (start == 0)
			firstC = nextNode;
		return this;
	}

	// Delete the character at location "index" from the current
	// MyStringBuilder and return the current MyStringBuilder. If "index" is
	// invalid, do nothing (just return the MyStringBuilder as is). If "index"
	// is the last character in the MyStringBuilder, go backward in the list in
	// order to make this operation faster (since the last character is simply
	// the previous of the first character)
	// Be careful for special cases!
	public MyStringBuilder deleteCharAt(int index) {
		if (index < 0 || index >= length)
			return this;
		if (length == 1) {
			firstC = null;
			length = 0;
			return this;
		}
		if (index == length - 1) {
			CNode prevNode = firstC.prev.prev, nextNode = firstC;
			length--;
			prevNode.next = nextNode;
			nextNode.prev = prevNode;
			return this;
		}
		CNode currNode = firstC;
		CNode prevNode = null, nextNode = null;
		for (int i = 0; i < length; ++i) {
			if (i == index) {
				prevNode = currNode.prev;
				nextNode = currNode.next;
				break;
			}
			currNode = currNode.next;
		}
		length--;
		prevNode.next = nextNode;
		nextNode.prev = prevNode;
		if (index == 0)
			firstC = nextNode;
		return this;
	}

	// Find and return the index within the current MyStringBuilder where
	// String str first matches a sequence of characters within the current
	// MyStringBuilder. If str does not match any sequence of characters
	// within the current MyStringBuilder, return -1. Think carefully about
	// what you need to do for this method before implementing it.
	public int indexOf(String str) {
		if (length < str.length())
			return -1;
		int[] kmp = new int[length];
		kmp[0] = -1;
		for (int i = 1, j = -1; i < str.length(); ++i) {
			while (j != -1 && str.charAt(j + 1) != str.charAt(i))
				j = kmp[j];
			if (str.charAt(i) == str.charAt(j + 1))
				++j;
			kmp[i] = j;
		}
		CNode currNode = firstC;
		for (int i = 0, j = -1; i < length; ++i) {
			while (j != -1 && str.charAt(j + 1) != currNode.data)
				j = kmp[j];
			if (str.charAt(j + 1) == currNode.data)
				++j;
			if (j == str.length() - 1)
				return i - (str.length() - 1);
			currNode = currNode.next;
		}
		return -1;
	}

	// Insert String str into the current MyStringBuilder starting at index
	// "offset" and return the current MyStringBuilder. if "offset" ==
	// length, this is the same as append. If "offset" is invalid
	// do nothing.
	public MyStringBuilder insert(int offset, String str) {
		if (offset < 0 || offset > length)
			return this;
		if (length == 0)
			return new MyStringBuilder(str);
		CNode currNode = firstC;
		CNode prevNode = null, nextNode = null;
		for (int i = 0; i <= length; ++i) {
			if (i == offset) {
				prevNode = currNode.prev;
				nextNode = currNode;
				break;
			}
			currNode = currNode.next;
		}
		currNode = prevNode;
		for (int i = 0; i < str.length(); ++i) {
			CNode newNode = new CNode(str.charAt(i), null, currNode);
			if (offset == 0 && i == 0)
				firstC = newNode;
			currNode.next = newNode;
			currNode = newNode;
		}
		currNode.next = nextNode;
		nextNode.prev = currNode;
		length += str.length();
		return this;
	}

	// Insert character c into the current MyStringBuilder at index
	// "offset" and return the current MyStringBuilder. If "offset" ==
	// length, this is the same as append. If "offset" is invalid,
	// do nothing.
	public MyStringBuilder insert(int offset, char c) {
		if (offset < 0 || offset > length)
			return this;
		CNode currNode = firstC;
		CNode prevNode = null, nextNode = null;
		for (int i = 0; i <= length; ++i) {
			if (i == offset) {
				prevNode = currNode.prev;
				nextNode = currNode.next;
				break;
			}
			currNode = currNode.next;
		}
		CNode newNode = new CNode(c, nextNode, prevNode);
		if (offset == 0)
			firstC = newNode;
		prevNode.next = newNode;
		newNode.prev = newNode;
		length++;
		return this;
	}

	// Return the length of the current MyStringBuilder
	public int length() {
		return length;
	}

	// Delete the substring from "start" to "end" - 1 in the current
	// MyStringBuilder, then insert String "str" into the current
	// MyStringBuilder starting at index "start", then return the current
	// MyStringBuilder. If "start" is invalid or "end" <= "start", do nothing.
	// If "end" is past the end of the MyStringBuilder, only delete until the
	// end of the MyStringBuilder, then insert. This method should be done
	// as efficiently as possible. In particular, you may NOT simply call
	// the delete() method followed by the insert() method, since that will
	// require an extra traversal of the linked list.
	public MyStringBuilder replace(int start, int end, String str) {
		end = end < length ? end : length;
		if (start < 0 || start >= end)
			return this;
		if (start == 0 && end == length)
			return new MyStringBuilder(str);
		CNode currNode = firstC;
		CNode prevNode = null, nextNode = null;
		for (int i = 0; i < length; ++i) {
			if (i == start)
				prevNode = currNode.prev;
			if (i == end - 1)
				nextNode = currNode.next;
			currNode = currNode.next;
		}
		length -= end - start;
		currNode = prevNode;
		for (int i = 0; i < str.length(); ++i) {
			CNode newNode = new CNode(str.charAt(i), null, currNode);
			if (start == 0 && i == 0)
				firstC = newNode;
			currNode.next = newNode;
			currNode = newNode;
		}
		currNode.next = nextNode;
		nextNode = currNode;
		length += str.length();
		return this;
	}

	// Return as a String the substring of characters from index "start" to
	// index "end" - 1 within the current MyStringBuilder. For this method
	// you should do the following:
	// 1) Create a character array of the appropriate length
	// 2) Fill the array with the proper characters from your MyStringBuilder
	// 3) Return a new String using the array as an argument, or
	// return new String(charArray);
	public String substring(int start, int end) {
		end = end < length ? end : length;
		if (start < 0 || start >= end)
			return new String();
		char[] charArray = new char[end - start];
		CNode currNode = firstC;
		for (int i = 0; i < length; ++i) {
			if (i >= start && i < end)
				charArray[i - start] = currNode.data;
			currNode = currNode.next;
		}
		return new String(charArray);
	}

	// Return as a String the reverse of the contents of the MyStringBuilder. Note
	// that this does NOT change the MyStringBuilder in any way. See substring()
	// above for the basic approach.
	public String revString() {
		char[] charArray = new char[length];
		if (length == 0)
			return new String(charArray);
		CNode currNode = firstC.prev;
		for (int i = 0; i < length; ++i) {
			charArray[i] = currNode.data;
			currNode = currNode.prev;
		}
		return new String(charArray);
	}

	// You must use this inner class exactly as specified below. Note that
	// since it is an inner class, the MyStringBuilder class MAY access the
	// data, next and prev fields directly.
	private class CNode {
		private char data;
		private CNode next, prev;

		public CNode(char c) {
			data = c;
			next = null;
			prev = null;
		}

		public CNode(char c, CNode n, CNode p) {
			data = c;
			next = n;
			prev = p;
		}
	}
}
