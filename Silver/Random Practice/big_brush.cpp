// CF - D. Big Brush - R2000

// Start: 12:19
// End: 1:17            58 mins

// YAYAYYAYAYAYAY so locked in omg all this hard work be paying off

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> c;
vector<vector<int>> curr;
vector<vector<int>> ans;    // i, j, c
vector<pair<int,int>> v;
vector<pair<int,int>> v2;

bool valid(int x, int y) {
    if (x<0||y<0||x>=N-1||y>=M-1) return false;

    int color = -1;
    for (auto& [a,b] : v) {     // check if all unfilled colors are the same
        if (curr[x+a][y+b] == -1) {
            if (color == -1) color = c[x+a][y+b];
            else if (c[x+a][y+b] != color) return false;
        }
    }

    if (color == -1) return false;  // already filled all 2x2 color from x,y

    // this index is valid! let's fill in the colors:
    for (auto& [a,b] : v) {
        if (curr[x+a][y+b] == -1) {
            curr[x+a][y+b] = color;
        }
    } ans.push_back({x, y, color});
    return true;
}

int main() {
    cin >> N >> M;

    c.resize(N, vector<int>(M));    // 1 <= c[i] <= NM
    curr.resize(N, vector<int>(M, -1));
    queue<pair<int,int>> q{};
    for (int i=0; i < N; i++) {
        for (int j=0; j < M; j++) {
            cin >> c[i][j];
            int color = c[i][j];
            if (i>0 && j>0 && color==c[i-1][j-1] && color==c[i-1][j] && color==c[i][j-1]) {
                // full 2x2 region with 1 color from i-1,j-1
                curr[i][j] = color; curr[i-1][j-1] = color; curr[i-1][j] = color; curr[i][j-1] = color;
                ans.push_back({i-1, j-1, c[i][j]});
                q.push({i-1,j-1});
            }
        }
    }

    v = {{0,0}, {1,0}, {0,1}, {1,1}};
    v2 = {{-1,-1}, {-1,0}, {0,-1}, {1,1}, {0,1}, {1,0}, {-1,1}, {1,-1}};
    // bfs
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;

        for (auto& [a,b] : v2) {    // add all valid next fill moves surrounding x,y
            if (valid(x+a,y+b)) {
                q.push({x+a, y+b});
            }
        }
    }

    bool filled = true;
    for (int i=0; i < N; i++) {
        for (int j=0; j < M; j++) {
            if (curr[i][j] == -1) {
                filled = false;
                break;
            }
        } if (!filled) break;
    }

    if (!filled) {
        cout << -1 << '\n';
        return 0;
    } cout << ans.size() << '\n';
    for (int i=ans.size()-1; i >= 0; i--) {
        auto& a = ans[i];
        cout << a[0]+1 << ' ' << a[1]+1 << ' ' << a[2] << '\n';
    }
}