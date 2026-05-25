// CSES Problem Set - Tree Diameter

// Start: 10:58
// End: 11:07           9 mins

// this was a really classic problem lol

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int mx_dist, furthest_node;

void dfs(int prev, int node, int dist) {
    for (auto& i : adj[node]) {
        if (i != prev) dfs(node, i, dist+1);
    }

    if (dist > mx_dist) {
        mx_dist = dist;
        furthest_node = node;
    }
}

int main() {
    int N; cin >> N;

    adj.resize(N);
    for (int i=0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    mx_dist = -1;
    furthest_node = -1;
    dfs(-1, 0, 0);
    dfs(-1, furthest_node, 0);

    cout << mx_dist << endl;
}
