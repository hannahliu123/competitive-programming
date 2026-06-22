// CSES - Exponentiation

#include <bits/stdc++.h>
using namespace std;

int main() {
    int M = 1000000007;
    int t; cin >> t;
    while (t--) {
        long long a, b; cin >> a >> b;
        // break a^b into seperate parts such that the exponent is a power of 2
        a %= M;
        long long ans = 1;
        while (b > 0) {
            if (b & 1) ans = ans * a % M;
            a = a*a % M;
            b >>= 1;
        }

        cout << ans << '\n';
    }
}