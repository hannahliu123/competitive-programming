// CF - B. Kites - R1x00

// Start: 8:07
// End: 8:27        20 mins

// holy crap this was easy it scared me so bad when i got WA. luckily it was just
// integer overflow and i figured that out in 5 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        sort(a.begin(), a.end());

        vector<int> diff(N-1);
        vector<int> prefMn(N-1);
        vector<int> suffMn(N-1);
        for (int i=0; i < N-1; i++) {
            diff[i] = a[i+1]-a[i];
            if (i==0) prefMn[i] = diff[i];
            else prefMn[i] = min(prefMn[i-1], diff[i]);
        } suffMn[N-2] = diff[N-2];
        for (int i=N-3; i >= 0; i--) {
            suffMn[i] = min(suffMn[i+1], diff[i]);
        }

        int ans = INT_MAX;
        for (int i=0; i < N-1; i++) {
            int left = INT_MAX/2, right = INT_MAX/2;
            if (i>=2) left = prefMn[i-2];
            if (i<=N-4) right = suffMn[i+2];
            int mn = min(left, right);
            ans = min(ans, diff[i]+mn);
        }

        cout << ans << '\n';
    }
}
