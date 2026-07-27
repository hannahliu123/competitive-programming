// A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> w(N);
        for (auto& i : w) cin >> i;

        if (N%2==1) {
            cout << "NO\n";
            continue;
        }

        int hi = 1e9, lo = 1;
        for (int i=0; i < N-1; i+=2) {
            hi = min(hi, w[i]-1);
            lo = max(lo, w[i+1]+1);
            if (hi < lo) break;
        }

        if (hi < lo) cout << "NO\n";
        else cout << "YES\n";
    }
}