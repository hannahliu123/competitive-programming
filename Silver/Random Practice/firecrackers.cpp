// CF - D. Firecrackers - R1700

// Start: 8:25
// End: 8:55        30 mins

// lol this was so easy i just messed up one simple area (i did an extra -1) for the
// sec calculation. no freaking way this is r1700 wth man. i mean ig its cos this is
// a really old problem but this is easier than bronze level wth. erm so its suppoused
// to be binary search but that's so pointless

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, A, B;
        cin >> N >> M >> A >> B;
        vector<int> s(M);
        for (auto& i : s) cin >> i;

        int fireworks = abs(A-B) - 1;
        int sec = (A<B? B-1 : N-B);
        sort(s.rbegin(), s.rend());     // g -> l
        int t = 1, ans = 0;
        for (auto& i : s) {
            if (t <= fireworks && t+i <= sec) {
                t++; ans++;
            }
        }

        cout << ans << endl;
    }
}
