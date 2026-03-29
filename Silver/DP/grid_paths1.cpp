// CSES Problem Set - Grid Paths I

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> grid(N+1, vector<int>(N+1,0));
    for (int i=1; i <= N; i++) {
        for (int j=1; j <= N; j++) {
            char c; cin >> c;
            if (i==1 && j==1) grid[i][j] = (c == '.'? 1 : 0);
            else if (c == '.') grid[i][j] = grid[i-1][j] + grid[i][j-1];
            grid[i][j] %= 1000000007;
        }
    }

    cout << grid[N][N] << endl;
}
