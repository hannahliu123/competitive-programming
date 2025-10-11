// USACO 2018 January Contest, Silver
// Problem 3. MooTube

// Start: 2:14
// End: 3:14        1 hr (wow exactly)

// Ughhh I understood the problem incorrectly

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> tree;    // node, relevance
int K;
int ans;

void dfs(int node, int prev) {
    for (auto p : tree[node]) {
        // if the relevance of that edge was less than K, then any nodes reachable
        // from that point shouldn't be considered
        if (p.first != prev && p.second >= K) {
            ans++;
            dfs(p.first, node);
        }
    }
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;

    tree.resize(N);
    for (int i{0}; i < N-1; ++i) {
        int p, q, r;
        cin >> p >> q >> r;
        p--; q--;
        tree[p].push_back({q, r});
        tree[q].push_back({p, r});
    }

    while (Q--) {   // how many videos will be suggested to viewers of video v given k
        int v;
        cin >> K >> v;
        v--;

        ans = 0;
        dfs(v, -1);
        cout << ans << endl;
    }
}
