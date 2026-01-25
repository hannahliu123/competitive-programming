// C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;

        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> b(N);
        for (auto& i : b) cin >> i;

        a[N-1] = max(a[N-1], b[N-1]);
        for (int i{N-2}; i >= 0; --i) {
            a[i] = max(a[i], max(a[i+1], b[i]));
        }

        vector<int> pref(N+1, 0);
        for (int i{0}; i < N; ++i) {
            pref[i+1] = pref[i]+a[i];
        }

        while (Q--) {
            int l, r;
            cin >> l >> r;

            cout << pref[r]-pref[l-1] << ' ';
        } cout << endl;
    }
}
