// USACO 2020 January Contest, Silver
// Problem 3. Wormhole Sort

// Start: 8:04
// End: 9:39        1 hr 35 mins

// OH SNAP BUDDY I DID IT... ok so i did read the tag to see binary search, but
// i really needed that or else i wouldve given up lol. GOSH this took so long.
// Im super duper cuper luper mooper wooper fooper pooper proud of this problem
// OHHHHH my gosh. Um im literally shocked that my uh 100+ lines of code solution
// worked. like what in the worlds man. and also i havent done binary search in 
// a while, so this was good practice. istg the editorials gonna be so neat and
// straightforward and im gonna hate myself, but hey at least this worked? The 
// main peice i missed was the fact that it was binary search, but once i got that
// the only struggle i had was implementation (yeah no that was a big struggle tho)


#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> target;
vector<vector<pair<int, int>>> adj;     // destination, index after sorted
vector<bool> usable;
vector<int> used;   // -1 if not used, otherwise an int representing its group

void dfs(int node, int group) {
    used[node] = group;
    for (auto i : adj[node]) {
        if (usable[i.second] && used[i.first] == -1) dfs(i.first, group);
    }
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    cin >> N >> M;
    target.resize(N);
    bool sorted = true;
    for (int i{0}; i < N; i++) {
        int x;
        cin >> x;
        target[i] = x-1;

        if (target[i] != i) sorted = false;
    }

    if (sorted) {   // already sorted
        cout << -1 << endl;
        return 0;
    }

    adj.resize(N);
    vector<pair<int, pair<int, int>>> wormholes;
    for (int i{0}; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        wormholes.push_back({w,{a,b}});
    }

    // push to adj with indexes
    sort(wormholes.begin(), wormholes.end());   // smallest -> largest width
    for (int i{0}; i < M; i++) {
        int a = wormholes[i].second.first;
        int b = wormholes[i].second.second;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }

    // binary search to see if it's possible with some min width of max path
    int lo = 0, hi = M-1;   // lo & hi index of wormholes
    while (lo < hi) {   // O(logN)
        int mid = lo + (hi - lo + 1) / 2;   // index to remove up to rounding up
        
        usable.clear();
        usable.resize(M, true);
        for (int i{0}; i <= mid; ++i) {
            // remove each wormhole
            usable[i] = false;
        }

        int group = 0;
        used.clear();
        used.resize(N, -1);
        for (int i{0}; i < N; ++i) {
            if (used[i] == -1) {
                group++;
                dfs(i, group);
            }
        }

        bool worked = true;
        for (int i{0}; i < N; ++i) {
            if (used[i] != used[target[i]]) {
                // doesn't work
                worked = false;
                break;
            }
        }

        if (worked) lo = mid;
        else hi = mid - 1;
    }

    cout << wormholes[lo+1].first << endl;
}
