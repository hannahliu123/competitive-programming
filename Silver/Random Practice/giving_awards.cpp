// D. Giving Awards - R2000

// So there are two solutions for them. One of them involves a graph, which i guess 
// feels more intuitive given the format of this problem. the other one is more
// straightforward imo but is just a greedy solution.

// So for the graph solution, I was thinking you could build a path following the
// a -> b edges then reverse the path so that a never comes before b. I also realized
// u could arbitrarily add edges wherever you wanted to but ig because i haven't done
// a graph problem in so long that kinda make me stuck because i forgot u can just
// implement dfs starting multiple times from unvisited nodes. My idea is wrong though
// because for it to work, you should never visit b before a. However, you can't account
// for incoming edges because dfs follows outgoing edges. So once you print a node, it's
// very possible that right afterwards you print a node that points towards the node
// u just printed as long as there is more than 1 incoming edge. 
// To actually guarentee you never print a final configuration with a before b, you want
// to print b before any of its parents (ingoing edges) or a after all of its children
// (outgoing edges). Logically, it would then make sense to just print all children first
// before parents. In the case of a loop of 3+ nodes, we can just neglect an edge because
// the first and last nodes won't be next to eachother. So if we just follow dfs as deep
// as possible then print a node only once it has no more unvisited children to visit, we
// will get the answer. 

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (auto& i : adj[node]) {
        if (!visited[i]) dfs(i);
    }
    cout << node+1 << ' ';
}

int main() {
    int N, M; cin >> N >> M;
    adj.clear(); adj.resize(N);
    for (int i=0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }

    visited.clear(); visited.resize(N, false);
    for (int i=0; i < N; i++) {
        if (!visited[i]) dfs(i);
    }

    cout << '\n';
}
