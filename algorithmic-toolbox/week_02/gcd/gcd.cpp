#include <iostream>

/**
 * Recursively calculate the greatest common divisor of two integers.
 *
 * @param  a
 *   The first integer.
 * @param  b
 *   The second integer.
 *
 * @return
 *   The greatest common divisor.
 */
int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  }

  return gcd(b, (a % b));
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
