// E

// first, it's obvious that we can't just naively compute the squared sum for all 
// combinations of k numbers. But, this does seem like there might be a clever way
// to count or "math" around the time constraints. So, the key realization is to
// break down the problem into expected values. We know that all combinations should
// be exactly of length k, so what we can do is find the average (expected value) of
// sum^2 values for any combination of length k. then we multiply that expected
// value by the total number of possible combinations. Note that we can't just compute
// the expected sum value then square it because the math doesn't work that way because
// squaring a number with a smaller magnitude results in a smaller change than squaring
// a number with a larger magnitude. So now we need to compute the expected value of
// a combinations of k values squared and also the total number of possible combinations

// Now we know that each element has a probability of K/N of being chosen in the current
// combination. However, we can't quite use that directly because we can't break up the
// sums within the square because you can't just move the square "out". Instead, it's
// key to notice that when you square the sum of some terms, which you can easily
// show using the box method, you end up with:
// (a+b+c+...)^2 = (a^2 + b^2 + c^2 + ...) + (ab + ac + ba + bc + ca + cb + ...)
// So, the expected value of (a+b+c+...)^2 can be broken up into two expected values
// using Linearity of Expectation: E(a^2 + b^2 + c^2 + ...)+E(2ab + 2ac + 2bc + ...)

// to compute the first term's expected value, we can break those up even further b/c
// it's just addition into the expected value for each item squared. That expected
// value is just the probability times the value squared, or K/N*a[i]^2 the summed
// over i from 0 to N-1.
// now for the second term, we can also split up the addition into the expected value
// of the product of each item with every other item excluding itself that is chosen.
// the probability the first item is chosen is K/N. Assuming it's chosen, the probability
// the second is also chosen is (K-1)/(N-1). The final expected value for one pair is
// (K(K-1))/(N(N-1)) * a[i]*a[j]. HOWEVER, this would take O(N^2) to compute, so we
// instead need a workaround for computing all the sums of a[i]*a[j] such that i!=j.
// what we can do is compute the sum of all i,j (including when i==j) then subtract
// the i==j sections. Say if the items were {a,b,c,d} and s=a+b+c+d, we would just have 
// a(s)+b(s)+c(s)+d(s) - a(a) - b(b) - c(c) - d(d), and that first section happens to
// equal (a+b+c+d)(s), which is just s^2. 

// finally once we have the overall expected value by combining those components, we
// multiply it by the number of total combinations to chose K items from N. But actually
// the nCr formula is equal to n!/(k!(n-k)!), and if we combined that with the two
// parts that made up the expected value, we can slightly tweak the expected value
// equation to account for multiplying by that (n k) so we dont need to divide K/N or 
// K-1/N-1

// oh also for modulos you can just keep taking modulos whereever there's addition or
// multiplication

#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

long long power(long long a, long long b) {     // a^b % MOD
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1) {	// b%2==1
            res = res * a % MOD;
        } a = a * a % MOD;
        b >>= 1;		// divide by 2
    } return res; 
}

int main() {
    int N, K; cin >> N >> K;
    vector<long long> a(N);
    for (auto& i : a) cin >> i;

    // (a+b+c+...)^2 = (a^2 + b^2 + c^2 + ...) + (ab + ac + ba + bc + ca + cb + ...)
    
    long long e1 = 0;     // sum(a[i]^2)
    long long e2 = 0;     // [sum(a[i])]^2 - sum(a[i]^2)
    for (int i=0; i < N; i++) {
        a[i] %= MOD;
        e1 = (e1+((a[i]*a[i])%MOD))%MOD;
        e2 = (e2+a[i])%MOD;
    }
    e2 = (e2*e2)%MOD;
    e2 = (e2-e1+MOD)%MOD;

    vector<long long> fact(N);
    vector<long long> invFact(N);
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[N-1] = power(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; i--) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    } 

    long long nCr1 = (((fact[N-1] * invFact[K-1]) % MOD) * invFact[N-K]) % MOD;
    long long nCr2 = 0;
    if (K>1 && N>1) nCr2 = (((fact[N-2] * invFact[K-2]) % MOD) * invFact[N-K]) % MOD;

    cout << (((nCr1*e1)%MOD) + ((nCr2*e2)%MOD)) % MOD << '\n';
}