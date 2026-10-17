// ARE WE FRRRRRRR AHHHGHGHHGH ok so for this one i was running out of time at the
// end of the contest anyways so i didn't go thru all my debugging stuff. but now i
// was able to figure out the long long issue with the indexes. HOWEVER even when i
// tried to fix it, my implementation still used an int (lowkey sketchy implementation)
// so i changed it and NOWWWW it works. holy crap i could've solved a-d this contest 
// but embarrassingly only solved a... thats awkwarddddd

// i actually really like this problem tho because it's like a prefix sum of a prefix
// sum. im glad i figured it out, tho my train of thought was kinda messy and could've
// been simplified.

// also a better way to implement this would've been to store a single vector of pairs
// where the first item is the index in B (so that quadrating pattern) and the second
// item is the prefix of B up to that index. Obviously the first item in this array
// would need to be {0,0}. The first item should keep increasing by 1, then 2, then 3,
// etc. and the second should increase by the prefix sum value. then u can figure out
// indexing yeah womp womp

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i=0; i < N; i++) cin >> a[i];

    vector<long long> pref(N+1, 0);
    for (int i=1; i <= N; i++) {
        pref[i] = pref[i-1]+a[i-1];
    }

    vector<long long> fwdidx(N+1);   // N+1 precalculated indexes of B (1-indexed) from 0 to i
    long long val=0, inc=1;
    for (int i=0; i<=N; i++) {
        fwdidx[i] = val;
        val += inc; inc++;
    }
    vector<long long> fwd(N+1,0);   // values of N+1 precalculated prefixes of B from 0 to fwdidx[i]
    for (int i=1; i <= N; i++) {
        fwd[i] = fwd[i-1] + pref[i];
    }

    while (Q--) {
        long long L, R; cin >> L >> R; R++;

        auto it = lower_bound(fwdidx.begin(), fwdidx.end(), L);
        it--;   // points to index definitely lower than L
        int fidx = it - fwdidx.begin();
        long long idx = *it;
        long long p = fwd[fidx] + pref[L-idx-1];

        it = lower_bound(fwdidx.begin(), fwdidx.end(), R);
        it--;
        fidx = it - fwdidx.begin();
        idx = *it;
        long long p2 = fwd[fidx] + pref[R-idx-1];

        cout << p2-p << '\n';
    }
}