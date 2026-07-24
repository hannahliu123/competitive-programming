// CF - D1. Tree Orientation (Easy Version) - R1800

// Start: 9:21
// End:  10:59      1 hr 38 mins

// holy moly okay that wasn't too bad i just got stuck on an edge case where you could
// be left with multiple connected components and not just one tree. to fix that i jsut
// had to resimulate dfs on the final graph to see if it was all connected
// Right now this solves the easy version with O(N^3) time complexity, because for each
// node we check all of its childen then all of the children of its children. We can
// cut that down to O(N^2) by making sure we only process each node once within the
// iterations for each node. After all, we know that there are only N-1 edges, so we
// need a way to optimally find each edge without having to recount.

// to do this, we know (and i even got this realization but didn't think much about it
// cos i didn't need it) that the current node i will 100% form an edge with its child
// that has the most children itself. then if we just remove all of the children of that
// child from node i, we can take the next maximum! this ensures we add edges optimally
// and prevents us from reprocessing nodes we don't need.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<pair<int,int>> all_edges;
bool pos;
vector<vector<int>> adj2;
vector<bool> visited;
int total_visited;

void create_edges(int node) {
    unordered_map<int,int> visit{};
    unordered_set<int> children{};
    for (int i : adj[node]) {   // child
        children.insert(i);
        if (visit.count(i)) continue;
        visit.insert({i,i});
        for (int j : adj[i]) {  // child of child
            visit[j] = i;
        }
    } unordered_set<int> child{};
    for (auto& p : visit) {
        if (children.count(p.first)==0) {
            pos = false; return;
        }
        child.insert(p.second);
    }
    for (int i : child) {   // edge from node -> i
        all_edges.push_back({node,i});
    }
}

void dfs(int node) {
    visited[node] = true;
    total_visited++;
    for (int i : adj2[node]) {
        if (!visited[i]) dfs(i);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;

        pos = true;
        adj.clear(); adj.resize(N);
        all_edges.clear();
        for (int i=0; i < N; i++) {
            string s; cin >> s;
            for (int j=0; j < N; j++) {
                if (i==j) {
                    if (s[j]=='0') { pos = false; break; }
                } else if (s[j]=='1') adj[i].push_back(j);
            }
        }

        for (int i=0; i < N; i++) {
            if (!pos) break;
            create_edges(i);
        }

        // check if it's actually a tree
        adj2.clear(); adj2.resize(N);
        visited.clear(); visited.resize(N, false);
        total_visited = 0;
        for (auto& p : all_edges) {
            adj2[p.first].push_back(p.second);
            adj2[p.second].push_back(p.first);
        }
        dfs(0);

        if (!pos || all_edges.size() != N-1 || total_visited != N) {
            cout << "No\n"; continue;
        }

        cout << "Yes\n";
        for (auto& p : all_edges) cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
}