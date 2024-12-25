package leture17;
// CMPINF 0401 Summer 2024
// Demonstration of interfaces in Java. 

// Any new Java class can implement any number of interfaces
class Comedian implements Laughable, Booable
{
	String name;

	public Comedian(String s)
	{
		name = new String(s);
	}
	// Many possible methods omitted
	
	public void laugh()
	{
		System.out.println("Ha ha ha for " + name);
	}

	public void boo()
	{
		System.out.println(name + " really stinks!");
	}

}

class SitCom implements Laughable
{
	String title;

	public SitCom(String s)
	{
		title = new String(s);
	}
	// Many possible methods omitted
	public void laugh()
	{
		System.out.println("Chuckle chuckle for " + title);
	}
	
	// We can override a default method if we wish, similar to overriding
	// a regular instance method.
	public void wacky()
	{	
		System.out.println("Overriding default method");
		System.out.print("\tCalling original version:\n\t");
		Laughable.super.wacky();
		// Note the unusual syntax for calling the "parent" version of the
		// method.  Unlike with superclasses, for interfaces we must use
		// the interface name.
	}
/*
	public void boo()
	{
		System.out.println("This series really stinkoramizes!");
	}
*/	
}

class Clown extends Object implements Laughable, Booable
{
	String type;

	public Clown(String s)
	{
		type = new String(s);
	}
	// Many possible methods omitted
	
	public void laugh()
	{
		System.out.println(type + " clown makes me chortle");
	}
	
	public void boo()
	{
		System.out.println(type + " makes me gag");
	}
}

public class ex20
{
	public static void main(String [] args)
	{
		Laughable [] L = new Laughable[5]; // Create an array of references
		// Note below that we are storing and accessing several different object
		// types within our array of Laughable.  This is polymorphism in its purest
		// form.  The method being called (ex: laugh()) has the same header / spec
		// for all of the objects but the code being associated with it depends on
		// the underlying object.  So L[0].laugh() and L[1].laugh() are called with
		// identical code but they are in fact two different methods -- one defined
		// in class Clown and the other defined in class SitCom.
		
		System.out.println("Accessing as Laughable:");
	
		//L[0] = new Laughable();  // not legal, since we cannot make objects
		                          // from the interface itself.  We need to use
		                          // the classes that implement it.

		L[0] = new Clown("Rodeo");
		// Even though the method boo() is defined for the class Clown, it
		// cannot be accessed here, since it is not in the Laughable interface.
		// The statement below will generate a compilation error.
		//L[0].boo();
		L[1] = new SitCom("Big Bang Theory");
		L[2] = new Comedian("Eddie Izzard");
		L[3] = new SitCom("Brooklyn Nine-Nine");
		L[4] = new Clown("Circus");
		// Note the for loop syntax below.  This is VERY handy when you want to
		// access all of the objects within an array (or other Iterable object)
		// but don't care about the position (i.e. index).  
		for (Laughable La: L)
		{
				La.laugh();
				//La.boo();
		}
		System.out.println();

		System.out.println("Accessing as Booable:");
		Booable [] B = new Booable[5];  // Make an array of Booable

		// Now, instead of making new objects, we are simply casting the types
		// to Booable.  Note that this means that the objects in both arrays
		// are being shared -- so care must be taken if an object is mutated.
		// However, these classes have no mutators, so that is not an issue here.
		//B[0] = L[0];  // This does not work -- object must be cast to Booable
		B[0] = (Booable) L[0];  B[0].boo();
		//B[1] = (Booable) L[1];  B[1].boo();// not legal, since the object currently
						// in L[1] does not implement Booable
		B[2] = (Booable) L[2];  B[2].boo();
		// B[3] = (Booable) L[3];  // also not legal
		B[4] = (Booable) L[4];  B[4].boo();

		// If we access the object through a reference matching its class, we can
		// acccess any of the methods in the class
		System.out.println();
		System.out.println("Accessing as a Comedian:");
		Comedian C = (Comedian) B[2];
		C.laugh();
		C.boo();
		System.out.println();
		
		// Demonstrating some other features of interfaces. 
		Laughable.weasel();   // Calling static method (since Java 1.8).  Note
		//A[0].weasel();
				// that the interface name is used to call this method,
				// similar to the way static methods within classes are called.
		//Laughable.wacky();	// Cannot call default method through interface,
				// since it is an instance method.  Default methods were added
				// to interfaces in Java 1.8.
		System.out.println(Laughable.chuckle);  // Accessing static variable
		//Laughable.chuckle = "Yuk yuk yuk";  // Not legal since static
							// variables in interfaces are always final
		L[0].wacky(); 	// Calling default method through object.
		L[1].wacky(); 	// Note that L[1] is a SitCom, which has overridden
						// wacky()
		C.wacky();  // Can call default method even if interface variable is
					// not used, since Comedian implements Laughable

		//L[0].weasel(); // This is not legal since weasel() is static		
	}
}
