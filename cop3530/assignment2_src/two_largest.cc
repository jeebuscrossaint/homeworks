#include <iostream>
#include <vector>

void TwoLargest(const std::vector<int>& A) {
    int large_1 = 0;
    int large_2 = 0;

    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > large_1) {
            large_2 = large_1;
            large_1 = A[i];
        } else if (A[i] > large_2) {
            large_2 = A[i];
        }
    }

    std::cout << "The two largest numbers are: " << large_1 << " and " << large_2 << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the size of the list: ";
    std::cin >> n;

    std::vector<int> A(n);
    std::cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    TwoLargest(A);

    return 0;
}