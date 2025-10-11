// CF - D. Solve The Maze - R1700

// Start: 9:23
// End: 10:11       48 mins

#include <bits/stdc++.h>
using namespace std;

char grid[50][50];
int row_num;
int col_num;
int good_found;
int bad_found;
vector<vector<bool>> visited;

void floodfill(int r, int c) {  // from destination
    if (r<0 || c<0 || r>=row_num || c>= col_num || visited[r][c] || grid[r][c]=='#') return;

    visited[r][c] = true;
    if (grid[r][c] == 'B') bad_found++;
    else if (grid[r][c] == 'G') good_found++;

    floodfill(r+1, c);
    floodfill(r-1, c);
    floodfill(r, c+1);
    floodfill(r, c-1);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> row_num >> col_num;

        visited.clear();
        visited.resize(row_num, vector<bool>(col_num, false));
        int good{0};
        for (int i{0}; i < row_num; ++i) {
            for (int j{0}; j < col_num; ++j) {
                cin >> grid[i][j];

                if (grid[i][j] == 'G') good++;
            }
        }

        bool possible = true;
        for (int i{0}; i < row_num; ++i) {
            for (int j{0}; j < col_num; ++j) {
                if (grid[i][j] == 'B') {
                    if (i+1<row_num && grid[i+1][j] == '.') grid[i+1][j] = '#';
                    if (i-1>=0 && grid[i-1][j] == '.') grid[i-1][j] = '#';
                    if (j+1<col_num && grid[i][j+1] == '.') grid[i][j+1] = '#';
                    if (j-1>=0 && grid[i][j-1] == '.') grid[i][j-1] = '#';
                }
            }
        }

        good_found = 0; bad_found = 0;
        floodfill(row_num-1, col_num-1);

        if (bad_found > 0 || good_found < good) possible = false;

        if (!possible) cout << "No\n";
        else cout << "Yes\n";
    }
}
