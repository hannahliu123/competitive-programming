// USACO 2019 December Contest, Silver
// Problem 3. Milk Visits

// Start: 3:15
// End: 3:51        36 mins (but i read the editorial...)

#include <bits/stdc++.h>
using namespace std;

string cows;
vector<vector<int>> roads;
map<int, int> group;

void dfs(int node, int prev) {
    if (cows[node] == cows[prev]) {     // group together
        group[node] = group[prev];
    } else group[node] = node;        // start own group
    
    for (int i : roads[node]) {
        if (i != prev) dfs(i, node);
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int N, M;
    cin >> N >> M >> cows;

    roads.resize(N);
    for (int i{0}; i < N-1; ++i) {      // roads bewtween X & Y
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        roads[X].push_back(Y);
        roads[Y].push_back(X);
    }

    // group all cows that next to eachother (connected) and produce the same milk to the
    // starting node using dfs
    group[0] = 0;
    dfs(0, 0);

    for (int i{0}; i < M; ++i) {      // walk from a -> b
        int A, B;
        char C;
        cin >> A >> B >> C;
        A--; B--;

        if (group[A] == group[B]) {     // only one type of milk
            if (cows[A] == C) cout << 1;
            else cout << 0;
        } else {    // both types of milk
            cout << 1;
        }
    }

    cout << endl;
}
