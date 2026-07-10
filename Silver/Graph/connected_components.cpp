// CF - E. Connected Components? - R2100

// The key to this problem is just to optimze DFS such that we don't have a O(N^2)
// solution. So naively, what you'd do is for each node, check if it has an edge
// to all other N nodes. We could use an unordered set for O(1) checking if an edge
// exists, but even then, for each node we need to check all other nodes. So
// instead of a traditional boolean visited vector, we can just keep another set
// of all unvisited nodes so far. This way, once a node is visited, we know we'll 
// never try to visit it again. This is enough because for every node we try to
// visit, it will either be a valid node to visit or it will be once of the M pairs.
// Because there are only 2M total nodes part of those pairs, this fits within our
// time constraints. Note that this set of unvisited nodes must be ordered because
// when u erase a node from the set, the order of nodes could change and so nodes
// that you've already processed (and determined had invalid edges) could reappear

#include <bits/stdc++.h>
using namespace std;

set<int> unvis;
vector<unordered_set<int>> adj;
vector<int> ans;
int cc;

void dfs(int n) {
    unvis.erase(n);
    ans[cc]++;
    auto it = unvis.begin();
    while (it != unvis.end()) {
        int i = *it;
        if (adj[n].count(i) == 0) { // an edge exists from n to i
            dfs(i);
            it = unvis.upper_bound(i);
        } else it++;
    }
}

int main() {
    int N, M; cin >> N >> M;
    unvis.clear();
    adj.clear(); adj.resize(N);
    for (int i=0; i < N; i++) unvis.insert(i);
    for (int i=0; i < M; i++) {
        int x,y; cin >> x >> y; x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    cc = 0;
    ans.clear();
    for (int i=0; i < N; i++) {
        if (unvis.count(i) != 0) {
            ans.push_back(0);
            dfs(i);
            cc++;
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto& i : ans) cout << i << ' ';
    cout << endl;
}