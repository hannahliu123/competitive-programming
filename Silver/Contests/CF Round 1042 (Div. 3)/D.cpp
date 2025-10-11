// Problem D

// This problem took me such a long time because i got tripped up by the word "diameter".
// I didn't understand how the test cases even worked because i thought the best solution
// always envolved taking the two diameter endpoints so it took me a really long time to
// even understand the problem. After that, though, it juts became a greedy problem of
// picking the one with most child endpoints and then keep picking that one

// Another more graph-like approach (instead of greedy heh) would be counting for each
// possible root, what is the number of leaves with a depth greater than one (so not 
// directly connected to the root). This is basically the exact same interpretation as
// my contest solution

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> adj(N);
        for (int i{0}; i < N-1; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int end = 0;
        int mx = 0;
        bool connected = false;
        for (int i{0}; i < N; ++i) {
            if (adj[i].size() == N-1) {
                connected = true;
                break;
            }

            int end_children = 0;
            for (auto c : adj[i]) {
                if (adj[c].size() == 1) end_children++;
            }

            end += end_children;
            mx = max(mx, end_children);
        }

        if (connected) cout << 0 << endl;
        else cout << end - mx << endl;
    }
}
