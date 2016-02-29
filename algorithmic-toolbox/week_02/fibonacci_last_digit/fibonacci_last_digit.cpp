#include <iostream>
#include <vector>

using std::vector;

/**
 * Calculate the last digit of the nth Fibonacci number.
 *
 * @param n
 *   The index of the number to find,
 *
 * @return int
 *   The last digit of the Fibanaci number at that index.
 */
int get_fibonacci_last_digit(int n) {
    vector<int> fib_numbers(n + 1);
    fib_numbers[0] = 0;
    fib_numbers[1] = 1;

    for (int i = 2; i < fib_numbers.size(); i++) {
        fib_numbers[i] = (fib_numbers[i - 1] + fib_numbers[i - 2]) % 10;
    }

    return fib_numbers[n];
}

int main() {
  int n;
  std::cin >> n;

  int c = get_fibonacci_last_digit(n);
  
  std::cout << c << '\n';
}
