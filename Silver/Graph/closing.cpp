// USACO 2016 US Open Contest, Silver
// Problem 3. Closing the Farm

// Start: 10:24
// End: 11:05       41 mins (only took so long cos i thought i needed O(N) time complexity and I also did laundry so hehe)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> closed;
vector<bool> visited;

void dfs(int n) {
    if (closed[n] || visited[n]) return;
    visited[n] = true;
    for (auto i : adj[n]) dfs(i);
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    adj.resize(N);
    closed.resize(N);visited.resize(N, false);
    for (int i{0}; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    vector<int> closing(N);
    for (auto& c : closing) cin >> c;

    // process all barns before closings
    int last_barn = closing[N-1] - 1;
    dfs(last_barn);
    if (accumulate(visited.begin(), visited.end(), 0) == N) cout << "YES\n";
    else cout << "NO\n";

    // processes barns while closing
    for (int i{0}; i < N-1; ++i) {
        closed[closing[i]-1] = true;
        visited.clear();
        visited.resize(N, false);
        dfs(last_barn);
        if (accumulate(visited.begin(), visited.end(), 0) == N-(i+1)) cout << "YES\n";
        else cout << "NO\n";
    }
}
