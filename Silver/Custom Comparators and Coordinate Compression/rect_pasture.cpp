// USACO 2020 December Contest, Silver
// Problem 2. Rectangular Pasture

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> x(N);    // value, index
    vector<pair<int, int>> y(N);
    set<vector<int>> pos{{}};   // currently has one empty vector
    for (int i{0}; i < N; ++i) {
        cin >> x[i].first >> y[i].first;
        x[i].second = i;
        y[i].second = i;
        pos.insert({i});    // single indicies
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    // x-values
    for (int i{0}; i < N-1; ++i) {
        vector<int> group{x[i].second};
        for (int j{i+1}; j < N; ++j) {    // groups
            group.push_back(x[j].second);
            sort(group.begin(), group.end());
            pos.insert(group);
        }
    }

    // y-values
    for (int i{0}; i < N-1; ++i) {
        vector<int> group{y[i].second};
        for (int j{i+1}; j < N; ++j) {    // groups
            group.push_back(y[j].second);
            sort(group.begin(), group.end());
            pos.insert(group);
        }
    }

    long long ans = pos.size();
    cout << ans << endl;
}
