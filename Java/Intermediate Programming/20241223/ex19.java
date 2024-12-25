// Now class Animal is abstract -- which means that it has one or more
// abstract methods and that objects cannot be instantiated (created)
// of this class.  However, references of this class can still be used
// to access objects of all of its subclasses.  Also, methods that ARE
// defined in this class (ex: toString()) can be used by subclass
// objects
package leture17;

abstract class Animal
{
	private String name;

	public Animal(String n)
	{
		name = new String(n);
	}

	// Now the methods below are abstract, which means that they are
	// declared in this class but have no "bodies" and must be
	// implemented by subclasses in order to be used.  The declaration
	// at this level is simply to allow for consistent access of objects
	// within this class hierarchy
	public abstract void characteristics();
	public abstract void move();

	public String toString()
	{
		return new String("My name is " + name + " and I am a " + getClass());
	}

}

class Fish extends Animal
{
	public static enum WaterType {freshWater, saltWater}
	
	private WaterType myWater;

	public Fish(String n, WaterType w)
	{
		super(n);
		myWater = w;
	}

	public void characteristics()
	{
		//super.characteristics();  // This call is commented out because
					// it no longer exists -- there is no superclass
					// version of this method to call.  For the same
					// reason, the calls are commented out in the other
					// subclasses below
		System.out.println("I have fins");
		System.out.println("I like " + myWater);
	}

	public WaterType getWaterType()
	{
		return myWater;
	}

	public void move()
	{
		System.out.println("I swim");
	}
}

class Shark extends Fish
{
	public Shark(String n, WaterType w)
	{
		super(n, w);
	}

	public void characteristics()
	{
		// Using the super version is ok here, since characteristics
		// was defined in class Fish
		super.characteristics();
		System.out.println("I am carnivorous");
	}
}

class Bird extends Animal
{
	public Bird(String n)
	{
		super(n);
	}

	public void characteristics()
	{
		// super.characteristics();
		System.out.println("I have feathers");
	}

	public void move()
	{
		System.out.println("I fly");
	}
}

class Ostrich extends Bird
{
	public Ostrich(String n)
	{
		super(n);
	}

	public void characteristics()
	{
		// Using the super version is ok here, since characteristics
		// was defined in class Bird
		super.characteristics();
		System.out.println("I have long legs");
	}

	public void move()
	{
		System.out.println("I run");
	}
}

class Person extends Animal
{
	public Person(String n)
	{
		super(n);
	}

	// The characteristics method was not defined in the Person class
	// from Example 18.  However, if we leave it out here we will have
	// an error, since there is no superclass version of the method
	// to use.  Thus, I have added a definition of characteristics below.
	// If we left it out, we would need to declare the Person class to
	// also be abstract.
	
	public void characteristics()
	{
		System.out.println("I vote");
	}	
	
	public void move()
	{
		System.out.println("I walk");
	}
}

public class ex19
{
	public static void main(String [] args)
	{
		Animal [] A = new Animal[8];

		//A[0] = new Animal("Herb"); // This statement is now
					  // an error, because Animal is abstract, and
					  // cannot be used to instantiate objects

		A[0] = new Shark("Jaws", Fish.WaterType.saltWater);
		A[1] = new Bird("Tweety");
		A[2] = new Fish("Nemo", Fish.WaterType.freshWater);
		A[3] = new Person("Marge");
		A[4] = new Ostrich("Big");
		A[5] = new Person("Hector");
		A[6] = new Shark("Lenny", Fish.WaterType.saltWater);
		A[7] = new Fish("Dory", Fish.WaterType.saltWater);

		for (int i = 0; i < A.length; i++)
		{
			System.out.println(A[i]);
			A[i].characteristics();
			A[i].move();

			if (A[i] instanceof Fish)
			{
				Fish F = (Fish) A[i];
				System.out.println(F.getWaterType() + " is fun!");
			}
			System.out.println();
		}
	}
}
