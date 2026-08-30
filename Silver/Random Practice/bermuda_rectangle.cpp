// D. Bermuda Rectangle - R1600

// okay i think i got a solution that works but TLEs. i had this before but the 
// implementation was really really messy (partially because i was doing this at school
// and i wasn't very focused). um i think i fixed it tho but the time complexity is
// O(sqrtS + q*sqrtS)

// to optimize it, one thing we can notice is that if a rectangle already sits inside a
// bermuda rectange, the answer is just x*y. this isn't enough at all, but its just something
// nice to notice (idt you actually need it).
// Now notice how when you're calculating the answer for one (x,y) coordinate, what im doing
// right now is finding the L-shape contribution of each factor. However, this is totally
// unnecessary because im looping through O(sqrtS) factors anyways and i could instead just
// loop through all O(2*sqrtS) factor pairs and see it's column contribution (so width times
// height, or (currx-prevx)*height). notice how the width is dependent on (capped by) x, so
// we can't exceed a width of x and height is capped by y, so we can't go above y. knowing
// this, we can precompute the area contributions of each x section if there were no cap,
// then use binary search to see at which x value the cap ends (because y values are
// decreasing; staircase structure). For all the y values that get capped, the area contribution
// is just the width (currx) times the y value (cap). then for all x values afterwards, we can
// use a prefix array of precomputed values (but make sure we stop at x)

// bro this implementation pmoed so much. when it comes to implementing, i need to just stay
// calm and not rush the process. it helps to name out all the variables and use if else
// statements a ton even if the code could technically be more consise. REMEMBER: Don't 
// over-optimize!!! (exp if you arent sure if it's 100% correct)

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long S; int Q;
        cin >> S >> Q;

        // find all factors
        vector<long long> factors{};
        for (long long i=1; i*i <= S; i++) {
            if (S%i==0) {
                factors.push_back(i);
                if (S/i != i) factors.push_back(S/i);
            }
        } 
        int F = factors.size();
        sort(factors.begin(), factors.end());

        vector<long long> pref(F+1,0LL);    // pref[i]=area from x=0 to x=f[i-1]
        long long prevX = 0;
        for (int i=1; i <= F; i++) {
            long long f = factors[i-1];
            pref[i] = pref[i-1] + (f-prevX)*(S/f);
            prevX = f;
        }

        while (Q--) {
            long long x, y; cin >> x >> y;

            long long ans = 0;
            auto it = lower_bound(factors.begin(), factors.end(), y);
            if (it != factors.end()) {
                long long leftx = S/(*it);
                if (leftx >= x) {
                    ans += x*y;
                } else {
                    ans += leftx*y;
                    int idx = upper_bound(factors.begin(), factors.end(), x) - factors.begin();
                    int idx2 = upper_bound(factors.begin(), factors.end(), leftx) - factors.begin();
                    ans += pref[idx] - pref[idx2];
                    if (idx < F) ans += (x-factors[idx-1])*(S/factors[idx]);
                }
            } else {
                int idx = upper_bound(factors.begin(), factors.end(), x) - factors.begin();
                ans += pref[idx];
                if (idx < F) ans += (x-factors[idx-1])*(S/factors[idx]);
            }
            cout << ans << '\n';
        }
    }
}
