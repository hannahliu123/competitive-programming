// Get me outta here!

// BFS would've been more efficient

#include <bits/stdc++.h>
using namespace std;

int N;
int M;
vector<vector<int>> maze;
vector<vector<pair<int,int>>> pre;

void floodfill(int r, int c, int dist, pair<int,int> p) {
    if (r<0||r>=N||c<0||c>=M || maze[r][c]==-1 || maze[r][c]<=dist+1) return;

    maze[r][c] = dist+1;
    pre[r][c] = p;

    floodfill(r, c+1, dist+1, {r,c});
    floodfill(r+1, c, dist+1, {r,c});
    floodfill(r, c-1, dist+1, {r,c});
    floodfill(r-1, c, dist+1, {r,c});
}

int main() {
    maze.clear();
    pre.clear();
    N = 0; M = 0;

    pair<int,int> start, end;
    string line;
    while (getline(cin, line) && line.length()>0) {
        N++;
        M = line.length();
        vector<int> l{};
        for (int i{0}; i < M; ++i) {
            if (line[i] == '#') l.push_back(-1);
            else {
                if (line[i] == 'S') start = {N-1, i};
                else if (line[i] == 'E') end = {N-1, i};
                l.push_back(1e9);
            }
        } maze.push_back(l);
    } pre.resize(N, vector<pair<int,int>>(M, {-1,-1}));

    floodfill(start.first, start.second, 0, make_pair(-1,-1));

    vector<pair<int,int>> ans{end};
    while (true) {
        auto& p = ans.back();
        auto& p2 = pre[p.first][p.second];
        ans.push_back(p2);
        if (p2 == start) break;
    }

    cout << "[";
    for (int i = (int)ans.size()-1; i >= 0; i--) {
        cout << "(" << ans[i].first << ", " << ans[i].second << ")";
        if (i > 0) cout << ", ";
    } cout << "]";

    return 0;
}
