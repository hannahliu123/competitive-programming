// D. Simons and Beating Peaks - R1700

// Start: 5:58
// End: 7:06        1 hr 8 mins

// YAYAYAYYAYA ok well my solution is based off of longest decreasing subsequence, so dp
// but the editorial yaps about cartesian trees... uh yea idk what that is. okay so its
// basically a binary tree where all children are either larger or smaller than the parent.
// i guess its conceptually similar to what i did. idk i just ended up realizing that we
// wanna find the longest decreasing then increasing sequence. but there are constraints
// to what counds as a sequence because only elemetns around non-cool indicies can be
// removed. non-cool indicies can also be removed by larger non-cool indicies. in this
// way i just tweaked the normal lis algorithm to come up with this solution :)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;
        vector<bool> perm(N, false);
        for (int i=1; i < N-1; i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) perm[i] = true;
        }

        vector<int> ldsf(N,1);  // forward
        vector<int> tails;
        for (int i=0; i < N; i++) {
            if (tails.empty() || a[i] < tails.back()) {
                tails.push_back(a[i]);
                ldsf[i] = tails.size();
            } else {
                int idx = lower_bound(tails.begin(), tails.end(), a[i], greater<int>()) - tails.begin();
                tails[idx] = a[i];
                ldsf[i] = idx+1;
                if (perm[i]) tails.erase(tails.begin()+idx+1, tails.end());
            }
        }
        vector<int> ldsb(N,1);  // backwards
        tails = {};
        for (int i=N-1; i >= 0; i--) {
            if (tails.empty() || a[i] < tails.back()) {
                tails.push_back(a[i]);
                ldsb[i] = tails.size();
            } else {
                int idx = lower_bound(tails.begin(), tails.end(), a[i], greater<int>()) - tails.begin();
                tails[idx] = a[i];
                ldsb[i] = idx+1;
                if (perm[i]) tails.erase(tails.begin()+idx+1, tails.end());
            }
        }

        int mx = 1;
        for (int i=0; i < N; i++) mx = max(mx, ldsf[i]+ldsb[i]-1);
        cout << N-mx << '\n';
    }
}