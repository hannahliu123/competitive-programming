// CF - D. Two Digit Strings - R1600

// bro im so done how did i forget about freaking prefix sum arrays. but even then, i
// was stuck because i thought we have to construct the answer using the pref sum
// array someone from like beginning to end and maybe using suffix sums too then it got
// complicated and my brain started giving out on me. in reality, i could've noticed how
// the numbers in the pref sum array need to match up and each time we combine a pair of
// numbers i and i+1, we just delete the prefix sum value ending at i. so essentially this
// gets reduced down to finding the lcs of the pref sum arrays which i learned with dp

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        int NA = a.size(), NB = b.size();

        vector<int> pa(NA+1, 0);
        for (int i=0; i < NA; i++) {
            int x = a[i] - '0';
            pa[i+1] = (pa[i] + x) % 10;
        }
        vector<int> pb(NB+1, 0);
        for (int i=0; i < NB; i++) {
            int x = b[i] - '0';
            pb[i+1] = (pb[i] + x) % 10;
        }

        if (pa[NA] != pb[NB]) { // we can't delete the last pref values
            cout << -1 << '\n';
            continue;
        }

        vector<vector<int>> dp(NA+1, vector<int>(NB+1,0));
        for (int i=1; i <= NA; i++) {
            for (int j=1; j <= NB; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (pa[i] == pb[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }

        cout << dp[NA][NB] << '\n';
    }
}