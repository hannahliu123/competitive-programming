// USACO 2023 December Contest, Silver
// Problem 2. Cycle Correspondence

// bruh ok so i got this to work but i kept accidentally using N vs K. maybe
// next time i should just a more non-generic name for N or K and also for 
// different vectors. i think imma start doing that.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N, -1);
    for (int i{0}; i < K; ++i) {
        int x; cin >> x; x--;
        a[x] = i;
    } vector<int> b(K);
    for (int i{0}; i < K; ++i) {
        cin >> b[i]; b[i]--;
    }

    vector<int> fwd(N, 0);
    vector<int> bwd(N, 0);
    int mx = 0, outside = N-K;
    for (int i{0}; i < K; ++i) {
        if (a[b[i]]==-1) {
            outside--;
            continue;
        }

        int idx = i-a[b[i]];
        if (idx<0) idx += K;
        fwd[idx]++;
        if (fwd[idx] > mx) mx = fwd[idx];

        idx = i+a[b[i]];
        if (idx>=K) idx -= K;
        bwd[idx]++;
        if (bwd[idx] > mx) mx = bwd[idx];
    }

    cout << mx+outside << endl;
}
