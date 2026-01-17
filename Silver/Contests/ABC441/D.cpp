// D

#include <bits/stdc++.h>
using namespace std;

int N, M, L, S, T;  // L edges, at least S and at most T
vector<vector<pair<int,int>>> adj;  // dest, cost
vector<bool> ans;   // true is possible

void dfs(int n, int cost, int edgeCnt) {
    if (edgeCnt == L) {
        if (cost >= S && cost <= T) ans[n] = true;
        return;
    }
    for (auto& p : adj[n]) {
        dfs(p.first, cost+p.second, edgeCnt+1);
    }
}

int main() {
    cin >> N >> M >> L >> S >> T;

    adj.clear(); adj.resize(N, vector<pair<int,int>>{});
    for (int i{0}; i < M; ++i) {
        int U, V, C;
        cin >> U >> V >> C;
        U--; V--;
        adj[U].push_back({V, C});
    }

    ans.clear(); ans.resize(N, false);
    dfs(0, 0, 0);
    
    for (int i{0}; i < N; ++i) {
        if (ans[i]) cout << i+1 << ' ';
    } cout << endl;
}
