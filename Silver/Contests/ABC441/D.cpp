// D

// my solution was just to brute force calculate every possible ending value (via
// recursion). my implementation took a while to figure out because recursion has
// always ben tricky for me, but im glad i came to this idea after analyzing time
// constraints (my preparation helped this time yayyayay!!!)

// WOW my solution is pretty much IDENTICAL to the editorial (lowkey like mine MORE
// than editorial) wowsers! i mean this is a pretty straight-forward problem with
// dfs and the only thing special was the restriction of edgeCnt. This makes sense
// though because it's not like i need to return any value. im just editing the global
// ans vector, and once i reach an edgeCnt of 10, i stop iterating (return). i do 
// remember though that when i was implementing this i forgot the return part until
// i used the dubugger. now ik tho :D

#include <bits/stdc++.h>
using namespace std;

int N, M, L, S, T;  // L edges, at least S and at most T
vector<vector<pair<int,int>>> adj;  // dest, cost
vector<bool> ans;   // true is possible

void dfs(int n, int cost, int edgeCnt) {
    if (edgeCnt == L) {
        if (cost >= S && cost <= T) ans[n] = true;
        return;
    }
    for (auto& p : adj[n]) {
        dfs(p.first, cost+p.second, edgeCnt+1);
    }
}

int main() {
    cin >> N >> M >> L >> S >> T;

    adj.clear(); adj.resize(N, vector<pair<int,int>>{});
    for (int i{0}; i < M; ++i) {
        int U, V, C;
        cin >> U >> V >> C;
        U--; V--;
        adj[U].push_back({V, C});
    }

    ans.clear(); ans.resize(N, false);
    dfs(0, 0, 0);
    
    for (int i{0}; i < N; ++i) {
        if (ans[i]) cout << i+1 << ' ';
    } cout << endl;
}
