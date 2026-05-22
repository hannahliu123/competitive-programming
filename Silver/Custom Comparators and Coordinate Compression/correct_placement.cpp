// CF - E. Correct Placement - R1700

// Start: 9:50
// End: 10:19       29 mins

// ehehe i like my code even better than the editorial lol bc i made that greedy
// decision to just min and max so we only need to match up the mins and maxes

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;

        vector<vector<int>> f(N);   // min(h,w), max(h,w), index (1-indexed)
        for (int i=0; i < N; i++) {
            int h, w;
            cin >> h >> w;
            f[i] = {min(h,w), max(h,w), i+1};
        } sort(f.begin(), f.end());

        vector<pair<int,int>> pref(N);    // prefix min, index (1-indexed)
        pref[0] = {f[0][1], f[0][2]};
        for (int i=1; i < N; i++) {
            pref[i] = pref[i-1];
            if (f[i][1] < pref[i].first) {
                pref[i] = {f[i][1], f[i][2]};
            }
        }

        vector<int> ans(N, -1);
        for (int i=0; i < N; i++) {
            // find index of first friend with lower [0]
            vector<int> target = {f[i][0], 0, 0};
            int idx = lower_bound(f.begin(), f.end(), target) - f.begin();
            if (--idx >= 0) {
                int mn = pref[idx].first;
                if (mn < f[i][1]) ans[f[i][2]-1] = pref[idx].second;
            }
        }

        for (auto& i : ans) cout << i << ' ';
        cout << endl;
    }
}
