// USACO 2025 February Contest, Silver
// Problem 2. Vocabulary Quiz

// FIRST TRY BABYYYYY finished at 9:45 (started contest at 8:30)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<pair<int,int>> val;
vector<int> dist;

void dfs(int node, int d) {
    dist[node] = d;
    if (node != 0 && adj[node].size() == 1) {
        val[node] = {1,1};
        return;
    }

    for (auto& i : adj[node]) {
        if (i > node) {
            dfs(i, d+1);
            val[node].first += val[i].first;
            val[node].second  = val[node].first;
        }
    }
}

int sayWord(int node, int amt) {
    val[node].second -= amt;

    if (val[node].second == 0) {
        // go up one and minus by val[node].first
        if (node == 0) return 0;
        int parent = adj[node][0];
        return sayWord(parent, val[node].first);
    } else {
        return dist[node] + 1;
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N+1, {});
    dist.resize(N+1, 0);
    val.resize(N+1, {0,0});    // original, updated
    for (int i{1}; i <= N; ++i) {
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    dfs(0, 0);

    int M = val[0].first;
    vector<int> words(M);
    for (auto& i : words) cin >> i;

    for (int i{0}; i < M; ++i) {
        int w = words[i];
        cout << sayWord(w, 1) << '\n';
    }
}
