// MARBLES - Marbles

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;

        // N stars and K-1 bars, except we can't have any empty boxes. So, we can
        // pre-allocate one marble to each of the boxes (so K marbles marbles must
        // be selected no matter what; one of each color). This leave us with N-K
        // marbles to place however we want in K boxes. In other words, we transformed
        // the problem to N-K stars and K-1 bars. In other words, we are calculating
        // nCr where n = N-K+K-1 = N-1 and r=K-1 or N-K
        // This time we don't need to take MOD :). So to calculate nCr(N-1, K-1), we
        // can break up the combination formula (N-1)! / (K-1)!(N-K)! into:
        // (N-1)(N-2)(N-3)...(N-K+1) / (K-1)(K-2)(K-3)...(1) 

        long long ans = 1;

        // avoid overflow
        int reps = min(N-K, K-1);

        for (int i=1; i <= reps; i++) {
            ans = ans*(N-i) / (i);  // using i vs K-i should be the same but start with the lower number or else it wont divide evenly
        }

        cout << ans << '\n';
    }
}