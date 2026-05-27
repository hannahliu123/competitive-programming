// USACO 2016 December Contest, Gold
// Problem 1. Moocast

// Start: 4:10
// End: 4:36        26 mins

// oh yeah locked innn :DDDDDDDDDDDDDDDDDDDD

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;  // X, idx
vector<bool> visited;
int seen;

void dfs(int n, int X) {
    visited[n] = true;
    seen++;

    for (auto& i : adj[n]) {
        if (i.first <= X) {
            if (!visited[i.second]) dfs(i.second, X);
        } else break;
    }
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int N; cin >> N;
    vector<pair<int,int>> cow(N);
    for (auto& i : cow) cin >> i.first >> i.second;

    adj.resize(N);
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            if (i==j) continue;
            int a = abs(cow[j].first - cow[i].first);
            int b = abs(cow[j].second - cow[i].second);
            adj[i].push_back({a*a + b*b, j});
        } sort(adj[i].begin(), adj[i].end());
    }

    // binary search on X
    int hi=INT_MAX, lo=0;
    while (lo != hi) {
        int mid = lo + (hi-lo)/2;

        visited.clear(); visited.resize(N, false);
        seen = 0;
        dfs(0, mid);

        if (seen == N) hi = mid;
        else lo = mid+1;
    }

    cout << lo << endl;
}
