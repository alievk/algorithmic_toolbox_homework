#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int min(int a, int b)
{
    return a > b ? b : a;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  while (capacity > 0 && weights.size()) {
      // take fraction of the most valuable item
      int max_val_i = -1;
      double max_val = -1;
      for (int i = 0; i < weights.size(); ++i) {
          double v = double(values[i]) / weights[i];
          if (v > max_val) {
              max_val = v;
              max_val_i = i;
          }
      }

      // subproblem
      int add = min(capacity, weights[max_val_i]);
      value += add * max_val;
      capacity -= add;

      // repeat
      weights.erase(weights.begin() + max_val_i);
      values.erase(values.begin() + max_val_i);
  }

  assert(capacity == 0 || weights.empty());

  return value;
}

void test()
{
    /*
    double optimal_value = get_optimal_value(50,
    {20, 50, 30},
    {60, 100, 120});
    */
    double optimal_value = get_optimal_value(10,
    {30},
    {500});

    std::cout.precision(10);
    cout << optimal_value << endl;
}

int main() {

  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;


    //test();

  return 0;
}
