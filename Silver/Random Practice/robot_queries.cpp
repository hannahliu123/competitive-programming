// D. Robot Queries - R1900

// Start: 8:17
// Idea: 8:41       24 mins for idea, 27 mins for confirmation, implementation, and debugging
// End: 9:08        51 mins total

// YIPPEE!!!!!! hehehehe so happy :)))) yuhh and the editorial is the same idea. i
// really like my thought process i went thru when solving this one. i def don't think
// this deseres a R1900 tho, but it was from 3 yrs ago soooo. oh okay so we actually
// didn't need the suffix array, but the idea is still the same. what i could've done 
// instead is just noticed that we can rewrite the ending position after any operation
// i within [l,r] as the original position at l-1 plus the change in position from i
// to r (still using prefixes). So, that would be pos[l-1] + pos[r] - pos[i-1] = (x,y).
// now to check if some (x,y) exists, we can instead transform the equation to:
// pos[i-1] = pos[l-1] + pos[r] - (x,y) then check if some index i exists within the
// range [l,r]

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    string s; cin >> s;

    vector<pair<int,int>> pref(N+1, {0,0});
    map<pair<int,int>, set<int>> pcnt{};
    pcnt[{0,0}] = {0};
    for (int i=1; i <= N; i++) {
        pref[i] = pref[i-1];
        if (s[i-1]=='R') pref[i].first++;
        else if (s[i-1]=='L') pref[i].first--;
        else if (s[i-1]=='U') pref[i].second++;
        else if (s[i-1]=='D') pref[i].second--;
        pcnt[pref[i]].insert(i);
    }
    vector<pair<int,int>> suff(N+2, {0,0});
    map<pair<int,int>, set<int>> scnt{};
    for (int i=N; i >= 1; i--) {
        suff[i] = suff[i+1];
        if (s[i-1]=='R') suff[i].first++;
        else if (s[i-1]=='L') suff[i].first--;
        else if (s[i-1]=='U') suff[i].second++;
        else if (s[i-1]=='D') suff[i].second--;
        scnt[suff[i]].insert(i);
    }

    while (Q--) {
        int x, y, l, r; cin >> x >> y >> l >> r;
        pair<int,int> ptarget = {x,y};
        pair<int,int> starget = {x+suff[r+1].first-pref[l-1].first, y+suff[r+1].second-pref[l-1].second};
        bool pos = false;
        if (!pcnt[ptarget].empty()) {
            int idx1 = *(pcnt[ptarget].begin());
            if (idx1 < l) pos = true;
            int idx2 = *(--(pcnt[ptarget].end()));
            if (idx2 > r) pos = true;
        } if (!scnt[starget].empty()) {
            auto it = scnt[starget].lower_bound(l);
            if (it!=scnt[starget].end() && *it <= r) pos = true;
        }

        cout << (pos? "YES\n" : "NO\n");
    }
}