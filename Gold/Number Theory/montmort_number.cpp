// Montmort Number: print all derangements of size i (1 <= i <= N)
// USACO Guide Derangements

#include <bits/stdc++.h>
using namespace std;

int N, M;

void PIE() {
    // derangements = permutations - invalid arrangements
    // alternating addition/subtraction

    long long d = 1;    // !0 = 1
    for (int i=1; i <= N; i++) {
        d = (d*i%M + (i%2==1? M-1 : 1)) % M;
        cout << d << ' ';
    }
}

void DP() {
    // d[i] = (i-1) * (!(i-1) + !(i-2))
    
    long long a = 1;    // i-2; !0 = 1
    long long b = 0;    // i-1; !1 = 0
    cout << b << ' ';
    for (int i=2; i <= N; i++) {
        long long c = (i-1) * (b + a) % M;
        cout << c << ' ';
        a = b;
        b = c;
    }
}

int main() {
    cin >> N >> M;

    // PIE();
    DP();
}