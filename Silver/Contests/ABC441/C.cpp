// C

// you can assume the cups of sake are chosen least optimally, so the K smallest cups
// contain sake. of course, the person choosing the cups doesn't know this, so with no
// imformation, it would be most optimal to choose the biggest -> smallest cups. after
// drinking N-K cups, it is guarenteed that the remaining cups will be sake (if u were
// unlucky and the N-K cups u drank were all water). this is essentially just a greedy
// problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    long long X;
    cin >> N >> K >> X;
    vector<int> a(N);
    for (auto& i : a) cin >> i;

    sort(a.begin(), a.end());
    int ans = N-K;  // cups without sake
    for (int i{K-1}; i >= 0; --i) {
        X -= a[i];
        ans++;
        if (X <= 0) break;
    }

    if (X <= 0) cout << ans << endl;
    else cout << -1 << endl;
}
