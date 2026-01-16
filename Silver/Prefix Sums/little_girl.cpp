// CF - C. Little Girl and Maximum Sum - R1500

// Start: 8:21
// End: 8:34        13 mins!!

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> diff(N+1, 0);

    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--; r;
        diff[l]++; diff[r]--;
    }

    for (int i{1}; i <= N; ++i) {
        diff[i] += diff[i-1];
    } sort(diff.begin(), diff.end());

    long long ans = 0LL;
    for (int i{0}; i < N; ++i) {
        ans += (long long)diff[i+1]*a[i];
    }

    cout << ans << endl;
}
