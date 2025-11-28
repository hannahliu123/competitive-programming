// Problem D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, Q;
        string s;
        cin >> N >> Q >> s;

        int total = 0;
        int tot = 0, DS = 0, HSi = 0, HSxv = 0, HS = 0;   // double spaces, half spaces
        int chain = 1;
        for (int i{0}; i < N; ++i) {
            if (s[i] == '?') {
                tot++;
                if (i > 0 && s[i-1] == '?') chain++;
                else if ((i > 0 && s[i-1] == 'I') && (i+1 < N && (s[i+1] == 'X' || s[i+1] == 'V'))) HS++;
                else if (i > 0 && s[i-1] == 'I') HSxv++;
                else if (i+1 < N && (s[i+1] == 'X' || s[i+1] == 'V')) HSi++;
                if (i+1 < N && s[i+1] != '?') {
                    DS += chain/2;
                    chain = 1;
                } else if (i == N-1) {
                    DS += chain/2;
                }
            } else {
                if (s[i] == 'X') total += 10;
                else if (s[i] == 'V') total += 5;
                else if (i+1 < N && (s[i+1] == 'X' || s[i+1] == 'V')) total -= 1;
                else total += 1;
            }
        }

        while (Q--) {
            int ans = total;
            int x, v, i;
            cin >> x >> v >> i;
            i = min(i, tot);
            v = min(v, tot-i);
            x = min(x, tot-i-v);

            int DS1 = DS, HSi1 = HSi, HSxv1 = HSxv, HS1 = HS;
            for (int j{0}; j < x; ++j) {    // 10s
                ans += 10;
                if (HSxv1 > 0) {
                    ans -= 2;
                    HSxv1--;
                } else if (HS1 > 0) {
                    ans -= 2;
                    HS1--;
                } else if (DS1 > 0 && i > 0) {
                    ans--;
                    DS1--;
                    i--;
                }
            } for (int j{0}; j < v; ++j) {    // 5s
                ans += 5;
                if (HSxv1 > 0) {
                    ans -= 2;
                    HSxv1--;
                } else if (HS1 > 0) {
                    ans -= 2;
                    HS1--;
                } else if (DS1 > 0 && i > 0) {
                    ans--;
                    DS1--;
                    i--;
                }
            } for (int j{0}; j < i; ++j) {    // 1s or -1s
                if (HSi1 > 0) {
                    ans--;
                    HSi1--;
                } else if (HS1 > 0) {
                    ans--;
                    HS1--;
                } else ans++;
            }

            cout << ans << endl;
        }
    }
}
