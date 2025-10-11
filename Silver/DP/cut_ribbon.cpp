// CF - A - Cut Ribbon

// This is just brute force. OMG this annoyed me so much. like i actually hate this
// problem so much asjfdhkjasfrefkajksdjfjfalksdj

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int ans{0};
    for (int i{0}; i <= n/a; ++i) {
        for (int j{0}; j <= (n-i*a)/b; ++j) {
            if ((n - a*i - b*j) % c == 0) {
                int k = (n - a*i - b*j) / c;
                ans = max(ans, i+j+k);
            }
        }
    }

    cout << ans << endl;
}
