// E. Split Into Two Sets - R1600

// Start: 9:09
// End: 9:45        36 mins

// yayayya this was pretty straighforward tho i did see the tag on accident. i havent 
// implemented this algorithm in a while too so this was nice practice

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> has; // index (id) of nodes that have curr index
vector<vector<int>> adj;
vector<int> visited;
int c1, c2;
bool pos;

void dfs(int node, bool c) {
    visited[node] = c;
    for (auto& i : adj[node]) {
        if (visited[i] == -1) dfs(i, !c);
        else if (visited[i] == c) {
            pos = false; return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        pos = true;
        has.clear(); has.resize(N+1);
        adj.clear(); adj.resize(N);
        for (int i=0; i < N; i++) {
            int a, b; cin >> a >> b;
            if (a==b || has[a].size()==2 || has[b].size()==2) pos = false;
            if (!pos) continue;
            for (auto& node : has[a]) {
                adj[i].push_back(node);
                adj[node].push_back(i);
            }
            for (auto& node : has[b]) {
                adj[i].push_back(node);
                adj[node].push_back(i);
            }
            has[a].push_back(i); has[b].push_back(i);
        }

        if (!pos) {
            cout << "NO\n";
            continue;
        }

        visited.clear(); visited.resize(N, -1);
        int diff_pairs = 0; // number of opposite colored node pairs w/ diff num of nodes
        for (int i=0; i < N; i++) {
            if (visited[i] == -1) {
                c1=0; c2=0;
                dfs(i, true);
                if (!pos) break;
                if (c1 != c2) diff_pairs++;
            }
        }

        if (!pos || diff_pairs%2==1) cout << "NO\n";
        else cout << "YES\n";
    }
}