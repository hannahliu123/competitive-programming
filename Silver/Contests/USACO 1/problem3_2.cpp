// USACO 2026 First Contest, Silver
// Problem 3. Sliding Window Summation

// Start: 9:40
// End: 10:48       1 hr 8 mins!!!!

// wowsers! tbf though i watched a video editorial a while ago and still 
// remembered some of the ideas there. i understand this solution which im
// super happy abt, but it just took me a while to impelment and confirm 
// everything heh

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        string s; cin >> s;
        
        if (K==1) {
            int ans = 0;
            for (auto& i : s) {
                if (i=='1') ans++;
            } cout << ans << ' ' << ans << endl;
            continue;
        }

        vector<pair<int,int>> ones(K, {1,0});   // if u start with 1, if u start with 0
        for (int i{0}; i < K; ++i) {
            int last = 1;
            for (int j{i}; j < N-K; j+=K) {
                if (s[j]==s[j+1]) {
                    if (last == 1) ones[i].first++;
                    else ones[i].second++;
                } else {
                    if (last == 1) ones[i].second++;
                    else ones[i].first++;
                    last = (last+1)%2;
                }
            }
        }

        int mn=0, mx=0;
        int onesMx = 0, onesMn = 0, diff = 1e9;
        for (int i{0}; i < K; ++i) {
            if (ones[i].first > ones[i].second) {
                onesMx++;
                mx += ones[i].first;
                mn += ones[i].second;
            } else {
                onesMn++;
                mn += ones[i].first;
                mx += ones[i].second;
            }
            diff = min(diff, abs(ones[i].first-ones[i].second));
        }
        if (onesMx%2 != s[0]-'0') mx -= diff;
        if (onesMn%2 != s[0]-'0') mn += diff;

        cout << mn << ' ' << mx << '\n';
    }
}
