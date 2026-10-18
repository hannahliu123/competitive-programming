// CSES Problem Set - Removing Digits

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> dp(N+1, 1e9);
    dp[0] = 0;
    for (int i=1; i <= N; i++) {
        int x = i;
        while (x > 0) {
            int digit = x % 10;
            dp[i] = min(dp[i], dp[i-digit]+1);
            x /= 10;
        }
    }

    cout << dp[N] << '\n';
}