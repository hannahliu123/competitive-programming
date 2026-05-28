// CSES Problem Set - Subarray Sum Constraints

// ok ik ive definitely encountered this type of problem before where i feel like we
// have a bunch of systems of equations. ig that should be a dead giveaway that the
// problem can be represented by a graph where the constraints are weighted edges
// that connect the nodes (which would be each individual value we are looking for
// true value of). The weight should be the coefficient, or the difference in value 
// to get from one node to the other. Then we can perform DFS on the graph and whenever
// we encounter a new node (part of a new cc), we can assign it an arbitrary value 
// (just use 0). When we encounter connected nodes, we assign it a value based on the
// edge it came from OR we check if their already computed value matches up with what
// we want to assign it. 

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;  // destination node, weight
vector<long long> pref;
vector<bool> visited;
bool pos;

void dfs(int n, long long val) {
    if (visited[n]) {   // if visited, we return
        if (pref[n] != val) pos = false;    // if it's not right then impossible, otherwise nothing changes so we can safely return
        return;
    }

    pref[n] = val;
    visited[n] = true;
    for (auto& i : adj[n]) {
        dfs(i.first, pref[n]+i.second);
    }
}

int main() {
    int N, M; cin >> N >> M;

    adj.resize(N+1);
    for (int i=0; i < M; i++) {
        int l, r, s;
        cin >> l >> r >> s; l--;
        // pref[r] - pref[l] = s, so pref[r] = pref[l] + s
        // This means an edge starting from l with a weight of s and ending at r
        adj[l].push_back({r,s});
        adj[r].push_back({l,-s});   // we also need this returning edge to fully link ccs (ex. if multiple edges only pointed to one node)
    }

    pref.resize(N+1, 0LL);
    visited.resize(N+1, false);
    pos = true;
    for (int i=0; i < N+1; i++) {
        if (!visited[i]) dfs(i, 0LL);
        if (!pos) break;
    }

    if (pos) {
        cout << "YES\n";
        vector<long long> a(N);
        for (int i=0; i < N; i++) a[i] = pref[i+1] - pref[i];
        for (long long i : a) cout << i << ' ';
    } else cout << "NO\n";
}
