// E

// so the solution actually is just binary search on the answer. i explicitly eliminated
// this cos i thought having some target percentage doesn't give you any useful information
// but the answer involves rearraging the equation involving mid=P. So, if we want to check
// if acheiving a win rate of P or higher is possible, we r checking if some range [l,r]
// exists such that w(l,r)/(r-l+1) >= P where w(l,r) is the number of o's from l to r.
// now because the numerator and denominator are both changing each time we change l and r,
// it's hard to figure out if and how that's possible. But if you rearrange that into
// w(l,r) >= P*(r-l+1) then into w(l,r) - P*(r-l+1) >= 0, now you can rearrange that into
// (r-l+1)*(I-P) where I is an indicator variable if the current item is an o or x. 
// Essentially, you can loop from l to r and if s[i]==o, its contr is 1-P and if s[i]
// ==x, its contr is 0-P (or -P). In this way, every elem in s can be replaced by either
// 1-P or -P and you just wanna find a subarray that has a sum >= 0 and also has at least
// K o's

// yeah i dont think i wouldve gotten this but its more of just spending more time
// considering stupid binary search (love hate it) and also rearranging equations more

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; string s; cin >> N >> K >> s;

    double lo = 0.0, hi = 1.0;
    while (hi-lo > 0.0000001) {
        double P = (lo+hi)/2;

        vector<double> pref(N+1,0);
        for (int i=1; i <= N; i++) {
            pref[i] = pref[i-1] + (s[i-1]=='o'? 1-P : -P);
        } 
        vector<double> suff_mx(N+1);
        suff_mx[N] = pref[N];
        for (int i=N-1; i >= 0; i--) {
            suff_mx[i] = max(pref[i], suff_mx[i+1]);
        }
        bool pos = false;
        int r=-1, os = 0;
        for (int l=0; l < N; l++) {
            while (r < N-1 && os < K) {
                r++;
                if (s[r]=='o') os++;
            } if (os < K) break;
            if (suff_mx[r+1] >= pref[l]) {
                pos = true; break;
            }
            if (s[l]=='o') os--;
        }

        if (pos) lo = P;
        else hi = P;
    }

    cout << fixed << setprecision(7) << lo << '\n';
}