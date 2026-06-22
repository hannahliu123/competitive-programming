// CSES - Exponentiation II

#include <bits/stdc++.h>
using namespace std;

// stop wait im actually so surprised i figured this out. i was kinda skeptical
// and very not confident tho so i glanced at the editorial before implementing.
// all u relaly needed to know for this one was that fermat's little theorem
// says a^M-1 % M = 1 always if M is prime. so, we can break up a^b^c into 
// a^M-1 * a^M-1 * ... * a^rem which will end up to just be 1 * 1 * ... * a^rem.
// thus we just need the rem to be modulo M-1 :)))

int main() {
    int M = 1000000007;
    int t; cin >> t;
    while (t--) {
        long long a, b, c; cin >> a >> b >> c;

        // calculate b^c % M-1
        long long res = 1;
        b %= (M-1);
        while (c > 0) {
            if (c & 1) res = res*b % (M-1);
            c >>= 1;
            b = b*b % (M-1);
        }

        // calculate a^res % M
        long long ans = 1;
        a %= M;
        while (res > 0) {
            if (res & 1) ans = ans*a % M;
            res >>= 1;
            a = a*a % M;
        }

        cout << ans << '\n';
    }
}