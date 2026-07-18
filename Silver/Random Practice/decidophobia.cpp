// CF - B. Decidophobia - R1500

// bro this is so annoying why can't i see these patterns theyre literally so obvious.
// anyways no matter what, if you start with everyone having no gift, the answer is 0.
// If you give person i a gift, the answer increases by 2d*a[i] and decreases by the sum
// of the weights of d people to the left and d people to the right. Now, say you move on
// to the next person (i+1). Now, if you decide to give i+1 a gift, you have to be careful
// because person i already got a gift. When person i got their gift, they counted i+1 as
// not having a gift, so it subtracted a[i+1] from the answer. But now that a[i+1] has a 
// gift, we need to add that a[i+1] back. Additionally, we also added 2d*a[i] when now it
// should've been (2d-1)*a[i], so we need to subtract a[i] as well. So when we do decide to
// add person i+1, the happiness increases by (2d-1)*a[i+1] (then we add back that a[i+1])
// so it becomes just 2d*a[i+1], then the happiness decreases by the sum of 2d around i+1
// except for person i, so -sum[i+1]+a[i] (then we subtract a[i]) so just sum[i+1]. The
// takeaway is that no matter what, when you give a person j a gift, the happiness in total
// will just increase by 2d*a[j] and decrease by the sum of weights which you can precompute.
// With that, you can greedily decide who to give gifts to

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, D; cin >> N >> D;
        vector<long long> a(N);
        for (int i=0; i < N; i++) {
            cin >> a[i];
        }

        vector<long long> sum(N, 0);
        int l=-1*D, r=-1;
        long long curr = 0;
        for (int i=N-1; i >= N-D; i--) curr += a[i];
        for (int i=0; i < N; i++) {
            sum[i] += curr;
            curr -= a[(l+N)%N];
            l++; r++;
            curr += a[(r+N)%N];
        }
        curr=0; l=N; r=N+D-1;
        for (int i=0; i < D; i++) curr += a[i];
        for (int i=N-1; i >= 0; i--) {
            sum[i] += curr;
            curr -= a[r%N];
            r--; l--;
            curr += a[l%N];
        }

        long long ans = 0;
        for (int i=0; i < N; i++) {
            long long contr = 2LL*D*a[i] - sum[i];
            if (contr > 0) ans += contr;
        }

        cout << ans << '\n';
    }
}
