// Atcoder - F - Exactly K Steps

// So here you should realize (which i did but i kidna gave up on this soluion idea) that
// if you find the diameter of the tree with endpoints L and R, the answer to each query
// lies either on the path from u to L or u to R. So, we root the tree once from L and once
// from R then keep track of the running path, we can get the solution. I think the main
// difficulty of this problem was just optimizing the memory and narrowing down what idea
// is possible and what isn't

// also instead of storing so so many paths, we can just pre-read the queries so that
// once we find a path we might need, we automatically store the answer to any queries
// that need that path, then move on. to avoid MLE, we should just keep 1 array to store
// the path then update that array by adding/removing values to/from the end.

// Okay this actually helped a lot with re-familiarizing myself with memory limits and
// trees in general cos i haven't done one of these problems in a good while

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