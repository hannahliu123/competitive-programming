// CF - C. PolandBall and Forest - R1300

// Start: 8:37
// End: 8:58        21 mins!

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;

void dfs(int node) {
    visited[node] = true;
    for (int i : adj[node]) {
        if (!visited[i]) dfs(i);
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N);
    visited.resize(N, false);
    for (int i{0}; i < N; ++i) {
        int a;
        cin >> a;
        adj[i].push_back(a-1);
        adj[a-1].push_back(i);
    }

    int ans{0};
    for (int i{0}; i < N; ++i) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }

    cout << ans << endl;
}
