// USACO 2020 December Contest, Silver
// Problem 1. Cowntagion

// Start: 6:08
// End: 6:25            17 mins

// yayaya this was just a simple dfs lol

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int ans;

void dfs(int node, int prev) {
    int children = adj[node].size();
    if (prev==-1) children++;
    int doubles = 0;
    int base = 1;
    while (base < children) {
        base *= 2;
        doubles++;
    } ans += doubles;
    for (auto& i : adj[node]) {
        if (i != prev) {
            ans++;
            dfs(i, node);
        }
    }
}

int main() {
    int N; cin >> N;
    adj.clear(); adj.resize(N);
    for (int i=0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans = 0;
    dfs(0,-1);

    cout << ans << '\n';
}