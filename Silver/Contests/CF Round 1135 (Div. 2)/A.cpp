#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        if (N<4) {
            cout << "-1\n";
            continue;
        }

        cout << "4 ";
        int nxt = N;
        for (int i=2; i <= N; i++) {
            if (i==4) {
                cout << "1 "; continue;
            } if (nxt==4) {
                nxt--;
            } cout << nxt << ' ';
            nxt--;
        } cout << '\n';
    }
}