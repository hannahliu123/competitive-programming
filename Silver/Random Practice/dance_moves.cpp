// USACO 2021 January Contest, Silver
// Problem 1. Dance Mooves

// I'm stuck after quiiiite a while (~50 mins) because i don't know how we would keep
// track of which positions we've visited without a 2D vector but we can't even iterate
// through that without surpassing the time complexity. idk how else we would track
// this though without overcounting positions you visit more than once. but otherwise,
// i did find a way to efficiently track the ending position of each node but idrk
// how to use that

// ohhh my gosh brocowski you CAN store a set of all visited positions for each cow
// after the first K iterations!!! bro oh my goodness how did i miss this like obviously
// we can just simulate the first K dance moves holy airball. and obviously after each
// swap, at the very most, two cows each visit a new position. So, there's a maximum of
// a total sum of 2K+N positions visited by all cows after K dance moves (+N because of
// the original N cow positions). We don't even need my "optimized" sorting algorithm
// thing because we can literaly just simulate the swaps IN ORDER and keep track of
// the positions each cows visited oml

// this problem wasn't even that hard i just dont know how i missed the fact that we so
// obviously should've just simulated the first K moves.

#include <bits/stdc++.h>
using namespace std;

vector<pair<int,set<int>>> dest;
vector<bool> visited;
vector<int> ans;
set<int> curr;

void dfs(int node) {
    visited[node] = true;
    for (auto& i : dest[node].second) curr.insert(i);
    if (!visited[dest[node].first]) dfs(dest[node].first);
    ans[node] = curr.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> pos(N);     // current cow at pos[i]
    dest.clear(); dest.resize(N);   // {final pos, {all visited pos}}
    for (int i=0; i < N; i++) {
        pos[i] = i;
        dest[i] = {i, {i}};
    }
    for (int i=0; i < K; i++) {
        int a, b; cin >> a >> b;
        a--; b--;   // swap cows at positions a and b
        dest[pos[a]].first = b;
        dest[pos[a]].second.insert(b);
        dest[pos[b]].first = a;
        dest[pos[b]].second.insert(a);
        swap(pos[a],pos[b]);
    }

    visited.clear(); visited.resize(N, false);
    ans.clear(); ans.resize(N);
    for (int i=0; i < N; i++) {
        if (!visited[i]) {
            curr = {};
            dfs(i);
        }
    }

    for (auto& i : ans) cout << i << '\n';
}