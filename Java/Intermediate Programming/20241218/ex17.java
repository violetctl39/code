// CMPINF 401 Summer 2024
// Demonstration of ad hoc polymorphism, or method overloading.  Note the
// different method signatures for the same method name.  When the program
// is COMPILED, the correct version of the method is determined for each
// of the method calls.  If an exact signature match is not possible, the
// version that requires the least amount of "widening" (i.e. the most
// specific match) is used. If more than one version can match with an equal
// amount of widening, the call is ambiguous and will generate a compilation
// error.  Be careful if you rely on widening for these calls -- they can
// have unusual behavior.  I recommend trying to have exact matches if possible.

public class ex17
{
	public static double max(double a, double b)
	{
		System.out.println("double double");
		if (a >= b) return a;
		return b;
	}

	public static double max(double a, float b)
	{
		System.out.println("double float");
		if (a >= b) return a;
		return b;
	}

	public static double max(float a, double b)
	{
		System.out.println("float double");
		if (a >= b) return a;
		return b;
	}

	public static double max(double a, double b, double c)
	{
		System.out.println("double double double");
		if (a >= b && a >= c) return a;
		if (b >= c) return b;
		return c;
	}
	
	public static double max(int a, int b, double c)
	{
		System.out.println("int int double");
		if (a >= b && a >= c) return a;
		if (b >= c) return b;
		return c;
	}
		
	public static double max(int a, double b, double c)
	{
		System.out.println("int double double");
		if (a >= b && a >= c) return a;
		if (b >= c) return b;
		return c;
	}
	
	public static void main(String [] args)
	{
		double d1 = 10, d2 = 15, d3 = 5;
		double bmax1;
		int i1 = 8, i2 = 4, i3 = 2;

		bmax1 = max(d1, d2);  // Only version with 2 arguments
		bmax1 = max(i1, d2, d3); // Matches a version exactly
		bmax1 = max(i1, i2, d3); // Matches a version exactly
		bmax1 = max(d1, d2, d3); // Matches a version exactly
		bmax1 = max(i1, i2, i3); // Least widening is for int int
								 // double (only one param widened)
		bmax1 = max(i1, i2);
	}
}
