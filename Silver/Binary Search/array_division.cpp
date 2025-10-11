// CSES - Array Division - https://cses.fi/problemset/task/1085

#include <bits/stdc++.h>
using namespace std;

long long N, K;
vector<long long> a{};

bool check(long long x) {
    // check how many subarrays are needed to split the array into subarrays 
    // each with a sum less than or equal to x. If more than K subarrays are
    // needed, then return false (x is too small)
    long long needed{1};
    long long sum{0};
    for (int i{0}; i < N; ++i) {    // loop through the entire array
        if (sum + a[i] > x) {   // need a new array to store next values
            needed++;
            sum = a[i];
        } else sum += a[i];
    }

    return needed <= K;
}

int main() {
    cin >> N >> K;
    a.resize(N);
    long long max_num{0};
    for (auto& i : a) {
        cin >> i;
        max_num = max(max_num, i);
    }

    // binary serach for the answer
    long long lo{max_num};
    long long hi{accumulate(a.begin(), a.end(), 0LL)};
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (check(mid)) {   // sum of items in subarrays is less than mid
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << hi << endl;
}
