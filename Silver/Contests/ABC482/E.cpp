// so i realized that the diameters for each tree must always pass through some same
// specific point. this is proven because if this weren't true and you have two paths
// of equal length that didn't intersect, you could always select a longer more 
// optimal path as your diameter by merging those two paths. ok i proved this in google
// docs but the diameters must meet at the center of some diameter path.

// once we find the center, we can compute the distances of all branches going outward
// from that center. we take the two maximum distances and based on the number of
// branches that acheive those maximum distances as well as the color of the leaf nodes
// of those far away branches, we can compute the numebr of pairs. 

// the implementation is a bit tricky and um as  you can see i wrote four different 
// slightly different dfs functions... heh not my best work but it gets the job done lol.
// oh also there's an edge case when N=2 so i just handled that separately.

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

void dfs2(int node, int prev, map<int,int>& v, map<int,int>& total) {
    if (adj[node].size() == 1) {
        v[c[node]]++;
        total[c[node]]++;
    }
    for (auto& i : adj[node]) {
        if (i!=prev && dist[i]==dist[node]-1) dfs2(i, node, v, total);
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

    if (N==2) {
        cout << (c[0]==c[1]? 1 : 0) << '\n';
        return 0;
    }

    mxdist=0; mxnode=-1;
    dfs(0, -1, 0);
    int node1 = mxnode;
    mxdist=0; mxnode=-1;
    dfs(node1, -1, 0);

    found = false;
    backdist = 0; midnode = 0;
    findmid(node1, -1);

    dist.clear(); dist.resize(N, 1);
    finddist(midnode, -1);
    
    int children = adj[midnode].size();
    if (mxdist%2==0) {  // k only
        vector<map<int,int>> v(children);
        map<int,int> total{};
        for (int i=0; i < children; i++) {
            if (dist[adj[midnode][i]] == mxdist/2) {
                dfs2(adj[midnode][i], midnode, v[i], total);
            }
        }
        long long ans = 0;
        for (int i=0; i < children; i++) {
            for (auto& [color,cnt] : v[i]) {
                ans += (long long)(total[color]-cnt)*cnt;
            }
        }
        cout << ans/2 << '\n';
    } else {    // k and k+1
        map<int,int> v1{};
        map<int,int> v2{};
        map<int,int> total{};   // unused :/
        for (int i=0; i < children; i++) {
            if (dist[adj[midnode][i]] == mxdist/2) {
                dfs2(adj[midnode][i], midnode, v1, total);
            } else if (dist[adj[midnode][i]] == mxdist/2 + 1) {
                dfs2(adj[midnode][i], midnode, v2, total);
            }
        }
        long long ans = 0;
        for (auto& [color,cnt] : v1) {
            ans += (long long)(v2[color])*cnt;
        }
        cout << ans << '\n';
    }
}