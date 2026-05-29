// USACO 2015 December Contest, Silver
// Problem 1. Switching on the Lights

// okay i thought this was just a simple floodfill problem at first so i rushed a
// classic implementation just to realize i didn't entirely understand the problem
// correctly. i was able to fix it tho but this problem got really messy and took
// unnecessarily long :(

// the main tricky part is that when you flip a switch, you could light up a room that
// you need to backtrack in order to reach, meaning you would need to return to a 
// bunch of already visited rooms to get to the newly lighted room. To fix this, every
// time you light up a room, we can check if one of its neighbors are already visited,
// and if so, we can just call floodfill on that room. this gets rid of the need for 
// my canvisit array (which is lowkey pointless ugh). then the other scenario is if you
// light up a room that cannot be visited, but then later on you visit a room adjacent
// to it so now you can visit it. we solve this issue by calling floodfill on all adjacent
// rooms as long as their lights are on

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<pair<int,int> > > > grid;
vector<vector<bool> > lighton;
set<pair<int,int> > canvisit;
vector<vector<bool> > visited;
int N, M, ans;

vector<pair<int,int> > getAdj(int x, int y) {
    return {{x+1,y}, {x-1,y}, {x,y+1}, {x,y-1}};
}

void floodfill(int x, int y) {
    if (x<0||x>=N || y<0||y>=N || !lighton[x][y] || visited[x][y]) return;

    visited[x][y] = true;
    canvisit.erase({x,y});

    vector<pair<int,int> > adjacent = getAdj(x,y);
    for (auto& p : adjacent) {
        int a = p.first, b = p.second;
        if (a>=0 && a<N && b>=0 && b<N && !visited[a][b]) {
            canvisit.insert({a,b});

            if (lighton[a][b]) floodfill(a,b);
        }
    }

    for (auto& p : grid[x][y]) {
        if (!lighton[p.first][p.second]) {
            ans++;
            lighton[p.first][p.second] = true;
            if (canvisit.count(p) && !visited[p.first][p.second]) floodfill(p.first, p.second);
        }
    }
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    cin >> N >> M;

    grid.resize(N, vector<vector<pair<int,int> > >(N));
    for (int i=0; i < M; i++) {
        int x, y, a, b; 
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        grid[x][y].push_back({a,b});
    }

    ans = 1;
    visited.resize(N, vector<bool>(N, false));
    canvisit.clear();
    lighton.resize(N, vector<bool>(N, false));
    lighton[0][0] = true;
    floodfill(0,0);

    cout << ans << endl;
}
