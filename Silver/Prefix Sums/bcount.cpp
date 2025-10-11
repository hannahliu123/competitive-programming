// USACO 2015 December Contest, Silver
// Problem 3. Breed Counting                        Level: Very Easy

// Start: 6:49
// End: 7:04        15 mins

// I'm still finding the indexes kinda confusing, so I have to like draw out a table
// before I know what im actually doing & implementing

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> pref(N+1, vector<int>(3));  // pref[3][0] - Holsteins from 0-2
    for (int i{1}; i <= N; ++i) {
        int x;
        cin >> x;   // 1, 2, or 3
        pref[i] = pref[i-1];
        pref[i][--x]++;     // 0-index
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;
        int h = pref[r][0]-pref[l-1][0];
        int g = pref[r][1]-pref[l-1][1];
        int j = pref[r][2]-pref[l-1][2];
        cout << h << ' ' << g << ' ' << j << '\n';
    }
}
