// A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t{0}; t < T; ++t) {
        int x;
        cin >> x;

        vector<int> crystals{1, 1, 3};

        int lo{1}, hi{3}, i{0}, j{1}, ans{3};
        while (crystals[0] < x || crystals[1] < x || crystals[2] < x) {
            if (i == 0) {
                crystals[i] = hi;
                if (j == 1) {
                    i = 1;
                    j = 2;
                } else if (j == 2) {
                    i = 2;
                    j = 1;
                }
            } else {    // i == 1 or 2
                crystals[i] = hi*2 + 1;
                lo = hi;
                hi = crystals[i];
                i = 0;
            }
            ans++;
        }

        cout << ans << '\n';
    }
}
