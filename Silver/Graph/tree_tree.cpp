// CF - F. Tree, TREE!!! - R1600

// I figured out that we could use subtrees instead of finding the LCA,
// but i was stuck because of the time complexity. I figured out a 
// straightforward O(N^2) solution, but I couldn't think of anything
// fitting O(N) or O(NlogN) (tho i dont think anything binary search-
// related would've helped). So I decided to look at the editorial and
// now I feel like I was so close and literally just missing that tiny
// little piece (though that tiny peice is probably really hard to figure
// out unless I practice more). Okay so I was already looking at subtree
// sizes and also comparing only the nodes beside each node, but the 
// real solution is just a slight variation of that.

// For every node, you need to compute how much it contributes to the
// final solution (so how many times its subtree size >= k for each node
// as a root). To find this, you should just assume one node as a 
// temporary root (probably just node 1) and then you calculate all 
// subtrees based on that root. Then, for each node, you need to compare
// its subtree size depending on nodes inside (below) and outside (above)
// that subtree. If the calculated subtree size is already >= k then 
// obviously all nodes above (or outside) that node will be valid roots
// in which the current node contributes to the answer. However, to 
// determine if the nodes below (or inside) that node qualify as roots,
// you need something else. This is the part that I was missing. The key 
// insight here (and idk if this should be common knowledge for trees) is 
// that if you chose any node inside (or below) a certain node, its new
// subtree size will be equal to the total number of nodes (N) minus the
// original subtree size. This is very straightforward if you think about
// it because if the subtree size was originally say 5, then the number
// of nodes above that node is N-5. If you chose any node inside that 
// original node, then all the nodes above it could be chosen and the 
// LCA would still be that node. I know that's a really bad explanation
// but im not gonna waste my time trying to rephrase it because its 
// honestly such a simple concept especially if you draw it out. Even
// when there are multiple branches, you could pick nodes from different
// branches cos if you "flipped" the tree those branches would still all
// be under the certain node. Now let me try to implement this

// I need to break things up into different cases (not too many ofc but
// be able to separate certain senarios). I think break into 2 is pretty
// common (like this problem) but up to four might work

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree;

void dfs(int node, int prev) {
    subtree[node] = 1;
    for (auto i : adj[node]) {
        if (i == prev) continue;
        dfs(i, node);
        subtree[node] += subtree[i];
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K;
        cin >> N >> K;
        adj.clear();
        adj.resize(N);
        subtree.clear();
        subtree.resize(N, 0);
        for (int i{0}; i < N-1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[--u].push_back(--v);
            adj[v].push_back(u);
        }

        dfs(0, -1);

        long long ans = 0;
        for (int i{0}; i < N; ++i) {
            int s = subtree[i];
            if (s >= K) ans += N-s; // all above (excluding itself)
            if (N-s >= K) ans += s;
        }

        cout << ans+N << endl;
    }
}
