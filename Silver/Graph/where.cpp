// USACO 2017 US Open Contest, Silver
// Problem 3. Where's Bessie?

#include <bits/stdc++.h>
using namespace std;

char grid[20][20];
vector<vector<bool>> visited;

int r1, r2, c1, c2;
void floodfill(int r, int c, char color) {
    if (r<r1 || c<c1 || r>r2 || c>c2 || visited[r][c] || grid[r][c]!=color) return;

    visited[r][c] = true;

    floodfill(r+1, c, color);
    floodfill(r-1, c, color);
    floodfill(r, c+1, color);
    floodfill(r, c-1, color);
}

int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    int row_col;
    cin >> row_col;

    for (int i{0}; i < row_col; ++i) {
        for (int j{0}; j < row_col; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<pair<pair<int, int>, pair<int, int>>> corners{};
    for (r1 = 0; r1 < row_col; ++r1) {         // top left row
        for (c1 = 0; c1 < row_col; ++c1) {     // top left col
            for (r2 = r1; r2 < row_col; ++r2) {         // bottom right row
                for (c2 = c1; c2 < row_col; ++c2) {     // bottom right 
                    visited.clear();
                    visited.resize(row_col, vector<bool>(row_col, false));
                    vector<int> colors(26, 0);     // number of sections of each color
                    for (int i{r1}; i <= r2; ++i) {         // current location
                        for (int j{c1}; j <= c2; ++j) {     // current location
                            if (!visited[i][j]) {
                                colors[grid[i][j]-'A']++;
                                floodfill(i, j, grid[i][j]);
                            }
                        }
                    }

                    vector<int> all_colors{};     // for all present colors, how many sections
                    for (int i{0}; i < 26; ++i) {
                        if (colors[i] > 0) all_colors.push_back(colors[i]);
                    }

                    sort(all_colors.begin(), all_colors.end());
                    if (all_colors.size() == 2 && all_colors[0] == 1 && all_colors[1] > 1) corners.push_back({{r1,c1},{r2,c2}});
                }
            }
        }
    }

    // if i isn't a subset of any j, then i is a pcl
    int pcl = 0;
    for (int i{0}; i < corners.size(); ++i) {
        bool valid = true;
        for (int j{0}; j < corners.size(); ++j) {
            if (j == i) continue;
            if ((corners[i].first.first>=corners[j].first.first && corners[i].first.second>=corners[j].first.second) && (corners[i].second.first<=corners[j].second.first && corners[i].second.second<=corners[j].second.second)) {
                // i is a subset of j
                valid = false;
                break;
            }
        } if (valid) pcl++;
    }

    cout << pcl << endl;
}
