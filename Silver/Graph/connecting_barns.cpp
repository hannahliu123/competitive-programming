// USACO 2021 December Contest, Silver
// Problem 2. Connecting Two Barns

// Start: 6:09
// End: 8:10        2 hrs 1 min but w/o last two test cases & I realized my logic
//                  was flawed and it was out of luck that I even managed to pass 
//                  the first 8. But this led me to my actual solution... sooooo

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
        b1_color = -1;
        b2_color = -1;
        for (int i{0}; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int next_color = 0;
        for (int i{0}; i < N; ++i) {
            if (color[i] == -1 && adj[i].size() > 0) dfs(i, ++next_color);
        }

        if (b1_color != -1 && b1_color == b2_color) {
            cout << 0 << endl;
            continue;
        } else if (b2_color == -1) {
            b2_color = next_color+1;
            color[N-1] = b2_color;
        } if (b1_color == -1) {
            b1_color = 0;
            color[0] = 0;
        }

        int b1 = 0, b2 = 0;
        long long ans = LLONG_MAX;
        bool barn2 = true;     // true = right barn is barn 2
        while (b1 < N && b2 < N) {
            bool found = false;
            if (barn2) {    // barn 2 on right  
                b2 = b1;
                for (int i{b1}; i < N; ++i) {
                    if (color[i] == b1_color) b1 = i;
                    else if (color[i] == b2_color) {
                        b2 = i;
                        found = true;
                        break;
                    }
                } if (!found) break;

                map<int, pair<int, int>> paths{};   // color: start, end
                for (int i{b1+1}; i < b2; ++i) {
                    if (color[i] != -1) {
                        if (paths.find(color[i]) == paths.end()) {  // doesn't exist
                            paths[color[i]] = {i, i};
                        } else {    // already exists
                            paths[color[i]].second = i;
                        }
                    }
                }

                long long l = (b2-b1)/2;
                long long r = b2-(b1+l);
                long long mn_cost = l*l + r*r;
                for (auto i : paths) {
                    pair<int, int> p = i.second;
                    l = p.first-b1;
                    r = b2-p.second;
                    mn_cost = min(mn_cost, l*l + r*r);
                }

                ans = min(ans, mn_cost);
                barn2 = false;
            } else {
                b1 = b2;
                for (int i{b2}; i < N; ++i) {
                    if (color[i] == b2_color) b2 = i;
                    else if (color[i] == b1_color) {
                        b1 = i;
                        found = true;
                        break;
                    }
                } if (!found) break;

                map<int, pair<int, int>> paths{};   // color: start, end
                for (int i{b2+1}; i < b1; ++i) {
                    if (color[i] != -1) {
                        if (paths.find(color[i]) == paths.end()) {  // doesn't exist
                            paths[color[i]] = {i, i};
                        } else {    // already exists
                            paths[color[i]].second = i;
                        }
                    }
                }

                long long l = (b1-b2)/2;
                long long r = b1-(b2+l);
                long long mn_cost = l*l + r*r;
                for (auto i : paths) {
                    pair<int, int> p = i.second;
                    l = p.first-b2;
                    r = b1-p.second;
                    mn_cost = min(mn_cost, l*l + r*r);
                }

                ans = min(ans, mn_cost);
                barn2 = true;
            }
        }

        cout << ans << endl;
    }
}
