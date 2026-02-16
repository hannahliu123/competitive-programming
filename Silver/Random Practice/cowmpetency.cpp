// USACO 2024 January Contest, Silver
// Problem 1. Cowmpetency

// for this problem i still just dont have a good idea. like im leaning towards
// something with a prefix max array but idk how we can dynamically update that
// over each iteration, and then also when you update the value of one index,
// that affects the other ones too, so i thought if we could store the potential
// updates then apply them all in one go that might work? but no it doesntttt (i
// think) so uh. then i thought we could keep a running max as well but its not
// enoughghghghghgh. sigh editorial time

// oh and also this is p bad cos idek how to get the lower subtasks. i know those
// are just brute force, but like how do i even implement an N^2 solution?

// Okay so this problem on its own is very confusing and it has a lot of edge
// cases and unique aspects. FJ knows a set number of scores and also has some
// constraints and wants the lexicographically smallest set of cowpentency scores.
// the constraints mean that say the maximum from 1-a is M_a and the max from a to
// h is M_b and the value at h is h. all values from 1 to h have to be strictly
// less than h and M_b has to be less than or equal to M_a or else h wouldn't be the
// first index with a larger value. 

// okay so for starters, we need to realize under what conditions the scores are 
// impossible. No sequence of scores can be formed if there is any form of overlap
// (a,h contained within another a,h or a/h within another a,h). This is because if
// they were completely contained and the h's weren't the same, that is impossible.
// but if the h's were the same, then it's fine except the one with the later a is
// irrelevant (they mean the same thing except the earlier a provides more of a 
// constraint). Using this same logic, an a can't be contained within another a,h
// because its h should then be the earlier h. 

// once we know the scores are possible and we get rid of any redundant a,h pairs,
// we need to greedily reconstruct the scores based on the constraints. we know
// that all constraints are separate form eachother, but changing a value in an 
// earlier a,h pair can affect later values. as a result, when we assign scores, we
// need to assign from left to right. but in order to even do that, we need to keep
// track of maximums within the intervals a to h because we need to make sure 0-a
// contains that number and h is larger than the max. If the interval from 0-a
// doesn't yet contain that value, we want to set the latest possible value to equal
// that value and all others to equal 1. 

// HOLY MOOOOLY THIS TOOK ME WAY TOO LONG AEIUALOIUELAJSFL. okay so there's just sm
// stuff you need to keep track of im honestly shocked it even worked. i didn't 
// realize we also still needed the prefMx array cos i thought we could just keep
// a running count but i didnt account for the situation if there's a cow afterwards
// that has a higher score so you dont need to update the cow right now.

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("cowmpetency.out", "w", stdout);

    int t; cin >> t;
    while (t--) {
        int N, Q, C;
        cin >> N >> Q >> C;

        vector<int> c(N);
        for (auto& i : c) cin >> i;

        vector<pair<int,int>> q(Q);
        for (int i{0}; i < Q; ++i) {
            cin >> q[i].first >> q[i].second;
            q[i].first--; q[i].second--;
        }

        vector<pair<int,int>> clean{};     // contraints
        sort(q.begin(), q.end());   // l -> g
        bool pos = true;
        for (auto [a, h] : q) {
            if (clean.empty()) {
                clean.push_back({a,h});
                continue;
            }
            auto [pa, ph] = clean.back();   // prev
            if (a < ph) {
                if (h != ph) {
                    pos = false;
                    break;
                }
            } else clean.push_back({a,h});
        }

        if (!pos) {
            cout << -1 << endl;
            continue;
        }

        // keep track of maximums between a,h for each constraint
        vector<int> mx(clean.size(), 1);
        int idx = 0;    // index of contraint
        for (int i{0}; i < N; ++i) {
            auto [a,h] = clean[idx];    // current constraint
            if (i >= h && idx < clean.size()-1) {    // next constraint
                a = clean[++idx].first;
                h = clean[idx].second;
            } else if (i >= h) continue;

            if (i > a) {
                mx[idx] = max(mx[idx], c[i]);
            }
        }

        idx = 0;
        // keep track of last 0 at or before a for each constraint
        vector<int> last0(clean.size(), -1);
        vector<int> prefMx(N, c[0]);
        for (int i{0}; i < N; ++i) {
            auto [a,h] = clean[idx];    // current constraint
            if (i >= h && idx < clean.size()-1) {    // next constraint
                a = clean[++idx].first;
                h = clean[idx].second;
            } else if (i >= h) continue;

            if (idx > 0) last0[idx] = max(last0[idx], last0[idx-1]);
            if (c[i]==0 && i<=a) last0[idx] = i;

            if (i>0) prefMx[i] = max(prefMx[i-1], c[i]);
        }

        idx = 0;
        for (int i{0}; i < N; ++i) {
            auto [a,h] = clean[idx];    // current constraint
            if (i == h) {
                bool zero = c[i] == 0;
                if (zero) c[i] = prefMx[i-1]+1;
                if (idx < clean.size()-1) {
                    idx++;
                    a = clean[idx].first;
                    h = clean[idx].second;
                    if (zero && i == last0[idx] && prefMx[i-1] < mx[idx] && prefMx[a] < mx[idx]) {
                        c[i] = mx[idx];
                    }
                } if (c[i] <= prefMx[i-1]) {
                    pos = false;
                    break;
                }
            } else if (i == last0[idx] && prefMx[i-1] < mx[idx] && prefMx[a] < mx[idx]) {
                c[i] = mx[idx];
            } else if (c[i] == 0) c[i] = 1;

            if (i>0) prefMx[i] = max(prefMx[i], prefMx[i-1]);
            prefMx[i] = max(prefMx[i], c[i]);

            if (i == a && mx[idx] > prefMx[i]) {
                pos = false;
                break;
            }
        }

        if (!pos || prefMx.back() > C) cout << -1 << endl;
        else {
            for (int i{0}; i < N; ++i) cout << c[i] << (i<N-1? " " : "");
            cout << endl;
        }
    }
}
