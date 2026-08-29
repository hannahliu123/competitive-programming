// D. Bermuda Rectangle - R1600

// Start: 8:27
// End: 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long S; int Q;
        cin >> S >> Q;

        // find factor pairs (up to sqrtS)
        vector<pair<int,int>> factors{};
        for (int i=1; (long long)i*i <= S; i++) {
            if (S%i==0) factors.push_back({i, S/i});
        }

        while (Q--) {
            int x, y; cin >> x >> y;
            int prev = 0;
            long long ans = 0;
            for (auto& p : factors) {
                if (x<p.first && y<p.first) break;
                pair<int,int> f1 = {min(x,p.first), min(y,p.second)};
                pair<int,int> f2 = {min(x,p.second), min(y,p.first)};
                f1 = {max(0,f1.first-prev), max(0,f1.second-prev)};
                f2 = {max(0,f2.first-prev), max(0,f2.second-prev)};
                int contr = (f1.first*f1.second) + (f2.first*f2.second) - (f1.first*f2.second);
                ans += max(0,contr);
                prev = p.first;
            }

            cout << ans << '\n';
        }
    }
}
