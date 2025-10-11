// wanna edit smthing but dont wanna mess up curr code

// Start: 8:10
// End: 8:44        34 mins!

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;      // color of barn 1 path = b1_color, color of barn 2 path = b2_color
int N, M, b1_color, b2_color;

void dfs(int node, int c) {
    color[node] = c;
    if (node == 0) b1_color = c;
    if (node == N-1) b2_color = c;
    for (auto i : adj[node]) if (color[i] == -1) dfs(i, c);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> N >> M;

        adj.clear();
        adj.resize(N);
        color.clear();
        color.resize(N, -1);
        for (int i{0}; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int next_color = 0;
        for (int i{0}; i < N; ++i) {
            if (color[i] == -1 && (adj[i].size() > 0 || i==0 || i==N-1)) {
                dfs(i, ++next_color);
            }
        }

        if (b1_color == b2_color) {
            cout << 0 << endl;
            continue;
        }

        vector<pair<int,int>> dist(N);  // closest dist from barn 1 & barn 2
        map<int, pair<long long, long long>> paths{};    // color: min dist b1, min dist b2
        long long ans = LLONG_MAX;
        int b1 = -1, b2 = -1;
        for (int i{0}; i < N; ++i) {    // values infront
            if (color[i] == b1_color) b1 = i;
            if (color[i] == b2_color) b2 = i;
            dist[i] = {i-b1, (b2==-1? N-1-i : i-b2)};
        } b1 = -1;
        for (int i{N-1}; i >= 0; --i) {     // values behind
            if (color[i] == b1_color) b1 = i;
            if (color[i] == b2_color) b2 = i;
            dist[i].first = min(dist[i].first, (b1==-1? 1000000 : b1-i));
            dist[i].second = min(dist[i].second, b2-i);
            long long l = dist[i].first;
            long long r = dist[i].second;
            ans = min(ans, l*l + r*r);

            // check if part of unconnected path
            if (color[i] != b1_color && color[i] != b2_color && color[i] != -1) {
                if (paths.find(color[i]) == paths.end()) {  // doesn't exist
                    paths[color[i]] = {l, r};
                } else {    // exists
                    paths[color[i]].first = min(paths[color[i]].first, l);
                    paths[color[i]].second = min(paths[color[i]].second, r);
                }
            }
        }

        // Now try using unconnected paths values
        for (auto i : paths) {
            auto p = i.second;
            ans = min(ans, p.first*p.first + p.second*p.second);
        }

        cout << ans << endl;
    }
}
