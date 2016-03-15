#include <iostream>

int get_change(int n) {
  
  int count = 0;

  count += n / 10;
  n = n % 10;

  count += n / 5;
  n = n % 5;

  count += n;

  return count;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
