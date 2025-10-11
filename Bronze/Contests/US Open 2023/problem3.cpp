// Rotate and Shift

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, T;    // cows, shifting positions, minutes
    cin >> N >> K >> T;

    vector<int> A(K);   // shifting positions
    vector<int> cows(N);
    for (int i{0}; i < K; ++i) cin >> A[i];
    for (int i{0}; i < N; ++i) cows[i] = i;

    int round{0};

    while (T--) {
        cout << round++ << "\t";
        for (int a : cows) cout << a << ' ';
        cout << '\n';

        int lastA = cows[A[K-1]];
        for (int i{K-1}; i >= 0; --i) {
            cows[A[i]] = (i==0? lastA : cows[A[i-1]]);
        } for (int& a : A) {
            a=(a+1)%N;
        }
    }

    cout << round << "\t";

    for (int i{0}; i < N; ++i) {
        if (i > 0) cout << ' ';
        cout << cows[i];
    } cout << endl;
}
