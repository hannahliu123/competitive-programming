// CF - C. Cellular Network - R1500

// Start: 10:25
// End: 10:50       25 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    vector<int> b(M);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    int r{0};
    for (int i{0}; i < N; ++i) {
        auto tower_bef = (lower_bound(b.begin(), b.end(), a[i]));
        if ((*tower_bef > a[i] && b[0] != *tower_bef) || tower_bef == b.end()) tower_bef--;
        auto tower_afr = upper_bound(b.begin(), b.end(), a[i]);
        if (tower_afr != b.end() && tower_bef != tower_afr) {
            int min_dist = min(a[i] - *tower_bef, *tower_afr - a[i]);
            r = max(r, min_dist);
        } else if (tower_bef == tower_afr) {
            r = max(r, *tower_afr - a[i]);
        } else r = max(r, a[i] - *tower_bef);
    }

    cout << r << endl;
}
