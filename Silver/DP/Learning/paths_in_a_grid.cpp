// CPH - 7.3 Paths in a grid

// Our next problem is to find a path from the upper-left corner to the lower-right
// corner of an n × n grid, such that we only move down and right. Each square
// contains a positive integer, and the path should be constructed so that the sum of
// the values along the path is as large as possible.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N{5};
    vector<vector<int>> grid{
        {3, 7, 9, 2, 7}, 
        {9, 8, 3, 5, 5}, 
        {1, 7, 9, 8, 5}, 
        {3, 8, 6, 4, 10}, 
        {6, 3, 9, 7, 8}
    };

    // sum keeps track of the maximum sum for that number (1-indexed because we set
    // everything with an index of 0 (everything on the top or left sides) to 0 so 
    // when we compare items that should've been on the top or left side there isn't
    // a negative indexing error)
    vector<vector<int>> sum(N+1, vector<int>(N+1, 0));
    for (int i{1}; i < N+1; ++i) {
        for (int j{1}; j < N+1; ++j) {
            sum[i][j] = max(sum[i-1][j], sum[i][j-1]) + grid[i-1][j-1];
            // maximum of the sum above or to the left + its value (0-indexed)
        }
    }

    cout << sum[N][N] << endl;  // 67 :D
}
