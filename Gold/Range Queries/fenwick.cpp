// CSES Problem Set - Dynamic Range Sum Queries

#include <bits/stdc++.h>
using namespace std;

int N; 
vector<int> a;
vector<long long> fenwick;    // binary indexed tree

void update(int k, long long u) {     // increase index k by u
    while (k <= N) {
        fenwick[k] += u;
        k += k&-k;
    }
}

long long query(int k) {    // sum from [1,k]
    long long sum = 0;
    while (k > 0) {
        sum += fenwick[k];
        k -= k&-k;
    } return sum;
}

int main() {
    int Q; 
    cin >> N >> Q;
    a.clear(); a.resize(N+1);
    fenwick.clear(); fenwick.resize(N+1, 0LL);
    for (int i=1; i <= N; i++) {
        cin >> a[i];
        update(i, a[i]);
    }

    while (Q--) {
        int type; cin >> type;
        if (type==1) {
            int k, u; cin >> k >> u;    // leave k 1-indexed
            update(k, u-a[k]);
            a[k] = u;
        } else {
            int l, r; cin >> l >> r;
            cout << query(r)-query(l-1) << '\n';
        }
    }
}