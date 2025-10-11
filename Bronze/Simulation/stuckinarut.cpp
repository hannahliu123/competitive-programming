// USACO 2020 December Contest, Bronze
// Problem 3. Stuck in a Rut

// Start: 3:08
// Break: 3:27-9:29       still on paper
// End: 10:24

// I give up this is too hard. I forgot to account for a suuuper important thing. Wait
// maybe i shouldn't give up. I feel like i give up too often. fine imma just try to
// cheese it w/ simulation and get like the first 5 test cases.

// NEW Start: 11:04
// NEW End: 11:33

// right so imma go to bed. uhh im not really getting anywhere. I really need to 
// practice this more...

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;      // N <= 50
    cin >> n;

    vector<pair<pair<int, int>, int>> N;
    vector<pair<pair<int, int>, int>> E;
    vector<int> ans(n, 1000000000);
    int ruts[101][101];

    for (int i{0}; i < n; ++i) {
        char dir;
        cin >> dir;
        pair<int, int> p;
        cin >> p.first >> p.second;
        if (dir == 'N') {
            N.push_back({p, i});
        } else {
            E.push_back({p, i});
        } ruts[p.first][p.second] = 1;
    }

    int inc{1};
    while (inc<100) {
        for (int i{0}; i < N.size(); ++i) {
            if (ruts[N[i].first.first][N[i].first.second+inc] > 0) {
                if (ans[N[i].second]==1000000000) ans[N[i].second] = inc;
            } ruts[N[i].first.first][N[i].first.second+inc] = inc+1;
        } for (int i{0}; i < E.size(); ++i) {
            if (ruts[E[i].first.first+inc][E[i].first.second] > 0 && ruts[E[i].first.first+inc][E[i].first.second] != inc+1) {
                if (ans[E[i].second]==1000000000) ans[E[i].second] = inc;
            } ruts[E[i].first.first][E[i].first.second+inc] = inc+1;
        } ++inc;
    }

    for (int x : ans) {
        if (x == 1000000000) cout << "Infinity\n";
        else cout << x << '\n';
    }

    // vector<pair<int, int>> North(N);
    // vector<pair<int, int>> East(N);
    // for (int i{0}; i < N; ++i) {
    //     char direction;
    //     int x, y;   // no repeated values for any cow
    //     cin >> direction >> x >> y;
    //     if (direction == 'N') {
    //         North[i] = {x, y};
    //         East[i] = {-1, -1};     // none
    //     } else {
    //         East[i] = {x, y};
    //         North[i] = {-1, -1};
    //     }
    // }

    // vector<int> ans(N, 1000000000);
    // for (int i{0}; i < N; ++i) {    // for each cow
    //     if (East[i].first == -1) {  // cow goes North
    //         for (int e{0}; e < N; ++e) {
    //             if (East[e].first != -1) {
    //                 if (East[e].first<North[i].first && East[e].second>North[i].second) {
    //                     if (East[e].second-North[i].second > North[i].first-East[e].first) {
    //                         ans[i] = min(ans[i], East[e].second-North[i].second);
    //                     }
    //                 }
    //             }
    //         }
    //     } else {    // cow goes East
    //         for (int n{0}; n < N; ++n) {
    //             if (North[n].first != -1) {
    //                 if (East[i].first<North[n].first && East[i].second>North[n].second) {
    //                     if (North[n].first-East[i].first > East[i].second-North[n].second) {
    //                         ans[i] = min(ans[i], North[n].first-East[i].first);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    // for (int x : ans) {
    //     if (x == 1000000000) {
    //         cout << "Infinity\n";
    //     } else cout << x << '\n';
    // }
}
