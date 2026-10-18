// CSES Problem Set - Book Shop

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    vector<int> cost(N);
    for (auto& i : cost) cin >> i;
    vector<int> val(N);
    for (auto& i : val) cin >> i;

    vector<vector<int>> dp(N+1, vector<int>(X+1, 0));
    // dp[i][j] = max val given first i items and a max cost of j
    for (int i=1; i <= N; i++) {
        for (int j=1; j <= X; j++) {
            dp[i][j] = dp[i-1][j];  // default: skip book i
            // note how we don't need dp[i][j-1] (but you could include it if you wanted
            // to because just these two decisions are sufficient. At each step, you only
            // need to decide if you want to buy the ith book or not
            if (j-cost[i-1] >= 0) dp[i][j] = max(dp[i][j], val[i-1]+dp[i-1][j-cost[i-1]]);
        }
    }

    cout << dp[N][X] << '\n';
}