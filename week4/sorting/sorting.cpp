#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int> &A, int l, int r, int &m1, int &m2)
{
    assert(l < r);
    int x = A[l];
    int j = l - 1;
    int k = l;

    for (int i = l + 1; i <= r; ++i) {
        if (A[i] == x) {
            k += 1;
            A[i] = A[k];
            A[k] = x;
        }
        else if (A[i] < x) {
            j += 1;
            A[j] = A[i];
            k += 1;
            A[i] = A[k];
            A[k] = x;
        }
    }

    m1 = j;
    m2 = k;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
 //   cout << l << " " << r << " " << a.size() << endl;
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m1, m2;
  partition3(a, l, r, m1, m2);
//  cout << a[l] << endl << m1 << endl << m2 << endl;

  randomized_quick_sort3(a, l, m1);
  randomized_quick_sort3(a, m2 + 1, r);
}

bool compare(const vector<int> &a1, const vector<int> &a2)
{
    assert(a1.size() == a2.size());
    for (int i = 0; i < a1.size(); ++i)
        if (a1[i] != a2[i]) {
            cout << "at index " << i << ": " << a1[i] << " != " << a2[i] << endl;
            return false;
        }
    return true;
}

void generate(vector<int> &A, int m, bool balanced = true)
{
    for (int i = 0; i < A.size(); ++i) {
        A[i] = rand() % m;
    }

    if (!balanced) {
        int x = m / 2;
        int j = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] <= x) {
                int t = A[j];
                A[j] = A[i];
                A[i] = t;
                j += 1;
            }
        }
    }
}

void print(const vector<int> &A)
{
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void test()
{
    while (true) {
        const int N = 100;
        vector<int> A(N);

        cout << "---\n";
        generate(A, 6);
        print(A);


        vector<int> A2 = A, A3 = A;
        randomized_quick_sort(A2, 0, A2.size() - 1);
        randomized_quick_sort3(A3, 0, A3.size() - 1);
        if (!compare(A2, A3))
            break;

        cout << "OK\n";


/*
        randomized_quick_sort3(A, 0, A.size() - 1);
        print(A);
*/

    }
}

int main() {
#if 1
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
#else
    test();
#endif
}
