// USACO 2026 Third Contest, Silver
// Problem 2. Milk Buckets

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> cap(N); // capacity
    for (auto& i : cap) cin >> i;
    
    vector<long long> need(N);    // number of pours needed from prev
    need[0] = (long long)cap[0];
    long long mult = 1;
    for (int i{1}; i < N; ++i) {
        long long x = (long long)cap[i]/cap[i-1];
        if (cap[i]%cap[i-1]>0) x++; // round up
        need[i] = x;
        mult *= x;
    }

    int Q; cin >> Q;
    while (Q--) {
        int i, v;    // cap[i] = v (persists through all queries)
        long long t;
        cin >> i >> v >> t; i--;

        cap[i] = v;
        if (i>0) {
            mult /= need[i];
            long long x = ((long long)cap[i]/cap[i-1]);
            if (cap[i]%cap[i-1]>0) x++; // round up
            need[i] = x;
            mult *= need[i];
        }

        t -= (long long)(N-1);
        long long y = (long long)t/(cap[0]+1);

        cout << cap[N-1]*y/mult << '\n';
    }
}
