// USACO 2017 February Contest, Silver
// Problem 3. Why Did the Cow Cross the Road III

// Start: 6:38
// End: 7:01        23 mins

// ok bro i needed this confidence boost after a long day of bitwise operators. this was
// such a straightforward problem it was literally just basic floodfill lol. 

#include <bits/stdc++.h>
using namespace std;

set<vector<int>> roads;
set<pair<int,int>> cows;
vector<vector<int>> visited;
vector<int> areas;
int N, K, R;
vector<vector<int>> v;

bool blocked(int a, int b, int c, int d) {
    return roads.count({a, b, c, d}) || roads.count({c, d, a, b});
}

void ff(int x, int y, int area) {
    if (x<0||y<0||x>=N||y>=N || visited[x][y]) return;

    visited[x][y] = true;
    if (cows.count({x,y})) areas[area]++;

    for (int i=0; i < 4; i++) {
        if (!blocked(x, y, x+v[i][0], y+v[i][1])) ff(x+v[i][0], y+v[i][1], area);
    }
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    cin >> N >> K >> R;

    roads.clear();
    cows.clear();
    for (int i=0; i < R; i++) {     // roads
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        roads.insert({r1, c1, r2, c2});
    } for (int i=0; i < K; i++) {   // cows
        int r, c; cin >> r >> c; r--; c--;
        cows.insert({r,c});
    }

    v = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    visited.resize(N, vector<int>(N, false));
    areas.clear();
    int idx = 0;
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            if (!visited[i][j]) {
                areas.push_back(0);
                ff(i,j,idx++);
            }
        }
    }

    int ans = 0;
    for (auto& c : areas) {
        ans += (c)*(K-c);
    } ans /= 2;

    cout << ans << endl;
}
