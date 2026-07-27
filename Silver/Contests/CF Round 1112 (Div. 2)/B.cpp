// B

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int N, K; cin >> N >> K;

        if (N-K < 2) {
            cout << -1 << '\n';
            continue;
        }

        // 1...0...101010...
        int zeroes = N/2;
        int ones = N-zeroes;
        int rep0 = 0, rep1 = 0;
        if (N%2==1) {
            rep0 = K/2;
            rep1 = K-rep0;
        } else {
            rep1 = K/2;
            rep0 = K-rep1;
        } rep0++; rep1++;
        for (int i=0; i < rep1; i++) cout << 1;
        for (int i=0; i < rep0; i++) cout << 0;
        ones -= rep1; zeroes -= rep0;
        while (ones>0 || zeroes>0) {
            if (ones>0) {
                cout << 1;
                ones--;
            } if (zeroes>0) {
                cout << 0;
                zeroes--;
            }
        } cout << '\n';
    }
}