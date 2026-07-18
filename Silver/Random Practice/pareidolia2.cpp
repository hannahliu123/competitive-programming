// USACO 2023 US Open Contest, Silver
// Problem 3. Pareidolia

// just implementation. ugh i need to remember to carry over the last e back to the first b
// cos those can start looking for another bessie following it. this is so confusing. i 
// hate anything that is complicated cos of indexing ughjdlkadjsfl avkdjtloirhtj li

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int N = S.length();

    vector<long long> dp(6, 0);   // number of substrings starting from each previous index that need the letter this index
    long long contr=0, ans = 0;
    for (int i=0; i < N; i++) {
        dp[0]++;    // always need a b if we start at this index

        if (S[i]=='b') {    // all substrings that needed b's need an e now
            dp[1]+=dp[0];
            dp[0]=0;
        } else if (S[i]=='e') {
            // finishing e
            contr += dp[5];
            dp[0] += dp[5];
            dp[5]=0;
            // first e
            dp[2]+=dp[1];
            dp[1]=0;
        } else if (S[i]=='s') {
            // 2nd s
            dp[4]+=dp[3];
            // 1st s
            dp[3]=dp[2];
            dp[2]=0;
        } else if (S[i]=='i') {
            dp[5]+=dp[4];
            dp[4]=0;
        }

        ans += contr;
    }

    cout << ans << endl;
}