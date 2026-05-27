// USACO 2020 February Contest, Silver
// Problem 3. Clock Tree

// practicing implementation

#include <bits/stdc++.h>
using namespace std;

vector<int> room;
vector<vector<int>> adj;
int sum1, sum2, group1, group2;

void dfs(int n, int prev, int color) {
    if (color==1) {
        group1++;
        sum1 += 12-room[n];
        color = 2;
    } else {
        group2++;
        sum2 += 12-room[n];
        color = 1;
    }

    for (auto& i : adj[n]) {
        if (i != prev) dfs(i, n, color);
    }
}

int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);

    int N; cin >> N;
    room.resize(N);
    for (auto& i : room) cin >> i;
    adj.resize(N);
    for (int i=0; i < N-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sum1=0; sum2=0; group1=0; group2=0;
    dfs(0, -1, 1);

    int rem1 = sum1%12, rem2 = sum2%12, ans=0;
    if (rem1 == rem2) ans = N;
    else if (rem1+1 == rem2) ans = group1;  // need to visit group2 more
    else if (rem1 == rem2+1) ans = group2;

    cout << ans << endl;
}
