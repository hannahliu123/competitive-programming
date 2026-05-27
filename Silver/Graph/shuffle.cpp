// USACO 2017 December Contest, Silver
// Problem 3. The Bovine Shuffle

// Start: 1:09
// End: 1:21        12 mins

// we're just looking for the number of cows within cycles

#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int ans = 0;
bool in_cycle;
vector<int> visited;

void dfs(int node) {
    if (visited[node] != -2) {
        if (visited[node] == -1) {
            visited[node] = 1;
            ans++;
            in_cycle = true;
        } return;
    }

    visited[node] = -1; // visiting
    dfs(a[node]);

    if (visited[node] > 0) {
        in_cycle = false;
    } else {
        if (in_cycle) ans++;
        visited[node] = 1;  // visited
    }
}

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int N; cin >> N;
    a.resize(N);
    for (auto& i : a) {
        cin >> i; i--;
    }

    ans = 0;
    in_cycle = false;
    visited.resize(N, -2);  // -2: unvisited
    for (int i=0; i < N; i++) {
        if (visited[i] == -2) dfs(i);
    }

    cout << ans << endl;
}
