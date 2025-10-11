// Kattis - https://open.kattis.com/problems/birthday

// the only tricky part for this problem is how you store the adj list but I got
// stumped by time complexity. I didn't realize i have FIVE whole seconds brooooo
// i thought i still had two do i didnt rly know how to do it. all in all it's 
// pretty simple if i was more focused and less... uh dead

#include <bits/stdc++.h>
using namespace std;

int P, C;
vector<bool> visited;
vector<vector<bool>> adj;     
// store as booleans so you can just set values to true/false it works because of how 
// small the constraints are

void dfs(int node) {
    visited[node] = true;
    for (int i{0}; i < P; ++i) {
        if (adj[node][i] && !visited[i]) dfs(i);
    }
}

int main() {
    while (true) {
        cin >> P >> C;

        if (P==0 && C==0) break;

        adj.clear();
        adj.resize(P, vector<bool>(P, false));
        visited.clear();
        visited.resize(P, false);
        vector<pair<int, int>> edges(C);
        for (int i{0}; i < C; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a][b] = true;   // set true to represent that it exists
            adj[b][a] = true;
            edges[i] = {a, b};
        }

        bool possible = true;   // true = everyone invited
        for (auto i : edges) {    // for each edge, try removing it
            adj[i.first][i.second] = false;
            adj[i.second][i.first] = false;
            visited.clear();
            visited.resize(P, false);
            dfs(0);
            for (int i{0}; i < P; ++i) {
                if (!visited[i]) {
                    possible = false;
                    break;
                }
            }
            adj[i.first][i.second] = true;
            adj[i.second][i.first] = true;
        }

        cout << (possible? "No" : "Yes") << endl;
    }
}
