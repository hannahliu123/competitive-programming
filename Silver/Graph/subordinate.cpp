// Intro to Tree Algorithms - CSES - https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans;

void dfs(int node, int prev) {
    ans[node] = 1;
    for (auto i : adj[node]) {
        if (i == prev) continue;
        dfs(i, node);
        ans[node] += ans[i];
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    ans.resize(n);
    for (int i{1}; i < n; ++i) {
        int boss;
        cin >> boss;
        boss--;
        adj[boss].push_back(i);
    }

    dfs(0, 0);
    for (int i{0}; i < n; ++i) {
        cout << ans[i]-1 << ' ';
    }

    cout << endl;
}
