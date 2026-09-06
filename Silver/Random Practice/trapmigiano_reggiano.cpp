// CF - C. Trapmigiano Reggiano - R1700

// i knew this had to be some greedy tree problem but i couldn't figure out what exactly
// greedy idea was. I spent so much time trying a solution involving looking at the nodes
// to the left of en in the direction of st vs the nodes to the right of en. But a greedy
// idea involving that goe complicated quickly and i didn't end up getting anywhere. in
// this case, I should've just abandoned that old idea and tried to think of something
// new completely unrelated OR i should've just decided to read the hints and take a 
// peek at the editorial instead of wasting sm time and feeling like im getting nowhere

// okay so i could've seen that if we wanted the mouse to end on en, then it's ideal to
// have the last cheese appearance just be on en itslef (well, not rly i mean ig it
// doesn't have to). BUT if that was the case, you'd have to notice that the previous
// step before that had to have the mouse end on a node right next to en. then the step
// before that should be a node next to the node next to en (so it could be en itself).
// in this greedy solution, each step pulls the mouse closer to the current level 
// away from en such that it will NEVER go below the current level (because the nodes
// below that level have already been selected). in this way, by the time you finally
// select en, it's guarenteed to end up at the root, en, because it physically cannot
// end up below en

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<pair<int,int>> dist;

void dfs(int node, int prev, int d) {
    dist[node] = {d, node+1};
    for (auto& i : adj[node]) {
        if (i != prev) dfs(i, node, d+1);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N, st, en; cin >> N >> st >> en;
        st--; en--;
        adj.clear(); adj.resize(N);
        dist.clear(); dist.resize(N);
        for (int i=0; i < N-1; i++) {
            int u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(en, -1, 0);
        sort(dist.rbegin(), dist.rend());
        for (auto& i : dist) cout << i.second << ' ';
        cout << '\n';
    }
}