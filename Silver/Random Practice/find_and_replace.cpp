// USACO 2023 January Contest, Silver
// Problem 1. Find and Replace

// Ok i spent 40 mins on this and came up with this solution but it completely doesnt
// work :'( ahh okay so my idea was so so close but i missed an edge case where if
// there's a cycle within a larger connected component, you don't need to increase
// ans anymore. why? well if multiple nodes point to some node i which we can treat
// as the start of the cycle, you can just set the node IN the cycle that points to
// i to some node OUTSIDE of the cycle that points to i. then eventually you'll need
// to set the outside ones to i anyways so you don't need to use a placeholder letter!

// um okay so i havent worked with successor graphs in a while so i had to revisit
// that implementation. my implementation in general for this problem is scarily messy
// heh and it didn't work at first cos i lowkey implemented it wrong.. heh

// this is a reminder for debugging that its so easy to miss little edge cases and
// also just implement things incorrectly even if the general idea of the problem
// isn't that hard/tricky. also i think this would be considered one of the easier
// usaco problems for silver soooo rip

#include <bits/stdc++.h>
using namespace std;

bool pos, in_cycle, alone_cycle;
int N, ans, d;
vector<int> adj;
vector<int> visited;
vector<set<int>> incoming;

void dfs(int node) {
    if (visited[node] != -1) {  // visited
        if (visited[node] == 0) {   // cycle!
            visited[node] = 2;  // start of cycle
            in_cycle = true;
            alone_cycle = true;
            if (d==52) pos = false;
        } return;
    }

    visited[node] = 0;  // currently being visited
    int to = adj[node];
    if (to != -1 && to != node) {
        ans++;
        dfs(to);
    }

    if (visited[node] == 2) {   // back to beginning of cycle
        if (incoming[node].size() > 1) alone_cycle = false;
        in_cycle = false;
    } else {
        if (in_cycle) {
            visited[node] = 2;    // inside cycle and fully visited
            if (incoming[node].size() > 1) alone_cycle = false;
        } else visited[node] = 1;      // outside cycle and fully visited
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        string s, e; cin >> s >> e;
        N = s.length();
        pos = true;
        adj.clear(); adj.resize(52, -1);
        visited.clear(); visited.resize(52, -1);
        incoming.clear(); incoming.resize(52, {});
        for (int i=0; i < N; i++) {
            int from=s[i]-'A', to=e[i]-'A';
            if (from > 31) from -= 6;
            if (to > 31) to -= 6;
            if (adj[from] != -1 && adj[from] != to) {
                pos = false; break;
            }
            adj[from] = to;
            incoming[to].insert(from);
        }

        d = 0;
        for (int i=0; i < 52; i++) {
            if (incoming[i].size()>0) d++;
        }

        if (!pos) {
            cout << -1 << '\n'; continue;
        }
        
        ans = 0;
        for (int i=0; i < 52; i++) {
            if (visited[i] == -1) {
                alone_cycle = false;
                in_cycle = false;
                dfs(i);
                if (alone_cycle) ans++;
                if (!pos) break;
            }
        }

        cout << (pos? ans : -1) << '\n';
    }
}