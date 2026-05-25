// CSES Problem Set - Tree Distances I

// Start: 11:35
// End: 11:56       21 mins

// ahhh i just missed an equal sign because the mx node wasnt updating properllyyyy these
// are actually shockingly simple and easy i feel like i need to do harder practice :/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist1;
vector<int> dist2;
int mx_dist, mx_node;

void dfs(int node, int prev, int dist, int state) {
    for (auto& i : adj[node]) {
        if (i != prev) dfs(i, node, dist+1, state);
    }
    
    if (state==1 && dist >= mx_dist) {
        mx_dist = dist;
        mx_node = node;
    } else if (state==2) dist1[node] = dist;
    else if (state==3) dist2[node] = dist;
}

int main() {
    int N; cin >> N;
    adj.resize(N);
    for (int i=0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // find endpoints (pt1, pt2)
    mx_dist = -1; mx_node = -1;
    dfs(0, -1, 0, 1);
    int pt1 = mx_node;
    dfs(pt1, -1, 0, 1);
    int pt2 = mx_node;

    // fill dist1 and dist2 with distance from pt1 and pt2
    dist1.resize(N);
    dist2.resize(N);
    dfs(pt1, -1, 0, 2);
    dfs(pt2, -1, 0, 3);

    for (int i=0; i < N; i++) {
        cout << max(dist1[i], dist2[i]) << ' ';
    } cout << endl;
}
