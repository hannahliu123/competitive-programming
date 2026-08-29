// CSES Problem Set - Even Outdegree Edges

// erm nevermind come back to this later...

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
int edges;

void dfs(int node) {
    edges += adj[node].size();
    visited[node] = true;
    for (auto& i : adj[node]) {
        if (!visited[i]) dfs(i);
    }
}

int main() {
    int N, M; cin >> N >> M;
    for (int i=0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited.clear(); visited.resize(N, false);
    adj.clear(); adj.resize(N, vector<int>{});
    int pos = true;
    for (int i=0; i < N; i++) {
        if (!visited[i]) {
            edges = 0;
            dfs(i);
            if ((edges/2) % 2 == 1) {
                pos = false;
                break;
            }
        }
    }

    if (!pos) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    priority_queue<vector<int>> pq{};   // -1*undecided edges, out, in, index
    for (int i=0; i < N; i++) pq.push({-1*(int)adj[i].size(), 0, 0, i});
    set<pair<int,int>> ans{};
    
    while (!pq.empty()) {
        vector<int> v = pq.top();
        pq.pop();
        int undec = -1*v[0];
        int out = v[1], in = v[2], idx = v[3];
        if (out%2==0) { // use all undec edges to go into the current node
            for (auto& i : adj[idx]) {
                if (ans.count({idx,i})==0 && ans.count({i,idx})==0) {   // undec edge
                    ans.insert({i,idx});
                }
            }
        } else {    // use one undec edge going out
            for (auto& i : adj[idx]) {
                if (ans.count({idx,i})==0 && ans.count({i,idx})==0) {   // undec edge
                    ans.insert({idx,i});
                    break;  // just need one
                }
            } out++;
            undec--;
        }
    }

    for (auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
}