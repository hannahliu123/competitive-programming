// Problem 1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L, R;
    cin >> N >> L >> R;

    int ans = 0;
    for (int i{0}; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;

        if (X <= L && Y >= R) ans++;
    }

    cout << ans << endl;
}
