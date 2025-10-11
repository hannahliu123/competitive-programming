// USACO 2019 January Contest, Silver
// Problem 2. Icy Perimeter

// Start: 8:55
// End: 9:14        19 mins yippeeeee!

#include <bits/stdc++.h>
using namespace std;

int grid[1000][1000];       // 0: empty, 1: ice cream
int row_col;
bool visited[1000][1000];
int area, perimeter;

void floodfill(int r, int c) {
    if (visited[r][c]) return;

    visited[r][c] = true;

    area++;
    int p = 4;
    if (r-1>=0 && grid[r-1][c] == 1) {
        p--;
        floodfill(r-1, c);
    } if (r+1<row_col && grid[r+1][c] == 1) {
        p--;
        floodfill(r+1, c);
    } if (c-1>=0 && grid[r][c-1] == 1) {
        p--;
        floodfill(r, c-1);
    } if (c+1<row_col && grid[r][c+1] == 1) {
        p--;
        floodfill(r, c+1);
    } perimeter += p;
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> row_col;

    for (int i{0}; i < row_col; ++i) {
        for (int j{0}; j < row_col; ++j) {
            char c; 
            cin >> c;
            if (c == '.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }

    int max_area = 0, min_perimeter = 0;
    for (int i{0}; i < row_col; ++i) {
        for (int j{0}; j < row_col; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {    // if ice cream & not visited
                area = 0; perimeter = 0;
                floodfill(i, j);
                if (area > max_area) {
                    max_area = area;
                    min_perimeter = perimeter;
                } else if (area == max_area) min_perimeter = min(min_perimeter, perimeter);
            }
        }
    }
    
    cout << max_area << ' ' << min_perimeter << endl;
}
