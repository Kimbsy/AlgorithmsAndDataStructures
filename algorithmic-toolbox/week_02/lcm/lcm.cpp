#include <iostream>

/**
 * Recursively calculate the greatest common divisor of two numbers.
 *
 * @param  a
 *   The first number.
 * @param  b
 *   The second number.
 *
 * @return
 *   The greatest common divisor.
 */
long long gcd(long long a, long long b) {
  if (a % b == 0) {
    return b;
  }

  return gcd(b, (a % b));
}

/**
 * Calculate the lowest common multiple of two numbers.
 *
 * @param  a
 *   The first number.
 * @param  b
 *   The second number.
 *
 * @return
 *   The lowest comnmon multiple.
 */
long long lcm(long long a, long long b) {
  std::cout << gcd(a, b) << '\n';
  return (a * b) / gcd(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
