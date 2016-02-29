#include <iostream>
#include <vector>

using std::vector;

/**
 * Debugging function which prints a vector's elements.
 *
 * @param v
 *   The vector to print.
 */
void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << '\n';
}

/**
 * Calculate the nth Fibonacci number.
 *
 * @param n
 *   The index of the number to find,
 *
 * @return int
 *   The Fibanaci number at that index.
 */
int calc_fib(int n) {
    vector<int> fib_numbers(n + 1);
    fib_numbers[0] = 0;
    fib_numbers[1] = 1;

    for (int i = 2; i < fib_numbers.size(); i++) {
        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
    }

    return fib_numbers[n];
}

int main() {
    int n = 0;
    std::cin >> n;

    if (n <= 1) {
        std::cout << n << '\n';
        return 0;
    }

    std::cout << calc_fib(n) << '\n';
    return 0;
}
