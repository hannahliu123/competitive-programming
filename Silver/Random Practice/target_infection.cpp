// D. Target Infection - R1700

// I did notice that a maximum vaule must appear at some l_i and a minimum value
// must appear at 0 or some r_i+1. Also I noticed the answer f(s) can only increase
// or decrease by one as you go left to right. Now, the issue arises where M is so
// large you can't even loop through M itself, so there's absolutely no way you can
// check all possible indicies. as a result, binary search is looking real promising
// rn but f(s) isn't monotonically increasing/decreasing! Well, in this case that
// actually doesn't matter (this is lowkey the IVT in calc holy crap) because as long
// as we keep our interval above and below K, we are guarenteed to be able to narrow
// down to some k. We just need to find a valid interval to start from. Well, if we
// have r=1e15 + 1, starting an interval at r will result in f(r)=0 because there
// are no infected indicies after 1e15. Then we can start l at the maximum valid
// (which will be some l_i). To check some f(mid), we just need to see how many
// intervals overlap it (could use binary search on the vector of intervals or we 
// could just look from 1->N through the entire vector of intervals)

// I actually really like this problem but holy moly was the implementation indexing
// a nightmare. in the future i wanna spend way less time on one probelm... heh esp
// considering how long this stupid implementation took me kslkfjalkdsfjlkdjsf
// ig imma use lambda functions more from now on

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;

    while (t--) {
        int N; ll M, K;
        cin >> N >> M >> K;

        vector<ll> l(N);
        vector<ll> r(N);
        vector<ll> pref(N+1);   // pref ending at r[i-1]
        for (int i=0; i < N; i++) {
            cin >> l[i] >> r[i];
            pref[i+1] = pref[i] + r[i]-l[i]+1;
        }

        auto f = [&](ll s) -> ll {
            ll e = s+M-1;

            int idx_s = lower_bound(r.begin(), r.end(), s) - r.begin();
            int idx_e = upper_bound(l.begin(), l.end(), e) - l.begin() - 1;

            if (idx_s > idx_e) return 0;
            
            ll ans = pref[idx_e+1] - pref[idx_s];
            if (s>l[idx_s]) ans -= s-l[idx_s];
            if (e<r[idx_e]) ans -= r[idx_e]-e;

            return ans;
        };
        
        ll mx = 0, cnt = 0, mx_idx = -1;
        for (int i=0; i < N; i++) {
            cnt = f(l[i]);
            if (cnt > mx) {
                mx = cnt; mx_idx = l[i];
            }
        }

        if (K > mx) {
            cout << -1 << '\n';
            continue;
        }

        ll lo=mx_idx, hi = 1e15+1;
        while (lo < hi) {
            ll mid = lo + (hi-lo)/2;

            cnt = f(mid);
            if (cnt == K) {
                lo = mid; break;
            } else if (cnt > K) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }

        cout << lo << '\n';
    }
}