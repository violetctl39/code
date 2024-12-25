// CMPINF 0401 Summer 2024
// Simple Java interface with one method
// Generally, an interface is used to state a list of method
// headers and allow the implementing classes to provide the
// method bodies.  Interfaces may also contain static variables
// but no instance variables are allowed.
// 
// As of Java 1.8 interfaces are now allowed to also have two
// additional features:
// 1) Static methods
// 2) Default methods 

public interface Laughable
{
	// Static variable (must also be final).  Even if you leave off
	// the "public static final" designations for these variables they
	// will still be "public static final"
	public static String chuckle = "Hardy Hardy Har!";
	
	// Regular method header.  Any class that implements Laughable must
	// define this method.
	public void laugh();  
	
	// Default method.  This method will automatically exist
	// for any class that implements the interface.  Note that this 
	// is actually ADDING functionality to an object, since is not
	// defined in the class directly -- it only exists through the
	// interface.
	default public void wacky()
	{
		System.out.println("This is a default method");
	}
	
	// Static method.  This method must be called through the interface
	// name (like other static methods) rather than through an object
	// that implements the interface.  See more info in ex20.java
	public static void weasel()
	{
	     System.out.println("This is a static method");
	}
}
