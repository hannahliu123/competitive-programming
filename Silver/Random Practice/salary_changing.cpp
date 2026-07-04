// CF - D. Salary Changing - R1900

// Start: 7:49
// End: 8:47        58 mins

// ayy im actually really proud i ended up figuring this one out. i did have to look at 
// my failed test cases tho cos morale was low lol. um i had a gut feeling it would be
// binary search and i was right yey but it did depend on the greedy realization that 
// if you can have a median of x and a median of y, then you can always have a median
// of any number between x and y.
// However, i didn't actually need to spend so much time realizing that! I have a bad
// habit of limiting my binary searches to strict equalities. I originally wanted to 
// directly serach on the median to see if it was possible to make a median exactly
// equal to M. However, a MUCH better solution would be to search on whether it was
// possible to make a median M or greater! So in this case, it would be a monotonic
// function and i wouldn't need that loophole. then i could start with lo=1 and hi=1e9.
// but if i did do that, i would need to update my binary search to check if the current
// median (or a value higher) can possible be created, which is true if there are (N+1)/2
// values greater than M. If it can't be created, we set hi to M-1 (upper bound). If it
// can, we check if it's minimum cost is <= S. If Not, we set hi to M-1 again.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; long long S;
        cin >> N >> S;

        vector<pair<int,int>> v(N);
        vector<int> l(N);
        vector<int> r(N);
        for (int i=0; i < N; i++) {
            cin >> l[i] >> r[i];
            v[i] = {l[i], r[i]};
        }

        if (N==1) {
            cout << min(S, (long long)r[0]) << '\n';
            continue;
        }

        sort(v.rbegin(), v.rend());  // g -> l
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());

        // binary search on median
        int lo=l[N/2], hi=r[N/2];
        while (lo != hi) {
            int M = lo + (hi - lo +1)/2;

            long long sum = 0;
            int less=0, greater=0, equal=0;
            vector<int> eq{};
            for (int i=0; i<N; i++) {
                if (v[i].first > M) {
                    greater++;
                    sum += v[i].first;
                } else if (v[i].second < M) {
                    less++;
                    sum += v[i].first;
                } else {
                    equal++;
                    eq.push_back(i);
                }
            }
            while (less < N/2) {
                int idx = eq.back();
                eq.pop_back();
                sum += v[idx].first;
                less++;
            }
            while (greater <= N/2) {
                int idx = eq.back();
                eq.pop_back();
                sum += M;
                greater++;
            }

            if (sum <= S) lo = M;
            else hi = M-1;
        }

        cout << lo << '\n';
    }
}