// J - Fire!

// Start: 8:55
// End: 30ish

#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> fire;
vector<vector<int>> joe;

bool valid(int i, int j) {
    return i>=0&&i<R&&j>=0&&j<C && fire[i][j]!=-1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> R >> C;
        fire.clear(); fire.resize(R, vector<int>(C, 1e9));
        joe.clear(); joe.resize(R, vector<int>(C, 1e9));
        queue<pair<int,int>> q{};
        queue<pair<int,int>> q2{};
        for (int i{0}; i < R; ++i) {
            for (int j{0}; j < C; ++j) {
                char c; cin >> c;
                if (c=='#') fire[i][j] = -1;
                else if (c=='F') {
                    fire[i][j] = 0;
                    q.push({i,j});
                } else if (c=='J') {
                    joe[i][j] = 0;
                    q2.push({i,j});
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (valid(i+1,j) && fire[i][j]+1<fire[i+1][j]) {
                fire[i+1][j] = fire[i][j]+1;
                q.push({i+1,j});
            } if (valid(i-1,j) && fire[i][j]+1<fire[i-1][j]) {
                fire[i-1][j] = fire[i][j]+1;
                q.push({i-1,j});
            } if (valid(i,j+1) && fire[i][j]+1<fire[i][j+1]) {
                fire[i][j+1] = fire[i][j]+1;
                q.push({i,j+1});
            } if (valid(i,j-1) && fire[i][j]+1<fire[i][j-1]) {
                fire[i][j-1] = fire[i][j]+1;
                q.push({i,j-1});
            }
        }

        while (!q2.empty()) {
            int i = q2.front().first;
            int j = q2.front().second;
            q2.pop();

            int time = joe[i][j]+1;
            if (valid(i+1,j) && time<fire[i+1][j] && time<joe[i+1][j]) {
                joe[i+1][j] = time;
                q2.push({i+1,j});
            } if (valid(i-1,j) && time<fire[i-1][j] && joe[i][j]+1<joe[i-1][j]) {
                joe[i-1][j] = time;
                q2.push({i-1,j});
            } if (valid(i,j+1) && time<fire[i][j+1] && joe[i][j]+1<joe[i][j+1]) {
                joe[i][j+1] = time;
                q2.push({i,j+1});
            } if (valid(i,j-1) && time<fire[i][j-1] && joe[i][j]+1<joe[i][j-1]) {
                joe[i][j-1] = time;
                q2.push({i,j-1});
            }
        }

        int ans = 1e9;
        for (int i{0}; i < R; ++i) {
            if (i==0 || i==R-1) {
                for (int j{0}; j < C; ++j) {
                    if (fire[i][j] > joe[i][j]) {
                        ans = min(ans, joe[i][j]+1);
                    }
                }
            } else {
                if (fire[i][0] > joe[i][0]) {
                    ans = min(ans, joe[i][0]+1);
                } if (fire[i][C-1] > joe[i][C-1]) {
                    ans = min(ans, joe[i][C-1]+1);
                }
            }
        }
        
        if (ans==1e9) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
}
