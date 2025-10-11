// USACO 2016 December Contest, Silver
// Problem 3. Moocast

// Start: 7:36
// End: 8:17        41 mins

// kinda messy but im glad i didn't have the completely wrong idea at least...

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> cows;

void dfs(int node, vector<bool> &v) {
    if (v[node]) return;
    v[node] = true;
    auto cow1 = cows[node];
    for (int i{0}; i < N; ++i) {
        if (v[i]) continue;
        auto cow2 = cows[i];
        int dist = (cow2[0]-cow1[0])*(cow2[0]-cow1[0]) + (cow2[1]-cow1[1])*(cow2[1]-cow1[1]);
        if (cow1[2]*cow1[2] >= dist) {
            dfs(i, v);
        }
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> N;

    cows.resize(N, vector<int>(3));
    for (int i{0}; i < N; ++i) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }

    int cnt{0};
    for (int i{0}; i < N; ++i) {
        vector<bool> v(N);
        dfs(i, v);
        cnt = max(cnt, accumulate(v.begin(), v.end(), 0));
    }

    cout << cnt << endl;
}
