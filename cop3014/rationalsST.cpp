#include "rationalsST.h"
#include <iostream>

namespace jeebuscrossaint {

// Unnamed namespace for implementation details

int Rational::gcd(int a, int b) {
    // Implement the greatest common divisor (GCD) function
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Implementation of member functions for the Rational class

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num) : numerator(num), denominator(1) {}

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
    // Ensure the denominator is not zero
    if (denominator == 0) {
        std::cerr << "Error: Denominator cannot be zero. Setting denominator to 1." << std::endl;
        denominator = 1;
    }

    // Simplify the rational number
    simplify();
}

void Rational::simplify() {
    int commonFactor = gcd(numerator, denominator);
    numerator /= commonFactor;
    denominator /= commonFactor;
}

std::ostream& operator<<(std::ostream& os, const Rational& rational) {
    os << rational.numerator << "/" << rational.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Rational& rational) {
    char slash; // To capture the '/' character
    is >> rational.numerator >> slash >> rational.denominator;

    // Ensure the denominator is not zero
    if (rational.denominator == 0) {
        std::cerr << "Error: Denominator cannot be zero. Setting denominator to 1." << std::endl;
        rational.denominator = 1;
    }

    // Simplify the rational number
    rational.simplify();

    return is;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    // Check if the numerators and denominators are equal
    return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    // Cross-multiply to compare the numerators
    return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator;
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
    // Cross-multiply to compare the numerators
    return lhs.numerator * rhs.denominator <= rhs.numerator * lhs.denominator;
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    return lhs.numerator * rhs.denominator > rhs.numerator * lhs.denominator;
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
    // Compare the numerators using cross-multiplication and negate the result
    return !(lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator);
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    // Check if the numerators or denominators are not equal
    return lhs.numerator != rhs.numerator || lhs.denominator != rhs.denominator;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    // Cross-multiply to find a common denominator
    int commonDenominator = lhs.denominator * rhs.denominator;

    // Add the numerators with the common denominator
    int resultNumerator = (lhs.numerator * rhs.denominator) + (rhs.numerator * lhs.denominator);

    // Create a new Rational object with the result
    return Rational(resultNumerator, commonDenominator);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    // Cross-multiply to find a common denominator
    int commonDenominator = lhs.denominator * rhs.denominator;

    // Subtract the numerators with the common denominator
    int resultNumerator = (lhs.numerator * rhs.denominator) - (rhs.numerator * lhs.denominator);

    // Create a new Rational object with the result
    return Rational(resultNumerator, commonDenominator);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    // Multiply the numerators and denominators separately
    int resultNumerator = lhs.numerator * rhs.numerator;
    int resultDenominator = lhs.denominator * rhs.denominator;

    // Create a new Rational object with the result
    return Rational(resultNumerator, resultDenominator);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    // Check if the divisor is not zero
    if (rhs.numerator == 0) {
        std::cerr << "Error: Division by zero is not allowed. Returning a default Rational." << std::endl;
        return Rational();
    }

    // Multiply by the reciprocal of the divisor
    int resultNumerator = lhs.numerator * rhs.denominator;
    int resultDenominator = lhs.denominator * rhs.numerator;

    // Create a new Rational object with the result
    return Rational(resultNumerator, resultDenominator);
}

} // namespace jeebuscrossaint
