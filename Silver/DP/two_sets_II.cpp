// CSES Problem Set - Two Sets II

// ugh i hate problems with mod and i thought i would need to compute the modular inverse
// of 2 in order to divide the final answer by 2 because right now the dp algorithm computes
// the total number of ways to arrange the N items into groups of the right sum. However,
// because we are splitting the arrays in half/half, the true answer is half that. But
// instead of computing modular inverses, you can actually just use dp[N-1][sum] instead
// of dp[N][sum]. Why? well think of it like generating a left and right partition such
// that both sum up to sum. If we only consider numbers up to N-1, we are essentially always
// puting item N into, say, the right partition. Thus, all groups with number NOT including
// N will be put into the left partition. After all, in all partitions (left & right), N
// has to appear somewhere. Thus, but not including N, we no longer double count!

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1e9 + 7;

int main() {
    int N; cin >> N;
    int sum = N*(N+1)/2;
    if (sum%2==1) {
        cout << 0 << '\n';
        return 0;
    }

    sum /= 2;
    vector<vector<ll>> dp(N+1, vector<ll>(sum+1, 0));
    // dp[i][j] = # ways to make j using the first i items
    dp[0][0] = 1;
    for (int i=1; i <= N; i++) {
        for (int j=0; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-i >= 0) dp[i][j] = (dp[i][j]+dp[i-1][j-i])%MOD;
        }
    }

    cout << dp[N-1][sum] << '\n';
}