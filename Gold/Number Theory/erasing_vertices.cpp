// AtCoder - A - Erasing Vertices
// USACO Guide Linearity of Expectation

#include <bits/stdc++.h>
using namespace std;

vector<int> reach;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int n) {
    visited[n] = true;
    reach[n]++;     // this node was reached
    for (auto& i : adj[n]) {
        if (!visited[i]) dfs(i);
    }
}

int main() {
    int N; cin >> N;

    // E[total nodes chosen] = sum of E[times each node is chosen]
    // Now we need to find the expected value of the number of times each
    // node is chosen, which is an indicator random variable! The probability
    // that a node is ever chosen will be equal to E[indicator_node_i]. A node
    // can only be chosen if it's alive, meaning another chosen node didn't
    // lead to/connect to this node. In other words, if there are K total nodes
    // that could wipe out the current node, the current node will only ever
    // be chosen if it's the first node chosen out of all A nodes, which equals
    // 1/A. Then we find the sum of 1/A for all nodes

    // So, for each node i, let's find all the nodes j it can reach. For each of
    // those nodes j that are reached, we know that node i is one of the nodes
    // that can reach it.

    adj.resize(N);
    for (int i=0; i < N; i++) {
        string s; cin >> s;
        for (int j=0; j < N; j++) {
            if (s[j]=='1') adj[i].push_back(j);
        }
    }

    reach.resize(N, 0);
    for (int i=0; i < N; i++) {
        visited.clear(); visited.resize(N, false);
        dfs(i);
    }

    double ans = 0;
    for (auto& i : reach) {
        ans += 1.0 / i;
    }

    cout << fixed << setprecision(20) << ans << endl;
}
