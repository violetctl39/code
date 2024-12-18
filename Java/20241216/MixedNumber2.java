// CMPINF 401 Summer 2024
// Compare to MixedNumber -- you will see that it produces identical results.

// We are now implementing a mixed number using inheritance rather than
// composition.  In this case, the MixedNumber2 class has ALL of the properties
// of the RationalNumber class.  Because of the return types, we need to
// redefine the operations, but note how little code is involved in them -- we
// are simply utilizing the operations defined already in the superclass.

public class MixedNumber2 extends RationalNumber
{
	// Note: We have no instance variables here, because everything we need
	// is in the RationalNumber class.  All we are doing in MixedNumber2 is
	// altering the way the RationalNumber is displayed.  This is a great
	// example of the notion of Data Abstraction -- we don't need to know
	// how our MixedNumber is stored in order to use it.

	// Use superclass constructor (since no new instance vars)
	public MixedNumber2(int w, int n, int d)
	{
		super(w * d + n, d);
	}

	// This constructor is necessary for the operations below, since they
	// return MixedNumber2 objects, and the superclass methods return
	// RationalNumber objects
	public MixedNumber2(RationalNumber f)
	{
		super(f.getNumerator(), f.getDenominator());
	}

	// All of these operations simply call the superclass version of them
	// and then use the result to construct a new MixedNumber2.  We need to
	// do it in this way because RationalNumber !(is a) MixedNumber2, so we
	// cannot assign a RationalNumber object to a MixedNumber2 variable.
	public MixedNumber2 add(MixedNumber2 m)
	{
		return new MixedNumber2(super.add(m));
	}
/*
	// See Lines 75-82 of ex15.java for some information about this method.
	public MixedNumber2 add(RationalNumber r)
	{
		return new MixedNumber2(super.add(r));
	}
*/
	public MixedNumber2 subtract(MixedNumber2 m)
	{
		return new MixedNumber2(super.subtract(m));
	}

	public MixedNumber2 multiply(MixedNumber2 m)
	{
		return new MixedNumber2(super.multiply(m));
	}

	public MixedNumber2 divide(MixedNumber2 m)
	{
		return new MixedNumber2(super.divide(m));
	}

	public String toString() // Show MixedNumber2 in expected way
	{
		return ((getNumerator() / getDenominator()) + " " +
			    (getNumerator() % getDenominator()) + "/" +
			     getDenominator());
	}
	// equals() is inherited and does not need to be redefined
}
