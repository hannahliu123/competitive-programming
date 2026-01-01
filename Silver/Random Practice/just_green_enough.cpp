// USACO 2021 February Contest, Silver
// Problem 3. Just Green Enough

// I had to see the "prefix sums" label before i realized how to approach this problem.
// I was kinda just staring at it for over an hour drawing out test cases and trying to 
// find patterns but nothing was working. I ended up looking at the label and that makes
// so much more sense. I haven't looked at the solution yet, but i think we need to
// create a 2d prefix sum array tracking the number of 100s in that subrectangle which 
// will take O(N^2) time. I think we might need another 2d prefix array for tracking the
// number of squares below 100 (cannot be included). 

vector<vector<int>> g;

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    g.resize(N, vector<int>(N));
    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < N; ++j) {
            cin >> g[i][j];
        }
    }

    long long ans = 0;

    cout << ans << endl;
}
