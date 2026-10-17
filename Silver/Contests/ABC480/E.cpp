// So bedcause the bounds on N are so large, let's look at what we could potentially
// fix. So if we cap the starting number (a), it can go from 1 to cubroot(n), or 10^6.
// If we cap k (increments of each value in the array), it can go from 1 to about
// 7*10^8, which is too large to iterate over. If we cap the length of the array, it
// can go from 3 to 19 in the worst case senario. So, it is sufficient to iterate
// over all possible combinations of a and length (l), the for each iteration, binary
// search on the maximum possible k value, meaning the total contribution is all k
// values from 1 to k_max, or just k_max total contributions. for each binary search,
// we need to iterate over the length, so it costs O(l*logK). The overall time 
// complexity is O(a*l*l*logK), which is about O(al^2 * logN) which is like kinda
// technically sufficient :)

// but to avoid overflows, instead of keeping multiplying prod by some value then
// checking if prod > N, we can just check if prod > N/x where x is the value we
// wanted to multiply by. 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;

bool valid(ll a, ll l, ll k) {
    ll prod = 1;
    for (int i=0; i < l; i++) {
        ll mult = a+i*k;
        if (prod > N/mult) return false;
        prod *= mult;
    }
    return prod <= N;
}

int main() {
    cin >> N;

    ll ans = 0;
    for (int a=1; a < 1e6; a++) {
        for (int l=3; l <= 19; l++) {
            if (!valid(a,l,1)) continue;
            ll lo=1, hi = 1e9;
            while (lo < hi) {
                ll mid = lo + (hi - lo + 1)/2;
                if (valid(a, l, mid)) {
                    lo = mid;
                } else hi = mid-1;
            }
            ans += lo;
        }
    }

    cout << ans << '\n';
}