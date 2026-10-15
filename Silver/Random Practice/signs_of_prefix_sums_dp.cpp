// D. Signs of Prefix Sums - R1700 (dp implementation)

// let dp[i][j] = the answer (min max value) when the first i items have been placed and
// the current prefix sum of those i items equals j. It can be proven that -3<=j<=3 because
// if j==4, we could replace it with a value lower in magnitude in all situation (cos we
// only need to guarentee that j doesn't equal its neighbors and there are only 2 neighbors.
// So in the worst case senario, if j=4 and it's neighbors are 3 and 2, then we can set j=1
// and it'll still be positive; vice versa for negatives).

// Implementation wise, for each i in string s, we compare the values from dp[i-1] (previous
// iteration) to see which optimal state we can branch out from to minimize the current dp[i][j].
// for each dp[i], we check 1,2,3 if +, -1,-2,-3 if -, and 0 if 0. Based on the previous iteration,
// for each pref value j_0 we were able to reach in i-1 steps, we can reach the next value j by
// having an item of value j-j_0. So, we want to determine the closest j value to our target j
// values. Also the base case is dp[0][0] = 0 and everything else is infinity. But because we can't
// have negative indicies, dp[0][3] = 0 (where 0, 1, and 2 represent -3, -2, -1).

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        string s; cin >> s;

        vector<vector<int>> dp(N+1, vector<int>(7, INT_MAX));
        dp[0][3] = 0;
        for (int i=0; i < N; i++) { // fill in dp[i+1]
            for (int j=0; j < 7; j++) {
                if (dp[i][j] == INT_MAX) continue;  // wasn't used
                // fill in dp[i+1][l...r] based on dp[i][j]
                int l=0, r=6;
                if (s[i]=='+') l=4;
                else if (s[i]=='-') r=2;
                else { l=3; r=3; }
                for (int k=l; k <= r; k++) {
                    if (j==k) continue; // can't have the same prefix
                                                    // old max, new max
                    dp[i+1][k] = min(dp[i+1][k], max(dp[i][j], abs(k-j)));
                }
            }
        }

        int ans = *min_element(dp[N].begin(), dp[N].end());
        cout << (ans==INT_MAX? -1 : ans) << '\n';
    }
}