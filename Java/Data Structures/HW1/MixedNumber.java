public class MixedNumber extends Fraction {
    private int whole;

    public MixedNumber(int whole, int numerator, int denominator) {
        super(numerator + whole * denominator, denominator);
        this.whole = this.numerator / this.denominator;
        this.numerator = this.numerator % this.denominator;
    }

    public MixedNumber(int whole, Fraction fraction) {
        super(fraction.getNumerator() * whole * fraction.getDenominator(), fraction.getDenominator());
        this.whole = this.numerator / this.denominator;
        this.numerator = this.numerator % this.denominator;
    }

    public Fraction toFraction() {
        return new Fraction(whole * denominator + numerator, denominator);
    }

    public int getWhole() {
        return whole;
    }

    public int getNumerator() {
        return whole == 0 ? numerator : Math.abs(numerator);
    }

    public int getDenominator() {
        return denominator;
    }

    public MixedNumber add(MixedNumber other) {
        Fraction newFraction = toFraction().add(other.toFraction());
        return new MixedNumber(0, newFraction);
    }

    public MixedNumber sub(MixedNumber other) {
        Fraction newFraction = toFraction().sub(other.toFraction());
        return new MixedNumber(0, newFraction);
    }

    public MixedNumber mul(MixedNumber other) {
        Fraction newFraction = toFraction().mul(other.toFraction());
        return new MixedNumber(0, newFraction);
    }

    public MixedNumber div(MixedNumber other) {
        Fraction newFraction = toFraction().div(other.toFraction());
        return new MixedNumber(0, newFraction);
    }

    public String toString() {
        if(whole == 0) return numerator + "/" + denominator;
        return whole + " " + Math.abs(numerator) + "/" + denominator;
    }

    public boolean equals(MixedNumber other) {
        return toFraction().equals(other.toFraction());
    }

    public int compareTo(MixedNumber other) {
        return toFraction().compareTo(other.toFraction());
    }
}