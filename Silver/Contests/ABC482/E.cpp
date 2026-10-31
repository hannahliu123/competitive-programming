#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> c;
int mxdist, mxnode;
int backdist;
bool found;
int midnode;
vector<int> dist;

void dfs(int node, int prev, int dist) {
    if (dist > mxdist) {
        mxdist = dist; mxnode = node;
    }
    for (auto& i : adj[node]) {
        if (i!=prev) dfs(i, node, dist+1);
    }
}

void findmid(int node, int prev) {
    if (node==mxnode) {
        found = true;
        return;
    }

    for (auto& i : adj[node]) {
        if (i!=prev) findmid(i, node);
        if (found) break;
    }

    if (found) {
        backdist++;
        if (backdist == mxdist/2) {
            midnode = node;
        }
    }
}

void finddist(int node, int prev) {
    if (adj[node].size()==1) {
        dist[node] = 1;
    }
    for (auto& i : adj[node]) {
        if (i!=prev) {
            finddist(i, node);
            dist[node] = max(dist[node], dist[i]+1);
        }
    }
}

int main() {
    int N; cin >> N;
    adj.clear(); adj.resize(N);
    c.clear(); c.resize(N);
    for (int i=0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } for (int i=0; i < N; i++) cin >> c[i];

    mxdist=0; mxnode=-1;
    dfs(0, -1, 0);
    int node1 = mxnode;
    mxdist=0; mxnode=-1;
    dfs(node1, -1, 0);

    found = false;
    backdist = 0; midnode = -1;
    findmid(node1, -1);

    dist.clear(); dist.resize(N, 1);
    finddist(midnode, -1);
}