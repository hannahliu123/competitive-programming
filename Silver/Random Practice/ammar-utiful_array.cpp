// H. Ammar-utiful Array - R1x00

// Start: 8:21
// End: 9:08            47 mins

// this was actually such an easy problem i just wasted so much time debugging my 
// stupid loop and also adding the faster i/o thing. im glad i didn't overoptimize lol
// and also this is the second time my code TLEs only if i don't add the i/o optimization.
// ig it's needed when there's a lot of input/output

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<int> val(N);
    for (int i=0; i < N; i++) cin >> val[i];
    vector<vector<int>> col(200000, vector<int>{});
    for (int i=0; i < N; i++) {
        int c; cin >> c; c--;
        col[c].push_back(val[i]);
    }
    vector<vector<ll>> pref(200000, vector<ll>{0LL});
    for (int c=0; c < 200000; c++) {
        for (int i=0; i < col[c].size(); i++) {
            pref[c].push_back(pref[c].back() + col[c][i]);
        }
    }

    vector<ll> diff(200000, 0LL);
    ll sum = 0LL;
    int Q; cin >> Q;
    while (Q--) {
        int type, c; ll x; cin >> type >> c >> x; c--;
        if (type==1) {
            sum += x;
            diff[c] += x;
        } else {
            int lo=0, hi=pref[c].size()-1;
            while (lo < hi) {
                int mid = (lo+hi+1)/2;
                ll contr = pref[c][mid] + (sum-diff[c])*(ll)mid;
                if (contr <= x) lo = mid;
                else hi = mid-1;
            }
            cout << lo << '\n';
        }
    }
}