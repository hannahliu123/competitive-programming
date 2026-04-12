// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        // vector<int> a(N);
        // for (auto& i : a) cin >> i;
        // int k; cin >> k;

        // int ans = 0, x = a[--k];
        // bool flipped = false;
        // int l = 0, r = N-1;
        // while (true) {
        //     if (flipped) {
        //         while (l<k && a[l]!=x) l++;
        //         while (r>k && a[r]!=x) r--;
        //     } else {
        //         while (l<k && a[l]==x) l++;
        //         while (r>k && a[r]==x) r--;
        //     }

        //     if (l==r && !flipped) break;

        //     flipped = (flipped? false : true);
        //     ans++;
        // }

        // i boundary is when a[i] != a[i+1]. we add padding on both sides of array a to make
        // sure the first and last values are counted as a boundary if they aren't equal to 
        // x
        // treat each "boundary" as smthing you want to remove. It's kinda similar to if you
        // deleted all repetitions of the same value in a row (ex. 100011 -> 101). say you 
        // choose to flip a region [l, r]. if l-1 or ris a boundary, it is removed. we can
        // remove at most two boundaries per 1 flip operation (one on each side of k). because
        // l <= k and r >= k, the boundaries to the left of k (l) must have an index <k (bc
        // l<=k so the boundary that is removed is <k). for the boundaries to the right of k (r),
        // it must have an index >= k (cos if u flip r, the boundary at r disappears)
        vector<int> a(N+2);
        for (int i=1; i <= N; i++) cin >> a[i];
        int k; cin >> k;
        int x = a[k];
        a[0] = x; a[N+1] = x;
        int left=0, right=0;
        for (int i{0}; i < N+1; i++) {
            if (a[i]!=a[i+1]) {
                if (i < k) left++;
                else right++;
            }
        }
        int ans = max(left, right);

        cout << ans << '\n';
    }
}
