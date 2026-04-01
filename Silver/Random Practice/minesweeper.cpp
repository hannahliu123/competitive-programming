// CF - C. Minesweeper - R1600

// Start: 6:43
// End: 7:07    24 mins

// bruh what this was so easy?!?

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int K; cin >> K;

        if (K==1) {
            cout << "YES\n1\n*\n.\n";
            continue;
        }

        if (K%5==0) {
            int ans = 3*(K/5);
            cout << "YES\n" << ans << '\n';
            for (int i=0; i < ans; i++) {
                if ((i-1) % 3 == 0) cout << '*';
                else cout << '.';
            } cout << '\n';
            for (int i=0; i < ans; i++) cout << '.';
        } else if ((K-3)%5==0) {
            K -= 3;
            int ans = 3*(K/5) + 2;
            cout << "YES\n" << ans << '\n';
            for (int i=0; i < ans; i++) {
                if (i % 3 == 0) cout << '*';
                else cout << '.';
            } cout << '\n';
            for (int i=0; i < ans; i++) cout << '.';
        } else if ((K-6)%5==0) {
            K -= 6;
            int ans = 3*(K/5) + 4;
            cout << "YES\n" << ans << '\n';
            for (int i=0; i < ans; i++) {
                if (i % 3 == 0) cout << '*';
                else cout << '.';
            } cout << '\n';
            for (int i=0; i < ans; i++) cout << '.';
        } else {
            cout << "NO";
        } cout << endl;
    }
}
