// C

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (auto& i : a) cin >> i;

        int ans{1};
        for (int i{1}; i < N; ++i) {
            if (a[i] > a[i-1]+1) ans++;
            else a[i] = a[i-1];
        }

        cout << ans << endl;
    }
}
