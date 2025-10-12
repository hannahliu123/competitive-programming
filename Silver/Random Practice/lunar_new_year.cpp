// CF - D. Lunar New Year and a Wander - R1500

// Start: 4:24
// End: 4:41        17 mins

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
set<int> options;   // least -> greatest
vector<bool> visited;
vector<int> ans;

void dfs(int node) {
    if (options.empty()) return;

    visited[node] = true;
    options.erase(node);
    ans.push_back(node);

    for (auto& i : adj[node]) {
        if (!visited[i]) options.insert(i);
    }

    auto it = options.begin();
    dfs(*it);
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N);
    visited.resize(N, false);
    for (int i{0}; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    options = {0};
    dfs(0);
    
    for (auto& i : ans) cout << i+1 << ' ';
    cout << endl;
}
