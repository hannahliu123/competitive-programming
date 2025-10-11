// CF - C. Rumor - R1300

// Start: 9:50
// End: 10:08? idk CF is down       18 mins

#include <bits/stdc++.h>
using namespace std;

// use minimal gold to spread rumor to all people

int min_cost;
vector<bool> visited;
vector<vector<int>> adj;
vector<int> cost;           // per player to start rumor

void dfs(int node) {
    visited[node] = true;
    min_cost = min(min_cost, cost[node]);
    for (int i : adj[node]) {if (!visited[i]) dfs(i);}
}

int main() {
    int N, M;       // characters, pairs of friends
    cin >> N >> M;

    visited.resize(N, false);
    adj.resize(N);
    cost.resize(N);
    for (auto& i : cost) cin >> i;

    for (int i{0}; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    long long gold{0};
    for (int i{0}; i < N; ++i) {    // each character
        if (!visited[i]) {
            min_cost = cost[i];
            dfs(i);
            gold += (long long)min_cost;
        }
    }

    cout << gold << endl;
}
