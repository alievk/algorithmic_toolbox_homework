#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int get_fibonacci_partial_sum_fast(long long from, long long to)
{
    vector<int> period{0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1};
    const int pn = period.size();

    vector<int> period_is(pn); // period inclusive sum
    period_is[0] = period[from % pn];
    for (int i = 1; i < pn; ++i) {
        period_is[i] = period_is[i - 1] + period[(from + i) % pn];
    }

    long long sum = ((to - from) / pn) * period_is.back() + period_is[(to - from) % pn];
    sum %= 10;

    return sum;
}

/*
void test()
{
    for (int n = 0; n <= 100000; ++n) {
        long long naive = get_fibonacci_partial_sum_naive(n);
        long long fast = get_fibonacci_partial_sum_naive(n);
        cout << n << endl;
        cout << naive << endl;
        cout << fast << endl;
        if (naive != fast)
            break;
        else
            cout << "OK\n";
    }
}
*/

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
