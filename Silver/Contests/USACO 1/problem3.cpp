// USACO 2026 First Contest, Silver
// Problem 3. Sliding Window Summation

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        string s; cin >> s;
        
        int mn = 0;
        int end = -1;
        for (int i{0}; i < s.length(); ++i) {
            if (s[i] == '1') {
                if (end < i) {
                    mn++;
                    end = i+K-1;
                }
            } else if (end < i) {   // s[i] == 0
                end = i;
            }
        }
        
        int mx = N;
        end = -1;
        for (int i{0}; i < s.length(); ++i) {
            if (s[i] == '1') {  // odd
                if (K%2 == 0) {
                    if (end < i) {  // remove a 1
                        mx--;
                        end = i+K-1;
                    }
                } else if (end >= i) {
                    end = i;
                }
            } else {    // s[i] == 0
                if (K%2 == 1) {
                    if (end < i) {  // remove a 1
                        mx--;
                        end = i+K-1;
                    }
                } else if (end >= i) {
                    end = i;
                }
            }
        }

        cout << mn << ' ' << mx << '\n';
    }
}
