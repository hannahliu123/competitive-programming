// CSES Problem Set - Counting Divisors

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    while (N--) {
        int x; cin >> x;

        int ans = 0;
        for (int i=1; i*i <= x; i++) {
            if (x%i==0) {
                if (x/i==i) ans++;
                else ans += 2;
            }
        }

        cout << ans << '\n';
    }
}