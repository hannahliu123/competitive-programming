// CF - E. Fair and Square - R1600

// Start: 9:22
// End: 10:56       1 hr 34 mins

// CHAT WHY ARE THESE PROBLEMS GETTING HARDER AND HARDER ERM WTH MAN. I THOUGHT I WAS GOOD
// WITH 1600 😭😭 oh welp at least i semi figured this out on my own :/ erm i got the idea
// but like figuring out the implementation specfics took way too long (esp getting that 
// formula which now that i think abt it wasn't even that bad). The part that took super long
// was determining how to count solutions got each perfect square node.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree;

void dfs(int node, int prev) {
    for (auto& i : adj[node]) {
        if (i != prev) {
            dfs(i, node);
            subtree[node] += subtree[i];
        }
    }
    subtree[node]++;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (int i=0; i < N; i++) cin >> a[i];
        adj.clear(); adj.resize(N);
        subtree.clear(); subtree.resize(N,0);
        for (int i=0; i < N-1; i++) {
            int u,v; cin >> u >> v; u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0,-1);

        long long ans = 0;
        for (int i=0; i < N; i++) {
            int s = (int)sqrt(a[i]);
            if (a[i]%s==0 && a[i]/s==s) {
                long long sum = 0;
                long long mult = 0, mult2 = 0;
                int idx = 0;
                for (auto& j : adj[i]) {
                    if (subtree[j] > subtree[i]) continue;
                    int curr = subtree[j];
                    if (idx > 1) {
                        mult2 += (mult*curr);
                    } if (idx > 0) {
                        mult += (sum*curr);
                    }
                    sum += curr;
                    idx++;
                }

                int curr = N-sum-1;
                if (idx > 1) {
                    mult2 += (mult*curr);
                } if (idx > 0) {
                    mult += (sum*curr);
                } sum += curr;

                ans += mult + mult2;
            }
        }

        cout << ans << '\n';
    }
}