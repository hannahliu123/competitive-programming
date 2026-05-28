// USACO 2022 February Contest, Silver
// Problem 1. Redistributing Gifts

// Start: 1:18
// End: 1:50        32 mins

// i think a main reason i figured this one out was because i knew it was suppoused
// to be a graph problem. at first i didn't even know how it could be one, so i don't
// think i would've began considering to look at this problem using nodes and edges.
// i guess one giveaway is that the problem is asking for rearrangements, so that
// tells us we need a way to have certain cows exchange gifts and we can store possible
// exchanges using edges. the main idea for this problem is to just start with each
// cow giving its gift to someone else and seeing if we can follow a path back to the
// original cow

// i def wouldn't have figured it out if the required time complexity was O(N^2) bc
// then u need SCC which i havent learned :(

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
set<int> returned;

void dfs(int n, int orig) {
    visited[n] = true;
    for (auto& i : adj[n]) {
        if (!visited[i]) dfs(i, orig);
        else if (i==orig) returned.insert(n);
    }
}

int main() {
    int N; cin >> N;
    vector<vector<int>> desired(N);
    adj.resize(N);
    for (int i=0; i < N; i++) {
        bool seen_i = false;
        for (int j=0; j < N; j++) {
            int x; cin >> x; x--;
            if (x==i) seen_i = true;
            if (!seen_i) {
                desired[i].push_back(x);
                adj[x].push_back(i);    // gift x can be given to cow i
            }
        }
    }

    for (int i=0; i < N; i++) {
        returned.clear();
        visited.clear();
        visited.resize(N, false);
        dfs(i, i);

        int ans = i+1;
        for (int x : desired[i]) {
            if (returned.count(x)) {
                ans = x+1;
                break;
            }
        } cout << ans << '\n';
    }
}
