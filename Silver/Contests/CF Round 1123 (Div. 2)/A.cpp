#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; char c; string s;
        cin >> N >> c >> s;

        int ans = 0;
        int l=0, r=N-1;
        while (l < r) {
            if (s[l] != s[r]) {
                if (s[l]==c || s[r]==c) ans++;
                else ans += 2;
            }
            l++; r--;
        }

        cout << ans << '\n';
    }
}