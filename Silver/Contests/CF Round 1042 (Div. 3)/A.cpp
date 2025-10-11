// Problem A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> b(N);
        for (auto& i : b) cin >> i;

        int ans = 0;
        for (int i{0}; i < N; ++i) {
            if (a[i] > b[i]) ans += a[i] - b[i];
        }

        cout << ans+1 << '\n';
    }
}
