// USACO 2022 December Contest, Silver
// Problem 3. Range Reconstruction

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> r(N, vector<int>(N));
    for (int i{0}; i < N; ++i) {
        for (int j{i}; j < N; ++j) {
            cin >> r[i][j];   // range from i to j
        }
    }

    vector<vector<pair<int,int>>> mn_mx(N, vector<pair<int,int>>(N));
    vector<int> a(N, 0);
    a[1] = r[0][1];
    mn_mx[0][0] = {0,0};
    mn_mx[0][1] = {0,a[1]};
    mn_mx[1][1] = {a[1],a[1]};
    for (int i{2}; i < N; ++i) {    // index of a we want to add
        set<int> possible{};
        set<int> new_possible{};
        for (int j{0}; j < i; ++j) {    // for each row going down
            new_possible = {};
            int r1 = r[j][i];
            int prev = r[j][i-1];
            int mn = mn_mx[j][i-1].first;
            int mx = mn_mx[j][i-1].second;
            if (r1 == prev) {    // in the interval [mn, mx]
                for (int k{mn}; k <= mx; ++k) {
                    if (possible.empty() || possible.find(k) != possible.end()) {
                        new_possible.insert(k);
                    }
                }
            } else {    // becomes mx+x or mn-x
                int x = r1 - prev;
                if (possible.empty() || possible.find(mx+x) != possible.end()) {
                    new_possible.insert(mx+x);
                } if (possible.empty() || possible.find(mn-x) != possible.end()) {
                    new_possible.insert(mn-x);
                }
            }
            possible = new_possible;
        }

        a[i] = *possible.begin();
        mn_mx[i][i] = {a[i], a[i]};
        for (int j{0}; j < i; ++j) {
            mn_mx[j][i] = mn_mx[j][i-1];
            mn_mx[j][i].first = min(mn_mx[j][i].first, a[i]);
            mn_mx[j][i].second = max(mn_mx[j][i].second, a[i]);
        }
    }

    for (int i{0}; i < N; ++i) {
        cout << a[i];
        if (i != N-1) cout << ' ';
    } cout << endl;
}
