#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  if (n <= 2) {
      summands.push_back(n);
      return summands;
  }

  summands.push_back(1);
  n -= 1;
  while (n > 0) {
      int l = summands.back();
      if (n > 2*(l + 1))
          l += 1;
      else
          l = n;

      n -= l;

      summands.push_back(l);
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
