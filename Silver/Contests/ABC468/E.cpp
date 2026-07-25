// E

// the solution to this one involves calculating the sum of all subtrings of lengths 1,
// then 2, then 3. the sum is the numerator and the length is the denominator and then
// you add up all the fractions. however, because of the mod, instead of evaluating n/d,
// we treat that as n * d^-1 (modular inverse of denominator). using fermats little
// theorem, we know the mod inverse of d is d^(M-2), which we can calculate in O(log M) 
// time with binary exponentiation. Then we just sum all those values

// for length 1, we add all pref[i] where i is from 1 to N and subtract all pref[j] where
// j is from 0 to N-1. so, we're just adding pref[N]-pref[0]. then for all length 2, we
// add all i from 2 to N and subtract j from 0 to N-2. So, we're just adding
// pref[N-1]+pref[N]-pref[0]-pref[1]. that is equal to the length for 1 (previously
// calculated) + pref[N-1]-pref[1]. then continue that patter for lengths 3, 4, ... N

// note that here you need to be extra careful with modular stuff and u need to constantly
// be taking mods and using long longs

#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> a(N);
    for (auto& i : a) cin >> i;

    vector<long long> pref(N+1,0);
    for (int i=1; i <= N; i++) {
        pref[i] = (pref[i-1]+a[i-1]) % MOD;
    }

    long long sum = 0;
    long long num = 0;  // numerator
    int l=0, r=N;
    for (long long den=1; den <= N; den++) {
        // note how we need to add MOD because pref[r]-pref[l] can be negative and num is
        // always changing because we take the MOD so it's very likely that the result is
        // negative
        num = (num + pref[r]-pref[l] + MOD) % MOD;
        l++; r--;

        long long x = (num * power(den, MOD-2)) % MOD;
        sum = (sum + x) % MOD;
    }

    cout << sum << '\n';
}