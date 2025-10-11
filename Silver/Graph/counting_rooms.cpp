// CSES - Counting Rooms - https://cses.fi/problemset/task/1192

// Start: 11:36
// End: 11:52           16 mins!

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
int grid[MAX_N][MAX_N];
int row_num;
int col_num;
bool visited[MAX_N][MAX_N];

void floodfill(int r, int c) {
    if (r<0 || c<0 || r>=row_num || c>=col_num || grid[r][c]!=1 || visited[r][c]) return;

    visited[r][c] = true;

    floodfill(r+1, c);
    floodfill(r-1, c);
    floodfill(r, c+1);
    floodfill(r, c-1);
}

int main() {
    cin >> row_num >> col_num;

    // Input the room (grid)
    for (int i{0}; i < row_num; ++i) {
        for (int j{0}; j < col_num; ++j) {
            char c; 
            cin >> c; 
            if (c == '#') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }

    int rooms = 0;
    for (int i{0}; i < row_num; ++i) {
        for (int j{0}; j < col_num; ++j) {
            if (!visited[i][j] && grid[i][j] == 1) {  // floor, not wall
                rooms++;
                floodfill(i, j);
            }
        }
    }
    
    cout << rooms << endl;
}
