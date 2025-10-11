// Problem B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;

        for (int i{0}; i < N-1; ++i) {
            if (i % 2 == 0) cout << -1 << ' ';
            else cout << 3 << ' ';
        }

        if (N % 2 == 0) cout << 2 << endl;
        else cout << -1 << endl;
    }
}
