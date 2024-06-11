#ifndef RATIONALSST_H
#define RATIONALSST_H

#include <iostream>

namespace jeebuscrossaint {

class Rational {
public:
    // Constructors
    Rational();                // Default constructor
    Rational(int num);         // Constructor with a single int parameter
    Rational(int num, int denom); // Constructor with two int parameters

    // Other member functions
    void simplify(); // Function to simplify the rational number

    // Getters for numerator and denominator
    int getNumerator() const;
    int getDenominator() const;

    // Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Rational& rational);
    friend std::istream& operator>>(std::istream& is, Rational& rational);
    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator<(const Rational& lhs, const Rational& rhs);
    friend bool operator<=(const Rational& lhs, const Rational& rhs);
    friend bool operator>(const Rational& lhs, const Rational& rhs);
    friend bool operator>=(const Rational& lhs, const Rational& rhs);
    friend bool operator!=(const Rational& lhs, const Rational& rhs);
    friend Rational operator+(const Rational& lhs, const Rational& rhs);
    friend Rational operator-(const Rational& lhs, const Rational& rhs);
    friend Rational operator*(const Rational& lhs, const Rational& rhs);
    friend Rational operator/(const Rational& lhs, const Rational& rhs);

private:
    // Private members
    int numerator;
    int denominator;

    // Private helper function for greatest common divisor (GCD)
    int gcd(int a, int b);
};

} // namespace jeebuscrossaint

#endif // RATIONALSST_H
