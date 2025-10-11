// A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int s;
        cin >> s;

        double result = sqrt(s);
        if (fmod(result, 1) == 0) {
            cout << 0 << ' ' << sqrt(s) << endl;
        } else cout << -1 << endl;
    }
}
