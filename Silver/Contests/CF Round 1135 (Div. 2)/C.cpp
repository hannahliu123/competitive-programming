#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

long long exp(long long a, long long b) {
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
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        sort(a.rbegin(), a.rend());

        long long ans = 0;
        for (int i=0; i < N; i++) {
            if ((i==0||a[i]!=a[i-1]) && (i==N-1||a[i]!=a[i+1])) {
                long long contr = exp(a[i]-1, i+1);
                ans = (ans + contr) % MOD;
            } else break;
        }

        cout << ans + 1 << '\n';
    }
}