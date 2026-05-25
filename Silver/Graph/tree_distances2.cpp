// CSES Problem Set - Tree Distances II

// Start: 11:57
// End: 12:28       31 mins

// yayayya im happy with this one. still pretty easy but uh slightly more complex.
// i did forget abt long longs cos i didnt realize that the distances could get so
// large. other than that tho i think this was a pretty solid implementation

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<long long> sub;
vector<long long> ans;

void dfs(int node, int prev, int dist) {
    for (auto& i : adj[node]) {
        if (i != prev) dfs(i, node, dist+1);
    }
    ans[0] += dist;
}

void calc_sub(int node, int prev) {
    for (auto& i : adj[node]) {
        if (i != prev) {
            calc_sub(i, node);
            sub[node] += sub[i];
        }
    }
}

void calc_ans(int node, int prev) {
    if (prev != -1) {
        ans[node] = ans[prev] - sub[node] + (N-sub[node]);
    }

    for (auto& i : adj[node]) {
        if (i != prev) calc_ans(i, node);
    }
}

int main() {
    cin >> N;
    adj.resize(N);
    for (int i=0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sub.resize(N, 1);
    ans.resize(N, 0);
    dfs(0, -1, 0);  // calculates ans[0]
    calc_sub(0, -1);
    calc_ans(0, -1);

    for (auto& i : ans) cout << i << ' ';
    cout << endl;
}
