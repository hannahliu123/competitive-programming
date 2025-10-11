// USACO 2016 January Contest, Silver
// Problem 2. Subsequences Summing to Sevens        Level: Easy

// Start: 7:06
// End: 7:24        18 mins

// Okay we cooked :) but i feel like i might not have gotten the idea if i didn't
// already know this was suppoused to use prefix sums.

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int N;
    cin >> N;

    vector<long long> pref(N+1);
    for (int i{0}; i < N; ++i) {
        int x;
        cin >> x;
        pref[i+1] = pref[i]+x;
    }
    
    int ans{0};
    for (int end{N}; end >= 1; --end) {
        for (int i{end}; i >= 1; --i) {
            long long z = pref[end]-pref[i-1];
            if ((pref[end]-pref[i-1]) % 7 == 0) {
                ans = max(ans, end-i+1);
            }
        }
    }

    cout << ans << endl;
}
