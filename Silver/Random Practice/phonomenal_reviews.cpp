// CCC '16 S3 - Phonomenal Reviews - https://dmoj.ca/problem/ccc16s3

// im assuming it's optimal to root the tree from a pho resturaunt then
// delete all unecessary nodes that come after a pho resuraunt. then find the
// longest dist between two nodes (which would automatically be from one pho
// resturaunt to another). then dfs on that resulting tree and stop when M
// pho resturaunts have been visited (or ig all nodes in the reduced tree).

// bruh okay so right idea but for some reason my first solution just didn't
// work. simulation failed because i was starting with one ending node and then
// trying to simulate visiting resturaunts with fewer children first. however,
// that doesn't necessarily guarentee i end up skipping the traversal of the
// longest sequence of edges because one child could have a weight of 10 but
// have 10 edges going out of it whereas another could have 5 but all connected
// in one line. the 5 would actually more likely lead you to the other end of 
// the longest sequence. either way that solution is overkill because you know
// the optimal path is just traversing each edge twice except for the longest
// sequence :)

#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<vector<int>> adj;
vector<bool> pho;
pair<int,int> mx;   // furthest from root {dist, idx}
vector<int> weights;
int total_pho;
int cnt;
int visited;

void valid(int node, int prev_node, int dist) {
    for (auto& i : adj[node]) {
        if (i != prev_node) {
            valid(i, node, dist+1);
            if (pho[i] && !pho[node]) {
                pho[node] = true;
                total_pho++;
            }
        }
    }
    if (pho[node] && dist > mx.first) mx = {dist, node};
}

void weight(int node, int prev_node) {
    weights[node]++;
    for (auto& i : adj[node]) {
        if (i != prev_node && pho[i]) {
            weight(i, node);
            weights[node] += weights[i];
        }
    }
    sort(adj[node].begin(), adj[node].end(), [](auto& a, auto& b){
        return weights[a] < weights[b];
    });
}

void dfs(int node, int prev_node) {
    visited++;
    cnt++;
    if (visited == total_pho) return;
    for (auto& i : adj[node]) {
        if (i != prev_node && pho[i]) {
            dfs(i, node);
            if (visited == total_pho) return;
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.clear(); adj.resize(N);
    pho.clear(); pho.resize(N, false);
    int root = -1;
    for (int i=0; i < M; i++) {
        int x; cin >> x;
        pho[x] = true;
        if (root == -1) root = x;
    }
    for (int i=0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    total_pho = M;
    mx = {0, root};
    valid(root, -1, 0);
    // weights.clear(); weights.resize(N,0);
    // weight(mx.second, -1);
    // cnt = -1;
    // visited = 0;
    // dfs(mx.second, -1);
    valid(mx.second, -1, 0);
    
    cout << 2*(total_pho-1) - (mx.first) << '\n';
}