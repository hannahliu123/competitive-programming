// CSES - Factory Machines - https://cses.fi/problemset/task/1620

// Start: 1:05
// End: 1:43        38 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long P;
    cin >> N >> P;

    vector<int> times(N);
    for (auto& t : times) cin >> t;

    // binary search on the lowest time required
    long long lo{1}, hi{1000000000000000000};
    while (lo < hi) {
        long long mid = lo + (hi - lo)/2;
        long long products{0};
        for (int i{0}; i < N; ++i) {
            products += mid/times[i];
            if (products >= P) break;
        }

        if (products >= P) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
}
