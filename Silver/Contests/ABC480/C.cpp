#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K, T; cin >> N >> K >> T;
    long long ans = 0;
    long long pre = 0;
    for (int i=0; i < N; i++) {
        long long start; cin >> start;
        if (pre >= T) continue;
        long long end = start+K;
        if (pre < start) {
            if (start > T) start = T;
            ans += (start-pre + K-1)/K;
        }
        pre = end;
    }
    if (pre < T) {
        ans += (T-pre + K-1)/K;
    }

    cout << ans << '\n';
}