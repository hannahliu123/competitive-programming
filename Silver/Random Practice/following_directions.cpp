// USACO 2023 January Contest, Silver
// Problem 2. Following Directions

// Start: 7:54
// End: 8:32        38 mins

// yayay very straightforward and im glad i planned it out well (no issues encountered :D)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> grid;
vector<string> sign;

int main() {
    int N; cin >> N;
    grid.clear(); grid.resize(N+2, vector<int>(N+2, 1));
    sign.clear(); sign.resize(N);
    for (int i=0; i < N; i++) {
        cin >> sign[i] >> grid[i][N+1];
        grid[i][N] = 0;
    }
    for (int i=0; i < N; i++) {
        cin >> grid[N+1][i];
        grid[N][i] = 0;
    } grid[N][N] = 0;

    ll ans = 0;
    for (int i=0; i <= N; i++) {
        for (int j=0; j <= N; j++) {
            if (i>0 && j<N && sign[i-1][j]=='D') grid[i][j] += grid[i-1][j];
            if (j>0 && i<N && sign[i][j-1]=='R') grid[i][j] += grid[i][j-1];
            if (j==N) ans += grid[i][j]*grid[i][j+1];
            if (i==N) ans += grid[i][j]*grid[i+1][j];
        }
    }
    cout << ans << '\n';

    int Q; cin >> Q;
    while (Q--) {
        int i, j; cin >> i >> j; i--; j--;
        int i2=i, j2=j;

        int x = grid[i][j];
        while (i<N && j<N) {
            if (sign[i][j]=='R') j++;
            else i++;
            grid[i][j] -= x;
        } 
        int c = 0;
        if (i==N) c = grid[i+1][j];
        if (j==N) c = grid[i][j+1];
        ans -= x*c;

        if (sign[i2][j2]=='R') sign[i2][j2] = 'D';
        else sign[i2][j2] = 'R';
        while (i2<N && j2<N) {
            if (sign[i2][j2]=='R') j2++;
            else i2++;
            grid[i2][j2] += x;
        }
        if (i2==N) c = grid[i2+1][j2];
        if (j2==N) c = grid[i2][j2+1];
        ans += x*c;

        cout << ans << '\n';
    }
}