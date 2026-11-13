// ugh nevermind im too lazy to finish this (tried dfs and realized it didnt work and started bfs)

#include <bits/stdc++.h>
using namespace std;

vector<string> maze;
vector<pair<int,int>> ans;
vector<vector<pair<int,int>>> visited;
int N, M;
pair<int,int> s, e;

void floodfill(pair<int,int> p, pair<int,int> pre) {
    int x=p.first, y=p.second;
    if (x<0||x>=N || y<0||y>=M || maze[x][y]=='#' || visited[x][y]!=make_pair(-1,-1)) return;
    
    visited[x][y] = pre;
    if (visited[e.first][e.second] != make_pair(-1,-1)) return;
    
    floodfill({x+1,y}, p);
    floodfill({x-1,y}, p);
    floodfill({x,y+1}, p);
    floodfill({x,y-1}, p);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string line;
    maze.clear();
    while (getline(cin, line) && line!="") {
        maze.push_back(line);
    }
    N = maze.size(), M = maze[0].length();
    visited.clear(); visited.resize(N, vector<pair<int,int>>(M, {-1,-1}));
    for (int i=0; i < N; i++) {
        for (int j=0; j < M; j++) {
            if (maze[i][j]=='S') {
                s = {i,j};
            } else if (maze[i][j]=='E') e = {i,j};
        }
    }
    
    vector<pair<int,int>> adj{{1,0}, {-1,0}, {0,1}, {0,-1}};
    queue<vector<int>> q{};
    // q.push(s);
    while (!q.empty()) {
        int x=q.front()[0], y=q.front()[1];
        q.pop();
        for (auto& [p1,p2] : adj) {
            int nx=x+p1, ny=y+p2;
            // if (valid(nx,ny)) 
        }
    }

    ans.clear();
    while (e != make_pair(-2,-2)) {
        ans.push_back(e);
        e = visited[e.first][e.second];
    }
    
    cout << "[";
    for (int i=ans.size()-1; i >= 0; i--) {
        cout << "(" << ans[i].first << ", " << ans[i].second << (i==0? ")]" : "), ");
    }
    
    return 0;
}
