// E. G-C-D, Unlucky! - R1400

// ugh tspmos so much. i realized the basic conditions that p has to decrease and s
// increase and how the divisibility must persist in p and s. i also noticed how s[0]
// and p[N-1] must match. but i feel like there are just so many edge cases and not 
// really an algorithm that solves this problem. i noticed also that we don't actually
// need to construct a, only determine if it exists so im guessing there's just some
// properties i need to figure out and as long as those are satisfied, some solution
// must exist. I mean the values of a could be anything because there are no bounds.

// the next step once we confirmed an array a might exist is to greedily build a[i]
// such that a[i] = lcm(p[i], s[i]). Why? We know a[i] is a multiple of p[i] and s[i],
// so by selecting the least common multiple, we set a[i] as the smallest possible valid
// value for a[i]. Why choose the smallest? Well, lcm guarentees that only the factors
// shared in both p[i] and s[i] result in a[i]. Picking larger values of a[i] introduces
// more potential prime factors, thus causing a[i] to potentially have a larger gcd when
// combined with other values in a (meaning it won't satisfy p and s).
// The reason this gives us the solution is because selecting the lcm gives us the most
// optimal possibility for each a[i]. When we check out work to see if array a is valid,
// it's possible that it will be invalid in the case where a[i] or s[i] is lower than
// it should be given the selected a[i]. notice tho how increasing the value at a[i]
// wouldn't make the current gcd smaller, only potentially larger. p[i] and s[i] will 
// never be higher than the gcd using our selected a[i] values because we know a[i] must
// have p[i] and s[i] as divisors, so gcd of those a[i] values will at the very least be
// p[i] or s[i] or higher. 

// so my intuition of not constructing the array a was wrong. if i just noticed each a[i]
// had to be a multiple of p[i] and s[i] and should be the lowest, i could've MAYBE gotten
// a better idea but this was too convoluted and complicated imo. NOT 1400 bro 

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<long long> p(N);
        for (auto& i : p) cin >> i;
        vector<long long> s(N);
        for (auto& i : s) cin >> i;

        bool pos = true;
        for (int i=1; i < N; i++) {
            if (p[i]>p[i-1] || p[i-1]%p[i]!=0) {
                pos = false; break;
            }
        }
        for (int i=N-2; i >= 0; i--) {
            if (s[i]>s[i+1] || s[i+1]%s[i]!=0) {
                pos = false; break;
            }
        }
        if (N>1 && p[0]%s[1]==0 && s[0]!=s[1]) pos = false;
        if (N>1 && s[N-1]%p[N-2]==0 && p[N-1]!=p[N-2]) pos = false;

        if (!pos || p[N-1]!=s[0]) {
            cout << "NO\n";
            continue;
        }

        vector<long long> a(N);
        for (int i=0; i < N; i++) {
            a[i] = lcm(p[i],s[i]);
        }
        long long pref_gcd = a[0];
        for (int i=0; i < N; i++) {
            pref_gcd = gcd(pref_gcd, a[i]);
            if (pref_gcd != p[i]) {
                pos = false; break;
            }
        }
        long long suff_gcd = a[N-1];
        for (int i=N-1; i >=0; i--) {
            suff_gcd = gcd(suff_gcd, a[i]);
            if (suff_gcd != s[i]) {
                pos = false; break;
            }
        }

        if (!pos) cout << "NO\n";
        else cout << "YES\n";
    }
}