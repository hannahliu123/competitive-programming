// wow so this was 3d dp but you could've simplified the space complexity to just N^2
// because we only ever use dp[t-1] so we could track a current and previous dp array.
// i needed mroe practice with dp anyways so this was nice. floodfill (dfs) wouldn't
// have worked because you wont guarentee your score is maximized

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> grid(N+1, vector<int>(N+1));
    for (int i=1; i <= N; i++) {
        for (int j=1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<vector<int>>> dp(2*N, vector<vector<int>>(N+1, vector<int>(N+1, -1)));
    dp[0][1][1] = grid[1][1];
    for (int t=1; t <= 2*(N-1); t++) {
        for (int r1 = max(1,t-N+2); r1 < min(t+2,N+1); r1++) {
            int c1 = t-r1 +2;
            if (grid[r1][c1]==-1) continue;
            for (int r2 = max(1,t-N+2); r2 < min(t+2,N+1); r2++) {
                int c2 = t-r2 +2;
                if (grid[r2][c2]==-1) continue;

                int contr = grid[r1][c1] + grid[r2][c2];
                if (r1==r2 && c1==c2) contr /= 2;

                vector<int> options {dp[t-1][r1][r2], dp[t-1][r1-1][r2], dp[t-1][r1][r2-1], dp[t-1][r1-1][r2-1]};
                for (auto& i : options) {
                    if (i==-1) continue;
                    dp[t][r1][r2] = max(dp[t][r1][r2], i+contr);
                }
            }
        }
    }

    if (dp[2*(N-1)][N][N]==-1) cout << "0\n";
    else cout << dp[2*(N-1)][N][N] << '\n';
    return 0;
}