// E. Minimizing Difference - R2000

// ahh so the greedy realization here was that its possible to contruct a solution such
// that either L or R will be from the original array. Why? well if both L and R weren't
// from the original array, it's optimal to instead of increase/decrease the respective
// left/right elements, just apply operations to the side with fewer elements until it
// reaches a value that is in the array.

// this was another one of those problems that looks so easy at first but has some hidden
// complications :( and also i got stuck on 1 idea for too long and it was thus hard for
// me to branch out. my idea was really really close tho and i knew it was. i literally
// knew about that greedy realization but i didn't take it seriously cos i thought there
// mightve been more to it. also i was trying to overoptimize again ugh. i think i lokwey
// could've gotten this one tho

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; ll K; cin >> N >> K;
    vector<int> a(N);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());

    vector<ll> pref(N,0);
    vector<ll> suff(N,0);
    for (int i=1; i < N; i++) {
        pref[i] = pref[i-1]+(ll)i*(ll)(a[i]-a[i-1]);
    } for (int i=N-2; i >= 0; i--) {
        suff[i] = suff[i+1]+(ll)(N-i-1)*(ll)(a[i+1]-a[i]);
    }

    ll ans = LLONG_MAX;
    int idx = 0;
    for (int i=0; i < N; i++) {
        if (pref[i] > K) break;
        while (suff[idx]+pref[i] > K || idx<i) idx++;
        ll leftover = K-(suff[idx]+pref[i]);
        ll mx = a[idx] - leftover/(N-idx);
        mx = max(mx, (ll)a[i]);
        ans = min(ans, mx-a[i]);
    } idx = N-1;
    for (int i=N-1; i >= 0; i--) {
        if (suff[i] > K) break;
        while (pref[idx]+suff[i] > K || idx>i) idx--;
        ll leftover = K-(suff[i]+pref[idx]);
        ll mn = a[idx] + leftover/(idx+1);
        mn = min(mn, (ll)a[i]);
        ans = min(ans, a[i]-mn);
    }

    cout << ans << '\n';
}