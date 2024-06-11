#include <iostream>
using namespace std;

class Pairs
{
public:
    // Default constructor
    Pairs();

    // Constructor with two parameters
    Pairs(int first, int second);

    // Constructor with one parameter
    Pairs(int first);

    // Overloaded operators
    Pairs operator+(const Pairs& other) const;
    Pairs operator-(const Pairs& other) const;
    Pairs operator*(int scalar) const;

    // Input and output operators
    friend istream& operator>>(istream& ins, Pairs& second);
    friend ostream& operator<<(ostream& outs, const Pairs& second);

    // Other member functions if needed

private:
    int f;
    int s;
};

// Default constructor
Pairs::Pairs() : f(0), s(0) {}

// Constructor with two parameters
Pairs::Pairs(int first, int second) : f(first), s(second) {}

// Constructor with one parameter
Pairs::Pairs(int first) : f(first), s(0) {}

// Overloaded operator + to add pairs
Pairs Pairs::operator+(const Pairs& other) const
{
    return Pairs(f + other.f, s + other.s);
}

// Overloaded operator - to subtract pairs
Pairs Pairs::operator-(const Pairs& other) const
{
    return Pairs(f - other.f, s - other.s);
}

// Overloaded operator * to multiply pair by scalar
Pairs Pairs::operator*(int scalar) const
{
    return Pairs(f * scalar, s * scalar);
}

// Overloaded operator >> for input
istream& operator>>(istream& ins, Pairs& second)
{
    char ch;
    ins >> ch >> second.f >> ch >> second.s >> ch;
    return ins;
}

// Overloaded operator << for output
ostream& operator<<(ostream& outs, const Pairs& second)
{
    outs << "(" << second.f << "," << second.s << ")";
    return outs;
}

int main()
{
    // Test the member functions and overloaded operators
    Pairs a(5, 6);
    Pairs b(3, -4);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    Pairs c = a + b;
    cout << "a + b: " << c << endl;

    Pairs d = a - b;
    cout << "a - b: " << d << endl;

    Pairs e = a * 2;
    cout << "a * 2: " << e << endl;

    Pairs f;
    cout << "Enter a pair (format: (x,y)): ";
    cin >> f;
    cout << "You entered: " << f << endl;

    return 0;
}
