// Atcoder Educational DP Contest - C - Vacation 

// Start: 8:38
// End: 9:07        29 mins

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> hap{};
vector<vector<int>> memo{};

int dp(int pos, int last){  // last: 0-A, 1-B, 2-C
    if (pos >= N) return 0;
    if (last != -1 && memo[pos][last] != -1) return memo[pos][last];

    int mx_hap{0};
    if (last != 0) mx_hap = max(mx_hap, dp(pos+1, 0)+hap[pos][0]);
    if (last != 1) mx_hap = max(mx_hap, dp(pos+1, 1)+hap[pos][1]);
    if (last != 2) mx_hap = max(mx_hap, dp(pos+1, 2)+hap[pos][2]);

    if (last != -1) memo[pos][last] = mx_hap;
    return mx_hap;
}

int main() {
    cin >> N;
    hap.resize(N, vector<int>(3));
    memo.resize(N, vector<int>(3));

    for (int i{0}; i < N; ++i) {
        cin >> hap[i][0] >> hap[i][1] >> hap[i][2];
        memo[i][0] = -1;
        memo[i][1] = -1;
        memo[i][2] = -1;
    }

    cout << dp(0, -1) << endl;
}
