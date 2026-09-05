#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        string s; cin >> s;
        int ans = 0;
        for (int i=0; i < N; i+=K) {
            bool john = false;
            for (int j=0; j < K; j++) {
                if (s[i+j]=='0') {
                    john = true; break;
                }
            }
            if (!john) ans++;
        }

        cout << ans << '\n';
    }
}