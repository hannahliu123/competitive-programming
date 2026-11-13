#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> h(N);
        for (auto& i : h) cin >> i;
        sort(h.begin(), h.end());
        int ans = 1;
        for (int i=1; i < N; i++) {
            if (h[i]==h[i-1]) {
                if (i==1 || h[i]!=h[i-2]) ans++;
            } else ans++;
        }

        cout << ans << '\n';
    }
}