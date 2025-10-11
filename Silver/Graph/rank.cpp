// ACSL '09 Practice P4 - Rank

// Start: 9:54
// End: 10:12       18 min!! woohoooooo!

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> adj;
vector<bool> visited;
bool cycle;

void dfs(int node, int origin) {
    if (visited[node] && node == origin) cycle = true;
    if (visited[node]) return;
    visited[node] = true;
    for (auto i : adj[node]) dfs(i, origin);
}

int main() {
    cin >> N >> K;

    adj.clear();
    adj.resize(N);
    for (int i{0}; i < K; ++i) {
        int a, b, as, bs;
        cin >> a >> b >> as >> bs;  // larger score wins
        a--; b--;
        if (as > bs) adj[a].push_back(b);
        else adj[b].push_back(a);
    }

    int ans = 0;
    for (int i{0}; i < N; ++i) {    // each player
        visited.clear();
        visited.resize(N, false);
        cycle = false;
        dfs(i, i);
        if (cycle) ans++;
    }

    cout << ans << endl;
}
