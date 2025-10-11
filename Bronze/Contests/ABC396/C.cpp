#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> B(N);
    vector<int> W(M);
    for (int i{0}; i < N; ++i) {
        cin >> B[i];
    } for (int j{0}; j < M; ++j) {
        cin >> W[j];
    }

    sort(B.rbegin(), B.rend());
    sort(W.rbegin(), W.rend()); // greatest to least

    int mx = max(M, N);
    long long ans{0};       // OH MY GOSH I HATE LONG LONGS
    for (int i{0}; i < mx; ++i) {
        if (i >= M) {
            if (B[i] > 0) {
                ans += B[i];
            }
        } else if (i < N) {
            if (W[i]>0 && (B[i]>0 || (B[i]<0 && abs(B[i])<W[i]))) {
                ans += (W[i] + B[i]);
            } else if (W[i]<0 && B[i]>0) {
                ans += B[i];
            }
        }
    }

    cout << ans << endl;
}
