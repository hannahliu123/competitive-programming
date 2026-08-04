// CCC '20 S2 - Escape Room - https://dmoj.ca/problem/ccc20s2

// Start: 8:24
// End: 8:41        17 mins

// yuhh that was so easy and straightforward yey

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prod;
unordered_set<int> visited; // values of cells visited
int M, N;
bool pos;

void dfs(int x) {
    if (x==M*N) {
        pos = true; return;
    }
    visited.insert(x);
    for (auto& i : prod[x]) {
        if (!visited.count(i)) dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    prod.clear(); prod.resize(1000001);   // prod[x] = {value of all cells with r*c==x}
    int start = -1;
    for (int i=1; i <= M; i++) {
        for (int j=1; j <= N; j++) {
            int x; cin >> x;
            prod[i*j].push_back(x);
            if (i==1 && j==1) start = x;
        }
    }

    pos = false;
    visited.clear();
    dfs(start);

    cout << (pos? "yes\n" : "no\n");
}