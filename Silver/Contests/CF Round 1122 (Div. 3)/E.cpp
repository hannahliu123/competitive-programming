// This is just a dynamic programming problem but even when i knew it was dp, i couldn't
// figure out what exactly to dp on and how to use past info in future answers. So the
// key is to evaluate the items together. so you want dp[i] = minimum operations needed to
// make i <= k. I used to be thinking of each a_i seperately (so trying to compute the
// answer for each a_i then sum up the individual contributions). now that i think of it, 
// i should've clearly been able to see how you could reuse information from different
// a_i. Obviously, dp[1...k] = 0. Then for i>k, dp[i] = min(1+p*dp[i/p]) for all prime
// factors of i. This works because you are trying starting by dividing each i by every
// possible one of its prime factors, which guarentees you're trying every single solution.
// After you divide i by p (1 operation), you need to convert the remaining p elements of
// value i/p into a value <= k.

// ahhh this is so straightforward but i just every so slightly missed the logic. i thought
// this might tle but it didnt :)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        
        vector<long long> dp(N+1, LONG_LONG_MAX);
        for (int i=0; i <= N; i++) {
            if (i <= K) {
                dp[i] = 0; continue;
            }

            vector<int> primes{};
            int x = i;
            if (x%2==0) {
                primes.push_back(2);
                while (x%2==0) x/=2;
            }
            for (int j=3; j*j<=x; j+=2) {
                if (x%j==0) {
                    primes.push_back(j);
                    while (x%j==0) x/=j;
                }
            }
            if (x>1) primes.push_back(x);

            for (auto& p : primes) {
                dp[i] = min(dp[i], dp[i/p]*p + 1);
            }
        }

        long long ans = 0;
        for (auto& i : a) {
            ans += dp[i];
        } cout << ans << '\n';
    }
}