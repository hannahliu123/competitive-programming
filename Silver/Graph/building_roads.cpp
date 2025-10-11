// CSES - https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;

int N, M;       // cities, roads
vector<vector<int>> adj{};    // 1-indexed
vector<bool> visited{};

void dfs(int node) {
    if (visited[node]) return;      // already visited
    visited[node] = true;       // set to visited
    for (auto n : adj[node]) dfs(n);    // visit all connected nodes
}

int main() {
    cin >> N >> M;

    adj.resize(N+1);
    visited.resize(N+1);
    for (int i{0}; i < M; ++i) {    // create adj list
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    vector<pair<int, int>> new_roads{};
    for (int i{1}; i <= N; ++i) {   // update unvisited node
        if (!visited[i]) {
            dfs(i);     // also visit all roads connected to the new road we built
            new_roads.push_back({1, i});
        }
    }

    cout << new_roads.size() << endl;
    for (auto road : new_roads) cout << road.first << ' ' << road.second << endl;
}
