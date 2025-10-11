// CSES - Forest Queries

// Start: 9:59
// End: 10:16       17 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> forest(N, vector<int>(N+1));
    for (int i{0}; i < N; ++i) {
        forest[i][0] = 0;
        for (int j{1}; j <= N; ++j) {
            char tree;
            cin >> tree;
            forest[i][j] = forest[i][j-1];
            if (tree == '*') forest[i][j]++;
        }
    }

    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int trees{0};
        for (int i{x1-1}; i < x2; ++i) {
            trees += (forest[i][y2] - forest[i][y1-1]);
        }

        cout << trees << '\n';
    }
}
