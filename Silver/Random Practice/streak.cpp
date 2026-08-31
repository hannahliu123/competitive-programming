#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long a, b, c; cin >> a >> b >> c;
        long long total = a + b + c;
        long long mx = max(a, max(b, c));
        long long mn = min(a, min(b, c));
        cout << min(mx, total-mx) - mn << '\n';
    }
}