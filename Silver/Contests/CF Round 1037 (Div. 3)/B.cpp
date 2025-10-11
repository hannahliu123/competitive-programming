// Problem B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> a(N);
        for (auto& i : a) cin >> i;

        int days{0}, ans{0};
        for (int i{0}; i < N; ) {
            if (a[i] == 0) days++;
            else days = 0;

            if (days == K) {
                ans++;
                days = 0;
                i += 2;
            } else i++;
        }

        cout << ans << endl;
    }
}
