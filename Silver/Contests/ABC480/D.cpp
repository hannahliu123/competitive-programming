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

    vector<int> fwdidx{};
    int inc = 0;
    for (int i=0; (int)fwdidx.size()<N+1; i++) {
        fwdidx.push_back(i);
        i += inc; inc++;
    }
    vector<long long> fwd(N+1,0);
    for (int i=1; i <= N; i++) {
        fwd[i] = fwd[i-1] + pref[i];
    }
    vector<int> bwdidx = fwdidx;
    for (int i=0; i < bwdidx.size(); i++) {
        bwdidx[i]++;
    }
    vector<long long> bwd(N+1,0);
    for (int i=N-1; i >= 0; i--) {
        bwd[i] = bwd[i+1] + pref[i+1];
    }

    while (Q--) {
        int L, R; cin >> L >> R;
        long long ans = fwd[N]; // sum of all B

        auto it = lower_bound(fwdidx.begin(), fwdidx.end(), L);
        it--;
        int fidx = it - fwdidx.begin();
        int idx = *it;
        long long p = fwd[fidx] + pref[L-idx-1];

        it = upper_bound(bwdidx.begin(), bwdidx.end(), R);
        int bidx = it - bwdidx.begin();
        idx = *it;
        long long s = bwd[bidx] + pref[bidx] - pref[bidx-(idx-R-1)];

        cout << ans-p-s << '\n';
    }
}