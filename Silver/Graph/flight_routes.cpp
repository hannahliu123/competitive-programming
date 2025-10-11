// CSES - Flight Routes Check - https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>
using namespace std;

// If there's a node x in which x can eventually reach all other nodes and all other
// nodes can eventually reach x, then "YES". (If there exists a valid x then all nodes
// should theoretically work in place of x). So we can pick any value of x (say 1), and
// see if it can reach every other node (using DFS). Then we can check if al other nodes
// can reach x by using a reverse graph and performing DFS again (except now when you
// check if x can reach all other nodes, you're actually checking the reverse, which is 
// if all other nodes can reach x).         BIG BRAIN EDITORIAL

// I could've implemented this a lot better, cos this solution is quite messy, but uh
// at least I understand the idea

vector<vector<int>> adj;
vector<vector<int>> r_adj;
vector<bool> visited;

void dfs(int n) {
    if (visited[n]) return;
    visited[n] = true;
    for (auto i : adj[n]) {
        if (!visited[i]) dfs(i);
    }
}

void r_dfs(int n) {
    if (visited[n]) return;
    visited[n] = true;
    for (auto i : r_adj[n]) {
        if (!visited[i]) r_dfs(i);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    adj.resize(N);
    r_adj.resize(N);
    for (int i{0}; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        adj[--a].push_back(--b);
        r_adj[b].push_back(a);      // reverse adjacency list
    }

    visited.resize(N, false);
    dfs(0);
    if (accumulate(visited.begin(), visited.end(), 0) < N) {    // not all were visited
        int x;
        for (int i{0}; i < N; ++i) {
            if (!visited[i]) {
                x = i;
                break;
            }
        }
        cout << "NO\n" << 1 << ' ' << x+1 << endl;
    } else {
        visited.clear();
        visited.resize(N, false);
        r_dfs(0);
        if (accumulate(visited.begin(), visited.end(), 0) < N) {    // not all were visited
            int x;
            for (int i{0}; i < N; ++i) {
                if (!visited[i]) {
                    x = i;
                    break;
                }
            }
            cout << "NO\n" << x+1 << ' ' << 1 << endl;
        } else cout << "YES" << endl;
    }
}
