// CF - G1. Medium Demon Problem (easy version) - R1700

// Start: 6:35
// End: 7:04        29 mins

// this was a very classic functional graphs problem except i lowkey forgot how to 
// do dfs for functional graphs so i had to relearn it real quick.

#include <bits/stdc++.h>
using namespace std;

vector<int> v;   // functional graph!
vector<int> visited;
bool in_cycle;
int mx_chain;

void dfs(int node) {
    if (visited[node] != -2) {  // hit a cycle
        if (visited[node] == -1) {
            visited[node] = 0;
            in_cycle = true;    // when we backtrack those nodes will be part of the cycle
        } return;
    }

    visited[node] = -1; // currently visiting
    dfs(v[node]);

    if (visited[node] == 0) {
        in_cycle = false;
    } else {
        if (in_cycle) visited[node] = 0;
        else visited[node] = visited[v[node]]+1;
        mx_chain = max(mx_chain, visited[node]);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        v.clear(); v.resize(N);
        for (auto& i : v) {
            cin >> i; i--;
        }

        visited.clear(); visited.resize(N, -2);
        in_cycle = false;
        mx_chain = 0;
        for (int i=0; i < N; i++) {
            if (visited[i] == -2) {
                dfs(i);
            }
        }

        cout << mx_chain + 2 << '\n';
    }
}
