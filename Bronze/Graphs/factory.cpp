// USACO 2019 US Open Contest, Bronze
// Problem 2. Milk Factory

// Start: 6:40
// End: 7:07        27 minutes

// AYY I COOKED IM SO HAPPY. K so turns out we dont need dfs or recursion and that
// stuff. Yippee!! Yeah so i read the solution. Basically the variable "none" that
// I used tracks how many nodes go nowhere, making it a sink (stuff can come in
// but nothing can go out). So if there were multiple sinks, there is no solution.
// the variable i called "index" tracked the index of that sink (so the answer)

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int N;  // N stations, N-1 walkways
    cin >> N;

    vector<int> adj[N+1];
    for (int i{0}; i < N-1; ++i) {
        int a, b;   // a -> b
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int none{0};
    int index{-1};
    for (int i{1}; i < N+1; ++i) {
        if (adj[i].size() < 1) {
            ++none;
            if (none > 1) {
                index = -1;
                break;
            }
            index = i;
        }
    }

    cout << index << endl;
}
