// Leetcode - 1143. Longest Common Subsequence

// ew you dont need to get input?!!?! ew its like a function 

#include <bits/stdc++.h>
using namespace std;

int main() {
    string text1, text2;
    cin >> text1 >> text2;

    int N = text1.length(), M = text2.length();
    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    for (int i=1; i <= N; i++) {
        for (int j=1; j <= M; j++) {
            if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[N][M] << endl;
    return dp[N][M];
}
