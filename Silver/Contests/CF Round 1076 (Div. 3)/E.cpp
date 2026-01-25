// E

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ans(N+1, -1);
        for (int i{0}; i < N; ++i) {
            int x; cin >> x;
            ans[x] = 1;
        }

        for (int i{1}; i <= N/2; ++i) {
            if (ans[i] == -1) continue;
            for (int j{2}; j<=i && j*i <= N; ++j) {
                if (ans[j] == -1) continue;
                if (ans[j*i] == -1) ans[j*i] = ans[i]+ans[j];
                else ans[j*i] = min(ans[j*i], ans[i]+ans[j]);
            }
        }

        for (int i{1}; i <= N; ++i) {
            cout << ans[i] << ' ';
        } cout << endl;
    }
}
