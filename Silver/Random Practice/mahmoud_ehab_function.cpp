// E. Mahmoud and Ehab and the function - R2100

// Start: 9:29
// Finalized Idea: 9:48         19 mins to get the idea
// End: 10:26                   57 mins total (tho quite a bit was spent trying to debug)

// i basically got this but i couldn't debug my solution so i ended up just reading the
// solution. the issue was just that i wasn't updating fa based on the index parity of
// l because i knew if the range had an even number of elements, we don't need to update
// anything, but if it had an odd, i would always just add x to fa. BUT if l started on a
// section where we would subtract that element, we should've instead been subtracting x
// not adding! gosh idk if i would've been able to realize that myself, but if something
// like this happened during the contest i would've been SOO pissed. ig in that senario i
// should move on and work on another problem (take a break) before coming back to this
// and looking through it LINE BY LINE and rereading the problem statement

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    long long fa = 0LL;
    for (int i=0; i < N; i++) {
        long long a; cin >> a;
        if (i%2==0) fa += a;
        if (i%2==1) fa -= a;
    }
    long long fb = 0LL;
    vector<long long> b(M);
    vector<long long> f{};
    for (int i=0; i < M; i++) {
        cin >> b[i];
        if (i%2==0) fb += b[i];
        if (i%2==1) fb -= b[i];
        if (i>=N-1) {
            if ((i-N+1)%2==0) f.push_back(fb);
            else f.push_back(-fb);

            if ((i-N+1)%2==0) fb -= b[i-N+1];
            else fb += b[i-N+1];
        }
    } sort(f.begin(), f.end());

    for (int i=0; i <= Q; i++) {
        if (i>0) {
            int l, r; long long x; cin >> l >> r >> x;
            if ((r-l)%2==0) {
                if (l%2==1) fa += x;
                else fa -= x;
            }
        }
        long long ans = LONG_LONG_MAX;
        auto it = lower_bound(f.begin(), f.end(), fa);
        if (it != f.end()) {
            ans = min(ans, abs(fa-(*it)));
        }
        if (it != f.begin()) {
            it--;
            ans = min(ans, abs(fa-(*it)));
        }

        cout << ans << '\n';
    }
}