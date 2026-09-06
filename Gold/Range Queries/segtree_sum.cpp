// CSES Problem Set - Dynamic Range Sum Queries

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> segtree;
int N;

void update(int k, ll u) {     // set segtree[k] to u
    k += N;
    segtree[k] = u;
    for (k /= 2; k > 0; k /= 2) {
        segtree[k] = segtree[2*k] + segtree[2*k+1];
    }
}

ll query(int l, int r) {   // [l, r)
    l += N; r += N;
    ll sum = 0;
    // while (l < r) {
    while (l <= r) {
        if (l%2==1) sum += segtree[l++];
        // if (r%2==1) sum += segtree[--r];
        if (r%2==0) sum += segtree[r--];
        l /= 2; r /= 2;
    } return sum;
}

int main() {
    int Q; 
    cin >> N >> Q;
    segtree.clear(); segtree.resize(2*N, 0LL);
    for (int i=0; i < N; i++) {
        int x; cin >> x;
        update(i, x);
    }

    while (Q--) {
        int type; cin >> type;
        if (type==1) {
            int k, u; cin >> k >> u;    // k should be 0-indexed
            update(k-1, u);
        } else {
            int l, r; cin >> l >> r;
            // cout << query(l-1,r) << '\n';
            cout << query(l-1,r-1) << '\n';
        }
    }
}