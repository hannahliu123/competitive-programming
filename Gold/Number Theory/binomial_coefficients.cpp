// CSES Problem Set - Binomial Coefficients

#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;
int MAX_N = 1000000;

int main() {
    vector<long long> fact(MAX_N+1);
    fact[0] = 1;
    for (int i=1; i <= MAX_N; i++) {
        fact[i] = fact[i-1]*i % MOD;
    }

    vector<long long> invFact(MAX_N+1);
    invFact[0] = 1;
    invFact[1] = 1;
    for (int i=2; i <= MAX_N; i++) {
        invFact[i] = (MOD - MOD/i) * invFact[MOD % i] % MOD;
    } for (int i=2; i <= MAX_N; i++) {
        invFact[i] = invFact[i-1]*invFact[i] % MOD;
    }

    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        long long ans = fact[a] * invFact[b] % MOD * invFact[a-b] % MOD;
        cout << ans << '\n';
    }
}