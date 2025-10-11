// CF - F. Money Trees - R1300

// Start: 4:22
// Break: 4:47 - 4:55
// End: 5:10                35 mins (bro i should've been able to solve that way faster)

// Okay I absolutely HATE how I solved this problem. I was rushing and I barely used paper
// and I didn't think anything through. This was literally just a classic two pointers 
// problem and I overcomplicated it so much I had to scratch my entire loop and restart. 
// I wasn't really focused when I sat down to practice, which I think is why I did so poorly.
// I need to remember quality over quantity. If I'm gonna practice CF, I better lock in
// completely. 

// So the editorial used binary search + prefix sums which I think is way more confusing than
// two pointers. It works in O(NlogN) time when mine works in O(2N) or basically O(N) time (I
// think at least) I gueeess it works but whatever. I think I need more practice with binary
// search anyways tho

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<long long> a(N);
        for (auto& i : a) cin >> i;
        vector<int> h(N);
        for (auto& i : h) cin >> i;

        int l = 0, r = 0, ans = 0;
        long long sum = a[0];
        while (r < N) {
            if (sum <= K) {
                ans = max(ans, r-l+1);
                if (r == N-1) break;
                if (h[r] % h[r+1] == 0) {
                    r++;
                    sum += a[r];
                } else {
                    r++;
                    l = r;
                    sum = a[l];
                }
            } else {
                sum -= a[l];
                l++;
            }
        }

        cout << ans << endl;
    }
}
