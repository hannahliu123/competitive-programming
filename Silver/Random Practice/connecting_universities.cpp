// CF - B. Connecting Universities - R1800

// oh my goshhhh i was kinda close in this problem but i was thinking in circles. the answer
// is annoyingly simple imo except i just wasn't thinking straight. for each edge, i got the
// right idea that we needed to count how many times it could be used but then i overcomplicated
// it when using nodes to calculate it and basdjlaksdjfakjdjvas. anyways, so for each edge,
// if it connects nodes i and j, the number of times it can be crossed in the most optimal
// pairing solution is the subtree size of node i when rooted from j (so just not counting
// the current edge being evaluated) or the subtree size of node j when rooted from i, whichever
// subtree size is minimum. This logically makes sense because there are only the min number
// of nodes on one size which can then be connected to one of the nodes on the other side. So,
// we can calcualte this value by rooting the tree from any node. The subtree size of node n
// when rooted from that node (let's call it s) compared to 2*K-s (the subtree size of 
// everything before node n) tells us how many times the edge from the parent to node n can
// be used. If we sum up this value for all nodes 1->n-1 (so all nodes except node 0), then
// that represents all n-1 edges (assuming we rooted the tree at node 0). 

// my train of thought for this problem was just overall really really messy guys am i cooked

#include <bits/stdc++.h>
using namespace std;

vector<int> subtree;
vector<vector<int>> adj;

void dfs(int n, int prev) {
    for (auto& i : adj[n]) {
        if (i==prev) continue;
        dfs(i, n);
        subtree[n] += subtree[i];
    }
}

int main() {
    int N, K; cin >> N >> K;

    adj.clear(); adj.resize(N);
    subtree.clear(); subtree.resize(N);
    for (int i=0; i < 2*K; i++) {
        int x; cin >> x; x--;
        subtree[x]++;;
    }
    for (int i=0; i < N-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);

    long long ans = 0;
    for (int i=1; i < N; i++) {
        ans += min(subtree[i], 2*K-subtree[i]);
    } cout << ans << endl;
}
