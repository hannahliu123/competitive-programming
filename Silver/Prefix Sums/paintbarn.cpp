// USACO 2019 February Contest, Silver
// Problem 2. Painting the Barn

// Start: 4:11
// End: 4:55    gave up and watched an explanation

// I wasted a lot of time cos i did the coordinate counting wrong
// Then I wasted time because i never learned this part of 2d prefix sum arrays and i
// couldn't connect the dots and figure it out. Anyways, this is the code before i
// read the solution code. 

// Restart: 5:26
// End: 5:36        hehe 10 min implementation muy bien

// Oh so I could've combined my last 3 loops into the same loop

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> barn(1001, vector<int>(1001));
    for (int i{0}; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        barn[x1][y1]++;
        barn[x1][y2]--;
        barn[x2][y1]--;
        barn[x2][y2]++;
    }

    // for (int i{0}; i <= 1000; ++i) {    // horizontally
    //     for (int j{1}; j <= 1000; ++j) {
    //         barn[i][j] += barn[i][j-1];
    //     }
    // }
    
    // for (int i{0}; i <= 1000; ++i) {    // vertically
    //     for (int j{1}; j <= 1000; ++j) {
    //         barn[j][i] += barn[j-1][i];
    //     }
    // }

    // int ans{0};
    // for (int i{0}; i <= 1000; ++i) {    // count ans
    //     for (int j{1}; j <= 1000; ++j) {
    //         if (barn[i][j] == K) ans++;
    //     }
    // }

    // Better implementation below: Calculate each element per iteration of the loop
    int ans{0};
    for (int x{0}; x <= 1000; ++x) {        // x is row
        for (int y{0}; y <= 1000; ++y) {    // y is column
            if (x > 0) barn[x][y] += barn[x-1][y];      // add element above
            if (y > 0) barn[x][y] += barn[x][y-1];      // add element to left
            if (x > 0 && y > 0) barn[x][y] -= barn[x-1][y-1];      // subtract overlap
            if (barn[x][y] == K) ans++;
        }
    }

    cout << ans << endl;
}
