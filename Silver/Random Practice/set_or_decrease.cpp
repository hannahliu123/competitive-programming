// CF - C. Set or Decrease - R1600

// Start: 4:46
// End: 5:28        42 mins

// yayyaya this problem was pretty straightforward

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; long long K;
        cin >> N >> K;
        vector<int> a(N);
        long long sum = 0;
        for (auto& i : a) {
            cin >> i; sum += (long long)i;
        } sort(a.rbegin(), a.rend());   // g -> l
        int mn = a[N-1];

        vector<long long> pref(N+1, 0);
        for (int i=1; i <= N; i++) {
            pref[i] = pref[i-1]+a[i-1];
        }

        // binary search on total steps
        int lo = 0, hi = INT_MAX;
        while (lo < hi) {
            int steps = lo + (hi - lo)/2;
            if (steps==7) {
                int x=2;
            }

            bool pos = false;
            for (int i=0; i <= min(N, steps); i++) {
                // set the first i elems in a to the min value
                int dec = steps-i;  // number of times we decrement the min value
                long long newMn = mn-dec;
                long long diff = dec;
                if (i < N) diff += pref[i] - newMn*i;

                if (sum - diff <= K) {
                    pos = true; break;
                }
            }

            if (pos) hi = steps;
            else lo = steps+1;
        }

        cout << lo << '\n';
    }
}