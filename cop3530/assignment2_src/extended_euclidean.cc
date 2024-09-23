#include <iostream>

void extendedEuclideanAlgorithm(int a, int b) {
    int s = 0, old_s = 1;
    int t = 1, old_t = 0;
    int r = b, old_r = a;

    while (r != 0) {
        int q = old_r / r;
        int temp_r = r;
        r = old_r - q * r;
        old_r = temp_r;

        int temp_s = s;
        s = old_s - q * s;
        old_s = temp_s;

        int temp_t = t;
        t = old_t - q * t;
        old_t = temp_t;
    }

    std::cout << "GCD = " << old_r << std::endl;
}

int main() {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    extendedEuclideanAlgorithm(a, b);

    return 0;
}