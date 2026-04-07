// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        int k; cin >> k;

        int ans = 0, x = a[--k];
        bool flipped = false;
        int l = 0, r = N-1;
        while (true) {
            if (flipped) {
                while (l<k && a[l]!=x) l++;
                while (r>k && a[r]!=x) r--;
            } else {
                while (l<k && a[l]==x) l++;
                while (r>k && a[r]==x) r--;
            }

            if (l==r && !flipped) break;

            flipped = (flipped? false : true);
            ans++;
        }

        cout << ans << '\n';
    }
}
