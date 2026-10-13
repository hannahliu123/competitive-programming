// E. Repentance Is Already on the Way - R1x00

// Start: 7:54
// End: 8:20        26 mins!!!!

// woohoooO!!! yay i needed this confidence boost heh but i fear this is a veeeery low
// rated problem... idk i wanna come back later once the rating is posted to see what it
// was cos rating is sooo deflated nowadays. i would guess like at most 1400 or maybe even
// as low as 1200

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<int> b(N);
        for (auto& i : b) cin >> i;

        int ans = 0;
        for (int i=0; i < N; i++) {
            if (i==N-1) {
                ans += (a[i]==b[i]? 2 : 1);
            } else {
                ans += (a[i]==b[i+1]? 2 : 1);
                ans += (a[i+1]==b[i]? 2 : 1);
            }
        }

        int diff = 0;
        int mx = ans;
        for (int i=0; i < N-1; i++) {
            diff += (a[i]==b[i]? 2 : 1);
            diff -= (a[i]==b[i+1]? 2 : 1);
            mx = max(mx, ans+diff);
        }

        cout << mx << '\n';
    }
}