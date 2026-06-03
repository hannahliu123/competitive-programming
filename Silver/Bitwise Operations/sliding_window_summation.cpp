// USACO 2026 First Contest, Silver
// Problem 3. Sliding Window Summation

// Start: 10:45
// End: 11:49       1 hr 4 mins

// HALLEJUAUYHAJAJHHHHH LETS GOO THANK YOU THANK YOU IDK WHO IM THANKKING BUT THAKN YOU.
// um okay so ive solved this problem a long time ago so i already kinda had an idea of how
// to approach this but it was very faint. it definitely did help tho

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        string r; cin >> r;

        if (K==1) {
            int ans = 0;
            for (auto& i : r) {
                if (i == '1') ans++;
            } cout << ans << ' ' << ans << '\n';
            continue;
        }

        vector<pair<int,int>> start(K, {0,0});
        for (int i=0; i < K; i++) {
            int a = 1, b = 0;
            int curr = 1;   // start with a 1
            for (int j=i; j < N-K; j += K) {
                if (r[j] == r[j+1]) {
                    if (curr==1) a++;
                    else b++;
                } else {
                    if (curr==1) b++;
                    else a++;
                    curr = 1-curr;
                }
            } start[i] = {a,b};
        }

        int mxans = 0, mnans = 0, mn_change = 1e9;   // total ones
        int mxones=0, mnones=0;   // in the first K indexes
        for (int i=0; i < K; i++) {
            if (start[i].first > start[i].second) {
                // start with a one on index i for max 1s
                mxones++;
                mxans += start[i].first;
                mnans += start[i].second;
            } else {
                // start with a one on index i for mn 1s
                mnones++;
                mxans += start[i].second;
                mnans += start[i].first;
            } mn_change = min(mn_change, abs(start[i].first-start[i].second));
        }

        if (mxones%2 != r[0]-'0') {
            mxans -= mn_change;
        } if (mnones%2 != r[0]-'0') {
            mnans += mn_change;
        }

        cout << mnans << ' ' << mxans << '\n';
    }
}