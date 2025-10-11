// CF - F. Forever Winter - R1300

// Start: 11:20
// End: 11:42

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> adj(N);
        for (int i{0}; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int arms{0};
        set<int> main{};
        for (int i{0}; i < N; ++i) {
            if (adj[i].size() == 1) {
                arms++;
                main.insert(adj[i][0]);
            }
        }

        cout << main.size() << ' ' << arms/(main.size()) << endl;
    }
}
