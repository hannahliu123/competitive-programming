// USACO 2022 December Contest, Silver
// Problem 1. Barn Tree

// bro i feel so frustrated and out of it recently. like every time i do these
// problems i end up just staring at the screen with no idea whatsoever of what to
// do. i end up just like staring for hours which i think isn't the best method of
// practice. i usually don't even get anywhere. and also when i do these problems
// im not like completely focused either. i lose my concentration after like 30
// minutes of not getting it, then i just start getting "sleepy" and "tired". ughh
// i think imma go back to doing cf problems. maybe get myself to be able to do 
// some higher rated problems like 1700 1800. as for this one, i was just giving up
// atp and didn't really get anywhere. like i feel like i got the ideas but had no 
// idea what to do with those ideas. i just need to practice more and do some lower
// leveled problems. normal usaco silver is still too hard for me rn

// OHH my lord this problem is legit ragebaiting me. i got tc 3 and 5 right but like
// all the others wrong for liek EVER and i kept tryna figure out what was wrong and 
// it kept only being tc 3 and 5 that wsa right and GUESS what the problem was. BRO.
// long longs. im so annoyed. now i know tho that just because i don't get a ! error
// doesnt mean i don't have a long long issue. the memory limit was larger so thats
// also a sign that long longs are used a LOT. i dont need to be stingy with memory
// and i should calculate where it's needed more often.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<long long> haybales;
vector<long long> subtrees;
long long average;
vector<vector<long long>> ans;    // from, to, how many

void dfs(int node, int prev) {
    // if subtrees[node] is pos then it gives haybales to its parent
    subtrees[node] = haybales[node]-average;
    for (auto i : adj[node]) {
        if (i == prev) continue;
        dfs(i, node);
        subtrees[node] += subtrees[i];
    }
}

void dfs2(int node, int prev) {
    for (auto i : adj[node]) {
        if (i != prev && subtrees[i] > 0) {
            dfs2(i, node);
        }
    }

    for (auto i : adj[node]) {
        if (i != prev && subtrees[i] <= 0) {
            if (subtrees[i] < 0) ans.push_back({node, i, -subtrees[i]});
            dfs2(i, node);
        }
    }

    if (node != 0 && subtrees[node] > 0) {
        ans.push_back({node, prev, subtrees[node]});
    }
}

int main() {
    int N;
    cin >> N;

    long long sum = 0;
    ans.clear();
    subtrees.clear();
    subtrees.resize(N);
    haybales.clear();
    haybales.resize(N);
    for (auto& i : haybales) {
        cin >> i;
        sum += i;
    } average = sum/(long long)N;

    adj.clear();
    adj.resize(N);
    for (int i{0}; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    dfs2(0, -1);

    cout << ans.size() << '\n';
    for (auto& v : ans) {
        cout << v[0]+1 << ' ' << v[1]+1 << ' ' << v[2] << '\n';
    }
}
