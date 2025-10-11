// Problem A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        int ans = 0;
        int neg = 0;
        for (int i{0}; i < N; ++i) {
            int x;
            cin >> x;

            if (x == 0) ans++;
            else if (x == -1) neg++;
        }

        if (neg % 2 == 1) ans += 2;

        cout << ans << endl;
    }
}
