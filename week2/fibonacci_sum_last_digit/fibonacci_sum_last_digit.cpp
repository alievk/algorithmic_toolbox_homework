#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
//        sum = (sum + current) % 10;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n)
{
    if (n <= 1)
        return n;

    vector<int> period{0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1};
    const int pn = period.size();

    vector<int> period_is(pn); // period inclusive sum
    period_is[0] = period[0];
    for (int i = 1; i < pn; ++i) {
        period_is[i] = period_is[i - 1] + period[i];
    }

    long long sum = (n / pn) * period_is.back() + period_is[n % pn];
    sum %= 10;

    /*
    long long sum = 1;
    for (long int i = 2; i <= n; ++i) {
        sum = (sum + period[i % period.size()]) % 10;
    }
    */

    /*
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    vector<int> v1, v2;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum = (sum + current) % 10;

        v1.push_back(tmp_previous % 10);
        v2.push_back(previous % 10);
    }

    for (auto i : v1)
        cout << i << " ";
    cout << endl;
    for (auto i : v2)
        cout << i << " ";
    cout << endl;
    */

    return sum;
}

void test()
{
    for (int n = 0; n <= 100000; ++n) {
        long long naive = fibonacci_sum_naive(n);
        long long fast = fibonacci_sum_fast(n);
        cout << n << endl;
        cout << naive << endl;
        cout << fast << endl;
        if (naive != fast)
            break;
        else
            cout << "OK\n";
    }
}

int main() {

    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << std::endl;
    std::cout << fibonacci_sum_fast(n) << std::endl;

    //test();
}
