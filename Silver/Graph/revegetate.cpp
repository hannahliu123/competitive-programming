// USACO 2019 February Contest, Silver
// Problem 3. The Great Revegetation

// Start: 10:52
// End: 11:29       37 mins!

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, char>>> adj;
vector<int> colors;
bool possible = true;

void dfs(int n, int c) {
    colors[n] = c;
    
    for (auto i : adj[n]) {
        if (colors[i.first] != -1) {    // already visited
            if (i.second == 'S' && colors[i.first] != c) {
                possible = false;
                return;
            } else if (i.second == 'D' && colors[i.first] == c) {
                possible = false;
                return;
            }
        } else {    // not visited
            int color;
            if (i.second == 'S') color = c;
            else color = (c == 1? 2 : 1);
            dfs(i.first, color);
        }
    }
}

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    cin >> N >> M;

    adj.resize(N);
    for (int i{0}; i < M; ++i) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        adj[--a].push_back({--b, c});
        adj[b].push_back({a, c});
    }

    string s = "1";
    colors.resize(N, -1);
    for (int i{0}; i < N; ++i) {
        if (colors[i] == -1) {
            dfs(i, 1);
            s.push_back('0');
        }
    }

    if (possible) cout << s << endl;
    else cout << 0 << endl;
}
