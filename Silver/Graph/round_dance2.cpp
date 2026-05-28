// CF - E. Round Dance - R1600

// Start: 2:25
// End: 2:54        29 mins

// ok this was a really easy problem but i hate my implementation. also ive solved
// it before so i kinda had an idea of it already

// oh so what the editorial did was they called half graphs bamboo graphs and full
// graphs cycles. then if there was ever a node with only one connection/edge, we
// know that component must be a bamboo. otherwise if all nodes had two edges, it
// must be a cycle. note that if there's only two nodes this doesnt work so the
// editorial used a vector<set<int>> as the adj list to not overcount

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
bool full;

void dfs(int n, int prev) {
    visited[n] = true;
    for (auto& i : adj[n]) {
        if (i != prev) {
            if (visited[i]) full = true;
            else dfs(i, n);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        adj.clear(); adj.resize(N);
        for (int i=0; i < N; i++) {
            int x; cin >> x; x--;
            if (adj[i].size()==1 && adj[i][0] == x) continue;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }

        full=false;
        int comp = 0, half = 0;
        visited.clear(); visited.resize(N, false);
        for (int i=0; i < N; i++) {
            if (!visited[i]) {
                dfs(i, -1);
                if (full) comp++;
                else half++;
                full = false;
            }
        }

        int mn = comp + (half>0? 1 : 0);
        int mx = comp + half;

        cout << mn << ' ' << mx << '\n';
    }
}
