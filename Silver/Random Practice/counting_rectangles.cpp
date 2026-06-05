// CF - E. Counting Rectangles - R1x00

// um so i found a working solution of precomputing a prefix sums array for
// all values of i from 1-1000 except this doesnt pass the memory limit because
// it requires us to store 10^8 long longs. now idrk how to optimize that solution
// so i read the editorial. ok so my time complexity was O(10^8), or O(1000Q)
// (because the max value of width or height is 1000). what i did was binary serach
// on the heights to find a valid range, then use that valid range to determine
// the number of rectangles with valid heights within that range using prefix sums.

// however, the actual code involves using a 1000x1000 array, instead of an
// 1000x100000 array. i didn't think of this, but you just have a normal 2d prefix
// sum array where pref[i][j] gives you the sum of all rectange areas that have
// a height <= i and a width <= j. this way, the answer is way simpler and it's
// just normal 2d prefix sum calculations

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, Q; cin >> N >> Q;

        vector<vector<long long>> pref(1001, vector<long long>(1001, 0));
        for (int i=0; i < N; i++) {
            int h, w; cin >> h >> w;
            pref[h][w] += (long long)h*w;
        }

        for (int i=1; i <= 1000; i++) { // fill in 2d pref
            for (int j=1; j <= 1000; j++) {
                pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }

        while (Q--) {
            int hs, ws, hb, wb; 
            cin >> hs >> ws >> hb >> wb;
            hs++; ws++; // must be greater than hs and ws
            hb--; wb--; // must be less than hb and wb
            
            long long ans = pref[hb][wb] - pref[hb][ws-1] - pref[hs-1][wb] + pref[hs-1][ws-1];

            cout << ans << endl;
        }
    }
}