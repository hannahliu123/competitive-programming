// I - Maze

// bro i tried implementing such a complicated answer. idek why i thought 
// of that but i was so convinced it would work too. i didn't draw enough test
// cases ig and i thought this was way more complicated than it shouldve been
// ugh all u had to do was find a connected component and then fill in the ones
// that weren't in there. bro that's so freaking simple oml what am i doingngn

// to get this idea, i think its mainly just common sense. i mean you just have
// to slightly reframe the problem statement to get this iddeaaaaaa omodgjaojfsd

#include <bits/stdc++.h>
using namespace std;

int N, M, K, s; 
vector<vector<char>> maze;
set<pair<int,int>> cc;

bool valid(int i, int j) {
    return !(i<0||i>=N||j<0||j>=M||maze[i][j]!='.'||cc.count({i,j}));
}

void floodfill(int i, int j) {
    if (cc.size() >= s-K) return;
    if (cc.count({i,j})) return;
    cc.insert({i,j});

    if (valid(i+1,j)) {
        floodfill(i+1,j);
    } if (valid(i-1,j)) {
        floodfill(i-1,j);
    } if (valid(i,j+1)) {
        floodfill(i,j+1);
    } if (valid(i,j-1)) {
        floodfill(i,j-1);
    }
}

int main() {
    cin >> N >> M >> K;

    s = 0;
    cc = {};
    maze.clear(); maze.resize(N, vector<char>(M));
    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < M; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') s++;
        }
    }

    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < M; ++j) {
            if (valid(i,j)) {
                floodfill(i,j);
                break;
            }
        }
    }

    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < M; ++j) {
            if (maze[i][j] == '.' && !cc.count({i,j})) cout << 'X';
            else cout << maze[i][j];
        } cout << '\n';
    }
}
