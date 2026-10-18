// C. The Values You Can Make - R1900

// woah this was my first time doing a 3D dp and im lowkey surprised it wasn't even
// close to surpassing the memory constraints. it makes sense tho because c++ vector
// of bools is optimized to take up very little memory. this solution i implemented
// is very similar to the cf editorial except the editorial goes one step further and
// optimizes the array to be of size [2][K][K] instead of [N][K][K] because 
// technically only ever access dp[i-1] but that's lowkey overkill and if i tried
// that i think i would fs mess smthing up. 

// okay but the usaco editorial does something kinda different where dp[i][j] is
// true if it's possible to select a group of coins such that a subset of them sum
// to i (Arya's subset) and the rest of them in the group sum to j. This way, the
// total sum of coins will be i+j, and we're interested in how many i exist (different
// sums Arya can acheive in her subset) when i+j=k. We technically need 3D dp again
// and have dp[k][i][j], but in the implementation we can just keep track of a 2D dp
// and then a previous 2D dp because once again we only need dp[i-] (just an
// optimization). im lowkey too lazy to do this tho so wtv :)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> c(N);
    for (auto& i : c) cin >> i;

    vector<vector<vector<bool>>> dp(N+1, vector<vector<bool>>(K+1, vector<bool>(K+1, false)));
    dp[0][0][0] = true;
    // dp[i][j][k] = true if arya can make a sum of k using coins that sum up to j out of
    // the first i coins
    for (int i=1; i <= N; i++) {
        for (int j=0; j <= K; j++) {
            for (int k=0; k <= K; k++) {
                if (dp[i-1][j][k]) dp[i][j][k] = true;    // had one less coin
                if (j-c[i-1]>=0 && dp[i-1][j-c[i-1]][k]) {
                    // use coin c[i-1] to make sum j
                    dp[i][j][k] = true;
                    if (k+c[i-1] <= K) dp[i][j][k+c[i-1]] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i=0; i <= K; i++) {
        if (dp[N][K][i]) ans++;
    } cout << ans << '\n';
    for (int i=0; i <= K; i++) {
        if (dp[N][K][i]) cout << i << ' ';
    } cout << '\n';
}