// CF - C. Journey - R1500 (but labeled easy in USACO guide...)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
double ans;    // final ans = sum of all (probability of reaching * length) of all leaf nodes

void dfs(int node, int prev, int length, double probability) {
    // if the node is a leaf node, add the probability of reaching it * length to ans
    // otherwise, divide the probability by the number of children the node has & call dfs 
    // on all of its children with a new arguments
    if (adj[node].size() == 1 && adj[node][0] == prev) {
        ans += probability * length;
        return;
    }

    int children = 0;
    for (int i : adj[node]) {
        if (i != prev) children++;
    }

    for (int i : adj[node]) {
        if (i != prev) dfs(i, node, length+1, probability/children);
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N);
    for (int i{0}; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1, 0, 1);
    cout << fixed << setprecision(15) << ans << endl;
}
