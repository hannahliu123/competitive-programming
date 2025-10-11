// USACO 2019 US Open Contest, Silver
// Problem 3. Fence Planning

// Start: 8:56
// End: 9:25        29 mins

// AHHH NO WAY FIRST TRY??!??! TEHEHEHEHH

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> cows;
vector<bool> visited;
vector<vector<int>> adj;

vector<int> dfs(int n) {
    visited[n] = true;
    // top (max_y), bottom (min_y), right (max_x), left (min_x)
    vector<int> v{cows[n].second, cows[n].second, cows[n].first, cows[n].first};
    for (auto i : adj[n]) {
        if (!visited[i]) {
            vector<int> v2 = dfs(i);
            v[0] = max(v[0], v2[0]);   // top (max_y)
            v[1] = min(v[1], v2[1]);   // bottom (min_y)
            v[2] = max(v[2], v2[2]);   // right (max_x)
            v[3] = min(v[3], v2[3]);   // left (min_x)
        }
    }

    return v;
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    cin >> N >> M;

    visited.resize(N);
    adj.resize(N);
    cows.resize(N);
    for (auto& i : cows) cin >> i.first >> i.second;
    for (int i{0}; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    int perimeter{1000000000};
    for (int i{0}; i < N; ++i) {
        if (!visited[i]) {
            vector<int> v = dfs(i);
            int p = 2*(v[0]-v[1]) + 2*(v[2]-v[3]);
            perimeter = min(perimeter, p);
        }
    }

    cout << perimeter << endl;
}
