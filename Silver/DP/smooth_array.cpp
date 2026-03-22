// G. Mukhammadali and the Smooth Array - R1600

// I just needed to frame the problem as "find a non-decreasing subsequence
// with the maxmimum cost". The final answer is the total cost - maximum cost

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> c(N);
        for (auto& i : c) cin >> i;

        vector<long long> dp(N);
        long long cost = 0;
        long long mx = 0;
        for (int i{0}; i < N; i++) {
            cost += (long long)c[i];
            dp[i] = c[i];
            for (int j{0}; j < i; j++) {
                if (a[i] >= a[j]) dp[i] = max(dp[i], dp[j]+c[i]);
            }
            mx = max(mx, dp[i]);
        }

        cout << cost-mx << endl;
    }
}
