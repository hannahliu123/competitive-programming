// CF - G2. Medium Demon Problem (hard version) - R1900

// Start: 7:06
// End: 8:04        58 mins

// okay so this wasn't too bad either but i got wa because my dfs function returned
// too early if the answer was 3. im assuming these problems r rated so high because
// of implementation and functional graph knowledge because the logic itself was very
// straightforward imo

#include <bits/stdc++.h>
using namespace std;

vector<int> v;   // functional graph!
vector<vector<int>> adj;    // opposite
vector<int> cycle;
vector<int> children;
bool in_cycle;
int mx;

void find_cycle(int node) {
    if (cycle[node] != -2) {
        if (cycle[node] == -1) {
            in_cycle = true;
            cycle[node] = 1;
        } return;
    }

    cycle[node] = -1; // visiting
    find_cycle(v[node]);

    if (cycle[node] == 1) {
        in_cycle = false;
    } else {
        if (in_cycle) cycle[node] = 1;
        else cycle[node] = 0;
    }
}

void dfs(int node) {
    for (auto& i : adj[node]) {
        if (cycle[i] != 1) {
            dfs(i);
            children[node] += children[i];
        }
    }

    if (cycle[node] == 1) return;
    mx = max(mx, children[node]);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        v.clear(); v.resize(N);
        adj.clear(); adj.resize(N);
        for (int i=0; i < N; i++) {
            int j; cin >> j; j--;
            v[i] = j;
            adj[j].push_back(i);
        }

        cycle.clear(); cycle.resize(N, -2);
        in_cycle = false;
        for (int i=0; i < N; i++) {
            if (cycle[i] == -2) {
                find_cycle(i);  // all items in the cycle will be 1
            }
        }

        mx = 0;
        children.clear(); children.resize(N, 1);
        for (int i=0; i < N; i++) {
            if (cycle[i] == 1) {
                dfs(i);
            }
        }

        cout << mx + 2 << '\n';
    }
}
