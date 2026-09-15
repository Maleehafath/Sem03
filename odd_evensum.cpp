#include <iostream>
// Function to calculate the sum of squares of odd and even numbers
void sumsquare(const int l[], int n, long long result[]) {
    long long odd_sum = 0;
    long long even_sum = 0;

    for (int i = 0; i < n; ++i) {
        long long square = static_cast<long long>(l[i]) * l[i];
        
        if (l[i] % 2 != 0) {
            odd_sum += square; // Odd number
        } else {
            even_sum += square; // Even number
        }
    }

    // Store results: result[0] = odd sum, result[1] = even sum
    result[0] = odd_sum;
    result[1] = even_sum;
}

int main() {
    // Example array
    int l[] = {1, 2, 3, 4, 5};
    int n = 5;
    long long result[2]; // Array to store [odd_sum, even_sum]

    sumsquare(l, n, result);

    // Displaying the results
    std::cout << "Array elements: {1, 2, 3, 4, 5}\n";
    std::cout << "Sum of squares of odd numbers: " << result[0] << " (1^2 + 3^2 + 5^2 = 1 + 9 + 25)\n";
    std::cout << "Sum of squares of even numbers: " << result[1] << " (2^2 + 4^2 = 4 + 16)\n";

    return 0;
}
