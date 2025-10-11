// CF - A. Copil Copac Draws Trees - R1400

// Start: 5:55
// End: 7:06        1 hr 11 mins

// I dunno maybe my brain wasn't turned on yet cos i haven't solved a problem
// in so long but i spend sm time just thinking and not getting anywhere. The
// key insight for this solution is literally just basic freaking dfs which is
// such a big part of graph and tree problems, so idrk why i didn't just think
// of trying that. tbf i havent solved a graph problem in forever, but i def
// think i shoulve gotten this MUCH faster. My solution is basically to create
// the tree and if you're ever going down a path of edges and the order that 
// an edge was given in the problem statement is less than the previous edge,
// then add 1 to the answer. This is b/c if the previous one occured later, 
// then the current one mustve taken place in another reading. I think this logic
// is pretty straightforward because you can only add edges starting from node 1
// and if that first edge was liek the fifth in a list and the next one was 2nd,
// the obviously you would need an extra reading to get there so it's technically
// processed chronologically and you just take the max of all calculated valeus

// One part of the problem statement that tripped me up was the clarification
// of u and v bc i didn't if you could add an edge if v existed but u didn't. I 
// think you should be able to but it wasn't very clear in the problem. Wtv imma
// just read the editorial now. lets see what i did stupid lol

// Ern dynamic programming...? okay so it's basically the same idea but processes
// it slightly differently using dp. I honestly like my solution much better and
// I also think my explanantions nicer :) hehe so ill take the w

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;  // node to, # order
int ans;

void dfs(int node, int prev, int prev_edge, int a) {
    for (auto i : adj[node]) {
        ans = max(ans, a);
        int n = i.first;
        if (n == prev) continue;

        int edge = i.second; // num/order of current edge
        if (prev_edge < edge) dfs(n, node, edge, a);  // keep on going
        else dfs(n, node, edge, a+1); // new reading
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        adj.clear();
        adj.resize(N);
        ans = 0;
        for (int i{0}; i < N-1; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }

        dfs(0, -1, -1, 1);

        cout << ans << endl;
    }
}
