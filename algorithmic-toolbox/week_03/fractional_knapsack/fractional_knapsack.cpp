#include <iostream>
#include <vector>

using std::vector;

int get_best_idx(vector<int> weights, vector<int> values) {
  int best = 0;
  int best_idx = 0;

  for (int i = 0; i < weights.size(); i++) {
    double ratio = (values[i] / weights[i]);
    if (ratio > best) {
      best = ratio;
      best_idx = i;
    }
  }

  return best_idx;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double remaining_capacity = (double) capacity;

  while (remaining_capacity > 0) {

    int best_idx = get_best_idx(weights, values);
    // std::cout << "best idx: " << best_idx << std::endl;

    if (weights[best_idx] > 0) {
      double amount = std::min((double)remaining_capacity, (double)weights[best_idx]);
      // std::cout << "amount: " << amount << std::endl;

      double ratio = (double) values[best_idx] / (double) weights[best_idx];
      // std::cout << "ratio: " << ratio << std::endl;
      value += amount * ratio;

      remaining_capacity -= amount;
      weights[best_idx] -= amount;

      if (weights[best_idx] == 0) {
        weights.erase(weights.begin() + best_idx);
        values.erase(values.begin() + best_idx);
      }
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;

  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  // vector<double> ratios(n);

  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    // ratios[i] = (double) values[i] / (double) weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
