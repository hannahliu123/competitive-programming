// CF - C. Covered Points Count - R1x00

// Start: 11:44
// End: 12:24       40 mins

// okay this problem was very straight-forward logic wise, but the implementation
// and indexing really tripped me up. Obviously, it was a coordinate compression and
// difference array problem, but i havent implemented coord comp in soooo long and i 
// jumped into implementation too quickly. i shouldve structured my work on paper
// better. bro tell me how i got literally every single error (WA, tle, runtine) lol.
// okay so basically first i store all indexes (normal without compression) in seg
// (for segments) and then i sort it use it to fill out a difference array (where i
// keep track of the original index in the second value of the pair).

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<pair<long long,int>> seg;
    for (int i=0; i < N; i++) {
        long long x, y; cin >> x >> y;
        seg.push_back({x,1});
        seg.push_back({y+1,-1});
    } sort(seg.begin(), seg.end());

    int idx = 0;
    vector<pair<int,long long>> diff{}; // difference array {running diff value, real index}
    for (int i=0; i < 2*N; i++) {
        if (i>0 && seg[i].first > seg[i-1].first) idx++;

        if (idx+1 > diff.size()) diff.push_back({seg[i].second, seg[i].first});
        else diff[idx].first += seg[i].second;
    } for (int i=1; i < diff.size(); i++) {
        diff[i].first += diff[i-1].first;
    }

    vector<long long> ans(N+1, 0);
    for (int i=0; i < diff.size()-1; i++) {
        ans[diff[i].first] += diff[i+1].second-diff[i].second;
    } for (int i=1; i <= N; i++) {
        cout << ans[i] << ' ';
    } cout << endl;
}
