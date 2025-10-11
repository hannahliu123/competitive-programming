// CF - C. Maximum Median - R1400

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> a{};

bool check(long long x) {
    // Check if x is a valid median value by looping through a one by one (starting
    // from the middle point because the first half doesn't matter)
    long long needed{0};    // i hate long longs :D
    for (int i{N/2}; i < N; ++i) {
        needed += max(0LL, x - a[i]);   // if a[i] is larger than target median
        // convert 0 to LL or else the stupid thing doesn't work >:(
    }

    return needed <= K;
}

int main() {
    cin >> N >> K;
    a.resize(N);
    for (auto& i : a) cin >> i;

    sort(a.begin(), a.end());

    // Check all possible median values to see if it is valid. Select the largest
    // possible median value using binary search for improved efficency.
    int lo{a[N/2]}, hi{2000000000};
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1)/2;     // round up (+1)
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << endl;
}
