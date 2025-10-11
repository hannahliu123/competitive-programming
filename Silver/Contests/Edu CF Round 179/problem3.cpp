// C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        vector<long long> a(N+1, 0);      // 1-indexed
        for (int i{1}; i <= N; ++i) cin >> a[i];

        long long ri{1}, li{1};
        long long ans{(N-1)*a[1]};
        for (int i{2}; i <= N; ++i) {
            li = i;
            if (a[li] != a[ri]) ri = i;
            ans = min(ans, (ri-1)*a[ri]+(N-li)*a[li]);
        }

        cout << ans << '\n';
    }
}
