// A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, S, X;
        cin >> N >> S >> X;

        int sum = 0;
        for (int i{0}; i < N; ++i) {
            int x; cin >> x;
            sum += x;
        }

            S -= sum;
            if (S%X == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else cout << "NO" << endl;
    }
}
