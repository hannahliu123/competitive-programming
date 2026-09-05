// I spent roughly 1 hour 10 mins trying to figure out a REALLLLLLY sketchy solution
// with binary search and prefix sums and like 5 different arrays of different values
// which got really really messy. I'm not trying to debug this cos idrk what's going
// on if im gonna be honest and idek if my solution idea should work in the first place.

// okay so basically this is just like a math rearranging-ish problem

// I knew this had to do something with prefix sums and binary search, but it got too
// complicated because i was tracking too many arrays. in situations like these, that's
// a key signal that you should take a step back and write down the original equations
// then expand out the equations and try to combine terms together that can be computed
// in one go. this is VERY common for pref array problems too so im actually really glad
// i tried to solve this problem

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; ll K; cin >> N >> K;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        vector<ll> pref(N+1);
        vector<ll> idxpref(N+1);
        for (int i=1; i <= N; i++) {
            pref[i] = pref[i-1]+(ll)a[i-1];
            idxpref[i] = idxpref[i-1]+(i-1);
        }

        cout << 0 << ' ';
        for (int i=1; i < N-1; i++) {
            if (a[i+1] <= (ll)a[i-1]+K) {
                cout << 0 << ' '; continue;
            }

            int lo=i+1, hi=N-1;
            while (hi != lo) {
                int x = (hi+lo+1)/2;
                ll l = (ll)a[x]-(ll)K*x;
                ll r = (ll)a[i-1] - (ll)K*i;
                if (l <= r) hi = x-1;
                else lo = x;
            }
            cout << (pref[lo+1]-pref[i+1])-(K*(idxpref[lo+1]-idxpref[i+1]))-((ll)(lo-i)*((ll)a[i-1]-K*i)) << ' ';
        } cout << 0 << '\n';
    }
}