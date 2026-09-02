// CSES Problem Set - Dynamic Range Minimum Queries

#include <bits/stdc++.h>
using namespace std;

vector<int> segtree;
int N;

void update(int k, int u) {
    k += N;
    segtree[k] = u;
    for (k /= 2; k > 0; k /= 2) {
        segtree[k] = min(segtree[2*k], segtree[2*k+1]);
    }
}

int query(int l, int r) {   // [l, r)
    l += N; r += N;
    int mn = INT_MAX;
    while (l < r) {
        if (l%2==1) mn = min(mn, segtree[l++]);
        if (r%2==1) mn = min(mn, segtree[--r]);
        l /= 2; r /= 2;
    } return mn;
}

int main() {
    int Q; 
    cin >> N >> Q;
    segtree.clear(); segtree.resize(2*N, INT_MAX);
    for (int i=0; i < N; i++) {
        int x; cin >> x;
        update(i, x);
    }

    while (Q--) {
        int type; cin >> type;
        if (type==1) {
            int k, u; cin >> k >> u;
            update(k-1, u);
        } else {
            int l, r; cin >> l >> r;
            cout << query(l-1, r) << '\n';
        }
    }
}