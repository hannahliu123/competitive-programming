// D. Unfair Game - R1600

// Start: 12:03
// End: 1:13        1 hr 10 mins

// i had to look at 2 hints from the editorial erm and i think i did worse than before wow.
// its okay cos i think the first time i did this i had just learned about bitwise ops and
// stuff so i immediately began thinking abt bits. wait idk man actually i think this was
// when i was doing dp idek whatever. um once i started looking at bits tho i got the solution
// relatively quickly and im glad i remembered about the pascals triangle ncr thing yay
// oh yeah one think i did really bad was i wasted like 20 minutes at the very beginning just
// playing around with the problem before i finished reading the problem statement so everything
// i was messing around with was absolutely useless... um yeah let's not do that again...

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> nCr(29, vector<int>(29,0));
    for (int n=0; n < 29; n++) {
        nCr[n][0] = 1;
        nCr[n][n] = 1;
        for (int r=1; r < n; r++) {
            nCr[n][r] = nCr[n-1][r-1] + nCr[n-1][r];
        }
    }

    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        int d = log2(N);
        int ans = (d+1 > K? 1 : 0);     // use 10... (d 0s)
        for (int i=1; i < d; i++) {     // i options
            for (int ones=i; ones>=0; ones--) {
                int zeroes=i-ones;
                int moves = zeroes + 2*ones + 1;
                if (moves > K) {
                    ans += nCr[i][zeroes];
                } else break;
            }
        } cout << ans << '\n';
    }
}
