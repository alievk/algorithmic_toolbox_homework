#include <iostream>
#include <cstdlib>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd_fast(b, a % b);
}

void test() {
    int max = 1000000;
    while (true) {
        int a = 1 + rand() % max;
        int b = 1 + rand() % max;
        int naive = gcd_naive(a, b);
        int fast = gcd_fast(a, b);
        cout << a << " " << b << endl;
        cout << naive << " " << fast << endl;
        if (naive == fast)
            cout << "OK\n";
        else
            break;
    }
}

int main() {

  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;

  //  test();
  return 0;
}
