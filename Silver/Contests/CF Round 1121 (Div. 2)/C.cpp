// Obviously we can't just loop through all possible dynasties because that
// would NOT fit within the time limit. Instead, we can focus on evaluating the
// contrubutions across all (N-1)! total dynasties for each node. If you sorted
// the ratings from least to greatest, the 0th node has N-1 options for parents,
// the 1st has N-2 options, etc. meaning the ith node has N-i-1 options that are
// equally split up among the (N-1)! total dynasties. The contribution for one
// node is the sum of (a_p - a_i) * (N-1)!/(N-i-1) across all N-i-1 parents (index
// p). Breaking that up, you get (N-1)!*sum(a_p)/(N-i-1) - (N-1)!*a_i. Now for each
// element i from 0 to N-1, we need to find the sum of ratings for each of their
// parents (suffix sum)
// now the issue of division arises. we could use modular inverses but tspmos so what
// we can do instead is keep track of prefex and suffix products. for (N-1)!/(N-i-1),
// we just multiply the prefix from 1 to N-i-2 then the suffix from N-i to N-1

//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 998244353;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<ll> a(N);
        for (auto& i : a) cin >> i;
        sort(a.begin(), a.end());

        vector<ll> pref(N, 1);
        for (int i=1; i < N; i++) pref[i] = (pref[i-1]*(N-i))%MOD;
        vector<ll> suff(N, 1);
        for (int i=N-2; i >= 0; i--) suff[i] = (suff[i+1]*(N-i-1))%MOD;
        vector<ll> sum(N+1);    // sum[i] = ratings suffix sums from i to N
        for (int i=N-1; i>=0; i--) sum[i] = (sum[i+1] + a[i])%MOD;

        ll ans = 0;
        for (int i=0; i < N-1; i++) {
            ll prod = (pref[i]*suff[i+1])%MOD;
            ll add = (prod*sum[i+1])%MOD;
            ans = (ans+add)%MOD;
            ll sub = (suff[0]*a[i])%MOD;
            ans = (ans+MOD-sub)%MOD;
        }

        cout << ans << '\n';
    }
}