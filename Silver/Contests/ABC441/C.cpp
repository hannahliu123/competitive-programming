// C

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
