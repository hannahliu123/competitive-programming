// CF - B. Studying Algorithms

// Start: 11:20
// End: 11:25       5 mins :D

#include <bits/stdc++.h>
using namespace std;;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> a(N);
    for (auto& i : a) cin >> i;

    sort(a.begin(), a.end());

    int i{0};
    int ans{0};
    while (X > 0 && i < N) {
        X -= a[i++];
        if (X >= 0) ans++;
    }

    cout << ans << endl;
}
