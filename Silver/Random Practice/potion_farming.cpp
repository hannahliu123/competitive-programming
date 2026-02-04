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
// used too muhc memory or time for th eother ones.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> leaves;
vector<vector<int>> t;
int nxt;

vector<int> dfs(int node, int prev) {
    if (node!=0 && adj[node].size()==1) {
        leaves[node]++;
        nxt++;
        t[node].push_back(nxt);
    }
    for (auto& i : adj[node]) {
        if (i==prev) continue;
        vector<int> v2 = dfs(i, node);
        copy(v2.begin(), v2.end(), back_inserter(t[node]));
        leaves[node] += leaves[i];
    } return t[node];
}

int main() {
    int N;
    cin >> N;

    vector<int> p(N);
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

    nxt = -1;
    t.clear(); t.resize(N);
    dfs(0, -1);
    int traversals = leaves[0];
    vector<pair<int,int>> p2(traversals);

    for (int i{0}; i < traversals; ++i) {
        p2[i] = {leaves[p[i]], p[i]};
    } sort(p2.begin(), p2.end());

    int potions = 0;
    vector<bool> used(traversals, false);
    for (int i{0}; i < traversals; ++i) {
        int node = p2[i].second;
        for (auto& path : t[node]) {
            if (!used[path]) {
                used[path] = true;
                potions++;
                break;
            }
        }
    }

    cout << potions << endl;
}


