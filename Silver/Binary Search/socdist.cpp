// USACO 2020 US Open Contest, Silver
// Problem 1. Social Distancing

// Start: 2:18
// End: 3:02        44 mins

// just some implementation issues at the end. also i didnt realize the grass
// array wasnt given to you sorted :(

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int N, M; cin >> N >> M;
    vector<pair<long long,long long>> grass(M);
    for (auto& i : grass) cin >> i.first >> i.second;
    sort(grass.begin(), grass.end());

    // binary search on D
    long long mn = grass[0].first, mx = grass[M-1].second;   // min & max position
    long long hi = 1e18, lo = 1;
    while (lo < hi) {
        long long mid = (hi+lo+1)/2;

        int idx = 0;
        long long pos = mn;
        bool possible = true;
        
        for (int c = 0; c < N; c++) {
            if (pos > mx) {
                possible = false;
                break;
            }

            while (pos > grass[idx].second) {
                idx++;
            } pos = max(pos, grass[idx].first);

            pos += mid;
        }

        if (possible) lo = mid;
        else hi = mid-1;
    }

    cout << lo << endl;
}
