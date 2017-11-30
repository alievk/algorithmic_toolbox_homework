#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    vector<long long> period;
    period.push_back(0);
    period.push_back(1);

    //cout << 0 << " " << 1 << " ";

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;

        //cout << i + 2 << " " << current << " " << current % m << endl;

        period.push_back(current);

        if (period[period.size() - 2] == 0 && period[period.size() - 1] == 1) {
            period.resize(period.size() - 2); // cut off 01 at the back
            //cout << "period " << period.size() << endl;
            break; // end of period detected
        }
    }

/*
    for (auto p : period)
        cout << p << " ";
    cout << endl;
*/

    return period[n % period.size()];
}

void test() {
    while (true) {
        int n = rand() % 50;
        int m = rand() % 10;
        long long naive = get_fibonacci_huge_naive(n, m);
        long long fast = get_fibonacci_huge_fast(n, m);
        cout << n << " " << m << endl;
        cout << naive << " " << fast << endl;
        assert(naive == fast);
        cout << "OK\n";
    }
}

int main() {

    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    cout << get_fibonacci_huge_fast(n, m) << endl;

    //test();
}
