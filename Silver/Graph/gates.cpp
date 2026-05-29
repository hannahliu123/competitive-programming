// USACO 2016 January Contest, Silver
// Problem 3. Build Gates

// ayyy this problem had a ton of really confusing indexing but it was pretty
// straightforwards conceptually. 

#include <bits/stdc++.h>
using namespace std;

int L, W, ans;
vector<vector<bool>> visited;
set<vector<int>> fence;

bool noBlock(int x, int y, int nx, int ny) {
    return !fence.count({x,y,nx,ny}) && !fence.count({nx,ny,x,y});
}

void floodfill(int x, int y) {
    if (x<0||x>=W||y<0||y>=L || visited[x][y]) return;

    visited[x][y] = true;
    vector<vector<int>> add{{1,0},{-1,0},{0,1},{0,-1}};
    for (auto& v : add) {
        int nx = x+v[0], ny = y+v[1];
        if (noBlock(x,y,nx,ny)) floodfill(nx,ny);
    }
}

int main() {
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    int N; cin >> N;
    string s; cin >> s;
    int currX=0, currY=0, mxX=0, mxY=0, mnX=0, mnY=0;
    for (int i=0; i < N; i++) {
        if (s[i] == 'N') currX--;
        else if (s[i] == 'E') currY++;
        else if (s[i] == 'S') currX++;
        else if (s[i] == 'W') currY--;

        mxX = max(mxX, currX);
        mnX = min(mnX, currX);
        mxY = max(mxY, currY);
        mnY = min(mnY, currY);
    }

    L = mxY - mnY + 2;
    W = mxX - mnX + 2;
    currX = abs(mnX);
    currY = abs(mnY);
    fence.clear();
    for (int i=0; i < N; i++) {
        if (s[i] == 'N') {
            fence.insert({currX, currY, currX, currY+1});
            currX--;
        } else if (s[i] == 'E') {
            currY++;
            fence.insert({currX, currY, currX+1, currY});
        } else if (s[i] == 'S') {
            currX++;
            fence.insert({currX, currY, currX, currY+1});
        } else if (s[i] == 'W') {
            fence.insert({currX, currY, currX+1, currY});
            currY--;
        }
    }

    ans = -1;
    visited.resize(W, vector<bool>(L, false));
    for (int i=0; i < W; i++) {
        for (int j=0; j < L; j++) {
            if (!visited[i][j]) {
                ans++;
                floodfill(i,j);
            }
        }
    }

    cout << ans << endl;
}
