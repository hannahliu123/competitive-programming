// Bitwise DP - 10.5 CPH - Optimal Selection Implementation

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 3;  // number of products
    int D = 8;   // number of days

    vector<vector<int>> price = {
        {6, 9, 5, 2, 8, 9, 1, 6}, // Product 0
        {8, 2, 6, 2, 7, 5, 7, 2}, // Product 1
        {5, 3, 9, 7, 3, 5, 1, 4}  // Product 2
    };

    vector<vector<int>> dp(1<<N, vector<int>(D, 1e9));
    for (int i=0; i < N; i++) { // purchasing 1 item
        dp[1<<i][0] = price[i][0];
    } for (int d=0; d < D; d++) {
        if (d==0) { // purchasing no items
            dp[0][d] = 0;
            continue;
        }
        
        for (int s=1; s < 1<<N; s++) {
            dp[s][d] = dp[s][d-1];
            for (int i=0; i < N; i++) {
                if (s & (1<<i)) {   // item i is in set s
                    dp[s][d] = min(dp[s][d], dp[s^(1<<i)][d-1]+price[i][d]);
                }
            }
        }
    }

    cout << dp[(1<<N)-1][D-1] << endl;
}