// CSES Problem Set - Range Update Queries

// yayaya im so happy i got this :))) literally just a segtree but backwards heheh

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, Q;
vector<ll> segtree;

void update(int l, int r, ll u) {
    l += N; r += N;
    while (l <= r) {
        if (l%2==1) segtree[l++] += u;
        if (r%2==0) segtree[r--] += u;
        l/=2; r/=2;
    }
}

ll query(int k) {
    ll ans = 0LL;
    k += N;
    while (k > 0) {
        ans += segtree[k];
        k /= 2;
    } return ans;
}

int main() {
    cin >> N >> Q;
    segtree.clear(); segtree.resize(2*N, 0LL);
    for (int i=0; i < N; i++) {
        cin >> segtree[i+N];
    }

    while (Q--) {
        int type; cin >> type;
        if (type==1) {
            int a, b, u; cin >> a >> b >> u;
            a--; b--;
            update(a, b, u);
        } else {
            int k; cin >> k; k--;
            cout << query(k) << '\n';
        }
    }
}