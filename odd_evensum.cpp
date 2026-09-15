#include <iostream>
#include <vector>

// Uses standard C++11/14/17 compatible signature
void sumsquare(const std::vector<int>& l, long long result[2]) {
    long long odd_sum = 0;
    long long even_sum = 0;

    for (int val : l) {
        long long square = static_cast<long long>(val) * val;
        if (val % 2 != 0) {
            odd_sum += square; // Odd number
        } else {
            even_sum += square; // Even number
        }
    }

    result[0] = odd_sum;
    result[1] = even_sum;
}

int main() {
    int n = 0;
    std::cout << "Enter the number of elements (n): ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid size entered.\n";
        return 1;
    }

    std::vector<int> l(n);
    std::cout << "Enter " << n << " elements separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> l[i];
    }

    long long result[2];
    sumsquare(l, result);

    std::cout << "\nResults:\n";
    std::cout << "Sum of squares of odd numbers: " << result[0] << "\n";
    std::cout << "Sum of squares of even numbers: " << result[1] << "\n";

    return 0;
}
