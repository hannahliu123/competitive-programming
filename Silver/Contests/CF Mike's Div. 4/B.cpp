#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        string s; cin >> s;

        char curr = 'R';
        int ans = 0;
        for (int i=0; i < N; i++) {
            if (s[i] != curr) {
                ans++;
            } else {
                if (curr=='R') curr='B';
                else curr='R';
            }
        }

        cout << ans << '\n';
    }
}