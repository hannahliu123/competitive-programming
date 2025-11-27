// USACO 2022 December Contest, Silver
// Problem 3. Range Reconstruction

// doesnt work and im gonna crash out

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

    vector<pair<int,pair<int,int>>> a(N, pair<int,pair<int,int>>{0,{-1,-1}});    // a, {op1, op2}
    a[1].first = r[0][1];
    for (int i{2}; i < N; ++i) {    // index of a we want to add
        int mn = a[i-1].first;  // already decided in previous iteration
        int mx = a[i-1].first;
        int sub = 1;
        for (int j{i-1}; j >= 0; --j) {    // for each row going up
            int r1 = r[j][i];
            int prev = r[j][i-1];
            mn = min(mn, a[i-sub].first);
            mx = max(mx, a[i-sub].first);
            if (r1 == prev) {    // in the interval [mn, mx]
                if (a[i].second.first == -1) {  // first iteration
                    a[i].first = a[i-1].first;
                    break;
                } 
                set<int> pos{};
                for (int k{mn}; k <= mx; ++k) {   // not first iteration
                    pos.insert(k);
                } if (pos.find(a[i].second.first) == pos.end()) {
                    a[i].first = a[i].second.second;
                    break;
                } else if (pos.find(a[i].second.second) == pos.end()) {
                    a[i].first = a[i].second.first;
                    break;
                }
            } else {    // r1 > prev and a[i] becomes mx+x or mn-x
                int x = r1 - prev;
                if (a[i].second.first == -1) {  // first iteration
                    a[i].second.first = mx+x;
                    a[i].second.second = mn-x;
                } else {    // not first iteration
                    if (a[i].second.first != mx+x && a[i].second.first != mn-x) {
                        a[i].first = a[i].second.second;
                        break;
                    } if (a[i].second.second != mx+x && a[i].second.second != mn-x) {
                        a[i].first = a[i].second.first;
                        break;
                    }
                }
            }
            sub++;
        }
    }

    for (int i{0}; i < N; ++i) {
        cout << a[i].first;
        if (i != N-1) cout << ' ';
    } cout << endl;
}
