#include "rationalsST.h"
#include <iostream>

using namespace std;
using namespace jeebuscrossaint;

int main() {
    // Test your Rational class here
    Rational r1, r2;

    cout << "Enter the first rational number (in the form a/b): ";
    cin >> r1;

    cout << "Enter the second rational number (in the form a/b): ";
    cin >> r2;

    // Test overloaded operators and functions
    cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
    cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
    cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;

    // Additional test cases as mentioned in the assignment

    // ...

    return 0;
}
