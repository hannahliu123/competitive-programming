// At a single column at index i with rock height h[i], the total water height is
// limited by the maximum rock column to the left and right. this pmos how simple
// it was....

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> h(N);
    for (int i=0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> mxLeft(N, -1);
    for (int i=1; i < N; i++) {
        mxLeft[i] = max(mxLeft[i-1], h[i-1]);
    }
    vector<int> mxRight(N, -1);
    for (int i=N-2; i >= 0; i--) {
        mxRight[i] = max(mxRight[i+1], h[i+1]);
    }

    int ans = 0;
    for (int i=0; i < N; i++) {
        int height = min(mxLeft[i], mxRight[i]);
        if (height == -1) continue;
        ans += max(0, height-h[i]);
    }

    cout << ans << '\n';

    return 0;
}
