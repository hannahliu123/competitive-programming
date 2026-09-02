#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        bool pos = true;
        for (int i=2; i*i <= (N+1); i++) {
            if ((N+1)%i==0) {
                pos = false; break;
            }
        }

        if (pos) cout << "YES\n";
        else cout << "NO\n";
    }
}