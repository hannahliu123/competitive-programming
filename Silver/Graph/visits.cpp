// USACO 2022 US Open Contest, Silver
// Problem 1. Visits

// Start: 12:45
// End: 1:36        51 mins

// yuhh im proud of this one cos i got the solution on my own AND i debugged it
// w/o looking at test cases :)))

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> a;
vector<int> visited;
vector<int> mn;
int idx;    // index of cycle (in mn)
bool in_cycle;

void dfs(int n) {
    if (visited[n] != -2) {
        if (visited[n] == -1) {
            visited[n] = 0;     // part of cycle
            mn.push_back(a[n].second);
            in_cycle = true;
            idx++;
        } return;
    }

    visited[n] = -1;    // currently visiting
    dfs(a[n].first);

    if (visited[n] == 0) {
        in_cycle = false;
    } else {
        if (in_cycle) {
            visited[n] = 0;
            mn[idx] = min(mn[idx], a[n].second);
        } else visited[n] = 1;  // outside cycle
    }
}

int main() {
    int N; cin >> N;
    a.resize(N);
    for (int i=0; i < N; i++) {
        int u, v;
        cin >> u >> v; u--;
        a[i] = {u,v};
    }

    visited.resize(N, -2);
    idx = -1;
    in_cycle = false;
    long long ans = 0;
    for (int i=0; i < N; i++) {
        ans += (long long)a[i].second;
        if (visited[i] == -2) {
            dfs(i);
        }
    }

    for (auto& i : mn) {
        ans -= (long long)i;
    }

    cout << ans << endl;
}
