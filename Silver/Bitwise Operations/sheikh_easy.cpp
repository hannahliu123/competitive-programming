// CF - C1. Sheikh (Easy version) - R1800

// Yeah no i don't think i wouldn't gotten this problem without a hint. Basically,
// the greedy observation is that if l=1, f(l,r) will always increase as r increases.
// this is because every time you increase r, you add x and subtract x xor y where
// y is any number. the value of the xor cannot increase by more than x (it can only
// increase by at most x), so the value of f(l,r) cannot decrease. thus, for the array
// a, the largest value of f(l,r) will occur when l=1 and r=N. However, this value may
// also be able to be acheived when l>1 or r<N, so you can use two pointers to increase
// l or decrease r as long as f(l,r) is still the max value utilizing prefix sums and
// prefix xor

// oh also for two pointers, you need to do the classic version starting both l and r
// from the start because if you start r from the end and try to narrow down a section
// in the middle, u wont always get the right answer cos there can be multiple different
// combos that result in f(l,r) = max_f

#include <bits/stdc++.h>
using namespace std;

vector<long long> prefSum;
vector<long long> prefXOR;

long long getf(int l, int r) {
    return (prefSum[r+1]-prefSum[l]) - (prefXOR[r+1]^prefXOR[l]);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int N, Q; cin >> N >> Q;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        int L, R; cin >> L >> R;

        prefSum.resize(N+1,0);
        prefXOR.resize(N+1,0);
        for (int i=1; i <= N; i++) {
            prefSum[i] = prefSum[i-1] + a[i-1];
            prefXOR[i] = prefXOR[i-1] ^ a[i-1];
        }

        long long f = prefSum[N] - prefXOR[N];
        int mnLen = N;
        L=0; R=N-1;
        int l=0;
        for (int r=0; r < N; r++) {
            while (l<r && getf(l,r) == f) {
                if (r-l+1 < mnLen) {    // update best l,r
                    mnLen = r-l+1;
                    L=l; R=r;
                } l++;
            }
        }

        long long newf = getf(L, R-1);
        while (R>L && newf == f) {
            R--;
            newf = getf(L, R-1);
        } newf = getf(L+1, R);
        while (L<R && newf == f) {
            L++;
            newf = getf(L+1, R);
        }

        cout << L+1 << ' ' << R+1 << '\n';
    }
}
