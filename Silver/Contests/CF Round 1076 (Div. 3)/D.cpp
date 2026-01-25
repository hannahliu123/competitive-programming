// D

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> a(N);   // strength
        for (auto& i : a) cin >> i;
        vector<int> b(N);   // strikes needed
        for (auto& i : b) cin >> i;

        sort(a.begin(), a.end());   // l -> g
        vector<int> pref(N+1, 0);
        for (int i{0}; i < N; ++i) {
            pref[i+1] = pref[i]+b[i];
        }

        long long ans = 0;
        for (int i{0}; i < N; ++i) {
            long long x = a[i];
            int swords = N-i;   // # of valid swords
            int level = upper_bound(pref.begin(), pref.end(), swords) - pref.begin();
            level--;
            ans = max(ans, x*level);
        }

        cout << ans << endl;
    }
}
