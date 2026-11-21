#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

long long power(long long a, long long b) {
    a %= MOD;
    long long res = 1;
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
    vector<long long> fact(200001);
    vector<long long> invFact(200001);
    fact[0] = 1;
    for (int i = 1; i <= 200000; i++) {	// compute the factorial of each i
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[200000] = power(fact[200000], MOD-2);
    for (int i = 200000-1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i+1)) % MOD;
    } 

    while (t--) {
        int N, M, Q; cin >> N >> M >> Q;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<long long> pref(N);
        pref[0] = a[0];
        for (int i=1; i < N; i++) pref[i] = pref[i-1]+a[i];
        vector<long long> suff(N);
        suff[N-1] = a[N-1];
        for (int i=N-2; i >= 0; i--) suff[i] = suff[i+1]+a[i];

        auto nCr = [&](long long n, long long r) -> long long {
            if (r>n) return 0;
            if (r==n) return 1;
            return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
        };

        while (Q--) {
            int idx, v; cin >> idx >> v; idx--;
            int j=N-1;
            int cnt = 0;
            for (int i=0; i < N-1; i++) {
                long long pre=pref[i], suf=suff[j];
                if (i>=idx) pre += v;
                if (j<=idx) suf += v;
                if (pre==suf) cnt++;
                j--;
            }

            cout << nCr(cnt,M-1) << '\n';
        }
    }
}