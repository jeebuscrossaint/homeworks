#include <iostream>
#include <vector>

// Function to convert k to its binary representation
std::vector<int> BinaryK(int k) {
    std::vector<int> K;
    while (k > 0) {
        K.push_back(k % 2);
        k = k / 2;
    }
    return K;
}

// Function to perform modular exponentiation
int ModularExpo(int a, const std::vector<int>& K, int n) {
    if (n == 1) return 0;
    int b = 1;
    int A = a;

    if (K[0] == 1) {
        b = a;
    }

    for (size_t i = 1; i < K.size(); ++i) {
        A = (A * A) % n;
        if (K[i] == 1) {
            b = (A * b) % n;
        }
    }

    return b;
}

int main() {
    int a, k, n;
    std::cout << "Enter the base (a): ";
    std::cin >> a;
    std::cout << "Enter the exponent (k): ";
    std::cin >> k;
    std::cout << "Enter the modulus (n): ";
    std::cin >> n;

    std::vector<int> K = BinaryK(k);
    int result = ModularExpo(a, K, n);

    std::cout << "Result of " << a << "^" << k << " mod " << n << " is: " << result << std::endl;

    return 0;
}