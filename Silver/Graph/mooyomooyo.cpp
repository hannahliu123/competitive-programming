// USACO 2018 December Contest, Silver
// Problem 3. Mooyo Mooyo

// This took about an hour. basically the idea was just simple ol brute force
// simulation but i did implement it a bit weirdly. the bounds were juse so
// relaxed i made unnecessary optimizations. like i did not need to make a 3d
// vector at all but oh well. and also for the gravity simulation, i could've
// just kept a vector of the valid values then updated them from the bottom 
// to top instead of wasting time implementing 2 ptrs

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> board;   // value, cc idx, visited
set<int> disappear;
int region, idx;
int N, K;

void ff(int x, int y, int c) {
    // out of bounds, visited, incorrect color (1-9)
    if (x<0||y<0||x>=N||y>=10 || board[x][y][2] || board[x][y][0]!=c) return;

    board[x][y][1] = idx;
    board[x][y][2] = 1;
    region++;

    ff(x+1, y, c);
    ff(x-1, y, c);
    ff(x, y+1, c);
    ff(x, y-1, c);
}

void gravity() {
    for (int i=0; i < 10; i++) {    // for each column
        int t = N-2;    // top
        for (int b=N-1; b >= 0; b--) {  // bottom (replace)
            int groupIdx = board[b][i][1];
            if (!disappear.count(groupIdx)) {
                t = min(t, b-1);
                board[b][i][2] = 0; // set to unvisited for later
                continue;
            }
            while (t>=0 && disappear.count(board[t][i][1])) {
                // board[t][i] becomes 0
                t--;
            }

            if (t==-1) board[b][i][0] = 0;
            else {
                board[b][i] = board[t][i];
                board[t][i][1] = groupIdx; // needs to be replaced
                t--;
            } board[b][i][2] = 0; // set to unvisited for later
        }
    }
}

int main() {
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);

    cin >> N >> K;
    board.resize(N, vector<vector<int>>(10, {0,0,0}));
    for (int i=0; i < N; i++) {
        string s; cin >> s;
        for (int j=0; j < 10; j++) {
            board[i][j][0] = s[j]-'0';
        }
    }
    
    bool removed = true;
    while (removed) {
        disappear.clear();
        region = 0; idx = 0;
        // find all connected regions & count their sizes
        for (int i=0; i < N; i++) {
            for (int j=0; j < 10; j++) {
                if (board[i][j][2] == 0) {
                    int c = board[i][j][0];
                    ff(i, j, c);
                    if (c!=0 && region>=K) disappear.insert(idx);
                    region = 0; idx++;
                }
            }
        }
        removed = (disappear.size() > 0);
        if (removed) gravity(); // have gravity act on removed spaces
    }
    
    for (int i=0; i < N; i++) {
        for (int j=0; j < 10; j++) {
            cout << board[i][j][0];
        } cout << '\n';
    }
}