// CS 0445 Spring 2023
//
// Testing of simple deque with iterator
// This program should run without changes with 
// your SimpleDequeWithIterator<T> class
// Note: You also need file DequeWithIteratorInterface.java to run this
//       program

import java.util.*;
public class TestIterator
{
	public static void main(String [] args)
	{
		DequeWithIteratorInterface<Integer> D1 = new SimpleDequeWithIterator<Integer>(5);

		for (int i = 0; i < 5; i++)
		{
			Integer newItem = Integer.valueOf(2 * i);
			System.out.println("Adding " + newItem + " to Deque");
			D1.addToBack(newItem);
		}
		
		Iterator<Integer> eye1 = D1.iterator();
		while (eye1.hasNext())
		{
			Integer currOne = eye1.next();
			System.out.println("Outer value: " + currOne);
			Iterator<Integer> eye2 = D1.iterator();
			System.out.print("\tInner values: ");
			while (eye2.hasNext())
			{
				Integer currTwo = eye2.next();
				System.out.print(currTwo + " ");
			}
			System.out.println();
		}
	}
}
		