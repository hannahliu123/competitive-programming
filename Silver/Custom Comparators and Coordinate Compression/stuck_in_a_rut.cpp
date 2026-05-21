// USACO 2020 December Contest, Silver
// Problem 3. Stuck in a Rut

// Start: 8:23
// End: 9:22    59 mins

// OMG LOCKED IN!!! bro this was amazing except i didn't realize if(-1) evaluates to
// true but if(0) evaluates to false. omg im actually so proud of this problem hehehe
// let me cookkkkkk! 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<vector<int>> e{};    // x, y, cow ID
    vector<vector<int>> n{};
    for (int i=0; i < N; i++) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;
        if (dir == 'E') e.push_back({x, y, i});
        if (dir == 'N') n.push_back({x, y, i});
    }
    sort(e.begin(), e.end());
    sort(n.begin(), n.end());

    vector<int> stopped(N, 0);  // cows stopped by cow i
    set<int> stop{};    // all cow IDs that have been stopped
    for (auto& cn : n) { // left -> right
        int nstop = INT_MAX;    // y-value at which cn is stopped
        int cstop = -1;     // the cow that stops cn
        vector<vector<int>> mightStop{};    // y-value of intersect, cow ID
        for (auto& ce : e) {
            if (ce[0] > cn[0]) break;
            if (ce[1] < cn[1] || stop.count(ce[2])) continue;

            int ndist = ce[1]-cn[1];   // dist cn travels before intersect
            int edist = cn[0]-ce[0];
            if (ndist < edist) {    // n might stop e
                mightStop.push_back({ce[1], ce[2]});
            } else if (edist < ndist) { // e might stop n
                if (ce[1] < nstop) {
                    nstop = ce[1];
                    cstop = ce[2];
                }
            }
        }

        for (auto& ce : mightStop) {
            if (ce[0] < nstop) {    // ce is stopped by cn
                stop.insert(ce[1]);
                stopped[cn[2]] += 1+stopped[ce[1]];
            }
        }

        if (cstop != -1) {    // cn was stopped
            stopped[cstop] += 1+stopped[cn[2]];
        }
    }

    for (int i : stopped) {
        cout << i << '\n';
    }
}
