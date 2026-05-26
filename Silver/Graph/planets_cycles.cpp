// CSES Problem Set - Planets Cycles

// imo this was actually pretty tricky but i think i understand it now. the
// in_cycle boolean confused me a lot but now i does make sense

#include <bits/stdc++.h>
using namespace std;

vector<int> t;
vector<int> ans;
vector<int> len;    // length of path before reaching this node
bool in_cycle;

void dfs(int node, int cnt) {
    if (ans[node] != -2) {  // visited before!
        if (ans[node] == -1) {
            ans[node] = cnt - len[node];
            in_cycle = true;
        }
        return;
    }

    ans[node] = -1;
    len[node] = cnt;
    dfs(t[node], cnt+1);

    if (ans[node] >= 0) {  // back to beginning of cycle
        in_cycle = false;
    } else {
        ans[node] = ans[t[node]];
        if (!in_cycle) ans[node]++;
    }
}

int main() {
    int N; cin >> N;
    t.resize(N);
    for (auto& i : t) {
        cin >> i; i--;
    }
    
    ans.resize(N, -2);  // -2:unvisited, -1:visiting (part of current cc)
    len.resize(N, -1);  // last time we visited this node
    in_cycle = false;
    for (int i=0; i < N; i++) {
        if (ans[i] == -2) dfs(i, 0);
    }

    for (auto& i : ans) cout << i << ' ';
    cout << endl;
}
