// okay so this problem wasnt actually that bat but the implementation is a nightmare

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1000000007;

ll power(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        } a = a * a % MOD;
        b >>= 1;
    } return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    
    // nCr stuff
    vector<ll> fact(200001);
    vector<ll> invFact(200001);
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) {	// compute the factorial of each i
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[200000] = power(fact[200000], MOD-2);
    for (int i = 200000-1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i+1)) % MOD;
    }

    auto nCr = [&](ll n, ll r) -> ll {
        if (r>n) return 0;
        if (r==n) return 1;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    };

    while (t--) {
        int N, M, Q; cin >> N >> M >> Q;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<ll> pref(N);
        pref[0] = a[0];
        for (int i=1; i < N; i++) pref[i] = pref[i-1]+a[i];
        vector<ll> suff(N);
        suff[N-1] = a[N-1];
        for (int i=N-2; i >= 0; i--) suff[i] = suff[i+1]+a[i];

        map<ll, vector<int>> pos;
        for (int i = 0; i < N-1; i++) {
            ll diff = suff[N-i-1] - pref[i];
            pos[diff].push_back(i);
        }

        while (Q--) {
            int idx, v; cin >> idx >> v; idx--;
            int i=idx, j=N-idx-1;
            if (j < i) {
                swap(i,j);
                v = -1*v;
            } j--;

            ll cnt = 0;
            int startidx0 = lower_bound(pos[0].begin(), pos[0].end(), i) - pos[0].begin();
            int endidx0 = upper_bound(pos[0].begin(), pos[0].end(), j) - pos[0].begin();
            cnt = startidx0 + (pos[0].size() - endidx0);
            int startidxv = lower_bound(pos[v].begin(), pos[v].end(), i) - pos[v].begin();
            int endidxv = upper_bound(pos[v].begin(), pos[v].end(), j) - pos[v].begin();
            cnt += (endidxv - startidxv);

            cout << nCr(cnt,M-1) << '\n';
        }
    }
}