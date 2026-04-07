// D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> p(K);
        for (auto& i : p) cin >> i;

        int ans = 0, x = a[p[0]];
        ;

        cout << ans << '\n';
    }
}
