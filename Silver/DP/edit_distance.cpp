// CSES Problem Set - Edit Distance

// The key here is to have the dp grid track the edit distance from the first i
// characters in the first word to the first j characters in the second word. To
// do this, there are 3 ways you can determine the minimum edit distance.
// 1. The answer directly above +1 because that's the minimum edit distance from
// the first i-1 characters of the first word (so one less than the current) to
// the first j characters of the second word (same as the current). As a result,
// now that we have one more character from the first word, we can just remove it
// (which takes one more "move") then do whatever we did to get to that prev answer
// 2. The answer directly to the left +1 because that's the min edit distanct from
// the first i characters of the first word (same as current) to the first j-1 
/// characters of the second word (one less than current). Thus, now that me have 
// one extra character in the second word, we can add that character to however
// we got the previous combination. 
// 3. The answer diagonal (top left) to the current word +1 or +0. The answer
// diagonal is the min edit distanct from the first i-1 chars and j-1 chars, meaning
// now we need to match the newly added ith and jth letters. If they are different,
// we need to replace one of them (so +1), but if they're the same, we dont need to
// do anything (so +0).

// Notice that these steps are literally just simulating removing a letter, adding
// a letter, or replacing a letter

// We also need to initialize the boundaries because we are checking values above,
// to the left, and most importantly, diagonally.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    int N = A.length(), M = B.length();

    vector<vector<int>> dp(N+1, vector<int>(M+1, 1e9));
    dp[0][0] = 0;
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=M; j++) {
            if (i>0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
            if (j>0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            if (i>0 && j>0) {
                bool same = A[i-1]==B[j-1];
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(same? 0 : 1));
            }
        }
    }

    cout << dp[N][M] << endl;
}
