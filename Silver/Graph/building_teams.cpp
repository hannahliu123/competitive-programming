// CSES - https://cses.fi/problemset/task/1668

// Start: 2:31
// End: 2:53            22 mins

#include <bits/stdc++.h>
using namespace std;

int N, M;   // pupils, friendships
bool possible;
vector<vector<int>> adj{};
vector<int> team{};

void dfs(int node, int team_num) {
    if (!possible || team[node] == team_num) return;
    if (team[node] != -1 && team[node] != team_num) {
        possible = false;
        return;
    }
    
    if (team[node] == -1) team[node] = team_num;
    if (team_num == 1) for (auto n : adj[node]) dfs(n, 2);
    else for (auto n : adj[node]) dfs(n, 1);
}

int main() {
    cin >> N >> M;

    possible = true;     // for now
    adj.resize(N+1);
    team.resize(N+1, -1);
    for (int i{0}; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);

    for (int i{1}; i <= N; ++i) {
        if (!possible) break;
        if (team[i] == -1) dfs(i, 1);
    }

    if (!possible) cout << "IMPOSSIBLE";
    else for (int i{1}; i <= N; ++i) cout << team[i] << ' ';
    cout << endl;
}
