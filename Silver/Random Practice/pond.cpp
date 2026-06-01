// AtCoder - D - Pond

// ohhh my gosh i feel so stupid right now. how did i not think of binary search? now
// that i read the editorial this problem feels relatively simple achhhh. you just need
// to do binary search on the answer, and with each iteration you check if it's possible
// to get x or less as a median (so if there are at least K^2/2 values greater than x).
// x can range from 0 to 1e9, so the binary serach takes log(1e9). then for each binary
// serach you need O(N^2) to check if it works or not. the final time complexity is 
// O(N^2 log 1e9). when we're checking it, we basically loop through every index in the
// park and check if a KxK area with the top left corner at that index contains at least
// K^2/2 values greater than x. But we need to know in O(1) time for each area, so we can
// construct a 2d prefix sum array in O(N^2) time beforehand to help us easily compute.
// We can set a value to 1 if it's greater than x and 0 otherwise then just count the
// number of ones in each KxK area. 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<vector<int>> park(N, vector<int>(N));
    for (int i=0; i < N; i++) {
        for (int j=0; j < N; j++) {
            cin >> park[i][j];
        }
    }

    int needed = (K*K)/2;
    int lo=0, hi=1e9;
    // binary search on the answer (true if the median can be <= x, or in other words, there exists a KxK area where there are K^2/2 or fewer items greater than x)
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;

        vector<vector<int>> pref(N+1, vector<int>(N+1, 0));
        for (int i=0; i < N; i++) {
            for (int j=0; j < N; j++) {
                int contr = (park[i][j]>mid? 1 : 0);
                pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + contr;
            }
        }

        int mn_cnt = 1e9;
        for (int i=0; i <= N-K; i++) {
            for (int j=0; j <= N-K; j++) {
                int cnt = pref[i+K][j+K] - pref[i][j+K] - pref[i+K][j] + pref[i][j];
                mn_cnt = min(mn_cnt, cnt);
            }
        }

        // if there's a KxK area with fewer that K^2/2 + 1 items greater than mid, meaning
        // the (K^2/2 + 1)th item (median) must be less than or equal to mid
        if (mn_cnt <= needed) hi = mid;
        else lo = mid+1;
    }

    cout << lo << endl;
}