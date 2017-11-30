#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void print(const vector<int> &A)
{
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void generate(vector<int> &A, int m)
{
    for (int i = 0; i < A.size(); ++i) {
        A[i] = rand() % m;
    }
}

int get_majority_element(vector<int> &a, int left) {
    if (a.size() == 1)
        return a[0];
    if (left > a.size()/2)
        return -1;

    int x = a[left];
    int j = left;
    for (int i = left + 1; i < a.size(); ++i)
        if (a[i] == x) {
            j += 1;
            a[i] = a[j];
            a[j] = x;
        }

    //cout << x << ": " << left << "-" << j << endl;
    if (j - left + 1 > a.size()/2)
        return x;

    get_majority_element(a, j + 1);
}

int get_majority_element_naive(const vector<int> &a) {
    for (int i = 0; i < a.size(); ++i) {
        int cur = a[i];
        int count = 0;
        for (int j = 0; j < a.size(); ++j)
            if (a[j] == cur)
                count += 1;
        if (count > a.size()/2)
            return cur;
    }
    return -1;
}

void test()
{
    /*
    vector<int> a{
        //2,7,3,7,7,7,7,3,3,3,7,3,3,3,3,3,3,3,1,2
        //2, 3, 9, 2, 2
        //1, 2, 3, 4
        //1, 2, 3, 1
        1, 1
        //1
    };

    print(a);

    cout << get_majority_element(a, 0) << endl;

    print(a);
    */

    /*
    while (true) {
        int n = 1 + rand() % 10;
        int m = 1 + rand() % 5;
        vector<int> a(n);
        generate(a, m);
        print(a);
        int naive = get_majority_element_naive(a);
        int fast = get_majority_element(a, 0);
        print(a);
        cout << naive << " " << fast << endl;
        if (naive != fast)
            break;
        cout << "OK\n";
    }
    */


    int n = 100000;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        a[i] = i;
//    int m = 4;
//    generate(a, m);
    clock_t s = clock();
    int res = get_majority_element(a, 0);
    cout << float(clock()-s)/CLOCKS_PER_SEC << endl;
    cout << res << endl;

}

int main() {
#if 0
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0) != -1) << '\n';
#else
    test();
#endif
}
