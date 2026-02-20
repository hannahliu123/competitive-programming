// USACO 2023 US Open Contest, Silver
// Problem 1. Milk Sum

// Start: 10:22
// End: 11:13       51 mins

// not bad but this was suppoused to be a really easy problem. i got tripped up on
// the implementation. the logic was so so so simple but there were so many issues i
// faced when figuring out the specific implementation. i should've just make my code
// messier and broke up the calculation into different cases (either replace with
// a higher val or lower val). the code wouldve been longer and not as clean, but it
// would've been a lot less confusing more me.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> a(N);   // milk per min, index after sorted
    vector<int> loc(N);   // loc in sorted from original order
    for (int i{0}; i < N; ++i) {
        int x; cin >> x;
        a[i] = {x,i};
    } sort(a.begin(), a.end());     // l -> g

    long long ans = 0LL;
    vector<long long> pref(N+1, 0);
    for (int i{0}; i < N; ++i) {
        loc[a[i].second] = i;
        ans += (long long)(i+1)*a[i].first;
        pref[i+1] = pref[i] + a[i].first;
    }

    int Q; 
    cin >> Q;
    while (Q--) {
        int i, j;   // j = new value
        cin >> i >> j; i--;
        
        long long T = ans;
        int ogIdx = loc[i];    // after sorted
        long long ogVal = a[ogIdx].first;
        int newIdx = upper_bound(a.begin(), a.end(), make_pair(j,0)) - a.begin();
        if (j>ogVal) {
            newIdx--;
            T += pref[ogIdx+1] - pref[newIdx+1];
        } else T += pref[ogIdx] - pref[newIdx];
        T -= ogVal*(ogIdx+1);
        T += (long long)j*(newIdx+1);

        cout << T << '\n';
    }
}
