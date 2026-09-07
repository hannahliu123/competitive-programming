// USACO 2023 February Contest, Silver
// Problem 1. Bakery

// bruhh okay so this problem is really just math and binary serach. You can just 
// directly binary search on the answer (moonies) because if you can solve the problem
// with m moonies, obviously you can solve it with m+1 or more moonies. Now the issue
// is how do we determine if m moonies is enough/valid? Well, we are looking for new
// cook times t1 and t2 such that ci*t1 + mi*t2 <= ti for all i (0 to N-1). But, both
// t1 and t2 are unknown so there could be so many combinations. However, if we have a
// fixed m (moonies), we can get rid of some of the variables because now we know:
// t1 = tc - d (where 0 <= d <= m) and t2 = tm - (m-d) = tm - m + d

// Now, we've rewritten t1 and t2 in terms of constants we know (tc and tm) and one 
// unknown variable d. To figure out if a solution exists, we just need to know if some
// value of d exists such that 0 <= d <= m. 

// So, substituting d into our original equation, we get:
// (mi-ci)*d <= ti - ai*tc - bi*(tm - m)
// Note that we need to seperate this into three cases
// 1.   If (mi-ci > 0), we can just divide both sides by the differences and use the
//      resulting value as an upper bound
// 2.   If (mi-ci < 0), we need to flip the sign, so the resulting value becomes a
//      lower bound
// 3.   If (mi-ci == 0), we CANNOT divide by 0! Instead, the left side just becomes 0,
//      and we want to check if the right side is greater than or equal to zero

// we can keep track of these upper and lower bounds for d, and if after processing all
// N inequalities, we have a valid range for d (lower bound <= upper bound), then this
// value of m is possible

// ugh we also need to be carefull with dividing by negative numbers with floor and ceil.
// also another constraint on d is that the final cook times for c and m both need to be
// >= 1

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T; cin >> T;
    while (T--) {
        int N, tc, tm; cin >> N >> tc >> tm;
        vector<int> c(N);
        vector<int> m(N);
        vector<ll> t(N);
        for (int i=0; i < N; i++) cin >> c[i] >> m[i] >> t[i];

        int lo = 0, hi = tc+tm-2;
        while (lo != hi) {
            int mid = lo + (hi - lo) / 2;

            bool pos = true;
            ll l = max(0,1-tm+mid), r = min(mid, tc-1);
            for (int i=0; i < N; i++) {
                ll diff = m[i]-c[i];
                ll right = t[i] - (ll)c[i]*tc - (ll)m[i]*(tm-mid);
                if (diff > 0LL) r = min(r, (ll)floor((long double)right/diff));
                else if (diff < 0LL) l = max(l, (ll)ceil((long double)right/diff));
                else if (right < 0LL) {
                    pos = false; break;
                }
            } if (l > r) pos = false;

            if (pos) hi = mid;
            else lo = mid+1;
        }

        cout << lo << '\n';
    }
}