// Problem B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N, S;
        cin >> N >> S;

        int zeroes = 0, twos = 0, ones = 0;
        vector<int> a(N);
        for (int i{0}; i < N; ++i) {
            cin >> a[i];
            if (a[i] == 2) twos++;
            else if (a[i] == 1) ones++;
            else zeroes++;
        }

        int mn = 2*twos + ones;
        S -= mn;
        if (S < 0) {
            for (int i{0}; i < N; ++i) cout << a[i] << ' ';
            cout << endl;
            continue;
        }

        if (S % 2 == 1) {
            S -= 3;
            if (S < 0) {
                for (int i{0}; i < zeroes; ++i) cout << 0 << ' ';
                for (int i{0}; i < twos; ++i) cout << 2 << ' ';
                for (int i{0}; i < ones; ++i) cout << 1 << ' ';
                cout << endl;
                continue;
            }
        }

        cout << -1 << endl;
    }
}
