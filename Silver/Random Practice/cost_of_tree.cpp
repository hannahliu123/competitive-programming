// D. Cost of Tree - R1800

// Start: 1:07
// End: 2:34        1 hr 27 mins

// HOLY MOLY BRO finalllyyy i did it although that took way too long jladjslkajfkdslf
// bro the implementaiton was so annoying literally pmoed but im so happy i figured it
// out heheheheheh. also understanding the problem itself took be a good while so even
// tho this problem took me almost 1.5 hours, the logic/reasoning behind it wasn't
// actually that complicated. rather it was pretty straightforward imo just dfs

// also this was another one of those problems where you could make a lot of simplifications
// as you made progress thinking about the problem. i think that's pretty common from
// graph traversal problems like this

#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<int>> adj;
vector<int> dist;
vector<long long> sum;
vector<long long> add;
vector<long long> ans;

void dfs(int node, int prev) {
    pair<int,int> mx1_dist{-1,-1};
    pair<int,int> mx2_dist{-1,-1};
    pair<long long,int> mx1_sum{-1,-1};
    pair<long long,int> mx2_sum{-1,-1};
    for (auto& i : adj[node]) {
        if (i == prev) continue;

        dfs(i, node);
        if (dist[i] > mx1_dist.first) {
            mx2_dist = mx1_dist;
            mx1_dist = {dist[i], i};
        } else if (dist[i] > mx2_dist.first) {
            mx2_dist = {dist[i], i};
        } if (sum[i] > mx1_sum.first) {
            mx2_sum = mx1_sum;
            mx1_sum = {sum[i], i};
        } else if (sum[i] > mx2_sum.first) {
            mx2_sum = {sum[i], i};
        }

        dist[node] = max(dist[node], dist[i]);
        sum[node] += sum[i];
        add[node] = max(add[node], add[i]);
        ans[node] += ans[i] + sum[i];
    }

    dist[node]++;
    sum[node] += a[node];

    if (adj[node].size() >= 2) {
        int d1 = mx1_dist.first;
        long long s1 = mx1_sum.first;
        if (mx1_sum.second == mx1_dist.second) {
            s1 = mx2_sum.first;
            int d2 = mx2_dist.first;
            long long s2 = mx1_sum.first;
            add[node] = max(add[node], (long long)d2*s2);
        } add[node] = max(add[node], (long long)d1*s1);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        a.clear(); a.resize(N);
        for (auto& i : a) cin >> i;

        adj.clear(); adj.resize(N);
        dist.clear(); dist.resize(N, 0);
        sum.clear(); sum.resize(N, 0);
        add.clear(); add.resize(N, 0);
        ans.clear(); ans.resize(N, 0);
        for (int i=0; i < N-1; i++) {
            int u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        for (int r=0; r < N; r++) {
            cout << ans[r] + add[r] << ' ';
        } cout << '\n';
    }
}