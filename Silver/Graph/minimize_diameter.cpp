// CF - F. Minimize the Diameter

// ohh okay so i got the idea right but i didn't realize that the formula only gives
// the diameter of the combined tree such that the added edge is part of the path, but
// the LONGEST path might not use that added edge (could just be the first/second tree
// itself)!

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj1;
vector<vector<int>> adj2;

int mx_dist, furthest_node;

void dfs(int node, int prev, int dist, vector<vector<int>>& adj) {
    for (auto& i : adj[node]) {
        if (i != prev) dfs(i, node, dist+1, adj);
    }

    if (dist > mx_dist) {
        mx_dist = dist;
        furthest_node = node;
    }
}

int main() {
    int N; cin >> N;
    adj1.resize(N);
    for (int i=0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    int M; cin >> M;
    adj2.resize(M);
    for (int i=0; i < M-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    mx_dist = -1;
    furthest_node = -1;
    dfs(0, -1, 0, adj1);
    dfs(furthest_node, -1, 0, adj1);
    int dist1 = mx_dist;

    mx_dist = -1;
    furthest_node = -1;
    dfs(0, -1, 0, adj2);
    dfs(furthest_node, -1, 0, adj2);
    int dist2 = mx_dist;

    cout << max(max(dist1, dist2), (dist1+1)/2 + (dist2+1)/2 + 1) << endl;
}
