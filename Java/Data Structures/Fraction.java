interface FractionInterface {
    public Fraction add(Fraction other);
    public Fraction sub(Fraction other);
    public Fraction mul(Fraction other);
    public Fraction div(Fraction other);
    public Fraction reciprocal();
    public String toString();
    public boolean equals(Fraction other);
    public int compareTo(Fraction other);
}
public class Fraction implements FractionInterface {
    private int numerator;
    private int denominator;

    private int gcd(int x, int y) {
        return y == 0 ? x : gcd(x, x % y);
    }

    public Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw new IllegalArgumentException("Denominator cannot be zero");
        }
        if (numerator == 0) {
            this.numerator = 0;
            this.denominator = 1;
        } else {
            int gcd = gcd(numerator, denominator);
            this.numerator = numerator / gcd;
            this.denominator = denominator / gcd;
            if (denominator < 0) {
                this.numerator = -this.numerator;
                this.denominator = -this.denominator;
            }
        }
    }

    public int getNumerator() {
        return this.numerator;
    }

    public int getDenominator() {
        return this.denominator;
    }

    public Fraction add(Fraction other) {
        int gcd = gcd(this.denominator, other.denominator);
        int lcm = this.denominator * other.denominator / gcd;
        int newNumerator = this.numerator * lcm / this.denominator + other.numerator * lcm / other.denominator;
        return new Fraction(newNumerator, lcm);
    }

    public Fraction sub(Fraction other) {
        int gcd = gcd(this.denominator, other.denominator);
        int lcm = this.denominator * other.denominator / gcd;
        int newNumerator = this.numerator * lcm / this.denominator - other.numerator * lcm / other.denominator;
        return new Fraction(newNumerator, lcm);
    }

    public Fraction mul(Fraction other) {
        int newNumerator = this.numerator * other.numerator;
        int newDenominator = this.denominator * other.denominator;
        return new Fraction(newNumerator, newDenominator);
    }

    public Fraction div(Fraction other) {
        if (other.numerator == 0) {
            throw new IllegalArgumentException("Cannot divide by zero");
        }
        int newNumerator = this.numerator * other.denominator;
        int newDenominator = this.denominator * other.numerator;
        return new Fraction(newNumerator, newDenominator);
    }

    public Fraction reciprocal() {
        if (this.numerator == 0) {
            throw new IllegalArgumentException("Cannot take reciprocal of zero");
        }
        return new Fraction(this.denominator, this.numerator);
    }

    public String toString() {
        return this.numerator + "/" + this.denominator;
    }

    public boolean equals(Fraction other) {
        return this.numerator == other.numerator && this.denominator == other.denominator;
    }

    public int compareTo(Fraction other) {
        int lcm = this.denominator * other.denominator / gcd(this.denominator, other.denominator);
        int thisNumerator = this.numerator * lcm / this.denominator;
        int otherNumerator = other.numerator * lcm / other.denominator;
        return Integer.compare(thisNumerator, otherNumerator);
    }
}