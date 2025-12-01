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
        int freeHS = 0, chainHS = 0;
        int chain = 0;
        for (int i{0}; i < N; ++i) {
            if (s[i] == '?') {
                tot++; chain++;
                bool hsxv = (i > 0 && s[i-1] == 'I');
                bool hsi = (i+1 < N && (s[i+1] == 'X' || s[i+1] == 'V'));
                if (hsxv && hsi) HS++;
                else if (hsxv) HSxv++;
                else if (hsi) HSi++;
                if (chain == 1 && hsxv) {   // start of chain & HS
                    chainHS++;
                } if ((i+1 < N && s[i+1] != '?') || i == N-1) {   // end of chain
                    if (hsi) chainHS++; // HS
                    if (chainHS > 0 && chain % 2 == 1) freeHS++;
                    DS += chain/2;
                    chain = 0;
                    chainHS = 0;
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
            
            int HSi1 = HSi, HSxv1 = HSxv, HS1 = HS;
            int HSused = 0, unusedXV = 0, unusedI = 0;
            for (int j{0}; j < x; ++j) {    // 10s
                ans += 10;
                if (HSxv1 > 0) {
                    ans -= 2;
                    HSxv1--;
                    HSused++;
                } else if (HS1 > 0) {
                    ans -= 2;
                    HS1--;
                    HSused++;
                } else unusedXV++;
            } for (int j{0}; j < v; ++j) {    // 5s
                ans += 5;
                if (HSxv1 > 0) {
                    ans -= 2;
                    HSxv1--;
                    HSused++;
                } else if (HS1 > 0) {
                    ans -= 2;
                    HS1--;
                    HSused++;
                } else unusedXV++;
            } for (int j{0}; j < i; ++j) {    // 1s or -1s
                if (HSi1 > 0) {
                    ans--;
                    HSi1--;
                    HSused++;
                } else if (HS1 > 0) {
                    ans--;
                    HS1--;
                    HSused++;
                } else {
                    ans++;
                    unusedI++;
                }
            }
            
            int DS1 = DS;
            if (HSused > freeHS) {
                DS1 -= ((HSused-freeHS) + 1) / 2;   // round up
            }
            int use = min({DS1, unusedI, unusedXV});
            ans -= (2*use);

            cout << ans << endl;
        }
    }
}
