// USACO 2018 January Contest, Silver
// Problem 1. Lifeguards

// Start: 1:11
// End: 2:08        57 mins

// achhh my implementation was so bad and it took me forever to figure out indexing. i
// think i had a lot of unnecessary code, so im gonna take a look at the editorial
// implementation. 

// so my idea of subtracting the minimum time any cow spends working alone from the total
// original time is correct, but there are much easier ways to do that. one way is by
// keeping a set of all the cows currently working. when the size of that set is 1, we
// know there is only one cow working alone

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int N; cin >> N;

    vector<pair<int,int>> shifts{};
    vector<pair<int,int>> pairs{};
    for (int i=0; i < N; i++) {
        int l, r; cin >> l >> r;
        shifts.push_back({l,1});
        shifts.push_back({r,-1});
        pairs.push_back({l,r});
    } sort(shifts.begin(), shifts.end());

    vector<pair<int,int>> diff{};   // {diff, orig}
    int idx = 0;
    for (int i=0; i < 2*N; i++) {
        if (i>0 && shifts[i].first > shifts[i-1].first) idx++;

        if (idx+1 > diff.size()) diff.push_back({shifts[i].second, shifts[i].first});
        else diff[idx].first += shifts[i].second;
    } for (int i=1; i < diff.size(); i++) {
        diff[i].first += diff[i-1].first;
    }

    vector<int> pref(diff.size(), 0);
    for (int i=1; i < pref.size(); i++) {
        pref[i] = pref[i-1];
        if (diff[i-1].first == 1) pref[i] += diff[i].second - diff[i-1].second;
    }

    int total = 0;  // original hours covered
    int start = diff[0].second;
    for (int i=0; i < diff.size(); i++) {
        if (diff[i].first == 0) {
            total += diff[i].second - start;
            if (i+1 < diff.size()) start = diff[i+1].second;
        }
    }

    int ans = 0;    // max time covered once 1 is fired
    for (auto p : pairs) {
        int l = p.first, r = p.second;
        int li = lower_bound(diff.begin(), diff.end(), make_pair(0, l), [](auto& a, auto& b) {
            return a.second < b.second;
        }) - diff.begin();
        int ri = lower_bound(diff.begin(), diff.end(), make_pair(0, r), [](auto& a, auto& b) {
            return a.second < b.second;
        }) - diff.begin();
        int x = total - (pref[ri]-pref[li]);
        ans = max(ans, x);
    }

    cout << ans << endl;
}
