// D

// split this up into regions between each special index. no matter what, if you have two
// boundaries anywhere but in different regions, that means theres at least 1 special index
// between them so they can be paired and flipped together to get rid of them. thinking of
// this problem as boundaries is actually so so helpful because the order in which you choose
// to flip/pair these boundaries doesnt matter, as long as you get rid of them. it's like
// combining areas of the same value until everything is the same. so, the answer will always
// be total_boundaries/2 because you can pair all of them UNLESS there is a region with more
// boundaries than total_boundaries/2. in that case, you can only pair some of them with
// boundaries outside that region. the remaining boundaries will need to be removed one by
// one by pairing it with the nearest special index. these flip operations will only get rid
// of one boundary per flip.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        vector<int> a(N+2);
        for (int i=1; i <= N; i++) cin >> a[i];
        vector<int> p(K+2);
        for (int i=1; i <= K; i++) cin >> p[i];
        int x = a[p[1]];
        a[0] = x; a[N+1] = x;
        p[0] = 0; p[K+1] = N+1;

        int mx = 0;     // max number of boundaries in a region
        int tot = 0;    // total number of boundaries
        for (int k=1; k <= K+1; k++) {
            int curr = 0;   // number of boundaries from prev special index to curr special index-1
            for (int i=p[k-1]; i < p[k]; i++) {
                if (a[i] != a[i+1]) curr++;
            }
            mx = max(mx, curr);
            tot += curr;
        }

        cout << max(mx, tot/2) << '\n';
    }
}
