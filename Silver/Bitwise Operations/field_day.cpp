// USACO 2023 US Open Contest, Silver
// Problem 2. Field Day

// Whenever you see small bounds, you should at least consider something brute-force-
// related over those small bounds. Here, C <= 18 means we can process every possible
// team combination (b/c 2^18 = 262144). For each team, if we represented the Gs and Hs
// as 0s and 1s, we know that we want to pick a team that is exactly the opposite (or
// bitwise ~) of the current team. If that team doesn't exist, we want to pick the team
// closest to that opposite. Now say we had a graph with 262144 nodes, each node
// representing a possible team. The edges can connect teams by flipping 1 bit. So,
// starting from that opposite team, we want to know the minimum number of edges we
// need to travel over before reaching a team combination that does exist. Each node
// can branch off in C (18) different ways, so we can have 262144*18 edges (though then
// a bunch are repeated but im too lazy to calculate that so we can use this as a rough
// estimate). This means we can't traverse the whole graph for every team, but we can
// precompute all the distances for each node. Then, for each team we can find the 
// min distance from the opposite team to find the answer in O(1)!

// oh yeah also we should use bfs cos we're looking for shortest path so dfs would be
// really redundant :/

// yeah i definitely wouldn't have thought of this... ig some hints were the C was very
// very small. tbf i did consider the complement idea and then finding a team that was
// most similar to the complement, but i thought it wouldn't be feasible to implement
// so i just didnt think much abt it. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, N; cin >> C >> N;
    vector<int> teams(N);
    vector<int> dist(1<<C, C);
    queue<pair<int,int>> q{};
    for (int i=0; i < N; i++) {
        string s; cin >> s;
        int x = 0;
        for (int j=0; j < C; j++) {
            if (s[j] == 'H') x |= (1<<j);
        }
        teams[i] = x;
        q.push({x, 0});
        dist[x] = 0;
    }
    
    while (!q.empty()) {
        int x = q.front().first;
        int d = q.front().second;
        q.pop();

        for (int i=0; i < C; i++) {
            int y = x ^ (1<<i);
            if (dist[y] > d+1) {
                q.push({y, d+1});
                dist[y] = d+1;
            }
        }
    }

    for (int i=0; i < N; i++) {
        int x = teams[i];
        for (int j=0; j < C; j++) {
            x ^= (1<<j);
        }
        int d = dist[x];
        cout << C-d << '\n';
    }
}
