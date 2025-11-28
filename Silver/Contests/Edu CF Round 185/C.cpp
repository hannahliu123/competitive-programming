// Problem C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        long long K;
        cin >> N >> K;

        vector<int> q(N);
        vector<int> r(N);
        for (auto& i : q) cin >> i;
        for (auto& i : r) cin >> i;
        sort(q.begin(), q.end());       // l -> g
        sort(r.begin(), r.end());

        int ans = 0, qi = N-1;
        for (int i{0}; i < N; ++i) {    // for each remainder
            long long y = r[i]+1;
            if (y >= K) break;
            long long x = q[qi--]*y + r[i];
            while (qi >= 0 && x > K) x = q[qi--]*y + r[i];
            if (x <= K) ans++;
            if (qi < 0) break;
        }

        cout << ans << endl;
    }
}
