// CF - C. News Distribution - R1400

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> adj(N);
    for (int i{0}; i < M; ++i) {
        int k;
        cin >> k;

        vector<int> friends(k);
        for (int j{0}; j < k; ++j) {
            cin >> friends[j];
            --friends[j];
        }

        // connect each member to the first member of the group (no more)
        for (int f{1}; f < k; ++f) {
            adj[friends[0]].push_back(friends[f]);
            adj[friends[f]].push_back(friends[0]);
        }
    }

    vector<bool> visited(N, false);
    vector<int> ans(N, 0);
    queue<int> q{};
    for (int i{0}; i < N; ++i) {
        if (visited[i]) continue;

        vector<int> connected{};    // track all connected users
        visited[i] = true;
        q.push(i);

        // BFS to calculate total connected users
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            connected.push_back(n);
            for (auto j : adj[n]) {
                if (visited[j]) continue;
                visited[j] = true;
                q.push(j);
            }
        }

        for (auto c : connected) ans[c] = connected.size();
    }

    for (int i{0}; i < N; ++i) cout << ans[i] << ' ';
    cout << endl;
}

// TLE :(
