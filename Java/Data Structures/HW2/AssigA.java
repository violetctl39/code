// CS 0445 Spring 2025
// AssigA driver program.  
// This program will test your MyDeque<T> class.
// See also AssigB.java for tests of your other classes.

// This program must work as is with your MyDeque<T> class.  Look carefully
// at all of the method calls so that you create your MyDeque<T> methods 
// correctly.  For example, note the constructor calls and the toString() 
// method call.  The output should be identical to my sample output.  See
// the output in AssigA-out.txt

public class AssigA
{
	public static void main(String [] args)
	{
		// Testing constructor.  Parameter is to set initial size of
		// the underlying array.  Note that the DequeInteface<T> used
		// here is a modified version of the author's interface.  Make
		// sure you use the modified version in your implementation.  You
		// can tell the difference because the version used in this program
		// has two extra methods: size() and capacity().
		DequeInterface<Integer> D1 = new MyDeque<Integer>(4);
		DequeInterface<Integer> D2 = new MyDeque<Integer>(6);

		// Testing addToBack, resizing and toString
		for (int i = 0; i < 10; i++)
		{
			Integer newItem = Integer.valueOf(2 * i);
			D1.addToBack(newItem);
			D2.addToBack(newItem);
			System.out.println(newItem + " added to Deque");
		}
		System.out.println();
		System.out.println("D1: " + D1.toString());
		System.out.println("D1 size: " + D1.size() + " and capacity: " + D1.capacity());
		System.out.println("D2: " + D2.toString());
		System.out.println("D2 size: " + D2.size() + " and capacity: " + D2.capacity());
		
		System.out.println();
		
		// Testing removeFront and removeBack
		while (!(D1.isEmpty()))
		{
			Integer F = D1.removeFront();
			Integer B = D2.removeBack();
			System.out.println("Front: " + F + " Back: " + B);
		}
		Integer noItem = D1.removeFront();
		if (noItem == null)
			System.out.println("Nothing in D");
		System.out.println();
		
		// Testing array management and addToFront
		int count = 1;
		DequeInterface<String> D3 = new MyDeque<String>(5);
		String theItem = new String("Item " + count);
		System.out.println("Adding " + theItem);
		D3.addToFront(theItem);
		for (int i = 0; i < 8; i++)
		{
			count++;
			theItem = new String("Item " + count);
			System.out.println("Adding " + theItem);
			D3.addToFront(theItem);
			theItem = D3.removeBack();
			System.out.println("Removing " + theItem);
		}
		int sz = D3.size();
		System.out.println("There are " + sz + " items in the deque");
		System.out.println("The capacity is " + D3.capacity());
		System.out.println();
		
		// Testing equals method.  equals() should return true if the
		// two deques are logically equivalent -- having equal items in
		// the same locations.  Note that physically they could be in
		// different positions in the underlying arrays as long as they
		// are the same "from front to back". 
		MyDeque<Integer> D4 = new MyDeque<Integer>(8);
		MyDeque<Integer> D5 = new MyDeque<Integer>(5);
		for (int i = 0; i < 5; i++)
			D4.addToBack(Integer.valueOf(0));  // put 5 items into D4
		for (int i = 1; i <= 5; i++)
		{
			Integer X = D4.removeFront();      // take out from D4
			D4.addToBack(Integer.valueOf(i));  // add same value to both
			D5.addToBack(Integer.valueOf(i));  // D4 and D5
		}
		// Both D4 and D5 should have the same items in the same relative order,
		// but they will be in different positions in the arrays.
		System.out.println(D4.toString());
		System.out.println(D5.toString());
		
		if (D4.equals(D5))
			System.out.println("Deques are equal");
		else
			System.out.println("Deques are not equal");
		System.out.println();
		
		D4.removeBack();
		System.out.println(D4.toString());
		if (D4.equals(D5))
			System.out.println("Deques are equal");
		else
			System.out.println("Deques are not equal");
		
		D4.addToBack(Integer.valueOf(99));
		System.out.println(D4.toString());
		if (D4.equals(D5))
			System.out.println("Deques are equal");
		else
			System.out.println("Deques are not equal");
		System.out.println();
		
		// Testing copy constructor method.  Note that the copy 
		// constructor should not be shallow -- it must make a copy
		// of the underlying array.  However, it does not have to be
		// totally deep (and really it cannot be, since the MyDeque<T>
		// class does not know what type T will be and whether it has a
		// copy constructor or clone() method).
		MyDeque<Integer> D6 = new MyDeque<Integer>(D5);
		System.out.println(D6.toString());
		
		if (D6.equals(D5))
			System.out.println("Deques are equal");
		else
			System.out.println("Deques are not equal");
		System.out.println();
		
		D6.addToBack(Integer.valueOf(88));
		System.out.println(D6.toString());
		if (D6.equals(D5))
			System.out.println("Deques are equal");
		else
			System.out.println("Deques are not equal");
		System.out.println();
	}
}
