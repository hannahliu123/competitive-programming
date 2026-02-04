// USACO 2024 January Contest, Silver
// Problem 2. Potion Farming

// Start: 6:43
// End: 7 39 uhguhguhg

// k so i cant rly figure out if it matters what potions we decide to target.
// i think i got the right answer for the total numebr of traversals if u need
// to reach all the nodes, but idrk if there's a desireable order. i mean it makes
// logical sense to pick up a potion from the lowest subtree size first becuase 
// that's your only opportunity. i feel like my code shoudl work thennn but i prob
// implemented something wrong whether thats indexing or if i just exceeded time
// compexlity. ik for a fact that i tle'd on tc 9 but maybe its cos i got stuck 
// in dfs? i also have no idea what my time complexity is heh. wait also i got wa
// for tc 2 and 5 so im wondering if my solution relaly just doesn't work for 
// larger test cases? i feel like i rly did rush the implementation for this
// problem...

// ok i figured out tc 2 and 5 were just because if you had N=2 then the start
// node (0) would be counted as and end node so that was easy but i think i either
// used too much memory or time for the other ones. 

// oh ok so i was exceeding memory. because the way i was storing the vector t
// meant that if say there was a logn line of node 1-2-3-4-5-6 then 6 branched out
// to say 6 more leaf nodes, each of the modes 1-6 would have a vector of length
// 6 in t[node]. Now say there are N=10^5 nodes. if N/2 of them each have each 
// have a vector of N/2 ints, that's around a total of N^2 integers stored (10^10).
// one int is 4 bytes and so that would result in 40000 MB. the limit for usaco
// is 256 MB!!

// another issue with this is the way i copied vectors. this means the creation of
// t also surpassed the time limit. if im copying x elemnts from one vector to 
// another, it takes O(x) time. so if i copy a total of 10^10 integers, that's
// gonna go past our time limit!! i should've spent more time thinking about this
// but i was rushing (again like always ughh) but even without calculating it, u
// can kinda sense that itll be a stretch so it was very naive of me to still 
// implement it anyways (hey at least i got the first few test cases :/)

// once i realized the way of storing t was so unreasonable, i should've tried
// looking for a different way to solve this problem. one thing i did notice is
// that i had to "backtrack" for each potion i decided to take and update all 
// the parent nodes to the node that had the potion. this clearly would've taken
// too long if say we had 10^4 paths and had to backtrack each time. because of 
// this, i kinda just disregarded this solution, when in reality, we could've
// processed all of this DURING the dfs. So basically, after you process how 
// many leaves are below a given node, that is the total number of traversals
// that involve the current node. So, if there were 3 potions on that node but it
// only has two traversals, you can add the minimum of those values (2) to the
// answer because it'll be impossible to reach it a third time!! then when you
// update the parent node, instead of adding 3 to its leaves, you add 0. This is
// such a nice and clean solution!

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> leaves;
vector<int> p;
vector<int> potions;
int ans;

void countLeaves(int node, int prev) {
    if (node!=0 && adj[node].size()==1) leaves[node]++;
    for (auto& i : adj[node]) {
        if (i==prev) continue;
        countLeaves(i, node);
        leaves[node] += leaves[i];
    }
}

void dfs(int node, int prev) {
    if (node!=0 && adj[node].size()==1) leaves[node]++;
    for (auto& i : adj[node]) {
        if (i==prev) continue;
        dfs(i, node);
        leaves[node] += leaves[i];  // remaining leaves
    }
    
    ans += min(potions[node], leaves[node]);
    leaves[node] = max(0, leaves[node]-potions[node]);
}

int main() {
    int N;
    cin >> N;

    p.clear(); p.resize(N);
    for (int i{0}; i < N; ++i) {
        cin >> p[i]; p[i]--;
    }

    adj.clear(); adj.resize(N);
    leaves.clear(); leaves.resize(N, 0);
    for (int i{0}; i < N-1; ++i) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    countLeaves(0, -1);

    potions.clear(); potions.resize(N, 0);
    ans = 0;
    for (int i{0}; i < leaves[0]; ++i) {    // for each traversal
        potions[p[i]]++;
    }

    leaves.clear(); leaves.resize(N, 0);
    dfs(0, -1);

    cout << ans << endl;
}


