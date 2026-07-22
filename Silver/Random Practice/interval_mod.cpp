// CF - A. Interval Mod - R1700

// Start: 9:57
// End: 10:28       31 mins

// YAYAYYY HOLY MOLY i can't beleive i got that so quickly. that did NOT feel like a 1700
// problem imma be so fr but hey we take it. yea the editorial solution is pretty much 
// the same YAYAYAYAYA

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, k, P, Q; cin >> N >> k >> P >> Q;
        vector<int> a(N);
        vector<int> p(N);
        vector<int> q(N);
        vector<long long> prefMn(N+1, 0);
        for (int i=0; i < N; i++) {
            cin >> a[i];
            p[i] = a[i] % P;
            q[i] = (a[i] % Q) % P;
            prefMn[i+1] = prefMn[i] + min(p[i], q[i]);
        }

        int l=0;
        long long psum=0, qsum=0;
        long long ans = LONG_LONG_MAX;
        for (int i=0; i < k-1; i++) {
            psum += p[i];
            qsum += q[i];
        }
        for (int r=k-1; r < N; r++) {
            psum += p[r]; qsum += q[r];
            long long sum = prefMn[r+1] - prefMn[l];
            ans = min(ans, min(psum, qsum) + prefMn[N] - sum);

            psum -= p[l]; qsum -= q[l];
            l++;
        }

        cout << ans << endl;
    }
}
