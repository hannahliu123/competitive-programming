// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, K;
        string s;
        cin >> n >> K >> s;

        int zero{0}, one{0};
        for (int i{0}; i < n; ++i) {
            if (s[i] == '0') zero++;
            else one++;
        }

        int diff{abs(zero-one)/2};

        if ((K%2 == diff%2) && (K >= diff) && (K <= n/2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
