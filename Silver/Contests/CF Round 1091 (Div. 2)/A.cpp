// A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (auto& i : a) cin >> i;

        if (K%2==0 || N%2==0) {
            cout << "YES\n";
            continue;
        }

        int nxt = 0;
        for (int i{0}; i < N; i++) {
            if (a[i]%2==1) {
                nxt = (nxt+1)%2;
            }
        }

        cout << (nxt==1? "YES\n" : "NO\n");
    }
}
