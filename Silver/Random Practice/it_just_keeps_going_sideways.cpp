// CF - F. It Just Keeps Going Sideways - R1700

// ughhh i was so so so close to getting this problem but then the implementation just
// got really complicated. at first it was just a matter or rearranging equations and
// using pref/suff sums. this is one of the problems where there are ways to simplify
// the implmentation by a ton but only if you stop thinking in circles. this is the type
// problem that i should prolly just walk away from and take a break then come back to 
// it later

// the actual solution has the first part similar to my logic, except cleaner. To compute
// the original answer w/o any operations applied, it's simply the final indexes for each
// height - the sum of original indexes at each height (which is what i did). but the
// editorial implmenetation was cleaner in that to compute the sum of original indexes,
// you just need to track it in one variable. at each hight, the current column contributes
// its index a[i] times, so it's contribution is i*a[i].

// now, for the final operation, we can simulate what happens when we remove the last
// (rightmost) occuring element from each height. When we do this, the sum of original
// indexes decreases by i (cos well we're removing i, duh). Then the sum of final indexes
// just decreases by N-row_cnt[a[i]]. You can try it out on paper but the math works out
// because there was originally row_cnt[a[i]] spaces that were occupied and so we used
// the suffix array but now we get rid of that last leftmost space cos we have one less
// element. Essentially, final indexes decrease by N-row_cnt[a[i]] then initial indexes 
// decrease by i

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<long long> suff(N+1, 0);
        for (int i=N-1; i >= 0; i--) {
            suff[i] = suff[i+1] + i;
        }

        vector<int> row_cnt(N+2, 0);    // total blocks in this row
        for (int i=0; i < N; i++) {
            row_cnt[a[i]+1]--;
            row_cnt[1]++;
        }
        for (int i=2; i <= N; i++) {
            row_cnt[i] += row_cnt[i-1];
        }

        long long ans = 0;
        for (int i=1; i <= N; i++) { // row, not column
            ans += suff[N-row_cnt[i]] - (long long)a[i-1]*(i-1);
        }
        
        int mx = 0;
        unordered_set<int> seen{};
        for (int i=N-1; i >= 0; i--) {
            if (seen.count(a[i])) continue;
            mx = max(mx, i-(N-row_cnt[a[i]]));
            seen.insert(a[i]);
        }

        cout << ans+mx << endl;
    }
}