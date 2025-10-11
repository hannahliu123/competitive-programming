// Problem C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> exists(N+1, 0);
        for (int i{0}; i < N; ++i) {
            int x;
            cin >> x;
            exists[x]++;
        }

        int ans = 0;
        for (int i{0}; i <= N; ++i) {
            if (i < K && exists[i] == 0) {
                ans++;
            } else if (i == K) {
                ans = max(ans, exists[i]);
            }
        }

        cout << ans << endl;
    }
}
