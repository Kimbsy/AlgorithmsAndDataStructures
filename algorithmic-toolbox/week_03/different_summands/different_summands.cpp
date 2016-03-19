#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

/**
 * Debugging function which prints a vector's elements.
 *
 * @param v
 *   The vector to print.
 */
void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

vector<int> optimal_summands(int n) {
  vector<int> summands;
  // vector<int> allowed(n);
  // std::iota(allowed.begin(), allowed.end(), 1);

  int copy = n;
  int max_summand = 1;

  while (n > 0) {



    int current = max_summand;
    while (current <= n && n > 0) {
      cout << "n: " << n << endl;
      cout << "current: " << current << endl;
      // bool not_in_vector = (std::find(summands.begin(), summands.end(), current) == summands.end());
      if ((current <= n / 2 /*|| current == n*/)/* && not_in_vector*/) {
        n -= current;
        summands.push_back(current);
        max_summand = current;
      } else {
        
      }
      current++;
    }
  }

  // print_vector(summands);
  
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
