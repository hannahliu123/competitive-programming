// USACO 2026 First Contest, Silver
// Problem 2. Mooclear Reactor

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, M; cin >> N >> M;
        vector<int> l(N);
        for (auto& i : l) cin >> i;
        vector<int> r(N);
        for (auto& i : r) cin >> i;

        for (int i{0}; i < M; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            x--; y--;
            // a[x] + a[y] = z
            ;
        }
    }
}
