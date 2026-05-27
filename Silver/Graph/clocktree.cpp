// USACO 2020 February Contest, Silver
// Problem 3. Clock Tree

// Start: 1:47
// End: 2:44        57 mins

// heheh im so proud of this one but my solution is like wayyy different from the 
// editorial. i just ran dfs on every possible node treating i as the root, but the
// editorial presents a O(N) time solution where you need to make the realization
// that you can treat the tree as a bipartite graph because well it's a tree, so
// each node can just be a different color than any nodes its connected to. Then, we
// can notice that each time you take one step, the sum of times in the group you
// just enter (let's say group 1) increases. then if you take another step, the sum
// in group 2 increases. For every even number of steps you take, the sums in each
// group increase my the same amount (and in other words, their change in difference
// is 0). Our end goal is to make every single clock equal to 12, so say if there's
// a clock at 3 in group 1, we need to visit that room 9 times to get it to 12. in
// order to do that, we also need to visit a room from group 2 9 times so we can
// alternate back and forth. We can generalize this observation to each combined
// group. Say if the total sum of group 1 with 10 nodes is 80, meaning we need to 
// visit group 1 at least 40 times (or 40 + a multiple of 12). Then say group 2
// needs to be visited 28 times (or 28 + a multiple of 12). In order to result in
// an equal number of visits, the lower number + 12x must equal the higher number
// because any additional multiples of 12 would just cancel out. In this case, 
// 40 = 28+12, so we have a valid combination. But in other words, if two numbers
// can be made equal by adding or subtracting multiples of 12, that means their
// remainders when divided by 12 are the same!

// Another thing to notice, though, is that if we only used up an odd number of 
// moves, then we could actually have the remainder of one of the groups be one
// more/less than the other group because we would have one extra visit and no
// "returning" visit to cancel it out.

// So using this logic, the final solution is that if both remainders are equal,
// it's possible to start from any node and eventually set all equal to 12. But
// if the remainder of one group is greater, we can't start from a node within
// that group because we need to visit that group an extra time. we can use an 
// odd number of moves to start on a node in the opposite group in order to end
// on a node in that group. Finally, if the difference in the remainders is more 
// than 1, it's impossible to start from any node and acheive a remainder of all 12s

#include <bits/stdc++.h>
using namespace std;

vector<int> room;
vector<vector<int>> adj;

int dfs(int n, int prev) {
    int cnt = 12-room[n];
    if (prev != -1 && adj[n].size() == 1) {
        return cnt;
    }

    for (auto& i : adj[n]) {
        if (i != prev) cnt -= dfs(i, n);
    }

    while (cnt < 0) cnt += 12;

    return cnt;
}

int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);

    int N; cin >> N;
    room.resize(N);
    for (auto& i : room) cin >> i;
    adj.resize(N);
    for (int i=0; i < N-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i=0; i < N; i++) {
        // try rooting the tree at each i
        int cnt = dfs(i, -1);
        // if (cnt==11 || cnt==12) ans++;
        if (cnt==11 || cnt==0) ans++;
    }
    
    cout << ans << endl;
}
