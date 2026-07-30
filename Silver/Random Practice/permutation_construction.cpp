// D. Permutation Construction - R1800

// we essentially want for every pref[j]-pref[i]>0, or pref[j]>pref[i] and i<j, we
// want p[i]>p[j]. then for all pref[j]<pref[i] and i<j, we want p[i]<p[j]. to 
// construct an optimal p, we want pref[j] to always be as large as possible in an
// inversion. thus, it makes sense to take the largest pref[j] and assign p[j] the
// value of 1 so it can end as many inversions as possible and start as few inversions
// as possible. Similarly, it also makes sense to take the smallest pref[i] and assign
// p[i] to be N so that it can start as many inversions as possible and end as few as
// possible. In this way, it is optimal to just assign values of p in order from 1 to
// N based on the values of pref from greatest to least

// wait actually thats not entirely correct. instead you can use an indicator variable
// of wether or not a combo (i,j) is an inversion, basically just p[i]>p[j]. then you
// can expand the formulas and math it out

// this problem was actually pretty simple my brain was just fried and im really
// disappointed that i didn't think this one through thoroughly. i should've written
// out that prefix sum relationship and tried to play around with the formula

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        vector<int> a(N);
        vector<pair<long long,int>> pref(N, {0,0});
        for (int i=0; i < N; i++) {
            cin >> a[i];
            if (i<N-1) {
                pref[i+1] = {a[i],i+1};
                pref[i+1].first += pref[i].first;
            }
        }
        sort(pref.rbegin(), pref.rend());   // g -> l
        vector<int> ans(N);
        for (int i=0; i < N; i++) {
            int idx = pref[i].second;
            ans[idx] = i+1;
        }

        for (auto& i : ans) cout << i << ' ';
        cout << '\n';
    }
}