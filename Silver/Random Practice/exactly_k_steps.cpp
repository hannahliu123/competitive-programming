// Atcoder - F - Exactly K Steps

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int mx_dist, n;
vector<int> ans;
vector<int> path;
vector<vector<pair<int,int>>> queries;  // node: {i, K}, {i, K}, ...

void dfs(int node, int prev, int dist) {
    if (dist > mx_dist) {
        mx_dist = dist;
        n = node;
    }
    for (auto& i : adj[node]) {
        if (i != prev) dfs(i, node, dist+1);
    }
}

void dfs2(int node, int prev, int dist) {
    for (auto& q : queries[node]) {
        int i = q.first, K = q.second;
        if (path.size() >= K) ans[i] = path[path.size()-K]+1;
    }
    path.push_back(node);
    for (auto& i : adj[node]) {
        if (i != prev) dfs2(i, node, dist+1);
    }
    path.pop_back();
}

int main() {
    int N; cin >> N;
    adj.clear(); adj.resize(N);
    for (int i=0; i < N-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    mx_dist = 0;
    dfs(0, -1, 0);
    int start = n;
    mx_dist = 0;
    dfs(start, -1, 0);
    int end = n;

    int Q; cin >> Q;
    queries.clear(); queries.resize(N);
    for (int i=0; i < Q; i++) {
        int u, K; cin >> u >> K; u--;
        queries[u].push_back({i, K});
    }

    ans.clear(); ans.resize(Q, -1);
    path = {};
    dfs2(start, -1, 0);
    path = {};
    dfs2(end, -1, 0);

    for (auto& i : ans) cout << i << '\n';
}