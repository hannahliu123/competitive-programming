// USACO 2023 February Contest, Silver
// Problem 3. Moo Route II

// i didn't know how to make my code faster. right now im just doing a simple dfs
// and continuing it as long as there is a more desireable landing time. it's hard
// to calculate the exact worst case time complexity, but say if you had one node
// connected to 100 other nodes, then each of those nodes connected back to that
// original node with a smaller arrival time. Now if there are approximately
// 2*10^5 nodes connected, you would visited each of those nodes 2*10^5 times,
// leading to at least an O(N^2) time complexity which is too much.

// To pass the full constraints, we need a strategy that guarantees each flight is
// processed at most once. The answer lies in a greedy sorting optimization. No
// matter what, we want Bessie to arrive in each airport as early as possible, bc
// that means she has more flight options to take. We also need to realize that the
// departure times are set in stone, so even if Bessie arrives earlier at an airport
// (say at time 5 vs 500), if the flight only departs at time 1000, Bessie can still
// only leave at time 1000. So, using this logic, we should always greedily process
// all flights per airport from latest (largest) departure time to earliest (smallest)
// departure time. This way, when Bessie first arrives at an airport, she should
// take all flights possible, then if those flights end up allowing her to come back
// and visit this same airport but at an earlier time, then she can take the new
// possible flights without having to retake the ones she knows she already took! 
// This optimization allows us to only take each flight one time O(M), though we do
// need to sort all the flights in O(M log M) time. 

// Now that we have a plan, we need to pick DFS or BFS. usually i just always go with
// dfs which is kinda bad because i literally NEVER practice using bfs. In this case,
// either works, so imma just use dfs again! also i think im gonna store the times
// from least -> greatest so i can keep calling .back() and also .pop_back() to just
// remove flights once we've taken them. The bfs approach would just involve a queue
// tracking the next airport we can visit and the time we arrive there. umm i think
// ill code bfs just to practice lol

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> flight;
vector<int> a;
vector<int> ans;

int main() {
    int N, M; cin >> N >> M;

    flight.resize(N);
    for (int i=0; i < M; i++) {
        int c, r, d, s; // depart airport, time, land airport, time
        cin >> c >> r >> d >> s;
        flight[c-1].push_back({r, d-1, s});
    } for (int i=0; i < N; i++) {
        // sort each airports' flights by departure time
        sort(flight[i].begin(), flight[i].end());   // l -> g
    }

    a.resize(N);
    for (auto& i : a) cin >> i;
    
    ans.resize(N, INT_MAX);
    queue<pair<int,int>> q{};
    q.push({0,0});  // airport 0 at time 0
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int airport = p.first;
        int arrival = p.second;
        ans[airport] = min(ans[airport], arrival);
        if (airport != 0) arrival += a[airport];

        if (flight[airport].size() == 0) continue;
        auto f = flight[airport].back();
        while (f[0] >= arrival) {
            flight[airport].pop_back();
            q.push({f[1], f[2]});
            if (flight[airport].size() > 0) f = flight[airport].back();
            else break;
        }
    }

    for (auto& i : ans) {
        if (i == INT_MAX) cout << -1 << '\n';
        else cout << i << '\n';
    }
}
