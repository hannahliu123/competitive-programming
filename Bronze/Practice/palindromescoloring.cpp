// CF - Palindromes Coloring - 1624D - R1400

// Start: 8:16
// End: 8:51        35 mins

// hehe im so very incredibly proud of this one :D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;   // string length & number of colors
        string s;
        cin >> n >> k >> s;

        vector<bool> pairs(26);
        int pair{0};
        for (int i{0}; i < n; ++i) {
            if (pairs[s[i]-'a']) {
                pair++;
                pairs[s[i]-'a'] = 0;
            } else pairs[s[i]-'a'] = 1;
        }

        int p = pair/k;     // num of pairs each k gets
        int ans{2*p};   // max length of shortest palindrome
        int remain = n-(2*k*p);
        if (remain >= k) ans++;

        cout << ans << '\n';
    }
}
