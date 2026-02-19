// USACO 2025 February Contest, Silver
// Problem 3. Transforming Pairs

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long ans = -1;
        queue<pair<int, pair<long long,long long>>> q{};    // # spells, a, b
        q.push({0,{a,b}});
        while (!q.empty()) {
            auto [spells, p] = q.front();
            long long f = p.first, s = p.second;
            q.pop();
            
            if (f==c && s==d) {
                ans = spells;
                break;
            } if (f+s<=c && s<=d) q.push({spells+1, {f+s, s}});
            if (f<=c && s+f<=d) q.push({spells+1, {f, s+f}});
        }

        cout << ans << endl;
    }
}
